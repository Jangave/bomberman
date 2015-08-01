/*
 * Bomberman.h
 *
 *  Created on: 31 de jul de 2015
 *      Author: juan
 */

#ifndef BOMBERMANMNNNMN_HEADERS_BOMBERMAN_H_
#define BOMBERMANMNNNMN_HEADERS_BOMBERMAN_H_

class Ambient;
class Window;

class Bomberman {
public:
	Bomberman();
	virtual ~Bomberman();

	int execute();

	Window* window;
	Ambient* ambient;

};

#endif /* BOMBERMANMNNNMN_HEADERS_BOMBERMAN_H_ */
