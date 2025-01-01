#include "Chess.h"

Chess::Chess(std::string board)
	: _board(board)
{
	_gameRounds = new Round(board);
}

Chess::~Chess()
{
	delete _gameRounds;
}

void Chess::finishedGame()
{
	char winner = _gameRounds->win();
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
	char currentColor = _gameRounds->getColor();
	if (currentColor == WHITE)
	{
		_gameRounds->setColor(BLACK);
	}
	else
	{
		_gameRounds->setColor(WHITE);
	}
}

void Chess::game()
{
	_gameRounds->turnToBoard();
	bool moveSuccessful = false;

	do
	{
		try
		{

		}
		catch (const ExceptionPieces& e)
		{
			std::cout << e.badMove() << std::endl;
		}

		try
		{
			bool kingInCheck = _gameRounds->check(_gameRounds->getColor(), _gameRounds->getBoard(), _gameRounds->getBoard()[0][0]->getStartIndex());
			if (kingInCheck)
			{
				throw ExceptionPieces();
			}
		}
		catch (const ExceptionPieces& e)
		{
			std::cout << e.moveToCheck() << std::endl;
		}
	} while (true);
}
