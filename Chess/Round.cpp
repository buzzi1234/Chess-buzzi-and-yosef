#include "Round.h"

//constructor
Round::Round(std::string inputBoard)
{
	setInputBoard(inputBoard);
	setColor(WHITE);
	turnToBoard();
}

//destructor
Round::~Round()
{
	setInputBoard("\0");
	setColor('\0');
	for (int row = 0; row < BOARD_LEN; row++) {
		for (int col = 0; col < BOARD_LEN; col++)
		{
			delete _board[row][col];
		}
		delete[] &_board[row];
	}
	delete[] &_board;
}

//getters
std::string Round::getInputBoard()
{
	return this->_inputBoard;
}
char Round::getColor()
{
	return this->_color;
}
Piece* (*Round::getBoard())[BOARD_LEN]
{
	return this->_board;
}

//setters
void Round::setInputBoard(std::string inputBoard)
{
	this->_inputBoard = inputBoard;
}
void Round::setColor(char color)
{
	this->_color = color;
}


/*
* The func takes the inputBoard and turns it to a full board in the 2d array
* input: none
* output: none
*/
void Round::turnToBoard()
{
	int txtIndex = 0;
	char color = ' ';
	char type = ' ';
	for (int row = 0; row < BOARD_LEN; row++)
	{
		for (int col = 0; col < BOARD_LEN; col++)
		{
			Point p(row, col);
			if (islower(this->_inputBoard[txtIndex]))
			{
				type = this->_inputBoard[txtIndex];
				color = BLACK;
			}
			else
			{
				type = this->_inputBoard[txtIndex];
				color = WHITE;
			}
			char newType = toupper(type);
			switch (newType)
			{
			case KING:

				this->_board[row][col] = new King(p, color, type);
				break;
			case KNIGHT:
				this->_board[row][col] = new Knight(p, color, type);
				break;
			case PAWN:
				this->_board[row][col] = new Pawn(p, color, type);
				break;
			case QUEEN:
				this->_board[row][col] = new Queen(p, color, type);
				break;
			case ROOK:
				this->_board[row][col] = new Rook(p, color, type);
				break;
			case BISHOP:
				this->_board[row][col] = new Bishop(p, color, type);
				break;
			default:
				p.setRow(-1);
				p.setCol(-1);
				this->_board[row][col] = new Pawn(p, NONE, NONE);
			}
			txtIndex++;
		}
	}
	if (this->_inputBoard[txtIndex] != '0')
	{
		setColor(BLACK);
	}
}

/*
* The func check if the given move is valid and then change it in the array
* input: none
* output: true if the move is valid false if not
*/
bool Round::moveInBoard()
{
	Point p = *(turnToPoint(this->_inputBoard.substr(0, 2)));
	Point p1 = *(turnToPoint(this->_inputBoard.substr(2, 2)));
	this->_board[p.getRow()][p.getCol()]->setEndIndex(p1);
	bool move = false;

	if (this->_board[p.getRow()][p.getCol()]->move(getColor(), getBoard()))
	{
		this->_board[p.getRow()][p.getCol()]->setStartIndex(p1);
		for (int row = 0; row < BOARD_LEN; row++)
		{
			for (int col = 0; col < BOARD_LEN; col++)
			{
				if (toupper(this->_board[row][col]->getType()) == KING && this->_board[row][col]->getColor() == getColor())
				{
					switch (getColor())
					{
					case BLACK:
						move = check(WHITE, getBoard(), this->_board[row][col]->getStartIndex());
						break;
					case WHITE:
						move = check(BLACK, getBoard(), this->_board[row][col]->getStartIndex());
						break;
					}
				}
			}
		}
		if (move)
		{
			Point p(-1, -1);
			delete this->_board[p1.getRow()][p1.getCol()];
			this->_board[p1.getRow()][p1.getCol()] = this->_board[p.getRow()][p.getCol()];
			this->_board[p.getRow()][p.getCol()] = new Pawn(p, NONE, NONE);
			return move;

		}

	}
	this->_board[p.getRow()][p.getCol()]->setStartIndex(p);
	this->_board[p.getRow()][p.getCol()]->setEndIndex(p);
	return move;


}

/*
* The func run all over the players and check if there is a check on the king
input: color - the kind of pieces we are looking for
*	   board - the board of the game
* output: true if the the check is valid false if not
*/
bool Round::check(char color, Piece* board[][BOARD_LEN], Point k)
{
	for (int row = 0; row < BOARD_LEN; row++)
	{
		for (int col = 0; col < BOARD_LEN; col++)
		{
			if (board[row][col]->getColor() == color)
			{
				board[row][col]->setEndIndex(k);
				if (board[row][col]->move(color, board))
				{
					return true;
				}
			}
		}
	}
	return false;
}

char Round::win()
{
	return 'c';
}


/*
* The func get a point in text and turn it to a point class
* input: point - the point in text
* output: a memory of the point in class
*/
Point* Round::turnToPoint(std::string point)
{
	int row = 0;
	int col = 0;
	switch (point[0])
	{
	case PLACE_A:
		col = 0;
		break;
	case PLACE_B:
		col = 1;
		break;
	case PLACE_C:
		col = 2;
		break;
	case PLACE_D:
		col = 3;
		break;
	case PLACE_E:
		col = 4;
		break;
	case PLACE_F:
		col = 5;
		break;
	case PLACE_G:
		col = 6;
		break;
	case PLACE_H:
		col = 7;
		break;
	}
	row = point[1] - '0';

	return new Point(row, col);
}