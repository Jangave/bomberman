/*
 * Ambient.h
 *
 *  Created on: 18/07/2015
 *      Author: juan
 */

#ifndef AMBIENT_H_
#define AMBIENT_H_

#include <vector>

#include "Object.h"

#include "Map.h"
#include "Window.h"


class Ambient {
public:
	Ambient();
	Ambient(Map* m, Window* w);
	virtual ~Ambient();

	void addObject(Object& o);

	const std::vector<Object>& getObject() const;
	void setObject(const std::vector<Object>& objects);

	void draw();
	void update();

	Window* window;
private:
	std::vector<Object> objects;
	Map* map;

};

#endif /* AMBIENT_H_ */
