/**
  * Créé par Cédric à l'aide du site du zéro "socket"
  * En colaboration avec Alexis et Jimmy
  * programme de transfert de données avec des sockets
  * langage::=C++
  */


/**
  * Permet la compilation sous avec windows
  */
#if defined (WIN32)
	#include <winsock2.h>


/**
  * Permet la compilation sous linux
  */
#elif defined (linux)
	#include <sys/types.h>
	#include <sys/socket.h>
	#include <netinet/in.h>
	#include <arpa/inet.h>
	#include <unistd.h>
	#include <pthread.h>
	// #define de simplification Linux to Windows
	#define closesocket(s) close(s)
#endif


/**
  * Inclusions standard multiplateforme
  */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstring>
#include <string>
#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>


/**
  * Inclusion personnelles
  */
#define _Je_serai_inclus_
#include "NetworkingException.hpp"
#include "reseau.hpp"


/**
  * Inclusions necessaire a partir de code.cpp
  */
#include <SFML/Window.hpp>
#include <GL/gl.h>
#include <GL/glu.h>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <cstdio>
#include <cmath>


/**
  * Permet de changer le port plus facilement que dans le code
  */
#define PORT 6685


/**
  * Active ou desactive les messages de debuggage
  */
bool bavard(false);


/**
  * Variables globales pour threads
  */
sockaddr_in sock_sin;
namespace sserv{
	std::mutex mx;
	std::mutex cs;
	std::mutex att_ec;
}

/**
  * Creer une nouvelle socket et retourne son indicateur
  */
