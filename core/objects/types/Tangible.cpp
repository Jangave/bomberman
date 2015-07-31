/*
 * Tangible.cpp
 *
 *  Created on: 30 de jul de 2015
 *      Author: juan
 */

#include "headers/Tangible.h"

#include "../../headers/Position.h"
#include "../../headers/Shape.h"

Tangible::Tangible(Shape* shape) : Node(){
	this->shape = shape;
}

Tangible::Tangible(Shape* shape, Position* position) : Node(position){
	this->shape = shape;
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
	return ((position->getX()+shape->getSizeDeformedX() > other->position->getX() && position->getX() < other->position->getX()+other->shape->getSizeDeformedX()) &&
		    (position->getY()+shape->getSizeDeformedY() > other->position->getY() && position->getY() < other->position->getY()+other->shape->getSizeDeformedY()));
}

void Tangible::setShape(Shape*& shape) {
	this->shape = shape;
}
