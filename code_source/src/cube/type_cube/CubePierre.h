/*
 * CubePierre.h
 *
 *  Créé le : 2013-02-08
 *  Auteur: Jimmy Turgeon
 */

#ifndef CUBEPIERRE_H_
#define CUBEPIERRE_H_

#include "../Cube.h"

class CubePierre : public Cube {
public: 
	CubePierre(int, int, int, float, bool, bool, bool, bool, bool, bool);
	virtual ~CubePierre();
};

#endif /* CUBEPIERRE_H_ */