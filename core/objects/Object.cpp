/*
 * Object.cpp
 *
 *  Created on: 31 de jul de 2015
 *      Author: juan
 */

#include "headers/Object.h"

Object::Object(Position* position, Image* image, Shape* shape) : Drawable(image), Tangible(shape) {
	this->position = position;
}

Object::~Object() {
	// TODO Auto-generated constructor stub

}

