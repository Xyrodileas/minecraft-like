/*
 * Plateau.h
 *
 *  Créé le : 2013-02-18
 *  Auteur: Jimmy Turgeon
 */

#ifndef PLATEAU_H_
#define PLATEAU_H_

#include <map>
#include "../cube/Cube.h"
#include "../cube/type_cube/CubePelouse.h"
#include "../cube/type_cube/CubePierre.h"
#include "../cube/type_cube/CubeTerre.h"
#include "../cube/Point.h"

class Plateau {
public:
	Plateau(int, int, int, float);
	virtual ~Plateau();

	void afficher_plateau();
	void supprimer_cube(int, int, int);
	void ajouter_cube(int,int,int);
	void verifier_integrite_cubes();
	bool isCube(int, int, int);
private:
	int largeur;
	int longueur;
	int hauteur;
	int tailleCube;
//	Cube ****plateau;

    std::map<int, Cube*> *** plateau;

	void initialiser_plateau();
	void activerFacesVoisines(int, int, int);
};

#endif /* PLATEAU_H_ */
