/*
 * Joueur.cpp
 *
 *  Créé le : 2013-1-08
 *  Auteur: Alexis Vuillaume
 */

#include "Joueur.h"
#define COEF_FRAMERATE 0.0001

Joueur::Joueur(float x, float y, float z, bool god)  ///\brief Créé un joueur (local)
{

	// Initialisation de la caméra à la position (x, y, z)
	positionPlayer = sf::Vector3f(x, y, z);
	positionCamera = sf::Vector3f(0,0,0);
	this->positionPlayer.x = x;
	this->positionPlayer.y = y;
	this->positionPlayer.z= z;
	this->godmod = god;
}

Joueur::~Joueur() {
}
void Joueur::avancer(float anglex, float angley, float Framerate) ///\brief Permet d'avancer le joueur 
{
		
	    positionPlayer.x = positionPlayer.x+5*cos(angley*M_PI/180.f)*cos(anglex*M_PI/180.f)*Framerate*COEF_FRAMERATE;
	    positionPlayer.y = positionPlayer.y+5*cos(angley*M_PI/180.f)*sin(anglex*M_PI/180.f)*Framerate*COEF_FRAMERATE;
	    if(this->godmod)
	    	positionPlayer.z=positionPlayer.z+5*sin(angley*M_PI/180.f)*Framerate*COEF_FRAMERATE;
}
void Joueur::reculer(float anglex, float angley, float Framerate) ///\brief Permet de reculer le joueur 
{
		positionPlayer.x = positionPlayer.x-5*cos(angley*M_PI/180.f)*cos(anglex*M_PI/180.f)*Framerate*COEF_FRAMERATE;
	    positionPlayer.y = positionPlayer.y-5*cos(angley*M_PI/180)*sin(anglex*M_PI/180)*Framerate*COEF_FRAMERATE;
	    if(this->godmod)
	    	positionPlayer.z=positionPlayer.z-5*sin(angley*M_PI/180.f)*Framerate*COEF_FRAMERATE;
}

void Joueur::gauche(float anglex, float angley, float Framerate) ///\brief Permet de déplacer vers la gauche le joueur 
{
		positionPlayer.x = positionPlayer.x-5*cos(angley*M_PI/180)*sin(anglex*M_PI/180)*Framerate*COEF_FRAMERATE;
	    positionPlayer.y = positionPlayer.y+5*cos(angley*M_PI/180.f)*cos(anglex*M_PI/180.f)*Framerate*COEF_FRAMERATE;


}
void Joueur::droite(float anglex, float angley, float Framerate) ///\brief Permet de déplacer vers la droite le joueur
{
		positionPlayer.x = positionPlayer.x+5*cos(angley*M_PI/180)*sin(anglex*M_PI/180)*Framerate*COEF_FRAMERATE;
	    positionPlayer.y = positionPlayer.y-(5*cos(angley*M_PI/180.f)*cos(anglex*M_PI/180.f))*Framerate*COEF_FRAMERATE;
}

float Joueur::getPosx() {
	return positionPlayer.x;
}
float Joueur::getPosy() {
	return positionPlayer.y;
}
float Joueur::getPosz() {
	return positionPlayer.z;
}
void Joueur::setPosz(float z) {
	positionPlayer.z = z;
}

void Joueur::maj(float anglex, float angley) ///\brief met à jour la position du regard (caméra)
{

	positionCamera.x=positionPlayer.x+35*cos(angley*M_PI/180.f)*cos(anglex*M_PI/180.f); 	// Calcul de la position du point à regarder en x
	positionCamera.y=positionPlayer.y+35*cos(angley*M_PI/180.f)*sin(anglex*M_PI/180.f); 	// Calcul de la position du point à regarder en y
	positionCamera.z=positionPlayer.z+35*sin(angley*M_PI/180.f);							// Calcul de la position du point à regarder en z

	// std::cout << camx << " " << camy << " " << camz << std::endl;
	gluLookAt(positionPlayer.x,positionPlayer.y,positionPlayer.z,positionCamera.x, positionCamera.y, positionCamera.z, 0, 0, 1);

}

float Joueur::getPosCamx(){
	return positionCamera.x;
}
float Joueur::getPosCamy(){
	return positionCamera.y;
}
float Joueur::getPosCamz(){
	return positionCamera.z;
}

