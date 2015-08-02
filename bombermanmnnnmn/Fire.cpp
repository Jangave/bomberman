/*
 * Fire.cpp
 *
 *  Created on: 2 de ago de 2015
 *      Author: juan
 */

#include "headers/Fire.h"

#include <GLFW/glfw3.h>

#include "../core/headers/Ambient.h"
#include "../core/headers/Image.h"
#include "../core/headers/Map.h"
#include "../core/headers/Position.h"
#include "../core/headers/Shape.h"
#include "Types.h"

Fire::Fire(Position* p, Ambient* ambient) : Entity(p, new Image(), new Shape(), ambient) {
	int u = ambient->getMap()->getUnit();
	position->setX(position->getX() / u * u + u/4);
	position->setY(position->getY() / u * u + u/4);

	image->setHeight(u/2);
	image->setWidth(u/2);
	image->setColor(1, 1, 0);

	shape->setSizeX(u/2);
	shape->setSizeY(u/2);

	initTime = glfwGetTime();

	type *= FIRE;
}

Fire::~Fire() {
}

void Fire::update() {
	if(glfwGetTime() - initTime > 1){
		ambient->removeEntity(this);
	}
}

void Fire::onCollide() {
}
