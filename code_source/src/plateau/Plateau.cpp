/*
 * Plateau.cpp
 *
 *  Créé le : 2013-02-18
 *  Auteur: Jimmy Turgeon
 */

#include "Plateau.h"
#include <iostream>
#include <stdexcept>

using namespace std;

Plateau::Plateau(int largeur, int longueur, int hauteur, float tailleCube)
{
	this->largeur = largeur;
	this->longueur = longueur;
	this->hauteur = hauteur;
	this->tailleCube = tailleCube;

	initialiser_plateau();
}

Plateau::~Plateau() {
}

void Plateau::initialiser_plateau() ///\brief Permet de remplir le plateau de cube avec les paramètres donné dans le constructeur
{
    plateau = new map<int, Cube*> ** [largeur];

	for (int x = 0; x < largeur; x++)
	{
	    plateau[x] = new map<int, Cube*> * [longueur];

		for (int y = 0; y < longueur; y++)
		{
		    plateau[x][y] = new map<int, Cube*>();

			for (int z = 0; z < hauteur; z++)
			{
			    bool gauche = false;
			    bool droite = false;
			    bool avant = false;
			    bool arriere = false;

			    if (x == 0)
                    gauche = true;

                if (y == 0)
                    avant = true;

                if (x == largeur-1)
                    droite = true;

                if (y == longueur-1)
                    arriere = true;

                if (z <= hauteur-5)
                    plateau[x][y]->insert(make_pair(z, new CubePierre(tailleCube*x,tailleCube*y,tailleCube*z, tailleCube, avant, arriere, false, false, gauche, droite)));
                else if (z <= hauteur-2)
                    plateau[x][y]->insert(make_pair(z, new CubeTerre(tailleCube*x,tailleCube*y,tailleCube*z, tailleCube, avant, arriere, false, false, gauche, droite)));
                else if (z <= hauteur-1)
                    plateau[x][y]->insert(make_pair(z, new CubePelouse(tailleCube*x,tailleCube*y,tailleCube*z, tailleCube, avant, arriere, false, true, gauche, droite)));

			}
		}
	}
}

void Plateau::afficher_plateau() ///\brief permet d'afficher le plateau avec opengl
{
    for (int x = 0; x < largeur; x++)
	{
		for (int y = 0; y < longueur; y++)
		{
			for (map<int,Cube*>::iterator it = plateau[x][y]->begin(); it != plateau[x][y]->end(); it++)
            {
                it->second->construire_cube();
            }
		}
	}
}

void Plateau::verifier_integrite_cubes() ///\brief Vérifie l'intégrité du plateau (méthode de test)
{
    for (int x = 0; x < largeur; x++)
	{
		for (int y = 0; y < longueur; y++)
		{
			for (map<int,Cube*>::iterator it = plateau[x][y]->begin(); it != plateau[x][y]->end(); it++)
            {
                Cube * cube = it->second;

                cout << "Coordonnées : " << cube->getX() << ";" << cube->getY() << ";" << cube->getZ() << endl << "Couleur : " << cube->getRouge() << ";" << cube->getVert() << ";" << cube->getBleu() << endl;

                cube = NULL;
            }
		}
	}
}

void Plateau::supprimer_cube(int x, int y, int z) ///\brief Permet de supprimer un cube de la map
{
	if (x <= largeur && x >= 0 && y <= longueur && y >= 0 && z < hauteur && z >= 0)
	{
		plateau[x][y]->erase(z);

		activerFacesVoisines(x, y, z);
	}
}

void Plateau::ajouter_cube(int x, int y, int z) ///\brief Permet d'ajouter un cube sur la map
{


	plateau[x][y]->insert(make_pair(z, new CubePierre(tailleCube*x,tailleCube*y,tailleCube*z, tailleCube, true, true, true, true, true, true)));
}

void Plateau::activerFacesVoisines(int x, int y, int z) ///\brief Active les faces voisines d'un cube (Utilisé lors de la suppression)
{
	if (x+1 < largeur)
        if (plateau[x+1][y]->find(z) != plateau[x+1][y]->end())
            plateau[x+1][y]->at(z)->afficher_gauche(true);

	if (x-1 >= 0)
        if (plateau[x-1][y]->find(z) != plateau[x-1][y]->end())
            plateau[x-1][y]->at(z)->afficher_droite(true);

	if (y+1 < longueur)
        if (plateau[x][y+1]->find(z) != plateau[x][y+1]->end())
            plateau[x][y+1]->at(z)->afficher_avant(true);

	if (y-1 >= 0)
        if (plateau[x][y-1]->find(z) != plateau[x][y-1]->end())
            plateau[x][y-1]->at(z)->afficher_arriere(true);

	if (z < hauteur && z+1 < hauteur)
        if (plateau[x][y]->find(z+1) != plateau[x][y]->end())
            plateau[x][y]->at(z+1)->afficher_dessous(true);

	if (z-1 >= 0)
        if (plateau[x][y]->find(z-1) != plateau[x][y]->end())
            plateau[x][y]->at(z-1)->afficher_dessus(true);
}
bool Plateau::isCube(int x, int y, int z) ///\brief Permet de vérifier s'il y a un cube (Utilisé pour la détection des colisions)
{
	std::cout << "IsCube " << x << y << z << " \n";
	try{
		plateau[x][y]->at(z);
		return true;
	}
	catch (const std::out_of_range& oor) {
		return false;
	}

}