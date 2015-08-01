/*
 * Entity.h
 *
 *  Created on: 31 de jul de 2015
 *      Author: juan
 */

#ifndef CORE_OBJECTS_HEADERS_ENTITY_H_
#define CORE_OBJECTS_HEADERS_ENTITY_H_

#include "../types/headers/Drawable.h"
#include "../types/headers/Tangible.h"
#include "../types/headers/Updateable.h"

class Entity: public Drawable, public Tangible, public Updateable {
public:
	Entity(Position* p, Image* image, Shape* shape, Ambient* ambient);
	virtual ~Entity();
};

#endif /* CORE_OBJECTS_HEADERS_ENTITY_H_ */
