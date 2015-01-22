/*
 * Personnage.h
 *
 *  Créé le : 2013-03-07
 *  Auteur: Jimmy Turgeon
 */

#ifndef PERSONNAGE_H_
#define PERSONNAGE_H_

#include "../cube/Point.h"
#include "Membre.h"

class Personnage {
public:
	Personnage(int, int, int, int, int, int);
	virtual ~Personnage();

	void construire_personnage();
protected:
    int x;
    int y;
    int z;
    int largeur;
    int longueur;
    int hauteur;

    Membre * brasDroit;
	Membre * brasGauche;
	Membre * tete;
	Membre * corps;
	Membre * jambeDroite;
	Membre * jambeGauche;

    void construire_corps();

    void initialiser_personnage();
};

#endif /* PERSONNAGE_H_ */
