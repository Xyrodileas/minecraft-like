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
	#define INVALID_SOCKET -1
	#define SOCKET_ERROR -1
	// #define de simplification Linux to Windows
	#define closesocket(s) close(s)
#endif


/**
  * Inclusions standard multiplateforme
  */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <chrono>
#include <cstring>
#include <string>
#include <thread>
#include <mutex>


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
  * Inclusion personnelle
  */
#define _Je_serai_inclus_
#include "NetworkingException.hpp"
#include "reseau.hpp"


/**
  * Permet de changer le port plus facilement
  * que dans le code.
  */
#define PORT 6685


/**
  * Active ou desactive les messages de debuggage
  */
bool bavard(false);


/**
  * Namespace client
  */
namespace ccli{
	std::mutex ms;
}

/**
  * Recupere les messages et les envoie au serveur
  */
void * envoi(void* arg){

	// Pointeur sur this
	Client * cli = (Client*)arg;

	int bufferI;

	while(1){
		// On verifie qu'il y a bien un message
		if(cli->messages_envoi.begin() != cli->messages_envoi.end()){
if(bavard)std::cout << "parcourt des messages a envoyer au serveur\n";
			// le +1 correspond au caractere de fin \0
			char bufferS[cli->messages_envoi.front().size()+1];
			strcpy(bufferS, cli->messages_envoi.front().c_str());
			bufferI = strlen(bufferS)+1;
			try{
				// On envoie la taille du buffer
				if((send(cli->sock, &bufferI, sizeof(bufferI), 0)) == -1)
					throw NetworkingException(105);
if(bavard)std::cout << "envoi de la taille de la chaine qui suivra de " << bufferI << " a la socket : " << cli->sock << std::endl;
				// puis le buffer
				if((send(cli->sock, bufferS, bufferI, 0)) == -1)
					throw NetworkingException(106);
if(bavard)std::cout << "Chaine \"" << bufferS << "\" envoye avec succes\n";
				// on supprime avec blocage pour etre sur de la
				// la suppression sans erreur
if(bavard)std::cout << "lock pour suppression de la chaine envoye\n";
				ccli::ms.lock();
				cli->messages_envoi.erase(cli->messages_envoi.begin());
				ccli::ms.unlock();
if(bavard)std::cout << "chaine envoye supprime\n";
			}catch(NetworkingException e){
				e.displaySortieStandard2();
			}
		}
		
	}

	return nullptr;
}

/**
  * Recupere les messages du serveur et les rend diponible 
  * par le client
  */
void* recu(void * arg){

	// Pointeur sur this
	Client * cli = (Client*)arg;

	// Iterateurs sur les messages a prendre comptant
	std::vector<std::string>::iterator go = cli->messages_recu.begin();

	int bufferI = sizeof(bufferI);
	
	while(1){
		while((recv(cli->sock, &bufferI, bufferI, 0)) != -1){
if(bavard)std::cout << "reception de la taille du buffer de " << bufferI << std::endl;
			// Si bien recu les donnees
			// on les traite
			char bufferS[bufferI];
			if((recv(cli->sock, &bufferS, bufferI, 0)) == -1)
				throw NetworkingException(108);
if(bavard)std::cout << "reception du buffer sur le client : " << cli->getNom() << std::endl;
				std::string tmp(bufferS);
				cli->messages_recu.push_back(bufferS);
if(bavard)std::cout << bufferS << " recu et mis dans la file d'attende de traitement par le client\n";
			// Sinon, les donnees ne seront pas renvoye,
			// c'est perdu
		}
	}

	return nullptr;
}

/**
  * Constructeur,
  *     Se connecte au serveur et attend des
  * messages dans un thread
  */
Client::Client(std::string nom): nom(nom){

	// Test valable pour Windows uniquement
	#if defined (WIN32)
	    WSADATA WSAData;
	    int erreur = WSAStartup(MAKEWORD(2,2), &WSAData);
	#else
		// Si l'on est sous Linux
		int erreur = 0;
	#endif

	// Corp du Main

	// Sockets et adressage
	sockaddr_in sin;
	// Buffer de reception
	std::string buffer;

	try{
		/* Si les sockets Windows fonctionnent */
		if(erreur)
			throw NetworkingException(100);


		/* Création de la socket */
		if((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1 )
			throw NetworkingException(101);

		/* Configuration de la connexion */
		sin.sin_addr.s_addr = inet_addr("127.0.0.1");
		sin.sin_family = AF_INET;
		sin.sin_port = htons(PORT);
if(bavard)std::cout << "socket client en place\n";
		/* Si l'on a réussi à se connecter */
		if(connect(sock, (sockaddr*)&sin, sizeof(sin)) == -1)
			throw NetworkingException(102);
if(bavard)std::cout << "connect() OK\n";
if(bavard)printf("Client\nConnection à %s sur le port %d\n", inet_ntoa(sin.sin_addr), htons(sin.sin_port));

		char bufferS[nom.size()+1];
		strcpy(bufferS, nom.c_str());
		int bufferI = strlen(bufferS);

		try{
if(bavard)std::cout << "envoi de la taille de notre nom de " << sizeof(nom) << std::endl;
			if((send(sock, &bufferI, sizeof(bufferI), 0)) == -1)
				throw NetworkingException(105);
if(bavard)std::cout << "envoi du nom " << nom << std::endl;
			if((send(sock, bufferS, bufferI, 0)) == -1)
				throw NetworkingException(106);
if(bavard)std::cout << "je " << nom << " suis officiellement accepte par le serveur\n";
		}catch(NetworkingException e){
			e.displaySortieStandard2();
		}
		// Thread etant un tableau, c'est bien une adresse
		// qui est ici envoye
if(bavard)std::cout << "creation du thread d'ecoute du serveur\n";
		pthread_create(threads, nullptr, envoi, this);
		// thread+1 correspond a l'adresse de thread[0]
		// plus un sizeof(pthread_t)
if(bavard)std::cout << "creation du thread d'envoi de messages vers le serveur\n";
		pthread_create(threads+1, nullptr, recu, this);
if(bavard)std::cout << "socket vers serveur : " << sock << std::endl;

	}catch(NetworkingException ex){
		ex.displaySortieStandard2();
	}		
}


/**
  * ne pas croire que envoyer() envoi sur le reseau,
  * cela se fait avec des fonctions prive
  * envoi met votre message sur une liste d'attente pour etre
  * envoye
  */
void Client::envoyer(std::string mess){
	messages_envoi.push_back(mess);
if(bavard)std::cout << "mise en attente d'un message client sur la file d'attente client\n";
}


/**
  * La reception est la recuperation des dernieres donne recu
  * et mise dans un file par autres clients
  */
std::string Client::recevoir(){ 

	std::string copie="";

	//S'il y a bien un message
	if(messages_recu.begin() != messages_recu.end()){
		// On le recupere
		copie = *(messages_recu.begin());
		// puis on le supprime
if(bavard)std::cout << "Message :\n" << copie << "\ncopie avant suppression\n";
		messages_recu.erase(messages_recu.begin());

if(bavard)std::cout << "Message client de la file d'attente supprime\n";
	}
	// Sinon, on renvoie une chaine reste vide
			
	return copie;
}


/**
  * Destructeur classique
  */
Client::~Client(){

	// Suppression des thread
	pthread_cancel(*threads);
	pthread_cancel(*(threads+1));

	// fermeture du socket
	shutdown(sock, 2);
	closesocket(sock);

}
