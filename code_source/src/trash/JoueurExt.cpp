/*
 * JoueurExt.cpp
 *
 *  Créé le : 2013-02-25
 *  Auteur: Jimmy Turgeon
 */

#include "JoueurExt.h"

JoueurExt::JoueurExt(float x, float y, float z, bool god, char** pseudo)
{
	this->pseudo = pseudo;

}


JoueurExt::~JoueurExt() {
}

Point JoueurExt::getPosRegard()
{
	return this->position;
}

Point JoueurExt::getPosJoueur()
{
	return this->getPosJoueur();
}

void JoueurExt::DrawJoueur() {

	glBegin(GL_POLYGON);
 
		glVertex3f( -35 + this.posx, -35 + this.posy, -35 + this.posz);  
		glVertex3f( -35+ this.posx,  35+ this.posy, -35+ this.posz);  
		glVertex3f(  35+ this.posx,  35+ this.posy, -35+ this.posz); 
		glVertex3f(  35+ this.posx, -35+ this.posy, -35+ this.posz);  
 
	glEnd();
}

void JoueurExt::setPosRegard(Point point)
{
	this->position = point;
}

void JoueurExt::setPosJoueur(int x, int y, int z)
{
	
	this->posz = z;
	this->posx = x;
	this->posy = y;

}


