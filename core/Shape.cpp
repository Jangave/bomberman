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

int Shape::getSizeDeformedX() {
	return sizeX + deformX;
}

int Shape::getSizeDeformedY() {
	return sizeY + deformY;
}
