/*
 * Fire.h
 *
 *  Created on: 19/07/2015
 *      Author: juan
 */

#ifndef HEADERS_FIRE_H_
#define HEADERS_FIRE_H_

#include "../core/objects/headers/Object.h"

class Ambient;

class Fire : public Object{
public:
	Fire(bool isLast, bool isX, Position* p, Ambient* a);
	virtual ~Fire();

	void update();

	double createTime;
};

#endif /* HEADERS_FIRE_H_ */
