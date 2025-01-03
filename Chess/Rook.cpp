#include "Rook.h"

//constructor
Rook::Rook(Point startIndex, char color, char type) :
	Piece()
{
	setStartIndex(startIndex);
	setEndIndex(startIndex);
	setColor(color);
	setType(type);
}

//destructor
Rook::~Rook()
{
	Piece::~Piece();
}

/*
* The func check if move to the given index is valid
* input: color - the kind of pieces we are looking for
*		 board - the board of the game
* output: true if the the move is valid false if not
*/
bool Rook::move(char color, Piece* board[][BOARD_LEN])
{
	if (inTheWay(getColor(), board))
	{
		return true;
	}
	return false;
}

/*
* The func checks if there is a player in the endindex can be eated
input: color - the kind of pieces we are looking for
*	   board - the board of the game
* output: true if the the move is valid false if not
*/
bool Rook::eat(char color, Piece* board[][BOARD_LEN])
{
	if (board[getEndIndex().getRow()][getEndIndex().getCol()]->getColor() != color)
	{
		return true;
	}
	return false;
}

/*
* The func checkes if there is pieces in the way of the current piece
* input: color - the kind of pieces we are looking for
*		 board - the board of the game
* output: true if the the move is valid false if not
*/
bool Rook::inTheWay(char color, Piece* board[][BOARD_LEN])
{
	if (getStartIndex().getRow() == getEndIndex().getRow() || getStartIndex().getCol() == getEndIndex().getCol())
	{
		return eat(color, board);
	}
	return false;
}