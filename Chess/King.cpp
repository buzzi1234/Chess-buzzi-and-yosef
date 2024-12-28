#include "King.h"

King::King(Point startIndex, char color) :
	Piece()
{
	setStartIndex(startIndex);
	setEndIndex(startIndex);
	setColor(color);
}
King::~King()
{
	Piece::~Piece();
}

bool King::move(char color, Piece* board[][BOARD_LEN])
{
}
bool King::eat(char color, Piece* board[][BOARD_LEN])
{

}
bool King::inTheWay(char color, Piece* board[][BOARD_LEN])
{

}

/*
* The func run all over the players and check if there is a check on the king
input: color - the kind of pieces we are looking for
*	   board - the board of the game
* output: true if the the check is valid false if not
*/
bool King::check(char color, Piece* board[][BOARD_LEN])
{
	for (int row = 0; row < BOARD_LEN; row++)
	{
		for (int col = 0; col < BOARD_LEN; col++)
		{
			if (board[row][col]->getColor() == color)
			{
				board[row][col]->setEndIndex(getStartIndex());
				if (board[row][col]->move(color, board))
				{
					return true;
				}
			}
		}
	}
	return false;
}
bool King::checkMate(char color, Piece* board[][BOARD_LEN])
{

}
