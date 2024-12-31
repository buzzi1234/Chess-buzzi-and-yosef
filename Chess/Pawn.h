#pragma once
#include "Piece.h"
#define WHITE_PAWN 'W'
#define BLACK_PAWN 'B'
#define BOARD_LEN 8
#define HELP_NUM 1
#define ROW_NUM_BLACK 6
#define ROW_NUM_WHITE 1
#define DOUBLE_JUMP_PAWN 2
#define EMPTY_INDEX -1

class Pawn : public Piece
{
private:
	int _jumps;
public:
	Pawn(Point startIndex, char color, char type);
	~Pawn();

	virtual bool move(char color, Piece* board[][BOARD_LEN]) override;
	virtual bool eat(char color, Piece* board[][BOARD_LEN]) override;
	//bool turnQueen();
	bool firstMove(char color, Piece* board[][BOARD_LEN]);
	virtual bool inTheWay(char color, Piece* board[][BOARD_LEN]) override;
};

