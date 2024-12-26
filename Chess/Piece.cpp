#include "Piece.h"

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