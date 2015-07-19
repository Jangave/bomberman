/*
 * Image.cpp
 *
 *  Created on: 18/07/2015
 *      Author: juan
 */

#include "headers/Image.h"

#include <GL/gl.h>
#include <iostream>

Image::Image() {
	width = 0;
	height = 0;
	for(int i = 0; i < 3; ++i)
		color[i] = 255;
}

Image::~Image() {
	// TODO Auto-generated destructor stub
}

const float* Image::getColor() const {
	return color;
}

int Image::getHeight() const {
	return height;
}

void Image::setHeight(int height) {
	this->height = height;
}

int Image::getWidth() const {
	return width;
}

void Image::setWidth(int width) {
	this->width = width;
}

Image::Image(int w, int h) {
	width = w;
	height = h;
	for(int i = 0; i < 3; ++i)
		color[i] = 255;
}

Image::Image(int w, int h, float* c) {
	width = w;
	height = h;
	for(int i = 0; i < 3; ++i)
		color[i] = c[i];
}

Image::Image(int w, int h, float r, float g, float b) {
	width = w;
	height = h;
	color[0] = r;
	color[1] = g;
	color[2] = b;
}

void Image::draw() {
}

void Image::draw(const Position& p) {
	glPushMatrix();
		glTranslatef(p.getX(), p.getY(), 0);
		glColor3f(color[0], color[1], color[2]);
		glBegin(GL_POLYGON);
			glVertex2i(0, 0);
			glVertex2i(width, 0);
			glVertex2i(width, height);
			glVertex2i(0, height);
		glEnd();
	glPopMatrix();
	std::cout << "draw" << std::endl;
}

const float Image::getColor(int i) const {
	return color[i];
}

void Image::setColor(float r, float g, float b) {
	color[0] = r;
	color[1] = g;
	color[2] = b;
}
