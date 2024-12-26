#include "Piece.h"
//getters
std::string Piece::getStartIndex()
{
	return _startIndex;
}
std::string Piece::getEndIndex()
{
	return _endIndex;
}
char Piece::getColor()
{
	return _color;
}

//setters
void Piece::setStartIndex(std::string startIndex)
{
	_startIndex = startIndex;
}
void Piece::setEndIndex(std::string endIndex)
{
	_endIndex = endIndex;
}
void Piece::setColor(char color)
{
	_color = color;
}