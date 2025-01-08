#include "Chess.h"

Chess::Chess()
{
	this->_move = '\0';
	this->_gameRounds = new Round(FRONTEND_MSG);
	this->_gameRounds->turnToBoard();
}

Chess::~Chess()
{
	this->_move = '\0';
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
			this->_move = '2';
			throw ExceptionPieces();
		}
		if (this->_gameRounds->isCheckmate())
		{
			this->_move = '8';
		}
		else if (this->_gameRounds->isCheck())
		{
			this->_move = '1';
		}
		else
		{
			this->_move = '0';
		}

		newRound();

	}
	catch (const ExceptionPieces& e)
	{
		std::cout << e.badMove() << std::endl;
		this->_move = '6';
	}
	for (int row = 0; row < BOARD_LEN; row++)
	{
		for (int col = 0; col < BOARD_LEN; col++)
		{
			std::cout << this->_gameRounds->getBoard()[row][col]->getType();
		}
		std::cout << "\n";
	}
	
}

//getter
char Chess::getMove()
{
	return this->_move;
}