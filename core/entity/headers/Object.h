/*
 * Object.h
 *
 *  Created on: 18/07/2015
 *      Author: juan
 */

#ifndef OBJECT_H_
#define OBJECT_H_

#include "../../headers/Image.h"
#include "../../headers/Position.h"

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
	void setPosition(float x, float y);
	const Ambient* getAmbient() const;
	void setAmbient(Ambient* ambient);

	virtual void update() = 0;
	//virtual void met() = 0;

protected:
	Image image;
	Position position;

	Ambient* ambient;
};

#endif /* OBJECT_H_ */
