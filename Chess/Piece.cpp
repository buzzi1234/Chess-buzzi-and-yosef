#include "Piece.h"
//getters
int Piece::getStartIndex()
{
	return _startIndex;
}
int Piece::getEndIndex()
{
	return _endIndex;
}
char Piece::getColor()
{
	return _color;
}

//setters
void Piece::setStartIndex(int startIndex)
{
	_startIndex = startIndex;
}
void Piece::setEndIndex(int endIndex)
{
	_endIndex = endIndex;
}
void Piece::setColor(char color)
{
	_color = color;
}