#pragma once
#include "Piece.h"
#include "Bishop.h"
#include "Rook.h"

#define BOARD_LEN 8
#define HELP_COLOR '#'
#define HELP_NUM 1
#define ROOK_TYPE 'r'
#define BISHOP_TYPE 'b'
#define BLACK 'B'
#define WHITE 'W'

class Queen : public Piece
{
private:
	Rook* _rook;
	Bishop* _bishop;
public:
	Queen(Point startIndex, char color, char type);
	~Queen();

	virtual bool move(char color, Piece* board[][BOARD_LEN]) override;
	virtual bool eat(char color, Piece* board[][BOARD_LEN]) override;
	virtual bool inTheWay(char color, Piece* board[][BOARD_LEN]) override;
};

