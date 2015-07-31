/*
 * Fire.cpp
 *
 *  Created on: 19/07/2015
 *      Author: juan
 */

#include "headers/Fire.h"

#include <GLFW/glfw3.h>

#include "core/headers/Ambient.h"
#include "core/headers/Image.h"
#include "core/headers/Position.h"

Fire::Fire(bool isLast, bool isX, Position* p, Ambient* a) : Object(p, new Image(1, 1, 1, 1, 0), a) {
	createTime = glfwGetTime();
	if(isX){
		position->move(0, 0.25);
		image->setHeight(0.5);
	} else {
		position->move(0.25, 0);
		image->setWidth(0.5);
	}
}

Fire::~Fire() {
	// TODO Auto-generated destructor stub
}

void Fire::update() {
	int d = glfwGetTime() - createTime;
	if(d > 0.5)
		ambient->removeObject(this);
}
