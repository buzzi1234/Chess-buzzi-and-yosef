#pragma warning( push )
#pragma warning( disable : 4200 )
#include "Bishop.h"
#include "King.h"
#include "Queen.h"
#include "Knight.h"
#include "Pawn.h"
#include "Rook.h"
#include "ExceptionPieces.h"

#define BOARD_LEN 8
#define BLACK 'B'
#define WHITE 'W'
#define NONE '#'
#define BISHOP 'b'
#define KING 'k'
#define QUEEN 'q'
#define KNIGHT 'n'
#define PAWN 'p'
#define ROOK 'r'

#define PLACE_A 'a'
#define PLACE_B 'b'
#define PLACE_C 'c'
#define PLACE_D 'd'
#define PLACE_E 'e'
#define PLACE_F 'f'
#define PLACE_G 'g'
#define PLACE_H 'h'


class Round
{
private:
	std::string _inputBoard;
	char _color;
	Point _p;
	Point _p1;
	Pawn* _pawn;
	Piece* _board[BOARD_LEN][BOARD_LEN];
	
public:
	Round(std::string inputBoard);
	~Round();

	std::string getInputBoard();
	char getColor();
	Piece* (*getBoard())[BOARD_LEN];


	void setInputBoard(std::string inputBoard);
	void setColor(char color);

	bool check(char color, Piece* board[][BOARD_LEN], Point k);
	void turnToBoard();
	bool moveInBoard();
	Point* turnToPoint(std::string point);
	bool isCheck();
	bool isCheckmate();

};
#pragma warning( pop )

