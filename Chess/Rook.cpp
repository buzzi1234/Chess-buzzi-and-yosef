#include "Rook.h"

//constructor
Rook::Rook(int startIndex, char color)
{
	setStartIndex(startIndex);
	setEndIndex(startIndex);
	setColor(color);
}

//destructor
Rook::~Rook()
{
	setStartIndex(0);
	setEndIndex(0);
	setColor('\0');
}

bool Rook::move()
{

}
bool Rook::eat()
{

}

/*
* The func checkes if there is pieces in the way of the current piece
* input: color - the kind of pieces we are looking for
*		 board - the board of the game
*		 row - the width of the board
*		 col - the height of the board
* output: true if the the move is valid false if not
*/
bool Rook::inTheWay(char color, Piece* board[][8])
{
	if (getStartIndex() / 10 == getEndIndex() / 10 && getStartIndex() % 10 != getEndIndex() % 10)
	{
		if (getStartIndex() % 10 > getEndIndex() % 10)
		{
			for (int col = (getStartIndex() % 10)- 1; col >= getEndIndex() % 10; col--)
			{
				if (board[getStartIndex() / 10][col]->getColor() == color)
				{
					return false;
				}
			}
			return true;
		}
		
		if (getStartIndex() % 10 < getEndIndex() % 10)
		{
			for (int col = (getStartIndex() % 10) + 1; col <= getEndIndex() % 10; col++)
			{
				if (board[getStartIndex() / 10][col]->getColor() == color)
				{
					return false;
				}
			}
			return true;
		}

		else
		{
			return false;
		}
	}
	else if (getStartIndex() / 10 != getEndIndex() / 10 && getStartIndex() % 10 == getEndIndex() % 10)
	{
		if (getStartIndex() / 10 > getEndIndex() / 10)
		{
			for (int col = (getStartIndex() / 10) - 1; col >= getEndIndex() / 10; col--)
			{
				if (board[col][getStartIndex() % 10]->getColor() == color)
				{
					return false;
				}
			}
			return true;
		}

		if (getStartIndex() / 10 < getEndIndex() / 10)
		{
			for (int col = (getStartIndex() / 10) + 1; col <= getEndIndex() / 10; col++)
			{
				if (board[col][getStartIndex() % 10]->getColor() == color)
				{
					return false;
				}
			}
			return true;
		}

		else
		{
			return false;
		}
	
	return false;
	
}