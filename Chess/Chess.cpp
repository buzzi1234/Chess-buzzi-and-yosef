#include "Chess.h"

Chess::Chess(std::string msg)
{
	this->_move = '\0';
	this->_gameRounds = new Round(msg);
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
	char moveSuccessful = '0';
	try
	{
		this->_gameRounds->setInputBoard(msg);
		moveSuccessful = this->_gameRounds->moveInBoard();
		if (!moveSuccessful)
		{
			this->_move = '2';
			throw ExceptionPieces();
		}
		this->_move = '0';
		newRound();

	}
	catch (const ExceptionPieces& e)
	{
		std::cout << e.badMove() << std::endl;

	}

	
}

//getter
char Chess::getMove()
{
	return this->_move;
}