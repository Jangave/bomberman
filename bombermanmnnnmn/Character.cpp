/*
 * Character.cpp
 *
 *  Created on: 31 de jul de 2015
 *      Author: juan
 */

#include "headers/Character.h"

#include <GLFW/glfw3.h>
#include <iostream>

#include "../core/headers/Ambient.h"
#include "../core/headers/Window.h"

Character::Character(Position* p, Image* image, Shape* shape, Ambient* ambient) : Entity(p, image, shape, ambient) {
	image->setColor(1,1,0);

	speed = ((float)ambient->getMap()->getUnit())/60.0*4;
}

Character::~Character() {
}

void Character::update(){

	position->move(shape->getDeformX(), shape->getDeformY());

	shape->setDeformX(0);
	shape->setDeformY(0);
	if(ambient->getKey(GLFW_KEY_W) == 1){
		shape->setDeformY(speed);
	}
	if(ambient->getKey(GLFW_KEY_A) == 1){
		shape->addDeformX(-speed);
	}
	if(ambient->getKey(GLFW_KEY_S) == 1){
		shape->addDeformY(-speed);
	}
	if(ambient->getKey(GLFW_KEY_D) == 1){
		shape->addDeformX(speed);
	}
}

void Character::onCollide(Tangible* other){
//	if(ambient->getKey(GLFW_KEY_W) == 1){
//		shape->setDeformY(20);
//	}
	//std::cout << "SX: " << s.getSizeX() << "\tSY: " << s.getSizeY() << std::endl;

	Shape s = intersectionSize(other);
	s = intersectionSize(other);
	if(s.getSizeX() < s.getSizeY()){
		if(shape->getDeformX() > 0)
			shape->addDeformX(-s.getSizeX());
		else if(shape->getDeformX() < 0)
			shape->addDeformX(s.getSizeX());
	} else {
		if(shape->getDeformY() > 0)
			shape->addDeformY(-s.getSizeY());
		else if(shape->getDeformY() < 0)
			shape->addDeformY(s.getSizeY());
	}

	if(isColliding(other)){
		s = intersectionSize(other);
		if(s.getSizeX() < s.getSizeY()){
			if(shape->getDeformX() > 0)
				shape->addDeformX(-s.getSizeX());
			else if(shape->getDeformX() < 0)
				shape->addDeformX(s.getSizeX());
		} else {
			if(shape->getDeformY() > 0)
				shape->addDeformY(-s.getSizeY());
			else if(shape->getDeformY() < 0)
				shape->addDeformY(s.getSizeY());
		}
	}
}


















