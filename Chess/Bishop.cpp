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
	int rowStep = (getEndIndex().getRow() > getStartIndex().getRow()) - (getEndIndex().getRow() < getStartIndex().getRow());
	int colStep = (getEndIndex().getCol() > getStartIndex().getCol()) - (getEndIndex().getCol() < getStartIndex().getCol());
	int row = getStartIndex().getRow() + rowStep;
	int col = getStartIndex().getCol() + colStep;
	
	while (row != getEndIndex().getRow() && col != getEndIndex().getCol())
	{
		if (board[row][col]->getColor() != HELP_COLOR)
		{
			return false;
		}
		row += rowStep;
		col += colStep;
	}
	
	return true;
}
