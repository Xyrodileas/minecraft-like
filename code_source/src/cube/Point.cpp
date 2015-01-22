/*
 * Point.cpp
 *
 *  Créé le : 2013-02-25
 *  Auteur: Jimmy Turgeon
 */

#include "Point.h"

Point::Point(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Point::~Point() {
}

void Point::setX(float x)
{
	this->x = x;
}

void Point::setY(float y)
{
	this->y = y;
}

void Point::setZ(float z)
{
	this->z = z;
}

float Point::getX()
{
	return this->x;
}

float Point::getY()
{
	return this->y;
}

float Point::getZ()
{
	return this->z;
}