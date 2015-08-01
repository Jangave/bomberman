/*
 * Map.cpp
 *
 *  Created on: 19/07/2015
 *      Author: juan
 */

#include "headers/Map.h"

#include <iostream>

#include "headers/Image.h"
#include "headers/Position.h"

Map::~Map() {
	// TODO Auto-generated destructor stub
}

int Map::getSizeViewX() const {
	return sizeViewX;
}

void Map::setSizeViewX(int sizeViewX) {
	this->sizeViewX = sizeViewX;
}

int Map::getSizeViewY() const {
	return sizeViewY;
}

void Map::setSizeViewY(int sizeViewY) {
	this->sizeViewY = sizeViewY;
}

int Map::getSizeX() const {
	return sizeX;
}

void Map::setSizeX(int sizeX) {
	this->sizeX = sizeX;
}

int Map::getSizeY() const {
	return sizeY;
}

void Map::setSizeY(int sizeY) {
	this->sizeY = sizeY;
}

int Map::getViewX() const {
	return viewX;
}

void Map::setViewX(int viewX) {
	this->viewX = viewX;
}

int Map::getViewY() const {
	return viewY;
}

int Map::getViewPxY() {
	return viewY * unit;
}

int Map::getViewPxX() {
	return viewX * unit;
}

Map::Map(int sizeX, int sizeY, int unit) {
	this->sizeX = sizeX;
	this->sizeY = sizeY;
	this->sizeViewX = sizeX;
	this->sizeViewY = sizeY;
	this->viewX = 0;
	this->viewY = 0;
	this->unit = unit;
}

Map::Map(int sizeX, int sizeY, int sizeViewX, int sizeViewY, int unit) {
	this->sizeX = sizeX;
	this->sizeY = sizeY;
	this->sizeViewX = sizeViewX;
	this->sizeViewY = sizeViewY;
	this->viewX = 0;
	this->viewY = 0;
	this->unit = unit;
}

Map::Map(int sizeX, int sizeY, int sizeViewX, int sizeViewY, int viewX, int viewY, int unit) {
	this->sizeX = sizeX;
	this->sizeY = sizeY;
	this->sizeViewX = sizeViewX;
	this->sizeViewY = sizeViewY;
	this->viewX = viewX;
	this->viewY = viewY;
	this->unit = unit;
}

void Map::moveView(int x, int y) {
	this->viewX += x;
	this->viewY += y;
}

void Map::setViewY(int viewY) {
	this->viewY = viewY;
}

int Map::getSizePxX() {
	return sizeX * unit;
}

int Map::getSizePxY() {
	return sizeY * unit;
}

bool Map::isInView(Drawable* d) {
	return ( (d->getPosition()->getX() + d->getImage()->getWidth()  > viewX*unit) && (d->getPosition()->getX() < viewX*unit + sizeViewX*unit) ) &&
		   ( (d->getPosition()->getY() + d->getImage()->getHeight() > viewY*unit) && (d->getPosition()->getY() < viewY*unit + sizeViewY*unit) );
}

int Map::getUnit() const {
	return unit;
}

void Map::setUnit(int unidade) {
	this->unit = unidade;
}
