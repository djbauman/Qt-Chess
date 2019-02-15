#include <iostream>
#include "Bishop.hpp"

// Constructor
Bishop::Bishop(Color c) : Piece(BISHOP, c) {}

/* Determine if this is a valid move based on the rules of the Bishop. */
bool Bishop::isValidMove(const Board *board, const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords) const
{
	if (board->isDiagonalMove(fromCoords, toCoords))
	{
		if (board->isPathClear(fromCoords, toCoords))
		{
			return true;
		}
	}

	// If we've gotten this far, not a valid move
	return false;

}


// Do I need to check that the final piece is a piece of the opposite color