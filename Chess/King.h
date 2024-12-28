#pragma once
#include "Piece.h"

#define BOARD_LEN 8
#define WHITE_KING 'w'
#define BLACK_KING 'b'
#define NONE_KING '#'
#define DIF_ROW 1
#define DIF_COL 1


class King : Piece
{
public:
	King(Point startIndex, char color);
	~King();

	virtual bool move(char color, Piece* board[][BOARD_LEN]) override;
	virtual bool inTheWay(char color, Piece* board[][BOARD_LEN]) override;

	bool check(char color, Piece* board[][BOARD_LEN]);
	bool checkMate(char color, Piece* board[][BOARD_LEN]);
};

