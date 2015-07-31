/*
 * Particle.cpp
 *
 *  Created on: 31 de jul de 2015
 *      Author: juan
 */

#include "headers/Particle.h"

Particle::Particle(Position* position, Image* image, Ambient* ambient) : Drawable(image), Updateable(ambient) {
	this->position = position;
}

Particle::~Particle() {
	// TODO Auto-generated destructor stub
}

