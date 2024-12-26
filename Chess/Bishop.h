#pragma once
#include "Piece.h"
class Bishop : public Piece
{
public:
	Bishop(int startIndex, char color);
	~Bishop();

	virtual bool move() override;
	virtual bool eat() override;
	virtual bool inTheWay() override;
};

