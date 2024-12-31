#include "King.h"


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

	int row = getStartIndex().getRow();
	int col = getStartIndex().getCol();
	setEndIndex(getStartIndex());
	if (check(color, board))
	{
		getStartIndex().setRow(row);
		getStartIndex().setCol(col);
		return false;
	}

	if (getStartIndex().getRow() == getEndIndex().getRow() || getStartIndex().getRow() + DIF_ROW == getEndIndex().getRow() || getStartIndex().getRow() - DIF_ROW == getEndIndex().getRow())
	{
		if (getStartIndex().getCol() + DIF_COL == getEndIndex().getCol())
		{
			return inTheWay(color, board);
		}

		if (getStartIndex().getCol() - DIF_COL == getEndIndex().getCol())
		{
			return inTheWay(color, board);
		}
	}

	if (getStartIndex().getCol() == getEndIndex().getCol())
	{
		if (getStartIndex().getRow() + DIF_ROW == getEndIndex().getRow())
		{
			return inTheWay(color, board);
		}

		if (getStartIndex().getRow() - DIF_ROW == getEndIndex().getRow())
		{
			return inTheWay(color, board);
		}
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
	if (board[getEndIndex().getRow()][getEndIndex().getCol()]->getColor() == NONE_KING)
	{
		if (board[getEndIndex().getRow()][getEndIndex().getCol()]->getColor() == color)
		{
			return true;
		}
	}
	return false;
}

/*
* EMPTY FUNC BECAUSE WE DONT NEED EAT HERE
*/
bool King::eat(char color, Piece* board[][BOARD_LEN])
{

}


bool King::checkMate(char color, Piece* board[][BOARD_LEN])
{

}
