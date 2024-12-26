#pragma once
#include "Piece.h"

class Rook : Piece
{
public:
	Rook(Point startIndex, char color);
	~Rook();

	virtual bool move(char color, Piece* board[][8]) override;
	virtual bool eat(char color, Piece* board[][8]) override;
	virtual bool inTheWay(char color, Piece* board[][8]) override;



};
