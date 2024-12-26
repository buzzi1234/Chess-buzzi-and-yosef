#pragma once
#include "Piece.h"
class Knight : public Piece
{
public:
	Knight(int startIndex, char color);
	~Knight();

	virtual bool move() override;
	virtual bool eat() override;
	virtual bool inTheWay() override;  
};