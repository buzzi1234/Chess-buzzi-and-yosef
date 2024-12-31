#include "Piece.h"
//constructor
Piece::Piece()
{
	Point _startIndex();
	Point _endIndex();
	setColor('#');
}
//destructor
Piece::~Piece()
{
	delete& this->_startIndex;
	delete& this->_endIndex;
	setColor('\0');
	setType('\0');
}

//getters
Point Piece::getStartIndex() const
{
	return _startIndex;
}
Point Piece::getEndIndex() const
{
	return _endIndex;
}
char Piece::getColor() const
{
	return _color;
}

char Piece::getType() const
{
	return _type;
}

//setters
void Piece::setStartIndex(Point startIndex)
{
	delete& _startIndex;
	_startIndex = startIndex;
}
void Piece::setEndIndex(Point endIndex)
{
	delete& _endIndex;
	_endIndex = endIndex;
}
void Piece::setColor(char color)
{
	_color = color;
}

void Piece::setType(char type)
{
	_type = type;
}