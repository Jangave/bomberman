/*
 * Character.cpp
 *
 *  Created on: 19/07/2015
 *      Author: juan
 */

#include "headers/Character.h"

#include <GLFW/glfw3.h>

#include "core/headers/Ambient.h"
#include "core/headers/Image.h"
#include "core/headers/Position.h"
#include "core/headers/Window.h"
#include "headers/Bomb.h"

Character::Character(Position p, Image i, Ambient* a) : Object(p, i, a){
	lastMove = glfwGetTime();
	position = p;
	image = i;
	ambient = a;
}

void Character::update() {
	//std::cout << lastMove << std::endl;
	if(glfwGetTime() - lastMove > 0.1){
		//std::cout << position.getX() << "\t" << position.getY() << std::endl;
		if(glfwGetKey(ambient->window->getNativeWindow(), GLFW_KEY_W) == 1){
			Object* i = ambient->getObject(position.getX(), position.getY()+1);
			if(i == 0){
				position.move(0, 1);
				lastMove = glfwGetTime();
			}
		}
		if(glfwGetKey(ambient->window->getNativeWindow(), GLFW_KEY_S) == 1){
			if(!ambient->getObject(position.getX(), position.getY()-1)){
				position.move(0, -1);
				lastMove = glfwGetTime();
			}
		}
		if(glfwGetKey(ambient->window->getNativeWindow(), GLFW_KEY_D) == 1){
			if(!ambient->getObject(position.getX()+1, position.getY())){
				position.move(1, 0);
				lastMove = glfwGetTime();
			}
		}
		if(glfwGetKey(ambient->window->getNativeWindow(), GLFW_KEY_A) == 1){
			if(!ambient->getObject(position.getX()-1, position.getY())){
				position.move(-1, 0);
				lastMove = glfwGetTime();
			}
		}
		if(glfwGetKey(ambient->window->getNativeWindow(), GLFW_KEY_SPACE) == 1){
			ambient->addObject(new Bomb(2, Position(position.getX()+0.25,position.getY()+0.25), ambient));
		}
	}
}

Character::~Character() {
}
