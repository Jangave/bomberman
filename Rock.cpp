/*
 * Rock.cpp
 *
 *  Created on: 19/07/2015
 *      Author: juan
 */

#include "headers/Rock.h"

#include "core/headers/Image.h"
#include "core/headers/Position.h"

Rock::Rock(Position* p, Image* i, Ambient* a) : Object(p, i, a){
	position = p;
	image = i;
	ambient = a;
}

Rock::~Rock() {
	// TODO Auto-generated destructor stub
}


void Rock::update() {
}
