#pragma once
#include <exception>

class ExceptionPieces : public std::exception
{
public:
	virtual const char* badMove() const
	{
		return "Bad Move! try another one.";
	}
	virtual const char* moveToCheck() const
	{
		return "Your King is in danger! try another move.";
	}
};