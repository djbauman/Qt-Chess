#include <iostream>
#include "Pawn.hpp"

// Constructor
Pawn::Pawn(Color c) : Piece(PAWN, c) {}

/* Determine if this is a valid move based on the rules of the pawn. */
bool Pawn::isValidMove(const Board *board, const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords) const
{
	// TODO: Implement
	if (board->isOccupied(toCoords))
	{
		return false;
	}
	else
	{
		return true;
	}
}