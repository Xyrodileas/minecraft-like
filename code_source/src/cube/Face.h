/*
 * Face.h
 *
 *  Créé le : 2013-02-25
 *  Auteur: Jimmy Turgeon
 */

#ifndef FACE_H_
#define FACE_H_

#include <GL/gl.h>
#include <GL/glu.h>
#include "Point.h"

class Face {
public:
	Face(Point, Point, Point, Point, int, int, int);
	virtual ~Face();

	void construire_face();
protected:
	Point point;
	Point point2;
	Point point3;
	Point point4;
	float taille;
	int rouge;
	int vert;
	int bleu;
};

#endif /* FACE_H_ */
