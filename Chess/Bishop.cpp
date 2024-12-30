#include "Bishop.h"
#include <cmath>

Bishop::Bishop(Point startIndex, char color, char type)
	: Piece()
{
	setStartIndex(startIndex);
	setColor(color);
	setEndIndex(startIndex);
	setType(type);
}

Bishop::~Bishop()
{
	Piece::~Piece();
}

/*
The function checks if Bishop's move is valid by
subtracting the initial and final row and subtracting the initial and final col and checks if they are equal.
input: color - The color of the player's turn; board - The board is playing.
output: Returns true or false if it is possible or not.
*/
bool Bishop::move(char color, Piece* board[][BOARD_LEN])
{
	if (abs(getEndIndex().getRow() - getStartIndex().getRow()) == abs(getEndIndex().getCol() - getStartIndex().getCol()))
	{
		return eat(color, board);
	}
	return false;
}

/*
The function checks if there is a player of the same color in his final position.
input: color - The color of the player's turn; board - The board is playing.
output: Returns true or false if it is possible or not.
*/
bool Bishop::eat(char color, Piece* board[][BOARD_LEN])
{
	if (board[getEndIndex().getRow()][getEndIndex().getCol()]->getColor() == color)
	{
		return false;
	}
	return inTheWay(color, board);
}

/*
The function checks if there is a player between the final position and the starting position.
input: color - The color of the player's turn; board - The board is playing.
output: Returns true or false if it is possible or not.
*/
bool Bishop::inTheWay(char color, Piece* board[][BOARD_LEN])
{
	//Checks if the Bishop goes forward
	if (getStartIndex().getRow() < getEndIndex().getRow())
	{
		// Checks if the Bishop goes right
		if (getStartIndex().getCol() < getEndIndex().getCol())
		{
			for (int i = getStartIndex().getRow(); i <= getEndIndex().getRow(); i++)
			{
				for (int j = getStartIndex().getCol(); j == getEndIndex().getCol(); j++)
				{
					if (board[i][j]->getColor() != HELP_COLOR)
					{
						return false;
					}
				}
			}
		}
		// Checks if the Bishop goes left
		if (getStartIndex().getCol() > getEndIndex().getCol())
		{
			for (int i = getStartIndex().getRow(); i <= getEndIndex().getRow(); i++)
			{
				for (int j = getStartIndex().getCol(); j == getEndIndex().getCol(); j--)
				{
					if (board[i][j]->getColor() != HELP_COLOR)
					{
						return false;
					}
				}
			}
		}
	}
	//Checks if the Bishop goes back
	else
	{
		//Checks if the Bishop goes right 
		if (getStartIndex().getCol() < getEndIndex().getCol())
		{
			for (int i = getStartIndex().getRow(); i == getEndIndex().getRow(); i--)
			{
				for (int j = getStartIndex().getCol(); j == getEndIndex().getCol(); j++)
				{
					if (board[i][j]->getColor() != HELP_COLOR)
					{
						return false;
					}
				}
			}
		}
		//Checks if the Bishop goes left
		if (getStartIndex().getCol() > getEndIndex().getCol())
		{
			for (int i = getStartIndex().getRow(); i == getEndIndex().getRow(); i--)
			{
				for (int j = getStartIndex().getCol(); j == getEndIndex().getCol(); j++)
				{
					if (board[i][j]->getColor() != HELP_COLOR)
					{
						return false;
					}
				}
			}
		}
	}
	return true;
}
