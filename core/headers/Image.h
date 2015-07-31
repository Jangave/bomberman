/*
 * Image.h
 *
 *  Created on: 18/07/2015
 *      Author: juan
 */

#ifndef IMAGE_H_
#define IMAGE_H_

#include "Position.h"

class Image {
public:
	Image();
	Image(float w, float h);
	Image(float w, float h, float* c);
	Image(float w, float h, float r, float g, float b);
	virtual ~Image();

	void draw();
	void draw(const Position& p);

	float getHeight() const;
	void setHeight(float height);
	float getWidth() const;
	void setWidth(float width);
	const float* getColor() const;
	const float getColor(int i) const;
	void setColor(float r, float g, float b);


protected:
	float width;
	float height;

	float color[3];

};

#endif /* IMAGE_H_ */
