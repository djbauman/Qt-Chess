#include <iostream>
#include "Rook.hpp"

// Constructor
Rook::Rook(Color c) : Piece(ROOK, c) {}

/* Determine if this is a valid move based on the rules of the Rook. */
bool Rook::isValidMove(const Board *board, const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords) const
{
	//int moveLength = board->getMoveLength(fromCoords, toCoords);

	if(board->isVerticalMove(fromCoords, toCoords) || board->isHorizontalMove(fromCoords, toCoords))
	{
		if (board->isPathClear(fromCoords, toCoords))
		{
			return true;
		}
	}

	// If we've gotten this far, not a valid move
	return false;

}
