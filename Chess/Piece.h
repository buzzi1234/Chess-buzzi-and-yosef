#pragma once

#include <iostream>
#include <string>
#include "Point.h"

class Piece {
private:
	Point _startIndex;
	Point _endIndex;
	char _color;
public:
	
	virtual bool move(char color, Piece* board[][8]) = 0;
	virtual bool eat(char color, Piece* board[][8]) = 0;
	virtual bool inTheWay(char color, Piece* board[][8]) = 0;
	Point getStartIndex() const;
	Point getEndIndex() const;
	char getColor() const;
	
	void setStartIndex(Point startIndex);
	void setEndIndex(Point endIndex);
	void setColor(char color);

};