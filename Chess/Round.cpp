#include "Round.h"

//constructor
Round::Round(std::string inputBoard)
{
	setInputBoard(inputBoard);
	setColor(WHITE);
	turnToBoard();
	for (int i = 0; i < BOARD_LEN; i++)
	{
		for (int j = 0; j < BOARD_LEN; j++)
		{
			_board[i][j] = nullptr;
		}
	}
	this->_p;
	this->_p1;
	_pawn = new Pawn(Point(0, 0), WHITE, 'P');
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
		delete[] & _board[row];
	}
	delete[] & _board;
	delete& this->_p;
	delete& this->_p1;
	delete _pawn;
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
			if (newType == KING)
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
	this->_p = *(turnToPoint(this->getInputBoard().substr(0,2)));
	this->_p1 = *(turnToPoint(this->getInputBoard().substr(2, 2)));
	char typeNew = ' ';
	bool move = false;
	if (this->_board[this->_p.getRow()][this->_p.getCol()]->getColor() == getColor())
	{
		this->_board[this->_p.getRow()][this->_p.getCol()]->setEndIndex(this->_p1);
		if (this->_board[this->_p.getRow()][this->_p.getCol()]->move(getColor(), getBoard()))
		{
			for (int row = 0; row < BOARD_LEN; row++)
			{
				for (int col = 0; col < BOARD_LEN; col++)
				{
					typeNew = tolower(this->_board[row][col]->getType());
					if (typeNew == KING && this->_board[row][col]->getColor() == getColor())
					{
						
						bool checkStatus = isCheck();
						bool checkmateStatus = isCheckmate();
						
						if (checkStatus || checkmateStatus)
						{
							return true;
						}
					}
				}
			}
			if (!move)
			{
				this->_board[this->_p.getRow()][this->_p.getCol()]->setStartIndex(this->_p1);
				Point p3(-1, -1);
				//delete& this->_board[p1.getRow()][p1.getCol()];
				this->_board[this->_p1.getRow()][this->_p1.getCol()] = this->_board[this->_p.getRow()][this->_p.getCol()];
				this->_board[this->_p.getRow()][this->_p.getCol()] = new Pawn(p3, NONE, NONE);
				this->_p.setCol(-1);
				this->_p.setRow(-1);


				if ((this->_board[this->_p1.getRow()][this->_p1.getCol()]->getType() == PAWN) && ((this->_board[this->_p1.getRow()][this->_p1.getCol()]->getColor() == WHITE_PAWN && this->_p1.getRow() == 0) || (this->_board[this->_p1.getRow()][this->_p1.getCol()]->getColor() == BLACK_PAWN && this->_p1.getRow() == BOARD_LEN - 1)))
				{
					std::string input;
					std::cout << "Enter the piece to promote the pawn to (Q, R, B, N): ";
					std::cin >> input;
					if (_pawn->turnPiece(input))
					{
						std::cout << "Pawn promoted!" << input << std::endl;
					}
					else
					{
						std::cout << "Promotion failed!" << std::endl;
					}
				}


				return !move;

			}

		}
	}
	this->_board[this->_p.getRow()][this->_p.getCol()]->setStartIndex(this->_p);
	this->_board[this->_p.getRow()][this->_p.getCol()]->setEndIndex(this->_p);

	return false;


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
	Piece* player = this->_board[this->_p1.getRow()][this->_p1.getCol()];
	this->_board[this->_p.getRow()][this->_p.getCol()]->setStartIndex(this->_p1);
	Point p3(-1, -1);
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

/*
* The func start to check the check (find the king and shift the players in the board)
* input: none
* output: true there is a check false dont.
*/
bool Round::isCheck()
{
	char Color = getColor();
	char counterColor;
	char typeNew;
	if (Color == WHITE)
	{
		counterColor = BLACK;
	}
	else
	{
		counterColor = WHITE;
	}
	if (this->_p.getCol() != -1)
	{
		Piece* player = this->_board[this->_p1.getRow()][this->_p1.getCol()];
		this->_board[this->_p.getRow()][this->_p.getCol()]->setStartIndex(this->_p1);
		Point p3(-1, -1);

		this->_board[this->_p1.getRow()][this->_p1.getCol()] = this->_board[this->_p.getRow()][this->_p.getCol()];
		this->_board[this->_p.getRow()][this->_p.getCol()] = new Pawn(p3, NONE, NONE);

		for (int row = 0; row < BOARD_LEN; row++)
		{
			for (int col = 0; col < BOARD_LEN; col++)
			{
				typeNew = tolower(this->_board[row][col]->getType());
				if (typeNew == KING && this->_board[row][col]->getColor() == Color)
				{
					Point kingP(row, col);
					if (check(counterColor, getBoard(), kingP))
					{
						this->_board[this->_p.getRow()][this->_p.getCol()] = this->_board[this->_p1.getRow()][this->_p1.getCol()];
						this->_board[this->_p1.getRow()][this->_p1.getCol()] = player;
						this->_board[this->_p.getRow()][this->_p.getCol()]->setStartIndex(this->_p);
						return true;
					}
				}
			}
		}
		this->_board[this->_p.getRow()][this->_p.getCol()] = this->_board[this->_p1.getRow()][this->_p1.getCol()];
		this->_board[this->_p1.getRow()][this->_p1.getCol()] = player;
		this->_board[this->_p.getRow()][this->_p.getCol()]->setStartIndex(this->_p);
	}
	return false;
}

/*
* The func start to check the checkmate
* input: none
* output: true there is a checkmate false dont.
*/
bool Round::isCheckmate()
{
	if (!isCheck())
	{
		return false;
	}
	char typeNew;
	char Color = getColor();
	for (int row = 0; row < BOARD_LEN; row++)
	{
		for (int col = 0; col < BOARD_LEN; col++)
		{
			typeNew = tolower(this->_board[row][col]->getType());
			if (typeNew == KING && this->_board[row][col]->getColor() == Color)
			{
				Point kingP(row, col);
			}
			
		}
	}

	return true;
}


