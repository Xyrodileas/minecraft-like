/*
 * Camera.cpp
 *
 *  Créé le : 2013-02-08
 *  Auteur: Alexis Vuillaume
 */

#include "Camera.h"


Camera::Camera(float x, float y, float z, bool god) {

	// Initialisation de la caméra à la position (x, y, z)

	this->posx = x;
	this->posy = y;
	this->posz= z;
	this->godmod = god;
}

Camera::~Camera() {
}
void Camera::avancer(float anglex, float angley, float Framerate) {
	
	    posx = posx+5*cos(angley*M_PI/180.f)*cos(anglex*M_PI/180.f)*Framerate*0.2;
	    posy = posy+5*cos(angley*M_PI/180.f)*sin(anglex*M_PI/180.f)*Framerate*0.2;
	    if(this->godmod)
	    	posz=posz+5*sin(angley*M_PI/180.f)*Framerate*0.2;
}
void Camera::reculer(float anglex, float angley, float Framerate) {
		posx = posx-5*cos(angley*M_PI/180.f)*cos(anglex*M_PI/180.f)*Framerate*0.2;
	    posy = posy-5*cos(angley*M_PI/180)*sin(anglex*M_PI/180)*Framerate*0.2;
	    if(this->godmod)
	    	posz=posz-5*sin(angley*M_PI/180.f)*Framerate*0.2;
}

void Camera::gauche(float anglex, float angley, float Framerate) {
		posx = posx-5*cos(angley*M_PI/180)*sin(anglex*M_PI/180)*Framerate*0.2;
	    posy = posy+5*cos(angley*M_PI/180.f)*cos(anglex*M_PI/180.f)*Framerate*0.2;


}
void Camera::droite(float anglex, float angley, float Framerate) {
		posx = posx+5*cos(angley*M_PI/180)*sin(anglex*M_PI/180)*Framerate*0.4;
	    posy = posy-(5*cos(angley*M_PI/180.f)*cos(anglex*M_PI/180.f))*Framerate*0.4;
}

float Camera::getPosx() {
	return this->posx;
}
float Camera::getPosy() {
	return this->posy;
}
float Camera::getPosz() {
	return this->posz;
}
void Camera::setPosz(float z) {
	this->posz = z;
}

void Camera::maj(float anglex, float angley) {

	float camx=posx+5*cos(angley*M_PI/180.f)*cos(anglex*M_PI/180.f); 	// Calcul de la position du point à regarder en x
	float camy=posy+5*cos(angley*M_PI/180.f)*sin(anglex*M_PI/180.f); 	// Calcul de la position du point à regarder en y
	float camz=posz+5*sin(angley*M_PI/180.f);							// Calcul de la position du point à regarder en z
	gluLookAt(posx,posy,posz,camx, camy, camz, 0, 0, 1);
}
