/*
 * DestroyableWall.cpp
 *
 *  Created on: 2 de ago de 2015
 *      Author: juan
 */

#include "headers/DestroyableWall.h"

#include "Types.h"

DestroyableWall::DestroyableWall(Position* position, Image* image, Shape* shape) : Wall(position, image, shape) {
	image->setColor(0.804, 0.522, 0.247);
	type *= DESTROYABLE;
}

DestroyableWall::~DestroyableWall() {
}
