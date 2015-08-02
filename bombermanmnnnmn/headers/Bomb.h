/*
 * Bomb.h
 *
 *  Created on: 1 de ago de 2015
 *      Author: juan
 */

#ifndef BOMBERMANMNNNMN_HEADERS_BOMB_H_
#define BOMBERMANMNNNMN_HEADERS_BOMB_H_

#include "../../core/objects/headers/Entity.h"

#include "Character.h"

class Bomb: public Entity {
public:
	Bomb(Position* p, int power, Ambient* ambient, Character* owner);
	virtual ~Bomb();

	void update();
	void onCollide(Tangible* other);

protected:
	Character* owner;

	double initTime;

	int power;
};

#endif /* BOMBERMANMNNNMN_HEADERS_BOMB_H_ */
