/*
 * Entity.cpp
 *
 *  Created on: 31 de jul de 2015
 *      Author: juan
 */

#include "headers/Entity.h"

Entity::Entity(Position* p, Image* image, Shape* shape, Ambient* ambient) : Drawable(image), Tangible(shape), Updateable(ambient) {
	this->position = p;
}

Entity::~Entity() {

}

