/*
 * Ecran.cpp
 *
 *  Créé le : 2013-02-08
 *  Auteur: Alexis Vuillaume
 */

#include "Ecran.h"
#include <SFML/Window.hpp>
#include <GL/gl.h>
#include <GL/glu.h>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <cstdio>

Ecran::Ecran(int haut, int larg, char* nom) {
	this->haut = haut;
	this->larg = larg;
	this->nom = nom;
}

Ecran::~Ecran() {
}

void dessiner() {
	sf::RenderWindow App(sf::VideoMode(larg, haut, 32), nom);
	sf::Clock Clock;

	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	gluPerspective(70,(double)640/480,1,10000);
	glEnable(GL_DEPTH_TEST);

	glClearDepth(1.f);
    glClearColor(0.f, 0.f, 0.f, 0.f);
}
