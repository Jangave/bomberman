/*
 * Updateable.h
 *
 *  Created on: 30 de jul de 2015
 *      Author: juan
 */

#ifndef CORE_ENTITY_HEADERS_UPDATEABLE_H_
#define CORE_ENTITY_HEADERS_UPDATEABLE_H_

#include "../../../headers/Node.h"

class Ambient;

class Updateable : virtual public Node {
public:
	Updateable(Ambient* ambient);
	Updateable(Ambient* ambient, Position* p);

	virtual void update() = 0;

	Ambient* getAmbient();
	void setAmbient(Ambient* ambient);

protected:
	Ambient* ambient;
};

#endif /* CORE_ENTITY_HEADERS_UPDATEABLE_H_ */
