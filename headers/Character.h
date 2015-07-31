/*
 * Character.h
 *
 *  Created on: 19/07/2015
 *      Author: juan
 */

#ifndef CORE_CHARACTER_H_
#define CORE_CHARACTER_H_

#include "../core/entity/headers/Object.h"

class Ambient;

class Character: public Object {
public:
	//Character();
	//Character(Position p, Image i);
	Character(Position* p, Image* i, Ambient* a);
	virtual ~Character();

	void update();

	double lastMove;
};

#endif /* CORE_CHARACTER_H_ */
