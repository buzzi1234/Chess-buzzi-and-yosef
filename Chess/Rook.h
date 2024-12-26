#pragma once
#include "Piece.h"

class Rook : Piece
{
public:
	Rook(int startIndex, char color);
	~Rook();

	virtual bool move() override;
	virtual bool eat() override;
	virtual bool inTheWay(char color, Piece* board[][8]) override;

};
