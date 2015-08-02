/*
 * Character.h
 *
 *  Created on: 31 de jul de 2015
 *      Author: juan
 */

#ifndef BOMBERMANMNNNMN_HEADERS_CHARACTER_H_
#define BOMBERMANMNNNMN_HEADERS_CHARACTER_H_

#include "../../core/objects/headers/Entity.h"

class Bomb;

class Character : public Entity {
public:
	Character(Position* p, Image* image, Shape* shape, Ambient* ambient);
	virtual ~Character();

	void update();
	void onCollide(Tangible* other);
	int getPlantedBombs() const;
	void setPlantedBombs(int plantedBombs);

protected:

	int speed;
	int nbombs;
	int fireSize;

	Bomb* bombBelow;

	//std::vector<Bomb*> bombs;
	int plantedBombs;

	void plantBomb();

};

#endif /* BOMBERMANMNNNMN_HEADERS_CHARACTER_H_ */
