#include "Rook.h"

//constructor
Rook::Rook(std::string startIndex, char color)
{
	setStartIndex(startIndex);
	setEndIndex(startIndex);
	setColor(color);
}

//destructor
Rook::~Rook()
{
	setStartIndex("\0");
	setEndIndex("\0");
	setColor('\0');
}

bool Rook::move()
{

}
bool Rook::eat()
{

}


bool Rook::inTheWay()
{

}