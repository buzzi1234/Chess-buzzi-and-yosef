#include "Chess.h"

Chess::Chess(std::string msg)
{
	this->_board[BOARD_BYTES - 1] = '\0';
	this->_gameRounds = new Round(msg);
	this->_gameRounds->turnToBoard();
}

Chess::~Chess()
{
	delete[] &this->_board;
	this->_gameRounds->~Round();
	delete _gameRounds;
}

void Chess::finishedGame()
{
	char winner = this->_gameRounds->win();
	if (winner == BLACK)
	{
		std::cout << "Black wins the game!" << std::endl;
	}
	else if (winner == WHITE)
	{
		std::cout << "White wins the game!" << std::endl;
	}
	else
	{
		std::cout << "It's a deaw!" << std::endl;
	}
}

void Chess::newRound()
{
	char currentColor = this->_gameRounds->getColor();
	if (currentColor == WHITE)
	{
		_gameRounds->setColor(BLACK);
	}
	else
	{
		_gameRounds->setColor(WHITE);
	}
}

void Chess::game(std::string msg)
{
	bool moveSuccessful = false;
	try
	{
		this->_gameRounds->setInputBoard(msg);
		moveSuccessful = this->_gameRounds->moveInBoard();
		if (!moveSuccessful)
		{
			throw ExceptionPieces();
		}

	}
	catch (const ExceptionPieces& e)
	{
		std::cout << e.badMove() << std::endl;

	}
	for (int row = 0; row < BOARD_LEN; row++)
	{
		for (int col = 0; col < BOARD_LEN; col++)
		{
			_board[(row*BOARD_LEN) + col] =_gameRounds->getBoard()[row][col]->getType();
		}
	}
	newRound();
	if (_gameRounds->getColor() == WHITE)
	{
		_board[BOARD_LEN * BOARD_LEN] = '0';
	}
	else
	{
		_board[BOARD_LEN * BOARD_LEN] = BLACK;
	}
	
}

//getter
char* Chess::getBoard()
{
	return this->_board;
}