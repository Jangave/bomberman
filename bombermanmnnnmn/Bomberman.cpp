/*
 * Bomberman.cpp
 *
 *  Created on: 31 de jul de 2015
 *      Author: juan
 */

#include "headers/Bomberman.h"

#include <GLFW/glfw3.h>

#include "../core/headers/Ambient.h"
#include "../core/headers/Image.h"
#include "../core/headers/Map.h"
#include "../core/headers/Position.h"
#include "../core/headers/Shape.h"
#include "../core/headers/Window.h"
#include "../core/objects/headers/Entity.h"
#include "headers/Character.h"

Bomberman::Bomberman() {
}

Bomberman::~Bomberman() {
	delete ambient;
	delete window;
}

int Bomberman::execute() {
	float unit = 32;
	int mx = 14, my = 12;

	Map* map = new Map((mx+1),(my+1), unit);
	map->setUnit(unit);

	window = new Window(map);
	window->setup();

	ambient = new Ambient(map, window);
	int cd = unit;// - 2;
	Character* cha = new Character(new Position(unit*5, unit*4), new Image(cd, cd), new Shape(cd, cd), ambient);

	for (int i = 1; i < mx; ++i) {
		ambient->addObject(new Object(new Position(unit*i, 0), new Image(unit, unit), new Shape(unit, unit)));
	}
	for (int i = 1; i < my; ++i) {
		ambient->addObject(new Object(new Position(0, unit*i), new Image(unit, unit), new Shape(unit, unit)));
	}
	for (int i = 1; i < mx; ++i) {
		ambient->addObject(new Object(new Position(unit*i, unit*my), new Image(unit, unit), new Shape(unit, unit)));
	}
	for (int i = 1; i < my; ++i) {
		ambient->addObject(new Object(new Position(unit*mx, unit*i), new Image(unit, unit), new Shape(unit, unit)));
	}
	for (int i = 2; i < mx-1; i += 2) {
		for (int j = 2; j < my-1; j += 2) {
			ambient->addObject(new Object(new Position(unit*i, unit*j), new Image(unit, unit), new Shape(unit, unit)));
		}
	}

	ambient->addEntity(cha);

	do{
		ambient->tick();
		window->update();
	}while(!window->isClosing() && !glfwGetKey(window->getNativeWindow(), GLFW_KEY_ESCAPE));

	return 0;
}
