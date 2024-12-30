#pragma once
#include "Piece.h"

#define BOARD_LEN 8
#define HELP_COLOR '#'

class Bishop : public Piece
{
public:
	Bishop(Point startIndex, char color, char type);
	~Bishop();

	virtual bool move(char color, Piece* board[][BOARD_LEN]) override;
	virtual bool eat(char color, Piece* board[][BOARD_LEN]) override;
	virtual bool inTheWay(char color, Piece* board[][BOARD_LEN]) override;
};

