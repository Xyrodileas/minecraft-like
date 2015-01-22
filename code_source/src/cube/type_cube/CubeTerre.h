/*
 * CubeTerre.h
 *
 *  Créé le : 2013-02-08
 *  Auteur: Jimmy Turgeon
 */

#ifndef CUBETERRE_H_
#define CUBETERRE_H_

#include "../Cube.h"

class CubeTerre : public Cube {
public: 
	CubeTerre(int, int, int, float, bool, bool, bool, bool, bool, bool);
	virtual ~CubeTerre();
};

#endif /* CUBETERRE_H_ */