/*
 * CubePierre.cpp
 *
 *  Créé le : 2013-02-08
 *  Auteur: Jimmy Turgeon
 */

#include "CubePierre.h"

CubePierre::CubePierre(int x, int y, int z, float taille, bool afficheDessus, bool afficheAvant, bool afficheArriere, bool afficheDessous, bool afficheGauche, bool afficheDroite) : Cube(x, y, z, taille, 127, 127, 127, afficheDessus, afficheAvant, afficheArriere, afficheDessous, afficheGauche, afficheDroite){
}

CubePierre::~CubePierre() {
}