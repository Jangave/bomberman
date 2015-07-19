/*
 * Object.h
 *
 *  Created on: 18/07/2015
 *      Author: juan
 */

#ifndef OBJECT_H_
#define OBJECT_H_

#include "Image.h"
#include "Position.h"

class Ambient;

class Object {
public:
	Object(Position p, Image i);
	Object(Position p, Image i, Ambient* a);
	virtual ~Object();

	const Image& getImage() const;
	void setImage(Image image);
	const Position& getPosition() const;
	void setPosition(Position& position);
	void setPosition(int x, int y);
	const Ambient* getAmbient() const;
	void setAmbient(Ambient* ambient);

	void update();

private:
	Image image;
	Position position;

	Ambient* ambient;
};

#endif /* OBJECT_H_ */
