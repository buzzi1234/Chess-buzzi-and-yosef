#pragma once
#include "Piece.h"

#define BOARD_LEN 8
#define HELP_NUM 1
#define HELP_NUM_DOUBLE 2


class Knight : public Piece
{
public:
	Knight(Point startIndex, char color, char type);
	~Knight();

	virtual bool move(char color, Piece* board[][BOARD_LEN]) override;
	virtual bool eat(char color, Piece* board[][BOARD_LEN]) override;
	virtual bool inTheWay(char color, Piece* board[][BOARD_LEN]) override;
};