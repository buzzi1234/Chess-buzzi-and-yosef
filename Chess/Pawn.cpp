#include "Pawn.h"
//constructor
Pawn::Pawn(Point startIndex, char color) :
	Piece()
{
	setStartIndex(startIndex);
	setColor(color);
	setEndIndex(startIndex);
}
//sestructor
Pawn::~Pawn()
{
	Piece::~Piece();
}

/*
The function checks if the index is within the range of Pawn moves.
input: color - The color of the player's turn; board - The board is playing.
output: Returns true or false if it is possible or not.
*/
bool Pawn::move(char color, Piece* board[][BOARD_LEN])
{
	switch (color)
	{
	case BLACK_PAWN:
		//Eating diagonally to the left
		if ((getStartIndex().getCol() - HELP_NUM == getEndIndex().getCol()) && (getStartIndex().getRow() - HELP_NUM == getEndIndex().getRow()))
		{
			return eat(color, board);
		}
		//Eating diagonally to the right
		if ((getStartIndex().getCol() + HELP_NUM == getEndIndex().getCol()) && (getStartIndex().getRow() - HELP_NUM == getEndIndex().getRow()))
		{
			return eat(color, board);
		}
		//walking one step
		if (getStartIndex().getRow() - HELP_NUM == getEndIndex().getRow())
		{
			return inTheWay(color, board);
		}
		//Walking for the first time two steps
		if (getStartIndex().getRow() - DOUBLE_JUMP_PAWN == getEndIndex().getRow())
		{
			return firstMove(color, board);
		}
		break;
	case WHITE_PAWN:
		//Eating diagonally to the left
		if ((getStartIndex().getCol() + HELP_NUM == getEndIndex().getCol()) && (getStartIndex().getRow() + HELP_NUM == getEndIndex().getRow()))
		{
			return eat(color, board);
		}
		//Eating diagonally to the right
		if ((getStartIndex().getCol() + HELP_NUM == getEndIndex().getCol()) && (getStartIndex().getRow() + HELP_NUM == getEndIndex().getRow()))
		{
			return eat(color, board);
		}
		//walking one step
		if (getStartIndex().getRow() + HELP_NUM == getEndIndex().getRow())
		{
			return inTheWay(color, board);
		}
		//Walking for the first time two steps
		if (getStartIndex().getRow() + DOUBLE_JUMP_PAWN == getEndIndex().getRow())
		{
			return firstMove(color, board);
		}
		break;
	default:
		return false;
	}


}

/*
The function checks if he can eat (which has no player).
input: color - The color of the player's turn; board - The board is playing.
output: Returns true or false if it is possible or not.
*/
bool Pawn::eat(char color, Piece* board[][BOARD_LEN])
{
	if (board[getEndIndex().getRow()][getEndIndex().getCol()]->getColor() == color)
	{
		return false;
	}
	return true;
}

/*
The function checks if it's his first turn to see if he can two step.
input: color - The color of the player's turn; board - The board is playing.
output: Returns true or false if it is possible or not.
*/
bool Pawn::firstMove(char color, Piece* board[][BOARD_LEN])
{
	switch (color) 
	{
	case BLACK_PAWN:
		if (getStartIndex().getRow() == ROW_NUM_BLACK)
		{
			return inTheWay(color, board);
		}
		break;
	case WHITE_PAWN:
		if (getStartIndex().getRow() == ROW_NUM_WHITE)
		{
			return inTheWay(color, board);
		}
		break;
	default:
		return false;
	}
}

/*
The function checks if there is a player's hood that interferes with his walking.
input: color - The color of the player's turn; board - The board is playing.
output: Returns true or false if it is possible or not.
*/
bool Pawn::inTheWay(char color, Piece* board[][BOARD_LEN])
{
	int row = getStartIndex().getRow();
	
	switch (color)
	{
	case BLACK_PAWN:
		if (board[row - HELP_NUM][getStartIndex().getCol()]->getStartIndex().getRow() == EMPTY_INDEX)
		{
			return true;
		}
		break;
	case WHITE_PAWN:
		if (board[row + HELP_NUM][getStartIndex().getCol()]->getStartIndex().getRow() == EMPTY_INDEX)
		{
			return true;
		}
		break;
	default:
		return false;
	}
}
