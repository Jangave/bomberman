/*
 * Tangible.h
 *
 *  Created on: 30 de jul de 2015
 *      Author: juan
 */

#ifndef CORE_OBJECTS_HEADERS_TANGIBLE_H_
#define CORE_OBJECTS_HEADERS_TANGIBLE_H_


#include "../../../headers/Node.h"

class Shape;

class Tangible : virtual public Node{
public:
	Tangible(Shape* shape);
	Tangible(Shape* shape, Position* position);

	~Tangible();

	bool isColliding(Tangible* other);

	void onCollide(Tangible* other);

	Shape*& getShape();
	void setShape(Shape*& shape);

protected:
	Shape* shape;
};

#endif /* CORE_OBJECTS_HEADERS_TANGIBLE_H_ */
