/*
 * Node.h
 *
 *  Created on: 31 de jul de 2015
 *      Author: juan
 */

#ifndef CORE_HEADERS_NODE_H_
#define CORE_HEADERS_NODE_H_

#include "Position.h"
#include "../Types.h"

class Node {
public:
	Node();
	Node(Position* p);
	~Node();

	Position*& getPosition();
	void setPosition(Position*& position);

	int type;
protected:
	Position* position;


};

#endif /* CORE_HEADERS_NODE_H_ */
