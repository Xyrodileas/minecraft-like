/*
 * Controles.h
 *
 *  Créé le : 2013-02-18
 *  Auteur: Alexis Vuillaume
 */

#ifndef CONTROLES_H
#define CONTROLES_H

#include <SFML/Window.hpp>
#include <GL/gl.h>
#include <GL/glu.h>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <cstdio>
#include <stdio.h>
#include <signal.h>
#include <iostream>
#include "Joueur.h"
#include "../plateau/Plateau.h"

class Controles {
public:
	Controles(int);
	void Check(sf::RenderWindow *window);
	void Action(Joueur&, Plateau&, float);
	float getAnglex();
	float getAngley();
	void Sauter(Joueur&, Plateau&);

	virtual ~Controles();

	float anglex;
	float angley;

	
private:
		bool azerty;
	    bool DownKeyDown;
	    bool RightKeyDown;
	    bool UpKeyDown;
	    bool LeftKeyDown;
	   	bool ZKeyDown;
	   	bool AKeyDown;
	    bool SKeyDown;
	    bool QKeyDown;
	    bool DKeyDown;
	    bool WKeyDown;
	   	bool PlusKeyDown;
	    bool MoinKeyDown;
	    bool SpaceKeyDown;
	    bool clicdroit;
	    bool clicgauche;
	    float MouseX;
		float MouseY;

		float saut;



};

#endif /* CONTROLES_H */