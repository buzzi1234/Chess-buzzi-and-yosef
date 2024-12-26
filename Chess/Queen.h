#pragma once
#include "Piece.h"
class Queen : public Piece
{
public:
	Queen(int startIndex, char color);
	~Queen();

	virtual bool move() override;
	virtual bool eat() override;
	virtual bool inTheWay() override;
};

