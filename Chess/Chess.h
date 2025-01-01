#pragma once
#include "Round.h"
#include <string>
#include <iostream>

#define BOARD_BYTES 66

class Chess
{
private:
	Round* _gameRounds;
	char _board[BOARD_BYTES];

public:
	Chess(std::string msg);
	~Chess();

	char* getBoard();
	

	void finishedGame();
	void newRound();
	void game(std::string msg);
};

