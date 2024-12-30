#include "Queen.h"


Queen::Queen(Point startIndex, char color)
	: Piece()
{
	setStartIndex(startIndex);
	setEndIndex(startIndex);
	setColor(color);

	_rook = new Rook(startIndex, color);
	_bishop = new Bishop(startIndex, color);
}

Queen::~Queen()
{
	delete _rook;
	delete _bishop;
	Piece::~Piece();
}

bool Queen::move(char color, Piece* board[][BOARD_LEN])
{
	if (abs(getEndIndex().getRow() - getStartIndex().getRow()) == abs(getEndIndex().getCol() - getStartIndex().getCol()))
	{
		_bishop->setStartIndex(getStartIndex());
		_bishop->setEndIndex(getEndIndex());
		return _bishop->move(color, board);
	}
	else if (getStartIndex().getRow() == getEndIndex().getRow() && getStartIndex().getCol() == getEndIndex().getCol())
	{
		_rook->setStartIndex(getStartIndex());
		_rook->setEndIndex(getEndIndex());
		return _rook->move(color, board);
	}
	return false;
}

bool Queen::eat(char color, Piece* board[][BOARD_LEN])
{
	if (abs(getEndIndex().getRow() - getStartIndex().getRow()) == abs(getEndIndex().getCol() - getStartIndex().getCol()))
	{
		_bishop->setStartIndex(getStartIndex());
		_bishop->setEndIndex(getEndIndex());
		return _bishop->eat(color, board);
	}
	else if (getStartIndex().getRow() == getEndIndex().getRow() && getStartIndex().getCol() == getEndIndex().getCol())
	{
		_rook->setStartIndex(getStartIndex());
		_rook->setEndIndex(getEndIndex());
		return _rook->eat(color, board);
	}
	return false;
}

bool Queen::inTheWay(char color, Piece* board[][BOARD_LEN])
{
	if (abs(getEndIndex().getRow() - getStartIndex().getRow()) == abs(getEndIndex().getCol() - getStartIndex().getCol()))
	{
		_bishop->setStartIndex(getStartIndex());
		_bishop->setEndIndex(getEndIndex());
		return _bishop->inTheWay(color, board);
	}
	else if (getStartIndex().getRow() == getEndIndex().getRow() && getStartIndex().getCol() == getEndIndex().getCol())
	{
		_rook->setStartIndex(getStartIndex());
		_rook->setEndIndex(getEndIndex());
		return _rook->inTheWay(color, board);
	}
	return false;
}
