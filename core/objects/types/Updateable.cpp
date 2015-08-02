/*
 * Updateable.cpp
 *
 *  Created on: 30 de jul de 2015
 *      Author: juan
 */

#include "headers/Updateable.h"

Updateable::Updateable(Ambient* ambient) : Node(){
	this->ambient = ambient;
	type *= UPDATEABLE;
}

void Updateable::update() {
}

Ambient* Updateable::getAmbient() {
	return ambient;
}

Updateable::Updateable(Ambient* ambient, Position* p) : Node(p){
	this->ambient = ambient;
	type *= UPDATEABLE;
}

void Updateable::setAmbient(Ambient* ambient) {
	this->ambient = ambient;
}
