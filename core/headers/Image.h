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
	Image(int w, int h);
	Image(int w, int h, float* c);
	Image(int w, int h, float r, float g, float b);
	virtual ~Image();

	void draw();
	void draw(Position* p);

	int getHeight() const;
	void setHeight(int height);
	int getWidth() const;
	void setWidth(int width);
	const float* getColor() const;
	const float getColor(int i) const;
	void setColor(float r, float g, float b);


protected:
	int width;
	int height;

	float color[3];

};

#endif /* IMAGE_H_ */
