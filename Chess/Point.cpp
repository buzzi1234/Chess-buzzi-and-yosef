#include "Point.h"
//constructor
Point::Point(int row, int col)
{
	setRow(row);
	setCol(col);
}
Point::Point()
{
	setRow(0);
	setCol(0);
}
//sestructor
Point::~Point()
{
	setRow(0);
	setCol(0);
}
//getters
int Point::getRow() const
{
	return _row;
}
int Point::getCol() const 
{
	return _col;
}
//setters
void Point::setRow(int row)
{
	_row = row;
}
void Point::setCol(int col)
{
	_col = col;
}

Point Point::operator=(Point& p)
{
	setRow(p.getRow());
	setCol(p.getCol());
}