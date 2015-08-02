/*
 * Node.cpp
 *
 *  Created on: 31 de jul de 2015
 *      Author: juan
 */

#include "headers/Node.h"

Node::Node(){
	position = 0;
	type = 1;
}

Node::Node(Position* p) {
	position = p;
	type = 1;
}

Node::~Node(){
	delete position;
}

Position*& Node::getPosition() {
	return position;
}

void Node::setPosition(Position*& position) {
	this->position = position;
}
