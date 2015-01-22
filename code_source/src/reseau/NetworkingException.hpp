#ifndef _NetworkingException_
#define _NetworkingException_

#include <map>
#include <iostream>

/**
  * raccourci permettant de simplifier l'insertion
  * de nouvelles erreurs dans map
  */ 
typedef std::pair<int, std::string> insertion;

/**
  * Cette classe permet de gérer des exeptions.
  * Specialise dans les erreurs de reseau, elle peut aussi
  * etre utilise pour n'importe quel type d'erreur.
  */
class NetworkingException{
private:
	// Stockage de toutes les erreurs
	static std::map<unsigned int, std::string> id_err;
	// Boolean pour empecher plusieurs initialisation
	static bool init;

	// Id pour la map
	unsigned int id;
	std::string cause;

	bool isset(bool);
	// ajoute une nouvelle erreur dans la map
	void add(int ex, std::string m){
		if(id_err.find(ex)==id_err.end())
			id_err.insert(insertion(ex,m));
	}
public:
	// Initialise toutes les erreurs definit par cette entête
	static void init_err();

	// Constructeurs
	NetworkingException(): id(2147483646){}
	NetworkingException(unsigned int ex): id(ex){
		if(id_err.find(ex) == id_err.end()) id = 2147483646; }
	NetworkingException(unsigned int ex, std::string c): id(ex), cause(c){
		if(id_err.find(ex) == id_err.end()) id = 2147483646; }
	NetworkingException(unsigned int ex, std::string m, std::string c): id(ex), cause(c){ add(ex,m); }
	NetworkingException(std::string m): id(2147483646), cause(m){}

	// Getters
	std::string getMessage(){ return id_err.find(id)->second; }
	std::string get_cause(){ return cause; }

	// Afficher de facon automatique
	void displaySortieStandard2();
};


/**
  * param un_ou_deux vaux vrai si l'on cherche isset message
  * 	et vaux faux si l'on veux isset cause
  * return vrai si le string du parametre demande est renseignee
  */
inline bool NetworkingException::isset(bool un_ou_deux){
	// si l'on veut le message et qu'il est renseigne, vrai
	// sinon, faux
	if(id_err.find(id) == id_err.end()) return false;
	if(un_ou_deux && id_err.find(id)->second != "NULL")
		return true;
	else
		return false;
	// si l'on veut la cause et qu'elle est renseigné, vrai
	// sinon, faux
	if(!un_ou_deux && cause != "NULL")
		return true;
	else
		return false;
}


/**
  * Affichage sur la sortie standard avec cout
  */
inline void NetworkingException::displaySortieStandard2(){
	if(isset(true))
		std::cout <<"\n\n Message d'erreur :" << std::endl << id_err.find(id)->second << std::endl;
	if(isset(false))
		std::cout << "Cause de l'erreur :" << cause << std::endl;
}


/**
  * Evite la definition multiple dans les compilations separes
  */
#ifndef _Je_serai_inclus_
/**
  * Initialisation des variables static
  */
std::map<unsigned int, std::string> NetworkingException::id_err;
bool NetworkingException::init = false;

/**
  * Si _Je_serai_inclus_ est definie alors
  * les variables seront importe au moment
  * du linkage
  */
#endif

/**
  * Initialise les erreurs en fonction d'un identifiant
  * Identifiants entre 0 et 99 (inclus) ==> le serveur parle
  * Identifiants superieurs a 99 ==> le client parle
  */
inline void NetworkingException::init_err(){

	// une initialisation suffit
	if(init) return;
	else init=true;

	// Erreur par defaut
	id_err.insert(insertion(2147483646,"Initialise mieu t'es erreurs !"));

	// Erreurs serveur
	id_err.insert(insertion(0,"Windows, Windows ... \nerreur non pas a 0 (serveur)"));
	id_err.insert(insertion(1,"socket() crashed (serveur)\n"));
	id_err.insert(insertion(2,"bind() crashed (serveur)\n"));
	id_err.insert(insertion(3,"listen() crashed (serveur)\n"));
	id_err.insert(insertion(4,"Envoie de donnees echoue"));
	id_err.insert(insertion(5,"accept() crashed (serveur)"));
	id_err.insert(insertion(6,"reception crashed (serveur)"));
	id_err.insert(insertion(7,"reception bufferI crashed (serveur)"));
	id_err.insert(insertion(8,"reception bufferS crashed (serveur)"));
	id_err.insert(insertion(9,"l'id de thread existe deja (serveur)"));
	id_err.insert(insertion(10,"Nom de client deja existant (serveur)"));

	// Erreurs client
	id_err.insert(insertion(100,"Windows, Windows ... \nerreur non pas a 0 (client)"));
	id_err.insert(insertion(101,"socket() crashed (client)\n"));
	id_err.insert(insertion(102,"connect() crashed (client)\n"));
	id_err.insert(insertion(103,"reception crashed (client)\n"));
	id_err.insert(insertion(104,"send crashed (client)\n"));
	id_err.insert(insertion(105,"send bufferI crashed(client)\n"));
	id_err.insert(insertion(106,"send bufferS crashed (client)\n"));
	id_err.insert(insertion(107,"reception bufferI crashed (client)\n"));
	id_err.insert(insertion(108,"reception bufferS crashed (client)\n"));
}

#endif
