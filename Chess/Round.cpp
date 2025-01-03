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
	char newType = ' ';
	Point p(0, 0);
	for (int row = 0; row < BOARD_LEN; row++)
	{
		for (int col = 0; col < BOARD_LEN; col++)
		{
			p.setRow(row);
			p.setCol(col);
			if (islower(this->_inputBoard[txtIndex]))
			{
				type = this->_inputBoard[txtIndex];
				color = WHITE;
			}
			else
			{
				type = this->_inputBoard[txtIndex];
				color = BLACK;
			}
			newType = tolower(type);
			if(newType == KING)
				this->_board[row][col] = new King(p, color, type);
			else if (newType == KNIGHT)
				this->_board[row][col] = new Knight(p, color, type);
				
			else if (newType == PAWN)
				this->_board[row][col] = new Pawn(p, color, type);

			else if (newType == QUEEN)
				this->_board[row][col] = new Queen(p, color, type);
				
			else if (newType == ROOK)
				this->_board[row][col] = new Rook(p, color, type);
				
			else if (newType == BISHOP)
				this->_board[row][col] = new Bishop(p, color, type);
			else
			{
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
	Piece* player = this->_board[p1.getRow()][p1.getCol()];
	char typeNew = ' ';
	bool move = false;
	if (this->_board[p.getRow()][p.getCol()]->getColor() == getColor())
	{
		this->_board[p.getRow()][p.getCol()]->setEndIndex(p1);
		move = this->_board[p.getRow()][p.getCol()]->move(getColor(), getBoard());
		if (move == '0')
		{
			Point p3(-1, -1);
			this->_board[p.getRow()][p.getCol()]->setStartIndex(p1);
			this->_board[p1.getRow()][p1.getCol()] = this->_board[p.getRow()][p.getCol()];
			this->_board[p.getRow()][p.getCol()] = new Pawn(p3, NONE, NONE);
			for (int row = 0; row < BOARD_LEN; row++)
			{
				for (int col = 0; col < BOARD_LEN; col++)
				{
					typeNew = tolower(this->_board[row][col]->getType());
					if (typeNew == KING && this->_board[row][col]->getColor() == getColor())
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
			if (!move)
			{
				

				//print the 2d array for debug
				for (int row = 0; row < BOARD_LEN; row++)
				{
					for (int col = 0; col < BOARD_LEN; col++)
					{
						std::cout << this->_board[row][col]->getType();
					}
					std::cout << "\n";
				}

				return !move;

			}
			this->_board[p.getRow()][p.getCol()] = this->_board[p1.getRow()][p1.getCol()];
			this->_board[p1.getRow()][p1.getCol()] = player;

		}
	}
	
	//print the 2d array for debug
	for (int row = 0; row < BOARD_LEN; row++)
	{
		for (int col = 0; col < BOARD_LEN; col++)
		{
			std::cout << this->_board[row][col]->getType();
		}
		std::cout << "\n";
	}

	this->_board[p.getRow()][p.getCol()]->setStartIndex(p);
	this->_board[p.getRow()][p.getCol()]->setEndIndex(p);
	return move;


}

/*
* The func run all over the players and check if there is a check on the king
input: color - the kind of pieces we are looking for
*	   board - the board of the game
*	   k - the start index of the king
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
					board[row][col]->setEndIndex(board[row][col]->getStartIndex());
					return true;
				}
				board[row][col]->setEndIndex(board[row][col]->getStartIndex());
				
			}
		}
	}
	return false;
}

char Round::win()
{
	return '8';
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
	row--;

	return new Point(row, col);
}