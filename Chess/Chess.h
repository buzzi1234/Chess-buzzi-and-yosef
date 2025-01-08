#pragma once
#include "Round.h"
#include <string>
#include <iostream>

#define BOARD_BYTES 66
#define FRONTEND_MSG "rnbkqbnrpppppppp################################PPPPPPPPRNBKQBNR1"

class Chess
{
private:
	Round* _gameRounds;
	char _move;

public:
	Chess();
	~Chess();

	char getMove();
	

	void finishedGame();
	void newRound();
	void game(std::string msg);
};

