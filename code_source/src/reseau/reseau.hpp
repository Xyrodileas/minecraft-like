/**
  * Créé par Cédric Outreville
  * Le but de cette classe est donner la possibilite
  * a mes partenaires de projets de creer un serveur
  * et des clients qui communiquent presque tout seuls
  *
  * langage::=C++
  */

#ifndef _RESEAU_CEDRIC
#define _RESEAU_CEDRIC

/**
  * Include standard
  */
#include <iostream>
#include <map>
#include <vector>

/**
  * raccourci permettant de simplifier l'insertion
  * de nouvelles erreurs dans map
  */

// typedef des sock
typedef std::pair<std::string, int> insertionI;
// typedef des threads
typedef std::pair<std::string, pthread_t*> insertionT;
// typedef pour les messages
typedef std::pair<int, std::string> insertionS;


/**
  * Include personnels
  */
#include "NetworkingException.hpp"

/**
  * La classe serveur gere beaucoup de choses toute seule.
  * Se limiter aux fonction publique pour usage.
  */
class Serveur{
private:

	// variables prives

	// socket serveur
	int sock;
	// sockets clients
	std::map<std::string, int> csock;
	// threads pour la mise en parrallele de taches
	std::map<std::string, pthread_t*> threads;
	// pile des messages a envoyer
	std::map<int, std::string> messages;

	// fonctions prives

	// initialise le socket serveur
	int creer_socket();
	// accept un nouveau client et retourne le socket cree
	void connexion(int);

	// Fonctions utilises dans des threads
	// effectue un echange avec le client passe en parametre
	void echange_client(int, std::string);
	// Ajoute un client
	friend void* attente_clients(void*);

	struct Ecoute{
		Serveur * serv;
		int csock;
		Ecoute(Serveur* s, int c): serv(s), csock(c){} 
	};

	friend void* ecoute_client(void*);
	friend void* envoi_aux_clients(void*);
public:
	// Constructeur unique
	Serveur();

	// traitement des clients

	void kick(std::string);
	/**
	  * Utilise seulement pour le debuggage
	  */
	void clients(){
		std::map<std::string, int>::iterator it = csock.begin();
		while(it != csock.end()){
			printf("Cli : %s:%d\n", it->first.c_str(), it->second);
			++it;
		}
	}
	void threadss(){
		std::map<std::string, pthread_t*>::iterator it = threads.begin();
		while(it != threads.end()){
			printf("threads : %s\n", it->first.c_str());
			++it;
		}
	}
	void messagess(){
		std::map<int, std::string>::iterator it = messages.begin();
		while(it != messages.end()){
			printf("messages de %d : %s\n", it->first, it->second.c_str());
			++it;
		}
	}

	~Serveur();
};


// nombre de client maximum
#define nb_sock 10


/**
  * La classe cliente est beaucoup plus simple puisqu'elle
  * se connecte, envoie et recoit des informations de deux
  * type possible et c'est tout !
  */
class Client{
private:
	// Nom du client (peut etre le pseudo du joueur)
	std::string nom;
	// lien vers le serveur
	int sock;
	// thread des messages
	pthread_t threads[2];
	// liste des messages
	std::vector<std::string> messages_recu;
	std::vector<std::string> messages_envoi;

	// fonctions prives

	// fonction qui envoi les messages au serveur
	friend void* envoi(void*);
	// fonction qui recoit les messages du serveur
	friend void* recu(void*);
public:
	Client(std::string);

	// envoyer() et recevoir ne sont que des getters et setters des messages
	void envoyer(std::string);
	std::string recevoir();

	// getter et setter du nom
	std::string getNom(){ return nom; }

	// pour debuggage
	void boite_envoi(){
		std::vector<std::string>::iterator it = messages_envoi.begin();
		printf("__________________\n");
		while(it != messages_envoi.end())
			std::cout << *it << std::endl;
		printf("__________________\n");
	}
	void boite_reception(){
		std::vector<std::string>::iterator it =messages_recu.begin();
		printf("__________________\n");
		while(it != messages_recu.end())
			std::cout << *it << std::endl;
		printf("__________________\n");
	}

	void quitter();
	~Client();
};


#endif
