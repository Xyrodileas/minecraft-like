/*
 * Joueur.h
 *
 *  Créé le : 2013-02-18
 *  Auteur: Alexis Vuillaume
 */

#ifndef JOUEUR_H
#define JOUEUR_H

#include <SFML/Window.hpp>
#include <GL/gl.h>
#include <GL/glu.h>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <cstdio>
#include <iostream>



class Joueur {
public:
	Joueur(float, float, float, bool);
	virtual ~Joueur();
	void avancer(float, float, float);
	void reculer(float, float, float);
	void gauche(float, float, float);
	void droite(float, float, float);
	void maj(float, float);
	float getPosx();
	float getPosy();
	float getPosz();
	float getPosCamx();
	float getPosCamy();
	float getPosCamz();
	void setPosz(float);

protected:
	sf::Vector3f positionPlayer;

	sf::Vector3f positionCamera;

	bool godmod;


};

#endif /* JOUEUR_H */