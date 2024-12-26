#pragma once

#include <iostream>
#include <string>
#include "Point.h"

class Piece {
protected:
	Point _startIndex;
	Point _endIndex;
	char _color;
public:
	Piece(Point startIndex, char color);
	
	virtual bool move(char color, Piece* board[][8]) = 0;
	virtual bool eat(char color, Piece* board[][8]) = 0;
	virtual bool inTheWay(char color, Piece* board[][8]) = 0;
	virtual Point getStartIndex() const;
	virtual Point getEndIndex() const;
	virtual char getColor() const;
	
	virtual void setStartIndex(Point startIndex);
	virtual void setEndIndex(Point endIndex);
	virtual void setColor(char color);

};