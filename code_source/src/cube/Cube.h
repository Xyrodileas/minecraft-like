/*
 * Cube.h
 *
 *  Créé le : 2013-02-08
 *  Auteur: Jimmy Turgeon
 */

#ifndef CUBE_H_
#define CUBE_H_

#include "Face.h"

class Cube {
public:
	Cube(int, int, int, float, int, int, int, bool, bool, bool, bool, bool, bool);
	virtual ~Cube();

	void construire_cube();
	void afficher_avant(bool afficheAvant);
	void afficher_arriere(bool afficheArriere);
	void afficher_dessous(bool afficheDessous);
	void afficher_dessus(bool afficheDessus);
	void afficher_gauche(bool afficheGauche);
	void afficher_droite(bool afficheDroite);

	int getX();
	int getY();
	int getZ();
	int getTaille();
	int getRouge();
    int getVert();
    int getBleu();
protected:
	int x;
	int y;
	int z;
	float taille;
	int rouge;
	int vert;
	int bleu;

	Face * avant;
	Face * arriere;
	Face * dessous;
	Face * dessus;
	Face * gauche;
	Face * droite;

	bool afficheAvant;
	bool afficheArriere;
	bool afficheDessous;
	bool afficheDessus;
	bool afficheGauche;
	bool afficheDroite;

	void initialiser_cube();
};

#endif /* CUBE_H_ */
