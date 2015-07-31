/*
 * Bomb.h
 *
 *  Created on: 19/07/2015
 *      Author: juan
 */

#ifndef BOMB_H_
#define BOMB_H_

#include "../core/objects/headers/Object.h"

class Ambient;

class Bomb : public Object{
public:
	Bomb(int power, Position* p, Ambient* a);
	virtual ~Bomb();

	void update();

	double createTime;

	int power;
};

#endif /* BOMB_H_ */
