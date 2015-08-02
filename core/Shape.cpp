/*
 * Shape.cpp
 *
 *  Created on: 30 de jul de 2015
 *      Author: juan
 */

#include "headers/Shape.h"

Shape::Shape(int sizeX, int sizeY) {
	this->sizeX = sizeX;
	this->sizeY = sizeY;
	deformX = 0;
	deformY = 0;
}

Shape::~Shape() {
}

int Shape::getDeformX() const {
	return deformX;
}

void Shape::setDeformX(int deformX) {
	this->deformX = deformX;
}

int Shape::getDeformY() const {
	return deformY;
}

void Shape::setDeformY(int deformY) {
	this->deformY = deformY;
}

int Shape::getSizeX() const {
	return sizeX;
}

void Shape::setSizeX(int sizeX) {
	this->sizeX = sizeX;
}

int Shape::getSizeY() const {
	return sizeY;
}

void Shape::setSizeY(int sizeY) {
	this->sizeY = sizeY;
}

int Shape::getDeformedSizeX() {
	if(deformX > 0)
		return sizeX + deformX;
	else
		return sizeX;
}

int Shape::getDeformedSizeY() {
	if(deformY > 0)
		return sizeY + deformY;
	else
		return sizeY;
}

void Shape::addDeformX(int x) {
	deformX += x;
}

void Shape::addDeformY(int y) {
	deformY += y;
}

int Shape::getNegativeDeformX() {
	if(deformX < 0)
		return deformX;
	else
		return 0;
}

int Shape::getNegativeDeformY() {
	if(deformY < 0)
		return deformY;
	else
		return 0;
}

Shape::Shape() {
	sizeX = 0;
	sizeY = 0;
	deformX = 0;
	deformY = 0;
}
