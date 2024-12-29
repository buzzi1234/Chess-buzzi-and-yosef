#pragma once
#include "Piece.h"

#define BOARD_LEN 8
#define HELP_COLOR '#'
#define HELP_NUM 1

class Queen : public Piece
{
private:
	char _bishopOrRook;
public:
	Queen(Point startIndex, char color);
	~Queen();

	virtual bool move(char color, Piece* board[][BOARD_LEN]) override;
	virtual bool eat(char color, Piece* board[][BOARD_LEN]) override;
	virtual bool inTheWay(char color, Piece* board[][BOARD_LEN]) override;
};

