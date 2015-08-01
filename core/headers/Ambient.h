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

class Ambient {
public:
	Ambient();
	Ambient(Map* m);
	virtual ~Ambient();

	//void addObject(Object* o);
	//void removeObject(Object* o);

	//const std::vector<Object*>& getObject() const;
	//void setObject(const std::vector<Object*>& objects);

	void addObject(Object* obj);
	void addEntity(Entity* ent);
	void addParticle(Particle* par);

	void tick();

	void draw(Drawable* d);

protected:
	std::vector<Entity*> entitys;
	std::vector<Object*> objects;
	std::vector<Particle*> particles;
	Map* map;

};

#endif /* AMBIENT_H_ */
