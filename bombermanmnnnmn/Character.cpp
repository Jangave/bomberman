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
#include "../core/headers/Image.h"
#include "../core/headers/Map.h"
#include "../core/headers/Position.h"
#include "../core/headers/Shape.h"
#include "headers/Bomb.h"
#include "Types.h"

Character::Character(Position* p, Image* image, Shape* shape, Ambient* ambient) : Entity(p, image, shape, ambient) {
	image->setColor(0.5,0.7,1);

	speed = ((float)ambient->getMap()->getUnit())/60.0*4;
	fireSize = 2;
	nbombs = 4;
	bombBelow = 0;
	plantedBombs = 0;
	//bombs = std::vector<Bomb*>();

	type *= CHARACTER;
}

Character::~Character() {
}

void Character::update(){
	if(bombBelow != 0){
		if(!isColliding(bombBelow)){
			bombBelow = 0;
		}
	}

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

	if(ambient->getKey(GLFW_KEY_KP_1) || ambient->getKey(GLFW_KEY_SPACE)){
		plantBomb();
	}
}

void Character::onCollide(Tangible* other){
	//if ((other->type%BOMB)==0) return;
	if(bombBelow == other) return;

	Shape s = intersectionSize(other);

	if(s.getSizeX() < s.getSizeY()){
		if(shape->getDeformX() > 0)
			shape->addDeformX(-s.getSizeX());
		else if(shape->getDeformX() < 0)
			shape->addDeformX(s.getSizeX());
	}
	if(s.getSizeX() > s.getSizeY()){
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
		}
		if(s.getSizeX() > s.getSizeY()){
			if(shape->getDeformY() > 0)
				shape->addDeformY(-s.getSizeY());
			else if(shape->getDeformY() < 0)
				shape->addDeformY(s.getSizeY());
		}
	}
	//std::cout << "SX: " << s.getSizeX() << "\tSY: " << s.getSizeY() << std::endl;
	if(s.getSizeX() <= s.getSizeY()){
		if(s.getSizeY() < ambient->getMap()->getUnit()/2){
			if(position->getY() > other->getPosition()->getY() && shape->getDeformY() == 0)
				shape->addDeformY(speed);
			if(position->getY() < other->getPosition()->getY() && shape->getDeformY() == 0)
				shape->addDeformY(-speed);
		}
	}
	if(s.getSizeX() >= s.getSizeY()){
		if(s.getSizeX() < ambient->getMap()->getUnit()/2){
			if(position->getX() > other->getPosition()->getX() && shape->getDeformX() == 0)
				shape->addDeformX(speed);
			if(position->getX() < other->getPosition()->getX() && shape->getDeformX() == 0)
				shape->addDeformX(-speed);
		}
	}

	//std::cout << ((other->type%BOMB)==0) << std::endl;
}

int Character::getPlantedBombs() const {
	return plantedBombs;
}

void Character::setPlantedBombs(int plantedBombs) {
	this->plantedBombs = plantedBombs;
}

void Character::plantBomb() {
	if(bombBelow == 0 && plantedBombs < nbombs){
		plantedBombs++;
		std::cout << "plantedBombs: " << plantedBombs << std::endl;
		bombBelow = new Bomb(new Position(position->getX() + shape->getSizeX()/2, position->getY() + shape->getSizeY()/2), fireSize, ambient, this);
		ambient->addEntity(bombBelow);
	}
}
