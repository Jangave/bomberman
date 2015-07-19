/*
 * Map.cpp
 *
 *  Created on: 19/07/2015
 *      Author: juan
 */

#include "headers/Map.h"

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

Map::Map(int sizeX, int sizeY) {
	this->sizeX = sizeX;
	this->sizeY = sizeY;
	this->sizeViewX = sizeX;
	this->sizeViewY = sizeY;
	this->viewX = 0;
	this->viewY = 0;
}

Map::Map(int sizeX, int sizeY, int sizeViewX, int sizeViewY) {
	this->sizeX = sizeX;
	this->sizeY = sizeY;
	this->sizeViewX = sizeViewX;
	this->sizeViewY = sizeViewY;
	this->viewX = 0;
	this->viewY = 0;
}

Map::Map(int sizeX, int sizeY, int sizeViewX, int sizeViewY, int viewX, int viewY) {
	this->sizeX = sizeX;
	this->sizeY = sizeY;
	this->sizeViewX = sizeViewX;
	this->sizeViewY = sizeViewY;
	this->viewX = viewX;
	this->viewY = viewY;
}

void Map::moveView(int x, int y) {
	this->viewX += x;
	this->viewY += y;
}

void Map::setViewY(int viewY) {
	this->viewY = viewY;
}
