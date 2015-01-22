/*
 * Personnage.h
 *
 *  Créé le : 2013-03-07
 *  Auteur: Jimmy Turgeon
 */

#ifndef MEMBRE_H_
#define MEMBRE_H_

#include "../cube/Face.h"

class Membre {
public:
	Membre(int, int, int, int, int, int, int, int, int);
	virtual ~Membre();

	void construire_membre();

	int getX();
	int getY();
	int getZ();
protected:
    int x;
    int y;
    int z;
    int largeur;
	int longueur;
	int hauteur;
	int rouge;
	int vert;
	int bleu;

    Face * avant;
	Face * arriere;
	Face * dessous;
	Face * dessus;
	Face * gauche;
	Face * droite;

    void initialiser_membre();
};

#endif /* MEMBRE_H_ */
