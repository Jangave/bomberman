/*
 * Tangible.h
 *
 *  Created on: 30 de jul de 2015
 *      Author: juan
 */

#ifndef CORE_OBJECTS_HEADERS_TANGIBLE_H_
#define CORE_OBJECTS_HEADERS_TANGIBLE_H_


#include "../../../headers/Node.h"

#include "../../../headers/Shape.h"

class Tangible : virtual public Node{
public:
	Tangible(Shape* shape);
	Tangible(Shape* shape, Position* position);

	~Tangible();

	bool isColliding(Tangible* other);
	virtual void onCollide(Tangible* other);
	Shape intersectionSize(Tangible* other);
	int intersectionSizeX(Tangible* other);
	int intersectionSizeY(Tangible* other);

	int dX();//deformedX
	int dY();//deformedY
	int dX2();//X + deformed sizeX
	int dY2();//Y + deformed sizeY

	Shape*& getShape();
	void setShape(Shape*& shape);

protected:
	Shape* shape;
};

#endif /* CORE_OBJECTS_HEADERS_TANGIBLE_H_ */
