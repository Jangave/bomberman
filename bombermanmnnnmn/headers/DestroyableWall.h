/*
 * DestroyableWall.h
 *
 *  Created on: 2 de ago de 2015
 *      Author: juan
 */

#ifndef BOMBERMANMNNNMN_HEADERS_DESTROYABLEWALL_H_
#define BOMBERMANMNNNMN_HEADERS_DESTROYABLEWALL_H_

#include "Wall.h"

class DestroyableWall: public Wall {
public:
	DestroyableWall(Position* position, Image* image, Shape* shape);
	virtual ~DestroyableWall();
};

#endif /* BOMBERMANMNNNMN_HEADERS_DESTROYABLEWALL_H_ */
