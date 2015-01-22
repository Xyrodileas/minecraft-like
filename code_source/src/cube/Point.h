/*
 * Point.h
 *
 *  Créé le : 2013-02-25
 *  Auteur: Jimmy Turgeon
 */

#ifndef POINT_H_
#define POINT_H_

class Point {
public:
	Point(float, float, float);
	virtual ~Point();

	Point& operator =(const Point&);

	float getX();
	float getY();
	float getZ();

	void setX(float);
	void setY(float);
	void setZ(float);
protected:
	float x;
	float y;
	float z;


};

#endif /* POINT_H_ */