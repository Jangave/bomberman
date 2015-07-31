/*
 * BomberLand.cpp
 *
 *  Created on: 18/07/2015
 *      Author: juan
 */

#include "headers/Bomberman.h"

#include <GLFW/glfw3.h>

#include "core/headers/Ambient.h"
#include "core/headers/Image.h"
#include "core/headers/Map.h"
#include "core/headers/Position.h"
#include "core/headers/Window.h"
#include "headers/Character.h"
#include "headers/Rock.h"

Bomberman::Bomberman() {
	glfwInit();
}

Bomberman::~Bomberman() {
}

int Bomberman::run() {
	Window* window = new Window(570, 390);
	window->setup();

	Map* map = new Map(19, 13);
	Ambient* ambient = new Ambient(map, window);

	Character* c = new Character(new Position(3, 3), new Image(1, 1, 1.f, 1.f, 1.f), ambient);
	ambient->addObject(c);

	//ambient->addObject(new Rock(Position(8,4), Image(1, 1, 0.5f, 0.5f, 0.5f), ambient));
	for(int i = 0; i < map->getSizeY(); ++i){
		ambient->addObject(new Rock(new Position(0, i), new Image(1, 1, 0.5f, 0.5f, 0.5f), ambient));
		ambient->addObject(new Rock(new Position(map->getSizeX()-1, i), new Image(1, 1, 0.5f, 0.5f, 0.5f), ambient));
	}
	for(int i = 1; i < map->getSizeX()-1; ++i){
		ambient->addObject(new Rock(new Position(i, 0), new Image(1, 1, 0.5f, 0.5f, 0.5f), ambient));
		ambient->addObject(new Rock(new Position(i, map->getSizeY()-1), new Image(1, 1, 0.5f, 0.5f, 0.5f), ambient));
	}

	for(int i = 2; i < map->getSizeX()-2; i+=2){
		for(int j = 2; j < map->getSizeX()-3; j+=2){
			ambient->addObject(new Rock(new Position(i, j), new Image(1, 1, 0.5f, 0.5f, 0.5f), ambient));
		}
	}

	while(!window->isClosing() && !glfwGetKey(window->getNativeWindow(), GLFW_KEY_ESCAPE)){
		window->update();
		ambient->update();
		//std::cout << ambient->getObject(5,5) << std::endl;
	}



	return 0;
}

int main(){
	return Bomberman().run();
}
