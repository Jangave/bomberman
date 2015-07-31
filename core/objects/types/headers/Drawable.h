/*
 * Drawable.h
 *
 *  Created on: 30 de jul de 2015
 *      Author: juan
 */

#ifndef CORE_OBJECTS_HEADERS_DRAWABLE_H_
#define CORE_OBJECTS_HEADERS_DRAWABLE_H_

#include "../../../headers/Image.h"
#include "../../../headers/Node.h"

class Drawable : virtual public Node{
public:
	Drawable(Image* image);
	Drawable(Image* image, Position* p);
	~Drawable();

	void draw(){
		image->draw();
	}

	Image*& getImage();
	void setImage(Image*& image);

protected:
	Image* image;

};

#endif /* CORE_OBJECTS_HEADERS_DRAWABLE_H_ */
