#pragma once

#include <iostream>
#include <string>

class Piece {
private:
	std::string _startIndex;
	std::string _endIndex;
	char _color;
public:
	virtual bool move() = 0;
	virtual bool eat() = 0;
	virtual bool inTheWay() = 0;
	std::string getStartIndex();
	std::string getEndIndex();
	char getColor();
	
	void setStartIndex(std::string startIndex);
	void setEndIndex(std::string endIndex);
	void setColor(char color);

};