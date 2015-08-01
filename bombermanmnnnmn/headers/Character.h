/*
 * Character.h
 *
 *  Created on: 31 de jul de 2015
 *      Author: juan
 */

#ifndef BOMBERMANMNNNMN_HEADERS_CHARACTER_H_
#define BOMBERMANMNNNMN_HEADERS_CHARACTER_H_

#include "../../core/objects/headers/Entity.h"

class Character : public Entity {
public:
	Character(Position* p, Image* image, Shape* shape, Ambient* ambient);
	virtual ~Character();

	void update();
	void onCollide(Tangible* other);

	int speed;
};

#endif /* BOMBERMANMNNNMN_HEADERS_CHARACTER_H_ */
