/*
 * Membre.cpp
 *
 *  Créé le : 2013-03-07
 *  Auteur: Jimmy Turgeon
 */

#include "Membre.h"

Membre::Membre(int x, int y, int z, int largeur, int longueur, int hauteur, int rouge, int vert, int bleu): avant(0), arriere(0), dessous(0), dessus(0), gauche(0), droite(0)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->largeur = largeur;
	this->longueur = longueur;
	this->hauteur = hauteur;
	this->rouge = rouge;
	this->vert = vert;
	this->bleu = bleu;

	initialiser_membre();
}

void Membre::initialiser_membre()
{
	//Points avants
	Point point(x,y,z);
	Point point2(x,y,hauteur-z);
	Point point3(largeur+x,y,hauteur-z);
	Point point4(largeur+x,y,z);

	//Points arrières
	Point point5(x,longueur+y,z);
	Point point6(largeur+x,longueur+y, z);
	Point point7(largeur+x,longueur+y,hauteur-z);
	Point point8(x,longueur+y,hauteur-z);

	this->avant = new Face(point, point2, point3, point4, rouge, vert, bleu);

	this->gauche = new Face(point, point2, point6, point5, rouge, vert, bleu);

	this->dessus = new Face(point, point5, point6, point7, rouge, vert, bleu);

	this->arriere = new Face(point5, point6, point7, point8, rouge, vert, bleu);

	this->dessous = new Face(point4, point8, point7, point3, rouge, vert, bleu);

	this->droite = new Face(point2, point3, point7, point6, rouge, vert, bleu);
}

void Membre::construire_membre()
{
    avant->construire_face();
    gauche->construire_face();
    dessous->construire_face();
    arriere->construire_face();
    dessus->construire_face();
    droite->construire_face();
}

int Membre::getX()
{
    return this->x;
}

int Membre::getY()
{
    return this->y;
}

int Membre::getZ()
{
    return this->z;
}


Membre::~Membre() {
}
