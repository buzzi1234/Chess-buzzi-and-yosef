#pragma once
#include "Piece.h"
#define WHITE_ROOK 'w'
#define BLACK_ROOK 'b'
#define NONE_ROOK '#'
#define BOARD_LEN 8
#define HELP_NUM 1


class Rook : public Piece
{
public:
	Rook(Point startIndex, char color, char type);
	~Rook();

	virtual bool move(char color, Piece* board[][BOARD_LEN]) override;
	virtual bool eat(char color, Piece* board[][BOARD_LEN]) override;
	virtual bool inTheWay(char color, Piece* board[][BOARD_LEN]) override;



};
