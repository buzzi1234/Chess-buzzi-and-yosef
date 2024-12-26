#include "Piece.h"
Piece::Piece()
{
	Point _startIndex();
	Point _endIndex();
	setColor('#');
}

Piece::~Piece()
{
	delete& this->_startIndex;
	delete& this->_endIndex;
	setColor('\0');
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

//setters
void Piece::setStartIndex(Point startIndex)
{
	_startIndex = startIndex;
}
void Piece::setEndIndex(Point endIndex)
{
	_endIndex = endIndex;
}
void Piece::setColor(char color)
{
	_color = color;
}