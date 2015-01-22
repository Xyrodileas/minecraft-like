/*
 * Camera.h
 *
 *  Créé le : 2013-02-18
 *  Auteur: Alexis Vuillaume
 */

#ifndef CAMERA_H
#define CAMERA_H

#include <SFML/Window.hpp>
#include <GL/gl.h>
#include <GL/glu.h>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <cstdio>

class Camera {
public:
	Camera(int, int, int);
	virtual ~Camera();
	void avancer(float, float);
	void reculer(float, float);
	void maj(float, float);
	float getPosx();
	float getPosy();
	float getPosz();
private:
	float posx;
	float posy;
	float posz;
	float camx;
	float camy;
	float camz;


};

#endif /* Camera_H */