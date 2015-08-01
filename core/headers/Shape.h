/*
 * Shape.h
 *
 *  Created on: 30 de jul de 2015
 *      Author: juan
 */

#ifndef CORE_ENTITY_HEADERS_SHAPE_H_
#define CORE_ENTITY_HEADERS_SHAPE_H_

class Shape {
public:
	Shape(int sizeX, int sizeY);
	virtual ~Shape();

	int getDeformX() const;
	void setDeformX(int deformX);
	int getDeformY() const;
	void setDeformY(int deformY);
	int getSizeX() const;
	void setSizeX(int sizeX);
	int getSizeY() const;
	void setSizeY(int sizeY);
	int getDeformedSizeX();
	int getDeformedSizeY();

	void addDeformX(int x);
	void addDeformY(int y);

	int getNegativeDeformX();
	int getNegativeDeformY();

protected:
	//std::vector<Position> vertices;

	int sizeX;
	int sizeY;

	int deformX;
	int deformY;

};

#endif /* CORE_ENTITY_HEADERS_SHAPE_H_ */
