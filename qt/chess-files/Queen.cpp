#include <iostream>
#include "Queen.hpp"

// Constructor
Queen::Queen(Color c) : Piece(QUEEN, c) {}

/* Determine if this is a valid move based on the rules of the Queen. */
bool Queen::isValidMove(const Board *board, const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords) const
{
	if(board->isVerticalMove(fromCoords, toCoords) || board->isHorizontalMove(fromCoords, toCoords))
	{
		if (board->isPathClear(fromCoords, toCoords))
		{
			return true;
		}
	}
	else if (board->isDiagonalMove(fromCoords, toCoords))
	{
		if (board->isPathClear(fromCoords, toCoords))
		{
			return true;
		}
	}

	// If we've gotten this far, not a valid move
	return false;

}
