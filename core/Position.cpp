/*
 * Position.cpp
 *
 *  Created on: 18/07/2015
 *      Author: juan
 */

#include "headers/Position.h"

Position::~Position() {

}

float Position::getX() const {
	return x;
}

void Position::setX(float x) {
	this->x = x;
}

float Position::getY() const {
	return y;
}

void Position::setY(float y) {
	this->y = y;
}

Position::Position(float xp, float yp) {
	x = xp;
	y = yp;
}

void Position::move(float xp, float yp) {
	x += xp;
	y += yp;
}

void Position::set(float xp, float yp) {
	x = xp;
	y = yp;
}

Position::Position() {
	x = 0;
	y = 0;
}
