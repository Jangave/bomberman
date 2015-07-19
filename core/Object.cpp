/*
 * Object.cpp
 *
 *  Created on: 18/07/2015
 *      Author: juan
 */

#include "headers/Object.h"




Object::Object(Position p, Image i) {
	position = p;
	image = i;
	ambient = 0;
}

Object::Object(Position p, Image i, Ambient* a) {
	position = p;
	image = i;
	ambient = a;
}

Object::~Object() {
}

const Image& Object::getImage() const {
	return image;
}

void Object::setImage(Image image) {
	this->image = image;
}

const Position& Object::getPosition() const {
	return position;
}

void Object::setPosition(Position& position) {
	this->position = position;
}

void Object::setPosition(int x, int y) {
	position.set(x, y);
}
//double lastMove;
void Object::update() {
	//image.draw(position);
	/*if(glfwGetTime() - lastMove > 0.25){
		if(glfwGetKey(ambient->window->getNativeWindow(), GLFW_KEY_W) == 1){
			position.move(0, 1);
			lastMove = glfwGetTime();
		}
		if(glfwGetKey(ambient->window->getNativeWindow(), GLFW_KEY_S) == 1){
			position.move(0, -1);
			lastMove = glfwGetTime();
		}
		if(glfwGetKey(ambient->window->getNativeWindow(), GLFW_KEY_D) == 1){
			position.move(1, 0);
			lastMove = glfwGetTime();
		}
		if(glfwGetKey(ambient->window->getNativeWindow(), GLFW_KEY_A) == 1){
			position.move(-1, 0);
			lastMove = glfwGetTime();
		}
	}*/
}

const Ambient* Object::getAmbient() const {
	return ambient;
}

void Object::setAmbient(Ambient* ambient) {
	this->ambient = ambient;
}
