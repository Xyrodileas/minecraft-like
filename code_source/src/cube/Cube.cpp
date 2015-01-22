/*
 * Cube.cpp
 *
 *  Créé le : 2013-02-08
 *  Auteur: Jimmy Turgeon
 */

#include "Cube.h"

Cube::Cube(int x, int y, int z, float taille, int rouge, int vert, int bleu, bool afficheAvant, bool afficheArriere, bool afficheDessous, bool afficheDessus, bool afficheGauche, bool afficheDroite): avant(0), arriere(0), dessous(0), dessus(0), gauche(0), droite(0)
{ // Permet de construire un Cube
	this->x = x;
	this->y = y;
	this->z = z;
	this->taille = taille;
	this->rouge = rouge;
	this->vert = vert;
	this->bleu = bleu;

	this->afficheAvant = afficheAvant;
	this->afficheArriere = afficheArriere;
	this->afficheDessous = afficheDessous;
	this->afficheDessus = afficheDessus;
	this->afficheGauche = afficheGauche;
	this->afficheDroite = afficheDroite;

	initialiser_cube();
}

void Cube::initialiser_cube() ///\brief Initialise les faces d'un cube
{
	//Points avants
	Point point(0+x,0+y,0+z);
	Point point2(0+x,0+y,taille+z);
	Point point3(taille+x,0+y,taille+z);
	Point point4(taille+x,0+y,0+z);

	//Points arrières
	Point point5(0+x,taille+y,0+z);
	Point point6(0+x,taille+y,taille+z);
	Point point7(taille+x,taille+y,taille+z);
	Point point8(taille+x,taille+y,0+z);

	this->avant = new Face(point, point2, point3, point4, rouge, vert, bleu);

	this->gauche = new Face(point, point2, point6, point5, rouge, vert, bleu);

	this->dessous = new Face(point, point5, point8, point4, rouge, vert, bleu);

	this->arriere = new Face(point5, point6, point7, point8, rouge, vert, bleu);

	this->dessus = new Face(point2, point6, point7, point3, rouge, vert, bleu);

	this->droite = new Face(point4, point3, point7, point8, rouge, vert, bleu);
}

void Cube::construire_cube() ///\brief Permet de construire un cube en affichant uniquement les faces visibles
{ 
	if (this->afficheAvant)
		avant->construire_face();

	if (this->afficheGauche)
		gauche->construire_face();

	if (this->afficheDessous)
		dessous->construire_face();

	if (this->afficheArriere)
		arriere->construire_face();

	if (this->afficheDessus)
		dessus->construire_face();

	if (this->afficheDroite)
		droite->construire_face();
}

void Cube::afficher_avant(bool afficheAvant)
{
	this->afficheAvant = afficheAvant;
}

void Cube::afficher_arriere(bool afficheArriere)
{
	this->afficheArriere = afficheArriere;
}

void Cube::afficher_dessous(bool afficheDessous)
{
	this->afficheDessous = afficheDessous;
}

void Cube::afficher_dessus(bool afficheDessus)
{
	this->afficheDessus = afficheDessus;
}

void Cube::afficher_gauche(bool afficheGauche)
{
	this->afficheGauche = afficheGauche;
}

void Cube::afficher_droite(bool afficheDroite)
{
	this->afficheDroite = afficheDroite;
}

int Cube::getX()
{
    return this->x;
}

int Cube::getY()
{
    return this->y;
}

int Cube::getZ()
{
    return this->z;
}

int Cube::getTaille()
{
    return this->taille;
}

int Cube::getRouge()
{
    return this->rouge;
}

int Cube::getVert()
{
    return this->vert;
}

int Cube::getBleu()
{
    return this->bleu;
}

Cube::~Cube() {
}
