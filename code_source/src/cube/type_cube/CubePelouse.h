/*
 * CubePelouse.h
 *
 *  Créé le : 2013-02-08
 *  Auteur: Jimmy Turgeon
 */

#ifndef CUBEPELOUSE_H_
#define CUBEPELOUSE_H_

#include "../Cube.h"

class CubePelouse : public Cube {
public: 
	CubePelouse(int, int, int, float, bool, bool, bool, bool, bool, bool);
	virtual ~CubePelouse();
};

#endif /* CUBEPELOUSE_H_ */