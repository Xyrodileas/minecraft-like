/*
 * JoueurExt.cpp
 *
 *  Créé le : 2013-02-25
 *  Auteur: Alexis Vuillaume
 */

#include "JoueurExt.h"

JoueurExt::JoueurExt(float x, float y, float z, bool god, char** pseudo) : Joueur(x,y,z,god)
{
	this->pseudo = pseudo;

}


JoueurExt::~JoueurExt() {
}



void JoueurExt::DrawJoueur() {

	  glBegin(GL_QUADS);        // Draw The Cube Using quads
    glColor3f(0.0f,1.0f,0.0f);    // Color Blue
    glVertex3f( 30 + posx, 30 + posy,-30 + posz);    // Top Right Of The Quad (Top)
    glVertex3f(-30 + posx, 30 + posy,-30 + posz);    // Top Left Of The Quad (Top)
    glVertex3f(-30 + posx, 30 + posy, 30 + posz);    // Bottom Left Of The Quad (Top)
    glVertex3f( 30 + posx, 30 + posy, 30 + posz);    // Bottom Right Of The Quad (Top)
    glColor3f(1.0f,30.0f,0.0f);    // Color Orange
    glVertex3f( 30 + posx,-30 + posy, 30 + posz);    // Top Right Of The Quad (Bottom)
    glVertex3f(-30 + posx,-30 + posy, 30 + posz);    // Top Left Of The Quad (Bottom)
    glVertex3f(-30 + posx,-30 + posy,-30 + posz);    // Bottom Left Of The Quad (Bottom)
    glVertex3f( 30 + posx,-30 + posy,-30 + posz);    // Bottom Right Of The Quad (Bottom)
    glColor3f(1.0f,0.0f,0.0f);    // Color Red    
    glVertex3f( 30 + posx, 30 + posy, 30 + posz);    // Top Right Of The Quad (Front)
    glVertex3f(-30 + posx, 30 + posy, 30 + posz);    // Top Left Of The Quad (Front)
    glVertex3f(-30 + posx,-30 + posy, 30 + posz);    // Bottom Left Of The Quad (Front)
    glVertex3f( 30 + posx,-30 + posy, 30 + posz);    // Bottom Right Of The Quad (Front)
    glColor3f(1.0f,1.0f,0.0f);    // Color Yellow
    glVertex3f( 30 + posx,-30 + posy,-30 + posz);    // Top Right Of The Quad (Back)
    glVertex3f(-30 + posx,-30 + posy,-30 + posz);    // Top Left Of The Quad (Back)
    glVertex3f(-30 + posx, 30 + posy,-30 + posz);    // Bottom Left Of The Quad (Back)
    glVertex3f( 30 + posx, 30 + posy,-30 + posz);    // Bottom Right Of The Quad (Back)
    glColor3f(0.0f,0.0f,1.0f);    // Color Blue
    glVertex3f(-30 + posx, 30 + posy, 30 + posz);    // Top Right Of The Quad (Left)
    glVertex3f(-30 + posx, 30 + posy,-30 + posz);    // Top Left Of The Quad (Left)
    glVertex3f(-30 + posx,-30 + posy,-30 + posz);    // Bottom Left Of The Quad (Left)
    glVertex3f(-30 + posx,-30 + posy, 30 + posz);    // Bottom Right Of The Quad (Left)
    glColor3f(1.0f,0.0f,1.0f);    // Color Violet
    glVertex3f( 30 + posx, 30 + posy,-30 + posz);    // Top Right Of The Quad (Right)
    glVertex3f( 30 + posx, 30 + posy, 30 + posz);    // Top Left Of The Quad (Right)
    glVertex3f( 30 + posx,-30 + posy, 30 + posz);    // Bottom Left Of The Quad (Right)
    glVertex3f( 30 + posx,-30 + posy,-30 + posz);    // Bottom Right Of The Quad (Right)
  glEnd();            // End Drawing The Cube
glFlush();
}

void JoueurExt::setPosRegard(int x, int y, int z)
{
	this->camx = x;
	this->camy = y;
	this->camz= z;
}
void JoueurExt::setPosJoueur(int x, int y, int z)
{
	
	this->posz = z;
	this->posx = x;
	this->posy = y;

}
float JoueurExt::getPosRegardx() {
	return this->camx;
}
float JoueurExt::getPosRegardy() {
	return this->camy;
}
float JoueurExt::getPosRegardz() {
	return this->camz;
}


