#pragma once
#include "Round.h"
#include <string>
#include <iostream>

class Chess
{
private:
	Round* _gameRounds;
	std::string _board;

public:
	Chess(std::string board);
	~Chess();

	void finishedGame();
	void newRound();
	void game();
};

