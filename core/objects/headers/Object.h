/*
 * Object.h
 *
 *  Created on: 31 de jul de 2015
 *      Author: juan
 */

#ifndef CORE_OBJECTS_HEADERS_OBJECT_H_
#define CORE_OBJECTS_HEADERS_OBJECT_H_

#include "../types/headers/Drawable.h"
#include "../types/headers/Tangible.h"

class Object: public Tangible, public Drawable {
public:
	Object(Position* position, Image* image, Shape* shape);
	virtual ~Object();
};

#endif /* CORE_OBJECTS_HEADERS_OBJECT_H_ */
