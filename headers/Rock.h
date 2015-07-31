/*
 * Rock.h
 *
 *  Created on: 19/07/2015
 *      Author: juan
 */

#ifndef ROCK_H_
#define ROCK_H_

#include "../core/entity/headers/Object.h"

class Rock: public Object {
public:
	Rock(Position* p, Image* i, Ambient* a);
	virtual ~Rock();

	void update();
};

#endif /* ROCK_H_ */
