/*
 *
 *  Created on: 18/07/2015
 *      Author: juan
 */

#include "headers/Ambient.h"


void Ambient::tick(){

	for (unsigned int i = 0; i < entitys.size(); ++i) {
		for (unsigned int j = i; j < entitys.size(); ++j) {
			if(entitys[i]->isColliding(entitys[j])){
				entitys[i]->onCollide(entitys[j]);
				entitys[j]->onCollide(entitys[i]);
			}
		}
		for (unsigned int j = 0; j < objects.size(); ++j) {
			if(entitys[i]->isColliding(objects[j])){
				entitys[i]->onCollide(objects[j]);
				objects[j]->onCollide(entitys[i]);
			}
		}
		entitys[i]->update();
		entitys[i]->draw();
	}
	for (unsigned int i = 0; i < objects.size(); ++i){
			objects[i]->draw();
	}
	for (unsigned int i = 0; i < particles.size(); ++i) {
		particles[i]->update();
		particles[i]->draw();
	}

}

void Ambient::addObject(Object* obj) {
	objects.push_back(obj);
}

void Ambient::addEntity(Entity* ent) {
	entitys.push_back(ent);
}

void Ambient::addParticle(Particle* par) {
	particles.push_back(par);
}

void Ambient::draw(Drawable* d){
	if(map->isInView(d))
		d->draw();
}

Ambient::Ambient() {
	objects = std::vector<Object*>();
	entitys = std::vector<Entity*>();
	particles = std::vector<Particle*>();
	map = 0;
}

Ambient::Ambient(Map* m) {
	objects = std::vector<Object*>();
	entitys = std::vector<Entity*>();
	particles = std::vector<Particle*>();
	map = m;
}

Ambient::~Ambient() {

	for (unsigned int i = 0; i < entitys.size(); ++i) {
		delete entitys[i];
	}
	for (unsigned int i = 0; i < objects.size(); ++i) {
		delete objects[i];
	}
	for (unsigned int i = 0; i < particles.size(); ++i) {
		delete particles[i];
	}
	delete map;
}

/*void Ambient::addObject(Object* o) {
	objects.push_back(o);
}


void Ambient::draw() {
	int dims[4];
	glGetIntegerv(GL_VIEWPORT, dims);

	float w = (dims[2]/map->getSizeViewX());
	float h = (dims[3]/map->getSizeViewY());

	for(unsigned int i = 0; i < objects.size(); ++i){
		float x = objects[i]->getPosition()->getX();
		float y = objects[i]->getPosition()->getY();

		glColor3f(objects[i]->getImage()->getColor(0),
				objects[i]->getImage()->getColor(1),
				objects[i]->getImage()->getColor(2));

		glBegin(GL_POLYGON);
			glVertex2i(x*w,y*h);
			glVertex2i(x*w+w*objects[i]->getImage()->getWidth(),y*h);
			glVertex2i(x*w+w*objects[i]->getImage()->getWidth(),y*h+h*objects[i]->getImage()->getHeight());
			glVertex2i(x*w,y*h+h*objects[i]->getImage()->getHeight());
		glEnd();
	}
}*/

/*void Ambient::update() {
	draw();
	for(unsigned int i = 0; i < objects.size(); ++i){
		objects[i]->update();
	}
}*/

/*Object* Ambient::getObject(Position* p) {
	for(unsigned int i = 0; i < objects.size(); ++i){
		Position* pt = objects[i]->getPosition();
		if(pt->getX() == p->getX() && pt->getY() == p->getY())
			return objects[i];
	}
	return 0;
}

Object* Ambient::getObject(int x, int y) {
	for(unsigned int i = 0; i < objects.size(); ++i){
		Position* pt = objects[i]->getPosition();
		if((int)pt->getX() == (int)x && (int)pt->getY() == (int)y)
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
}*/

