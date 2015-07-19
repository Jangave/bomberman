/*
 * Map.h
 *
 *  Created on: 19/07/2015
 *      Author: juan
 */

#ifndef MAP_H_
#define MAP_H_

class Map {
public:
	Map();
	Map(int sizeX, int sizeY);
	Map(int sizeX, int sizeY, int sizeViewX, int sizeViewY);
	Map(int sizeX, int sizeY, int sizeViewX, int sizeViewY, int viewX, int viewY);
	virtual ~Map();

	void moveView(int x, int y);
	
	int getSizeViewX() const;
	void setSizeViewX(int sizeViewX);
	int getSizeViewY() const;
	void setSizeViewY(int sizeViewY);
	int getSizeX() const;
	void setSizeX(int sizeX);
	int getSizeY() const;
	void setSizeY(int sizeY);
	int getViewX() const;
	void setViewX(int viewX);
	int getViewY() const;
	void setViewY(int viewY);

private:
	int sizeX, sizeY;
	int sizeViewX, sizeViewY;
	int viewX, viewY;
	
};

#endif /* MAP_H_ */
