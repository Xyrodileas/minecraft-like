/*
 * Camera.cpp
 *
 *  Créé le : 2013-02-08
 *  Auteur: Alexis Vuillaume
 */

#include "Camera.h"


Camera::Camera(int x, int y, int z) {
	this->posx = x;
	this->posy = y;
	this->posz= z;
}

Camera::~Camera() {
}
void Camera::avancer(float anglex, float angley) {
	    posx = posx+5*cos(angley*M_PI/180.f)*cos(anglex*M_PI/180.f)*Framerate*0.05;
	    posy = posy+5*cos(angley*M_PI/180.f)*sin(anglex*M_PI/180.f)*Framerate*0.05;

}
void Camera::reculer(float anglex, float angley) {
		posx = posx-5*cos(angley*M_PI/180.f)*cos(anglex*M_PI/180.f)*Framerate*0.05;
	    posy = posy-5*cos(angley*M_PI/180)*sin(anglex*M_PI/180)*Framerate*0.05;
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

void Camera::maj(float anglex, float angley) {

	this->camx=posx+5*cos(angley*M_PI/180.f)*cos(anglex*M_PI/180.f); 	// Calcul de la position du point à regarder en x
	this->camy=posy+5*cos(angley*M_PI/180.f)*sin(anglex*M_PI/180.f); 	// Calcul de la position du point à regarder en y
	this->camz=posz+5*sin(angley*M_PI/180.f);						// Calcul de la position du point à regarder en z
	gluLookAt(posx,posy,posz,camx, camy, camz, 0, 0, 1);
}
