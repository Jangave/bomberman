/*
 * Wall.h
 *
 *  Created on: 19/07/2015
 *      Author: juan
 */

#ifndef WALL_H_
#define WALL_H_

#include "../core/entity/headers/Object.h"

class Wall: public Object {
public:
	Wall();
	virtual ~Wall();

	void update();
};

#endif /* WALL_H_ */
