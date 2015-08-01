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
	Position(int xp, int yp);
	virtual ~Position();

	void move(int xp, int yp);
	void set(int xp, int yp);

	int getX() const;
	void setX(int x);
	int getY() const;
	void setY(int y);

protected:
	int x;
	int y;

};

#endif /* POSITION_H_ */
