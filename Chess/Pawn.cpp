#include "Pawn.h"
//constructor
Pawn::Pawn(Point startIndex, char color, char type) :
	Piece()
{
	this->_jumps = HELP_NUM;
	setStartIndex(startIndex);
	setColor(color);
	setEndIndex(startIndex);
	setType(type);
}
//sestructor
Pawn::~Pawn()
{
	this->_jumps = 0;
	Piece::~Piece();
}

/*
The function checks if the index is within the range of Pawn moves.
input: color - The color of the player's turn; board - The board is playing.
output: Returns true or false if it is possible or not.
*/
bool Pawn::move(char color, Piece* board[][BOARD_LEN])
{
	switch (getColor())
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
		if (getStartIndex().getRow() - DOUBLE_JUMP_PAWN == getEndIndex().getRow() && getStartIndex().getCol() == getEndIndex().getCol())
		{
			return firstMove(color, board);
		}
		break;
	case WHITE_PAWN:
		//Eating diagonally to the left
		if ((getStartIndex().getCol() - HELP_NUM == getEndIndex().getCol()) && (getStartIndex().getRow() + HELP_NUM == getEndIndex().getRow()))
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
		if (getStartIndex().getRow() + DOUBLE_JUMP_PAWN == getEndIndex().getRow() && getStartIndex().getCol() == getEndIndex().getCol())
		{
			return firstMove(color, board);
		}
		break;
	default:
		return false;
	}

	return false;
}

/*
The function checks if he can eat (which has no player).
input: color - The color of the player's turn; board - The board is playing.
output: Returns true or false if it is possible or not.
*/
bool Pawn::eat(char color, Piece* board[][BOARD_LEN])
{
	if (board[getEndIndex().getRow()][getEndIndex().getCol()]->getColor() == color || board[getEndIndex().getRow()][getEndIndex().getCol()]->getColor() == NONE_PAWN)
	{
		return false;
	}
	return true;
}

bool Pawn::turnPiece(std::string type)
{
	if (type == "Q") 
	{
		this->setType(QUEEN);
	}
	else if (type == "R") 
	{
		this->setType(ROOK);
	}
	else if (type == "B") 
	{
		this->setType(BISHOP);
	}
	else if (type == "N") 
	{
		this->setType(KNIGHT);
	}
	else 
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
			if (inTheWay(color, board))
			{
				this->_jumps = DOUBLE_JUMP_PAWN;
				if (inTheWay(color, board))
				{
					this->_jumps = HELP_NUM;
					return true;
				}
				this->_jumps = HELP_NUM;
			}
		}
		break;
	case WHITE_PAWN:
		if (getStartIndex().getRow() == ROW_NUM_WHITE)
		{
			if (inTheWay(color, board))
			{
				this->_jumps = DOUBLE_JUMP_PAWN;
				if (inTheWay(color, board))
				{
					this->_jumps = HELP_NUM;
					return true;
				}
				this->_jumps = HELP_NUM;
			}
		}
		break;
	default:
		return false;
	}

	return false;
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
		if (board[row - this->_jumps][getStartIndex().getCol()]->getStartIndex().getRow() == EMPTY_INDEX)
		{
			return true;
		}
		break;
	case WHITE_PAWN:
		if (board[row + this->_jumps][getStartIndex().getCol()]->getStartIndex().getRow() == EMPTY_INDEX)
		{
			return true;
		}
		break;
	default:
		return false;
	}

	return false;
}
