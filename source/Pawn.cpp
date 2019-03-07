#include <iostream>
#include "Pawn.hpp"

/* Constructor */
Pawn::Pawn(Color c) : Piece(PAWN, c) {}

/* Determine if this is a valid move based on the rules of the pawn. */
bool Pawn::isValidMove(const Board *board, const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords) const
{
	int moveLength = board->getMoveLength(fromCoords, toCoords);

	// Not valid if not forward move
	if (!board->isForwardMove(fromCoords, toCoords, this))
	{
		return false;
	}

	// Not valid if horizontal move
	if (board->isHorizontalMove(fromCoords, toCoords))
	{
		return false;
	}

	// Must be length 1 and capture if diagonal
	if (board->isDiagonalMove(fromCoords, toCoords))
	{
		// Is 1 step?
		if (moveLength == 1)
		{
			if (board->isOccupiedDifferentColor(fromCoords, toCoords))
			{
				// Capture!
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			// Only moveLength of 1 is allowed on diagonals
			return false;
		}
	}

	// Must be length 1 or 2, clear path, and unoccupied destination if vertical
	if (board->isVerticalMove(fromCoords, toCoords))
	{
		// Is occupied?
		if (board->isOccupied(toCoords))
		{
			return false;
		}

		// Is length 2?
		if (moveLength == 2)
		{
			if (!getMoved() && board->isPathClear(fromCoords, toCoords))
			{
				return true;
			}
		}
		else if (moveLength == 1)
		{
			return true;
		}
		else
		{
			// No lengths besides 1 and 2 permitted
			return false;
		}
	}

	// If we've gotten this far, definitely not a valid move
	return false;

}