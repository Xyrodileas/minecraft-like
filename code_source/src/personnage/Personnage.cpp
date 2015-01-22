/*
 * Personnage.cpp
 *
 *  Créé le : 2013-03-07
 *  Auteur: Jimmy Turgeon
 */

#include "Personnage.h"

Personnage::Personnage(int x, int y, int z, int largeur, int longueur, int hauteur): brasDroit(0), brasGauche(0), tete(0), corps(0), jambeDroite(0), jambeGauche(0)
{
    this->x = x;
    this->y = y;
    this->z = z;

    initialiser_personnage();
}

void Personnage::initialiser_personnage()
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

//	this->brasDroit = new Membre(x, y, z, 10, 20, 40, 0, 0, 0);
//
//	this->brasGauche = new Membre(x, y, z, 30, 20, 40, 0, 0, 0);
//
//	this->tete = new Membre(x, y, z, 30, 20, 40, 0, 0, 0);

	construire_corps();

//	this->jambeDroite = new Membre(x, y, z, 30, 20, 40, 0, 0, 0);
//
//	this->jambeGauche = new Membre(x, y, z, 30, 20, 40, 0, 0, 0);
}

void Personnage::construire_corps()
{
    int largeurCorps = (largeur/100)*60;

    int hauteurCorps = hauteur/2;

    int cx = (this->largeur/2) - (largeurCorps/2);
    int cy = this->longueur - (this->longueur/2);
    int cz = (this->hauteur/7) * 3;

    this->corps = new Membre(cx, cy, cz, largeurCorps, longueur, hauteurCorps, 0, 0, 0);
}

void Personnage::construire_personnage()
{

}

Personnage::~Personnage() {
}
