#include "Queen.h"

Queen::Queen(Point startIndex, char color)
	: Piece()
{
	_bishopOrRook = ' ';
	setStartIndex(startIndex);
	setEndIndex(startIndex);
	setColor(color);
}

Queen::~Queen()
{
	_bishopOrRook = ' ';
	Piece::~Piece();
}

bool Queen::move(char color, Piece* board[][BOARD_LEN])
{
	if (abs(getEndIndex().getRow() - getStartIndex().getRow()) == abs(getEndIndex().getCol() - getStartIndex().getCol()))
	{
		_bishopOrRook = 'B';
		return eat(color, board);
	}
	if (getStartIndex().getRow() == getEndIndex().getRow() && getStartIndex().getCol() == getEndIndex().getCol())
	{
		_bishopOrRook = 'R';
		return eat(color, board);
	}
	return false;
}

bool Queen::eat(char color, Piece* board[][BOARD_LEN])
{
	switch (_bishopOrRook)
	{
	case 'B':
		if (board[getEndIndex().getRow()][getEndIndex().getCol()]->getColor() == color)
		{
			return false;
		}
		return inTheWay(color, board);
		break;
	case 'R':
		if (board[getEndIndex().getRow()][getEndIndex().getCol()]->getColor() == color)
		{
			return false;
		}
		return inTheWay(color, board);
		break;
	default:
		return false;
	}

	return false;
}

bool Queen::inTheWay(char color, Piece* board[][BOARD_LEN])
{
	switch (_bishopOrRook)
	{
	case 'B':
		//Checks if the Queen goes forward
		if (getStartIndex().getRow() < getEndIndex().getRow())
		{
			// Checks if the Queen goes right
			if (getStartIndex().getCol() < getEndIndex().getCol())
			{
				for (int i = getStartIndex().getRow(); i <= getEndIndex().getRow(); i++)
				{
					for (int j = getStartIndex().getCol(); j == getEndIndex().getCol(); j++)
					{
						if (board[i][j]->getColor() != HELP_COLOR)
						{
							return false;
						}
					}
				}
			}
			// Checks if the Queen goes left
			if (getStartIndex().getCol() > getEndIndex().getCol())
			{
				for (int i = getStartIndex().getRow(); i <= getEndIndex().getRow(); i++)
				{
					for (int j = getStartIndex().getCol(); j == getEndIndex().getCol(); j--)
					{
						if (board[i][j]->getColor() != HELP_COLOR)
						{
							return false;
						}
					}
				}
			}
		}
		//Checks if the Queen goes back
		else
		{
			//Checks if the Queen goes right 
			if (getStartIndex().getCol() < getEndIndex().getCol())
			{
				for (int i = getStartIndex().getRow(); i == getEndIndex().getRow(); i--)
				{
					for (int j = getStartIndex().getCol(); j == getEndIndex().getCol(); j++)
					{
						if (board[i][j]->getColor() != HELP_COLOR)
						{
							return false;
						}
					}
				}
			}
			//Checks if the Queen goes left
			if (getStartIndex().getCol() > getEndIndex().getCol())
			{
				for (int i = getStartIndex().getRow(); i == getEndIndex().getRow(); i--)
				{
					for (int j = getStartIndex().getCol(); j == getEndIndex().getCol(); j++)
					{
						if (board[i][j]->getColor() != HELP_COLOR)
						{
							return false;
						}
					}
				}
			}
		}
		return true;
		break;
	case 'R':
		if (getStartIndex().getRow() == getEndIndex().getRow() && getStartIndex().getCol() != getEndIndex().getCol())
		{
			if (getStartIndex().getCol() > getEndIndex().getCol())
			{
				for (int col = getStartIndex().getCol() - HELP_NUM; col > getEndIndex().getCol(); col--)
				{
					if (board[getStartIndex().getRow()][col]->getColor() == color)
					{
						return false;
					}
				}
				return true;
			}

			if (getStartIndex().getCol() < getEndIndex().getCol())
			{
				for (int col = getStartIndex().getCol() + HELP_NUM; col < getEndIndex().getCol(); col++)
				{
					if (board[getStartIndex().getRow()][col]->getColor() == color)
					{
						return false;
					}
				}
				return true;
			}

		}
		else if (getStartIndex().getRow() != getEndIndex().getRow() && getStartIndex().getCol() == getEndIndex().getCol())
		{
			if (getStartIndex().getRow() > getEndIndex().getRow())
			{
				for (int row = getStartIndex().getRow() - HELP_NUM; row > getEndIndex().getRow(); row--)
				{
					if (board[row][getStartIndex().getCol()]->getColor() == color)
					{
						return false;
					}
				}
				return true;
			}

			if (getStartIndex().getRow() < getEndIndex().getRow())
			{
				for (int row = getStartIndex().getRow() + HELP_NUM; row < getEndIndex().getRow(); row++)
				{
					if (board[row][getStartIndex().getCol()]->getColor() == color)
					{
						return false;
					}
				}
				return true;
			}
		}
		break;
	default:
		return false;
	}

	return false;
}
