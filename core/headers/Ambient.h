/*
 * Ambient.h
 *
 *  Created on: 18/07/2015
 *      Author: juan
 */

#ifndef AMBIENT_H_
#define AMBIENT_H_

#include <vector>

#include "../objects/headers/Entity.h"
#include "../objects/headers/Object.h"
#include "../objects/headers/Particle.h"

#include "Map.h"
#include "Window.h"

class Ambient {
public:
	Ambient();
	Ambient(Map* m, Window* w);
	virtual ~Ambient();

	//void addObject(Object* o);
	//void removeObject(Object* o);

	//const std::vector<Object*>& getObject() const;
	//void setObject(const std::vector<Object*>& objects);

	void addObject(Object* obj);
	void addEntity(Entity* ent);
	void addParticle(Particle* par);
	void removeObject(Object* obj);
	void removeEntity(Entity* ent);
	void removeParticle(Particle* par);

	void tick();

	void draw(Drawable* d);
	std::vector<Tangible*> collisions(Tangible* t);

	const std::vector<Entity*>& getEntitys() const;
	void setEntitys(const std::vector<Entity*>& entitys);
	Map* getMap();
	void setMap(Map* map);
	const std::vector<Object*>& getObjects() const;
	void setObjects(const std::vector<Object*>& objects);
	const std::vector<Particle*>& getParticles() const;
	void setParticles(const std::vector<Particle*>& particles);
	Window* getWindow();
	void setWindow(Window* window);

	int getKey(int key);

protected:
	std::vector<Entity*> entitys;
	std::vector<Object*> objects;
	std::vector<Particle*> particles;
	Map* map;

	Window* window;

	std::vector<Object*> objectsToRemove;
	std::vector<Entity*> entitysToRemove;
	std::vector<Particle*> particlesToRemove;

	void removePendents();
};

#endif /* AMBIENT_H_ */
