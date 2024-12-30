#include "Rook.h"

//constructor
Rook::Rook(Point startIndex, char color) :
	Piece()
{
	setStartIndex(startIndex);
	setEndIndex(startIndex);
	setColor(color);
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
	if (inTheWay(color, board))
	{
		switch (getColor())
		{ 
			case BLACK_ROOK:
				return eat(WHITE_ROOK, board);
				break;

			case WHITE_ROOK:
				return eat(BLACK_ROOK, board);
			default:
				return eat(NONE_ROOK, board);
		}
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
	if (getStartIndex().getRow() == getEndIndex().getRow() && getStartIndex().getCol() != getEndIndex().getCol())
	{
		if (board[getStartIndex().getRow()][getEndIndex().getCol()]->getColor() == color)
		{
			return true;
		}
	}
	else if (getStartIndex().getRow() != getEndIndex().getRow() && getStartIndex().getCol() == getEndIndex().getCol())
	{
		if (board[getEndIndex().getRow()][getStartIndex().getCol()]->getColor() == color)
		{
			return true;
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
bool Rook::inTheWay(char color, Piece* board[][BOARD_LEN])
{
	if (getStartIndex().getRow() == getEndIndex().getRow() && getStartIndex().getCol() != getEndIndex().getCol())
	{
		if (getStartIndex().getCol() > getEndIndex().getCol())
		{
			for (int col = getStartIndex().getCol() - HELP_NUM; col > getEndIndex().getCol(); col--)
			{
				if (board[getStartIndex().getRow()][col]->getColor() == color)
				{
					return false;
				}
			}
			return true;
		}

		else if (getStartIndex().getCol() < getEndIndex().getCol())
		{
			for (int col = getStartIndex().getCol() + HELP_NUM; col < getEndIndex().getCol(); col++)
			{
				if (board[getStartIndex().getRow()][col]->getColor() == color)
				{
					return false;
				}
			}
			return true;
		}

	}
	else if (getStartIndex().getRow() != getEndIndex().getRow() && getStartIndex().getCol() == getEndIndex().getCol())
	{
		if (getStartIndex().getRow() > getEndIndex().getRow())
		{
			for (int row = getStartIndex().getRow() - HELP_NUM; row > getEndIndex().getRow(); row--)
			{
				if (board[row][getStartIndex().getCol()]->getColor() == color)
				{
					return false;
				}
			}
			return true;
		}

		if (getStartIndex().getRow() < getEndIndex().getRow())
		{
			for (int row = getStartIndex().getRow() + HELP_NUM; row < getEndIndex().getRow(); row++)
			{
				if (board[row][getStartIndex().getCol()]->getColor() == color)
				{
					return false;
				}
			}
			return true;
		}
	}
	return false;
}