#include "Knight.h"
#include <cmath>

Knight::Knight(Point startIndex, char color, char type)
	: Piece()
{
	setStartIndex(startIndex);
	setEndIndex(startIndex);
	setColor(color);
	setType(type);
}

Knight::~Knight()
{
	Piece::~Piece();
}

/*
The function checks if the Knight moves properly
It checks by the difference of the initial and final row
and the difference of the initial and final Col.
input: color - The color of the player's turn; board - The board is playing.
output: Returns true or false if it is possible or not.
*/
bool Knight::move(char color, Piece* board[][BOARD_LEN])
{
	int rowDifference = abs(getEndIndex().getRow() - getStartIndex().getRow());
	int colDifference = abs(getEndIndex().getCol() - getStartIndex().getCol());

	if ((rowDifference == HELP_NUM_DOUBLE && colDifference == HELP_NUM) || (rowDifference == HELP_NUM && colDifference == HELP_NUM_DOUBLE))
	{
		return eat(color, board);
	}
	return false;
}

/*
The function checks if there is no one of the same color in the final square.
input: color - The color of the player's turn; board - The board is playing.
output: Returns true or false if it is possible or not.
*/
bool Knight::eat(char color, Piece* board[][BOARD_LEN])
{
	if (board[getEndIndex().getRow()][getEndIndex().getCol()]->getColor() == color)
	{
		return false;
	}
	return true;
}

/*
* EMPTY FUNC BECAUSE WE DONT NEED INTHEWAY IN KNIGHT
*/
bool Knight::inTheWay(char color, Piece* board[][BOARD_LEN])
{
	return false;
}
