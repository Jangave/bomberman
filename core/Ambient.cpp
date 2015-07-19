/*
 *
 *  Created on: 18/07/2015
 *      Author: juan
 */

#include "headers/Ambient.h"

#include <GL/gl.h>

#include "headers/Image.h"
#include "headers/Position.h"

class Window;

Ambient::Ambient() {
	map = 0;
	window = 0;
}

Ambient::Ambient(Map* m, Window* w) {
	map = m;
	window = w;
}

Ambient::~Ambient() {
	// TODO Auto-generated destructor stub
}

const std::vector<Object>& Ambient::getObject() const {
	return objects;
}

void Ambient::addObject(Object& o) {
	objects.push_back(o);
}

void Ambient::setObject(const std::vector<Object>& object) {
	this->objects = objects;
}

void Ambient::draw() {
	int dims[4];
	glGetIntegerv(GL_VIEWPORT, dims);
	int w = dims[2]/map->getSizeViewX();//objects[i].getImage().getWidth();
	int h = dims[3]/map->getSizeViewY();//objects[i].getImage().getHeight();

	for(unsigned int i = 0; i < objects.size(); ++i){
		int x = objects[i].getPosition().getX();
		int y = objects[i].getPosition().getY();

		glColor3f(objects[i].getImage().getColor(0),
				objects[i].getImage().getColor(1),
				objects[i].getImage().getColor(2));

		glBegin(GL_POLYGON);
			glVertex2i(x*w,y*h);
			glVertex2i(x*w+w,y*h);
			glVertex2i(x*w+w,y*h+h);
			glVertex2i(x*w,y*h+h);
		glEnd();
	}
}

void Ambient::update() {
	draw();
	for(unsigned int i = 0; i < objects.size(); ++i){
		objects[i].update();
	}
}
