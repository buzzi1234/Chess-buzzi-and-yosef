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
	_startIndex.setCol(startIndex.getCol());
	_startIndex.setRow(startIndex.getRow());
}
void Piece::setEndIndex(Point endIndex)
{
	_endIndex.setCol(endIndex.getCol());
	_endIndex.setRow(endIndex.getRow());
}
void Piece::setColor(char color)
{
	_color = color;
}

void Piece::setType(char type)
{
	_type = type;
}