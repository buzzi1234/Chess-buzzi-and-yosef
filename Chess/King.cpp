#include "King.h"
#include <cmath>

//constructor
King::King(Point startIndex, char color, char type) :
	Piece()
{
	setStartIndex(startIndex);
	setEndIndex(startIndex);
	setColor(color);
	setType(type);
}

//destructor
King::~King()
{
	Piece::~Piece();
}


/*
* The func check if move to the given index is valid
* input: color - the kind of pieces we are looking for
*		 board - the board of the game
* output: true if the the move is valid false if not
*/
bool King::move(char color, Piece* board[][BOARD_LEN])
{
	if (abs(getStartIndex().getRow() - getEndIndex().getRow()) <= DIF_ROW && abs(getStartIndex().getCol() - getEndIndex().getCol()) <= DIF_COL)
	{
		return inTheWay(color, board);
	}
	return false;
}

/*
* The func checkes if there is pieces in the way of the current piece
* input: color - the kind of pieces we are looking for
*		 board - the board of the game
* output: true if the the move is valid false if not
*/
bool King::inTheWay(char color, Piece* board[][BOARD_LEN])
{
	if (board[getEndIndex().getRow()][getEndIndex().getCol()]->getColor() == NONE_KING || board[getEndIndex().getRow()][getEndIndex().getCol()]->getColor() != color)
	{
		return true;
	}
	return false;
}

/*
* EMPTY FUNC BECAUSE WE DONT NEED EAT HERE
*/
bool King::eat(char color, Piece* board[][BOARD_LEN])
{
	return true;
}


bool King::checkMate(char color, Piece* board[][BOARD_LEN])
{
	return false;
}
