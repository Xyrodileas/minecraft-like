/*
 * Face.cpp
 *
 *  Créé le : 2013-02-25
 *  Auteur: Jimmy Turgeon
 */

#include "Face.h"

Face::Face(Point un, Point deux, Point trois, Point quatre, int rouge, int vert, int bleu):point(un), point2(deux), point3(trois), point4(quatre)
{
	this->rouge = rouge;
	this->vert = vert;
	this->bleu = bleu;
}

void Face::construire_face()///\ Permet de construire une face
{
	glBegin(GL_QUADS);

		//Affiche le carré de la bonne couleur
		glColor3ub(this->rouge,this->vert,this->bleu);

		glTexCoord2f(0.0f, 0.0f); glVertex3f(point.getX(), point.getY(), point.getZ());
		glTexCoord2f(64.0f, 0.0f); glVertex3f(point2.getX(), point2.getY(), point2.getZ());
		glTexCoord2f(64.0f, 64.0f); glVertex3f(point3.getX(), point3.getY(), point3.getZ());
		glTexCoord2f(64.0f, 0.0f); glVertex3f(point4.getX(), point4.getY(), point4.getZ());
	glEnd();

	glBegin(GL_LINE_LOOP);

		//Affiche un contour noir
		glColor3ub(0,0,0);

		glVertex3f(point.getX(), point.getY(), point.getZ());
		glVertex3f(point2.getX(), point2.getY(), point2.getZ());
		glVertex3f(point3.getX(), point3.getY(), point3.getZ());
		glVertex3f(point4.getX(), point4.getY(), point4.getZ());
	glEnd();
}

Face::~Face() {
}
