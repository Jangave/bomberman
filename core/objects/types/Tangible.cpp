/*
 * Tangible.cpp
 *
 *  Created on: 30 de jul de 2015
 *      Author: juan
 */

#include "headers/Tangible.h"

#include <iostream>

#include "../../headers/Position.h"

Tangible::Tangible(Shape* shape) : Node(){
	this->shape = shape;
	type *= TANGIBLE;
}

Tangible::Tangible(Shape* shape, Position* position) : Node(position){
	this->shape = shape;
	type *= TANGIBLE;
}

Shape*& Tangible::getShape() {
	return shape;
}

Tangible::~Tangible() {
	delete shape;
}

void Tangible::onCollide(Tangible* other) {
}

bool Tangible::isColliding(Tangible* other) {
	return (dX2()> other->dX()  &&
			dX() < other->dX2() &&
		    dY2()> other->dY()  &&
			dY() < other->dY2());
}

int Tangible::dX() {
	return position->getX()+shape->getNegativeDeformX();
}

int Tangible::dY() {
	return position->getY()+shape->getNegativeDeformY();
}

int Tangible::dX2() {
	return position->getX() + shape->getDeformedSizeX();
}

int Tangible::dY2() {
	return position->getY() + shape->getDeformedSizeY();
}

void Tangible::setShape(Shape*& shape) {
	this->shape = shape;
}

Shape Tangible::intersectionSize(Tangible* other) {
	int x, x2, y, y2;

	if(dX() < other->dX() && other->dX() < dX2())
		x = other->dX();
	else
		x = dX();
	if(dX() < other->dX2() && other->dX2() < dX2())
		x2 = other->dX2();
	else
		x2 = dX2();

	if(dY() < other->dY() && other->dY() < dY2())
		y = other->dY();
	else
		y = dY();
	if(dY() < other->dY2() && other->dY2() < dY2())
		y2 = other->dY2();
	else
		y2 = dY2();

	return Shape(x2 - x, y2 - y);
}

/*int Tangible::intersectionSizeX(Tangible* other) {
	int x, x2, y, y2;

	if(dX() < other->dX() && other->dX() < dX2())
		x = other->dX();
	else
		x = dX();
	if(dX() < other->dX2() && other->dX2() < dX2())
		x2 = other->dX2();
	else
		x2 = dX2();

	return x2 - x;
}*/
