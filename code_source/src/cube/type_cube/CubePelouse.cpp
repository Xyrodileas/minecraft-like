/*
 * CubePelouse.cpp
 *
 *  Créé le : 2013-02-08
 *  Auteur: Jimmy Turgeon
 */

#include "CubePelouse.h"

CubePelouse::CubePelouse(int x, int y, int z, float taille, bool afficheDessus, bool afficheAvant, bool afficheArriere, bool afficheDessous, bool afficheGauche, bool afficheDroite) : Cube(x, y, z, taille, 0, 255, 0, afficheDessus, afficheAvant, afficheArriere, afficheDessous, afficheGauche, afficheDroite){
}

CubePelouse::~CubePelouse() {
}