int Serveur::creer_socket(){

	int sock;

	try{
	    	if((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1)
			throw NetworkingException(1);
		/* Si la socket est valide */
if(bavard)printf("Server\nOuverture de la socket %d en TCP/IP\n", sock);

		if(bind(sock, (sockaddr*)&sock_sin, sizeof(sock_sin)) == -1)
			throw NetworkingException(2);
		/* Si la socket fonctionne */

		if(listen(sock, 5) == -1)
			throw NetworkingException(3);

		/* Attente pendant laquelle le client se connecte */
if(bavard)printf("Server\nPatientez pendant que le client se connecte ...\n");
	}catch(NetworkingException ex){
		ex.displaySortieStandard2();
	}

	return sock;
}


/**
  * Renvoie un socket de connection avec le client fraichement connecte
  * Sans exeption, le serveur connait l'existance du client mais
  * le client saura qu'il est reellement connecte qu'a partir
  * de la reception de ces coordonnees par ...ecoute_clients(...)
  */
// Troll de compilation
void* ecoute_client(void*);
// connexion ()
void Serveur::connexion(int sock){

	/**
	  * variables adressage
	  */
	sockaddr_in csock_sin;
	socklen_t recsize=sizeof(csock_sin);

	int csock, bufferI = sizeof(bufferI);
	try{
		// retourne un socket pour la transaction avec le client
		// accepte
		if((csock = accept(sock, (sockaddr*)&csock_sin, &recsize)) == -1)
			throw NetworkingException(5);
		else{
if(bavard)printf("accept OK\n");
			// Si le client est accepte,
			// on attend la taille de son nom
			if((recv(csock, &bufferI, bufferI, 0)) == -1)
				throw NetworkingException(7);
if(bavard)printf("arrive de la taille du nom du nouveau client de %d\n", bufferI);
			char bufferS[bufferI];
			if((recv(csock, &bufferS, bufferI, 0)) == -1)
				throw NetworkingException(8);
if(bavard)printf("reception du nom du client %s\n", bufferS);
			std::string tmp(bufferS);
			if(this->csock.find(tmp) == this->csock.end()){
				sserv::cs.lock();
if(bavard)std::cout << "cs.lock();\n";
				this->csock.insert(insertionI(tmp, csock));
if(bavard)printf("%s ajoute dans la map de csock\n", tmp.c_str());
				sserv::cs.unlock();
if(bavard)std::cout << "cs.unlock();\n";
			}else{
				shutdown(csock, 2);
				closesocket(csock);
				throw NetworkingException(10);
			}
			// On ne sais jamais si un client ne va pas prendre
			// on nom deja utilise dans le code de ce programme
			if(threads.find(tmp) != threads.end())
				throw NetworkingException(9);
if(bavard)std::cout << "Ajout d'un nouveau thread pour une ecoute avec " << csock << std::endl;
			pthread_t * Ttmp = new pthread_t;
			threads.insert(insertionT(tmp, Ttmp));
			Serveur::Ecoute * Etmp = new Serveur::Ecoute(this, csock);
			pthread_create(Ttmp, nullptr, ecoute_client, (void*)Etmp);
if(bavard)std::cout << "Thread d'ecoute lance pour " << Etmp->csock << std::endl;
		}
				
if(bavard)printf("il est connecte avec la socket %d de %s:%d\n", csock, inet_ntoa(csock_sin.sin_addr), htons(csock_sin.sin_port));
	}catch(NetworkingException e){
		e.displaySortieStandard2();
	}
}


/**
  * Threads
  * Un par socket client
  * l'efficassité augmentera en fonction de l'evolution
  * du materiel faisant tourner les serveurs
  * @csock socket client a qui envoyer le message
  * @bufferS message a envoyer
  */
void Serveur::echange_client(int csock, std::string bufferS){

	char tmp[bufferS.size()+1];
	strcpy(tmp, bufferS.c_str());
	int bufferI = strlen(tmp)+1;

	try{
		if((send(csock, &bufferI, sizeof(bufferI), 0)) == -1)
			throw NetworkingException(4);
		if((send(csock, tmp, bufferI, 0)) == -1)
			throw NetworkingException(4);

if(bavard)std::cout << "Server\nMessage : " << bufferS << "\nTo " << csock << " envoye" << std::endl;

	}catch(NetworkingException e){
		e.displaySortieStandard2();
	}
}


/**
  * Fonction ami de la classe serveur permettant la
  * demade de connexion par les clients
  */
void* attente_clients(void * arg){
	// serv est un pointeur sur le serveur courant
	Serveur * serv = (Serveur*)arg;
	while(1){
if(bavard)std::cout << "Arrive sur une nouvelle connexion\n";
		serv->connexion(serv->sock);
if(bavard)std::cout << "Nouvelle connexion prise en compte\n";
	}

	return nullptr;
}


/**
  * ecoute les messages de sont client attitre par
  * @csock
  * et insert les receptions dans messages
  */
void* ecoute_client(void* arg){

	Serveur * serv = ((Serveur::Ecoute*)arg)->serv;

	int csock = ((Serveur::Ecoute*)arg)->csock;

	// Libération de la memoire utilise
	delete (Serveur::Ecoute*)arg;

	// taille du buffer de reception
	int bufferI;
	// Tant que le client est connecte, on l'ecoute

if(bavard)std::cout << "Nouvelle ecoute du socket " << csock << std::endl;
	while(1){
		try{
			// On attend la taille du prochain buffer de reception
			// et on verifie aque le serveur n'a pas deja un de
			// nos messages en attente. Permet le lag et non le seg
			// fault
if(bavard)std::cout << "Attente de reception de taille du prochain buffer pour " << csock << std::endl;	
			if((recv(csock, &bufferI, sizeof(bufferI), 0)) == -1)
				throw NetworkingException(7);

			// Si on est toujours la, on a compris la taille,
			// On va chercher le buffer de la taille bufferI recu
			// precedement,
			// et on le met dans une file d'attente de traitement
if(bavard)std::cout << "FROM : " << csock << "\nBufferI obtenu, une chaine de " << bufferI << " va arriver\n";
			// buffer de reception du message
			char bufferS[bufferI];
			if((recv(csock, bufferS, bufferI, 0)) == -1)
				throw NetworkingException(8);
if(bavard)std::cout << "BufferS obtenu avec succes\n";
			// S'il n'y a pas eu d'exception, on peut executer
			// la suite

			// Prend la main sur les messages de serv
			// et empeche les autres decrire dessus
if(bavard)std::cout << bufferS << ": a inserer : mx.lock()\n";
			sserv::mx.lock();
			if(serv->messages.find(csock) != serv->messages.end())
				serv->messages.erase(csock);
			serv->messages.insert(insertionS(csock, bufferS));
			sserv::mx.unlock();
if(bavard)std::cout << "mx.unlock()\n";
if(bavard)std::cout << serv->messages.find(csock)->second << " : Ajoute dans serv->messages\n";

		}catch(NetworkingException e){
			e.displaySortieStandard2();
		}

		// Dans tout les cas, on attendra la taille
		// d'un prochain buffer
		bufferI = sizeof(bufferI);
	}		

	return nullptr;
}


/**
  * Prend tout les messages stocké dans la base et les
  * renvoi a tout les clients sauf l'emetteur
  */
void* envoi_aux_clients(void* arg){

	Serveur * serv = (Serveur*)arg;
	std::map<int, std::string>::iterator itMess = serv->messages.begin();
	std::map<std::string, int>::iterator itCli = serv->csock.begin();

if(bavard)printf("Envoi_aux_client(void*) lance\n");
	while(1){
		if(itMess != serv->messages.end()){
if(bavard)std::cout << "Un nouveau message doit être envoye a tout les clients\n";
			// Parcourt de tout les clients
			while(itCli != serv->csock.end()){
				// Si la socket a qui on envoie le message
				// est different de l'emeteur du message,
				// on envoie, sinon, on itere et on passe au suivant
				if(itCli->second != itMess->first){
if(bavard)printf("Envoi de la chaine %s a %s\n", itMess->second.c_str(), itCli->first.c_str());
					serv->echange_client(itCli->second, itMess->second);
				}
				++itCli;
			}
			// Apres l'envoie a tous, il faut biensur enlever
			// le message sans oublier de bloquer
			// l'ecriture sur les messages
if(bavard)printf("Suppression de la chaine envoye\n");
			sserv::mx.lock();
if(bavard)std::cout << "mx.lock();\n";
			serv->messages.erase(itMess);
			sserv::mx.unlock();
if(bavard)std::cout << "mx.unlock();\n";
		}
		// on repart pour un parcourt de tout les clients
		itCli = serv->csock.begin();
		// On prend le prochain message
		itMess = serv->messages.begin();
	}

	return nullptr;
}


/**
  * Le constructeur 
  *    initialise les erreurs du Networking exception
  *    initialise la socket principale et lui donne un adressage
  *    creer un thread pour ecouter les demandes de connection
  * des différents clients
  */
Serveur::Serveur(){
	// Test valable pour Windows uniquement
	#if defined (WIN32)
	    WSADATA WSAData;
	    int erreur = WSAStartup(MAKEWORD(2,2), &WSAData);
	#else
	// Si l'on est sous Linux
	    int erreur = 0;
	#endif


	// Corps du constructeur


	// Jette une NetworkingException si defaillance,
	// sock_sinon, le code continu son execution
	if(erreur) throw NetworkingException(0);
	/* Si les sockets Windows fonctionnent */


	// Initialisation des erreurs de réseau celon
	// mon entete
	NetworkingException::init_err();

	/* Configuration de l'adressage */
	/* Adresse IP automatique */
	sock_sin.sin_addr.s_addr=htonl(INADDR_ANY);
	/* Protocole familial (IP) */
	sock_sin.sin_family=AF_INET;
	/* Listage du port */
	sock_sin.sin_port=htons(PORT);

	// Met en place la socket du serveur
	sock = creer_socket();

	// thread pour prendre les connections et creer des sockets d'ecoutes
	// pour chaque nouvelles connexions
	threads.insert(insertionT("attente_clients", new pthread_t));

	pthread_create(threads.find("attente_clients")->second, nullptr, attente_clients, this);

	// thread pour envoyer les messages
	threads.insert(insertionT("envoi_aux_clients", new pthread_t));

	pthread_create(threads.find("envoi_aux_clients")->second, nullptr, envoi_aux_clients, this);

}


/**
  * Ferme les connexions et les threads lance avant la fermeture
  * du serveur
  * libere la memoire allouer pour les "new thread_t"
  */
Serveur::~Serveur(){

if(bavard)std::cout << "clients :" << std::endl;

	std::map<std::string, int>::iterator ita = csock.begin();
	while(ita !=  csock.end()){
if(bavard)std::cout << "     kicked : " << ita->first << std::endl;
		shutdown(ita->second, 2);
		closesocket(ita->second);
		++ita;
	}
	std::map<std::string, pthread_t*>::iterator itb = threads.begin();
	while(itb != threads.end()){
		pthread_cancel(*(itb->second));
		delete (itb->second);
		++itb;
	}
	closesocket(sock);

	// Nettotage des complexe de Windows
	#if defined (WIN32)
		WSACleanup();
	#endif

}


/**
  * Comme sont nom l'indique, on sort le client du nom
  * @nom
  */
void Serveur::kick(std::string nom){}
