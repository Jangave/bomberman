/*
 * Drawable.cpp
 *
 *  Created on: 30 de jul de 2015
 *      Author: juan
 */

#include "headers/Drawable.h"

#include "../../headers/Position.h"

Image*& Drawable::getImage() {
	return image;
}

Drawable::~Drawable() {
	delete image;
}

void Drawable::setImage(Image*& image) {
	this->image = image;
}

Drawable::Drawable(Image* image) : Node(){
	this->image = image;
	type *= DRAWABLE;
}

Drawable::Drawable(Image* image, Position* p) : Node(p){
	this->image = image;
	type *= DRAWABLE;
}

void Drawable::draw() {
	image->draw(position);
}
