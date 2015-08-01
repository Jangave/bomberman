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
#include "../core/objects/headers/Object.h"

Bomberman::Bomberman() {
	window = new Window(200, 100);

	window->setup();

	Map* map = new Map(100,100);
	ambient = new Ambient(map);
}

Bomberman::~Bomberman() {
	delete ambient;
	delete window;
}

int Bomberman::execute() {

	char c = 0;

	Object* obj = new Object(new Position(50, 50), new Image(20,20), new Shape(20, 20));

	ambient->addObject(obj);

	do{
		ambient->tick();
		window->update();
	}while(!window->isClosing() && !glfwGetKey(window->getNativeWindow(), GLFW_KEY_ESCAPE));

	return 0;
}
