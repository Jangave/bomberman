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
#include "core/headers/Object.h"
#include "core/headers/Position.h"
#include "core/headers/Window.h"

Bomberman::Bomberman() {
	glfwInit();
}

Bomberman::~Bomberman() {
}

int Bomberman::run() {
	Window window = Window(400, 400);
	window.setup();

	Map map = Map(10, 10);
	Ambient ambient = Ambient(&map, &window);

	Object o = Object(Position(2, 3), Image(1, 1, 1.f, 0.f, 1.f), &ambient);

	ambient.addObject(o);

	while(!window.isClosing() && !glfwGetKey(window.getNativeWindow(), GLFW_KEY_ESCAPE)){
		window.update();
		ambient.update();

	}



	return 0;
}

int main(){
	return Bomberman().run();
}
