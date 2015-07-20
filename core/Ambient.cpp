/*
 *
 *  Created on: 18/07/2015
 *      Author: juan
 */

#include "headers/Ambient.h"

#include <GL/gl.h>
#include <iterator>

#include "entity/headers/Object.h"
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

const std::vector<Object*>& Ambient::getObject() const {
	return objects;
}

void Ambient::addObject(Object* o) {
	objects.push_back(o);
}

void Ambient::setObject(const std::vector<Object*>& object) {
	this->objects = objects;
}

void Ambient::draw() {
	int dims[4];
	glGetIntegerv(GL_VIEWPORT, dims);

	float w = (dims[2]/map->getSizeViewX());
	float h = (dims[3]/map->getSizeViewY());

	for(unsigned int i = 0; i < objects.size(); ++i){
		float x = objects[i]->getPosition().getX();
		float y = objects[i]->getPosition().getY();

		glColor3f(objects[i]->getImage().getColor(0),
				objects[i]->getImage().getColor(1),
				objects[i]->getImage().getColor(2));

		glBegin(GL_POLYGON);
			glVertex2i(x*w,y*h);
			glVertex2i(x*w+w*objects[i]->getImage().getWidth(),y*h);
			glVertex2i(x*w+w*objects[i]->getImage().getWidth(),y*h+h*objects[i]->getImage().getHeight());
			glVertex2i(x*w,y*h+h*objects[i]->getImage().getHeight());
		glEnd();
	}
}

void Ambient::update() {
	draw();
	for(unsigned int i = 0; i < objects.size(); ++i){
		objects[i]->update();
	}
}

Object* Ambient::getObject(Position& p) {
	for(unsigned int i = 0; i < objects.size(); ++i){
		const Position& pt = objects[i]->getPosition();
		if(pt.getX() == p.getX() && pt.getY() == p.getY())
			return objects[i];
	}
	return 0;
}

Object* Ambient::getObject(int x, int y) {
	for(unsigned int i = 0; i < objects.size(); ++i){
		const Position& pt = objects[i]->getPosition();
		if((int)pt.getX() == (int)x && (int)pt.getY() == (int)y)
			return objects[i];
	}
		return 0;
}

void Ambient::removeObject(Object* o) {
	for ( std::vector<Object*>::iterator it = objects.begin(); it != objects.end(); ++it){
	   if( (*it) == o ){
	      delete * it;
	      objects.erase(it);
	      break;
	   }
	}
}

