#pragma once
#include <iostream>

class Point {
private:
	int _row;
	int _col;
public:
	Point(int row, int col);
	~Point();
	int getRow() const;
	int getCol() const;

	void setRow(int row);
	void setCol(int col);
	Point operator=(Point& p);

};
