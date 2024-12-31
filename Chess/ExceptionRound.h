#pragma once
#include <exception>

class ExceptionRound : public std::exception
{
public:
	virtual const char* wrongInput() const
	{
		return "Wrong Input!";
	}
};