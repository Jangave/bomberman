/*
 * Position.h
 *
 *  Created on: 18/07/2015
 *      Author: juan
 */

#ifndef POSITION_H_
#define POSITION_H_

class Position {
public:
	Position();
	Position(float xp, float yp);
	virtual ~Position();

	void move(float xp, float yp);
	void set(float xp, float yp);

	float getX() const;
	void setX(float x);
	float getY() const;
	void setY(float y);

private:
	float x;
	float y;

};

#endif /* POSITION_H_ */
