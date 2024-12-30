#pragma once

#include <iostream>
#include <string>
#include "Point.h"

#define BOARD_LEN 8

class Piece {
protected:
	Point _startIndex;
	Point _endIndex;
	char _color;
	char _type;
public:
	Piece();
	~Piece();
	
	virtual bool move(char color, Piece* board[][BOARD_LEN]) = 0;
	virtual bool eat(char color, Piece* board[][BOARD_LEN]) = 0;
	virtual bool inTheWay(char color, Piece* board[][BOARD_LEN]) = 0;
	Point getStartIndex() const;
	Point getEndIndex() const;
	char getColor() const;
	char getType() const;
	
	void setStartIndex(Point startIndex);
	void setEndIndex(Point endIndex);
	void setColor(char color);
	void setType(char type);

};