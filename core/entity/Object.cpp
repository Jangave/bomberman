/*
 * Object.cpp
 *
 *  Created on: 18/07/2015
 *      Author: juan
 */

#include "headers/Object.h"


Object::Object(Position p, Image i) {
	position = p;
	image = i;
	ambient = 0;
}

Object::Object(Position p, Image i, Ambient* a) {
	position = p;
	image = i;
	ambient = a;
}

Object::~Object() {
}

const Image& Object::getImage() const {
	return image;
}

void Object::setImage(Image image) {
	this->image = image;
}

const Position& Object::getPosition() const {
	return position;
}

void Object::setPosition(Position& position) {
	this->position = position;
}

void Object::setPosition(float x, float y) {
	position.set(x, y);
}

const Ambient* Object::getAmbient() const {
	return ambient;
}

void Object::setAmbient(Ambient* ambient) {
	this->ambient = ambient;
}
