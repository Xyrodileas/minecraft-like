/*
 * Player.h
 *
 *  Créé le : 2013-02-18
 *  Auteur: Alexis Vuillaume
 */

#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Window.hpp>
#include <GL/gl.h>
#include <GL/glu.h>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <cstdio>
#include <iostream>


class Player {
public:
	Player(float, float, float, bool);
	virtual ~Player();
	void avancer(float, float, float);
	void reculer(float, float, float);
	void gauche(float, float, float);
	void droite(float, float, float);
	void maj(float, float);
	float getPosx();
	float getPosy();
	float getPosz();
	void setPosz(float);

private:
	float posx;
	float posy;
	float posz;
	float camx;
	float camy;
	float camz;
	bool godmod;


};

#endif /* Player_H */