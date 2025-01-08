#include "Queen.h"

//constructor
Queen::Queen(Point startIndex, char color, char type)
	: Piece()
{
	setStartIndex(startIndex);
	setEndIndex(startIndex);
	setColor(color);
	setType(type);

	_rook = new Rook(startIndex, color, ROOK_TYPE);
	_bishop = new Bishop(startIndex, color, BISHOP_TYPE);
}

//destructor
Queen::~Queen()
{
	delete _rook;
	delete _bishop;
}

/*
* The func check if move to the given index is valid
* input: color - the kind of pieces we are looking for
*		 board - the board of the game
* output: true if the the move is valid false if not
*/
bool Queen::move(char color, Piece* board[][BOARD_LEN])
{
	if (abs(getEndIndex().getRow() - getStartIndex().getRow()) == abs(getEndIndex().getCol() - getStartIndex().getCol()))
	{
		_bishop->setStartIndex(getStartIndex());
		_bishop->setEndIndex(getEndIndex());
		return _bishop->move(color, board);
	}
	else if (getStartIndex().getRow() == getEndIndex().getRow() || getStartIndex().getCol() == getEndIndex().getCol())
	{
		_rook->setStartIndex(getStartIndex());
		_rook->setEndIndex(getEndIndex());
		return _rook->move(color, board);
	}
	return false;
}

/*
* The func checks if there is a player in the endindex can be eated
input: color - the kind of pieces we are looking for
*	   board - the board of the game
* output: true if the the move is valid false if not
*/
bool Queen::eat(char color, Piece* board[][BOARD_LEN])
{
	if (abs(getEndIndex().getRow() - getStartIndex().getRow()) == abs(getEndIndex().getCol() - getStartIndex().getCol()))
	{
		_bishop->setStartIndex(getStartIndex());
		_bishop->setEndIndex(getEndIndex());
		return _bishop->eat(color, board);
	}
	else if (getStartIndex().getRow() == getEndIndex().getRow() || getStartIndex().getCol() == getEndIndex().getCol())
	{
		_rook->setStartIndex(getStartIndex());
		_rook->setEndIndex(getEndIndex());
		return _rook->eat(color, board);
	}

	return false;
}

/*
* The func checkes if there is pieces in the way of the current piece
* input: color - the kind of pieces we are looking for
*		 board - the board of the game
* output: true if the the move is valid false if not
*/
bool Queen::inTheWay(char color, Piece* board[][BOARD_LEN])
{
	if (abs(getEndIndex().getRow() - getStartIndex().getRow()) == abs(getEndIndex().getCol() - getStartIndex().getCol()))
	{
		_bishop->setStartIndex(getStartIndex());
		_bishop->setEndIndex(getEndIndex());
		return _bishop->inTheWay(color, board);
	}
	else if (getStartIndex().getRow() == getEndIndex().getRow() || getStartIndex().getCol() == getEndIndex().getCol())
	{
		_rook->setStartIndex(getStartIndex());
		_rook->setEndIndex(getEndIndex());
		return _rook->inTheWay(color, board);
	}
	return false;
}
