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
bool Rook::inTheWay(char color, Piece* board[][8], int row, int col)
{

}