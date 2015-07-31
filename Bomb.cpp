/*
 * Bomb.cpp
 *
 *  Created on: 19/07/2015
 *      Author: juan
 */

#include "headers/Bomb.h"

#include <GLFW/glfw3.h>

#include "core/headers/Ambient.h"
#include "core/headers/Image.h"
#include "core/headers/Position.h"
#include "headers/Fire.h"

Bomb::Bomb(int power, Position* p, Ambient* a) : Object(p, new Image(0.5, 0.5, 0, 1, 1), a){
	createTime = glfwGetTime();
	this->power = power;
}

Bomb::~Bomb() {
	// TODO Auto-generated destructor stub
}

void Bomb::update() {
	int d = glfwGetTime() - createTime;
	if(d > 2){
		float x = position->getX()-0.25;
		float y = position->getY()-0.25;

		for(int i = 1; i <= power; ++i)
			if(ambient->getObject(x+i, y) == 0)
				ambient->addObject(new Fire(0, 1, new Position(x+i, y), ambient));
			else
				break;
		for(int i = 1; i <= power; ++i)
			if(ambient->getObject(x-i, y) == 0)
				ambient->addObject(new Fire(0, 1, new Position(x-i, y), ambient));
			else
				break;
		for(int i = 1; i <= power; ++i)
			if(ambient->getObject(x, y+i) == 0)
				ambient->addObject(new Fire(0, 0, new Position(x, y+i), ambient));
			else
				break;
		for(int i = 1; i <= power; ++i)
			if(ambient->getObject(x, y-i) == 0)
				ambient->addObject(new Fire(0, 0, new Position(x, y-i), ambient));
			else
				break;


		ambient->removeObject(this);
	}
}
