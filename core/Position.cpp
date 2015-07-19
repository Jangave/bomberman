/*
 * Position.cpp
 *
 *  Created on: 18/07/2015
 *      Author: juan
 */

#include "headers/Position.h"

Position::~Position() {

}

int Position::getX() const {
	return x;
}

void Position::setX(int x) {
	this->x = x;
}

int Position::getY() const {
	return y;
}

void Position::setY(int y) {
	this->y = y;
}

Position::Position(int xp, int yp) {
	x = xp;
	y = yp;
}

void Position::move(int xp, int yp) {
	x += xp;
	y += yp;
}

void Position::set(int xp, int yp) {
	x = xp;
	y = yp;
}

Position::Position() {
	x = 0;
	y = 0;
}
