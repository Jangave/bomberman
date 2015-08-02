/*
 * Fire.h
 *
 *  Created on: 2 de ago de 2015
 *      Author: juan
 */

#ifndef BOMBERMANMNNNMN_HEADERS_FIRE_H_
#define BOMBERMANMNNNMN_HEADERS_FIRE_H_

#include "../../core/objects/headers/Entity.h"

class Fire : public Entity {
public:
	Fire(Position* p, Ambient* ambient);
	virtual ~Fire();

	void update();
	void onCollide();

protected:
	double initTime;
};

#endif /* BOMBERMANMNNNMN_HEADERS_FIRE_H_ */
