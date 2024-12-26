#pragma once

#include <iostream>
#include <string>

class Piece {
private:
	int _startIndex;
	int _endIndex;
	char _color;
public:
	virtual bool move() = 0;
	virtual bool eat() = 0;
	virtual bool inTheWay(char color, Piece* board[][8]) = 0;
	int getStartIndex();
	int getEndIndex();
	char getColor();
	
	void setStartIndex(int startIndex);
	void setEndIndex(int endIndex);
	void setColor(char color);

};