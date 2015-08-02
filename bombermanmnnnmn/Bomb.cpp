/*
 * Bomb.cpp
 *
 *  Created on: 1 de ago de 2015
 *      Author: juan
 */

#include "headers/Bomb.h"

#include <GLFW/glfw3.h>

#include "../core/headers/Ambient.h"
#include "../core/headers/Image.h"
#include "../core/headers/Map.h"
#include "../core/headers/Position.h"
#include "../core/headers/Shape.h"
#include "headers/Fire.h"
#include "Types.h"

Bomb::Bomb(Position* p, int power, Ambient* ambient, Character* owner) : Entity(p, new Image(), new Shape(), ambient){

	int u = ambient->getMap()->getUnit();
	position->setX(position->getX() / u * u + u/4);
	position->setY(position->getY() / u * u + u/4);

	image->setHeight(u/2);
	image->setWidth(u/2);
	image->setColor(0, 1, 1);

	shape->setSizeX(u/2);
	shape->setSizeY(u/2);

	this->owner = owner;

	initTime = glfwGetTime();

	this->power = power;

	type *= BOMB;

	/*std::vector<Tangible*> collisions = ambient->collisions(this);
	for (unsigned int i = 0; i < collisions.size(); ++i) {
		if(collisions[i]->type % )
	}*/
}

Bomb::~Bomb() {
}

void Bomb::update() {
	if(glfwGetTime() - initTime > 3){
		for (int i = 1; i <= power; ++i) {
			Fire* f = new Fire(new Position(position->getX()+ambient->getMap()->getUnit()*i, position->getY()), ambient);
			if(ambient->collisions(f).size() == 0)
				ambient->addEntity(f);
			else{
				delete f;
				break;
			}
		}
		for (int i = 1; i <= power; ++i) {
			Fire* f = new Fire(new Position(position->getX()-ambient->getMap()->getUnit()*i, position->getY()), ambient);
			if(ambient->collisions(f).size() == 0)
				ambient->addEntity(f);
			else{
				delete f;
				break;
			}
		}
		for (int i = 1; i <= power; ++i) {
			Fire* f = new Fire(new Position(position->getX(), position->getY()+ambient->getMap()->getUnit()*i), ambient);
			if(ambient->collisions(f).size() == 0)
				ambient->addEntity(f);
			else{
				delete f;
				break;
			}
		}
		for (int i = 1; i <= power; ++i) {
			Fire* f = new Fire(new Position(position->getX(), position->getY()-ambient->getMap()->getUnit()*i), ambient);
			if(ambient->collisions(f).size() == 0)
				ambient->addEntity(f);
			else{
				delete f;
				break;
			}
		}

		owner->setPlantedBombs(owner->getPlantedBombs()-1);
		ambient->removeEntity(this);
	}
	//std::cout << (glfwGetTime() - initTime) << std::endl;
}

void Bomb::onCollide(Tangible* other) {
}
