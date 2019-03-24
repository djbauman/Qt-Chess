#include <iostream>
#include "Knight.hpp"

// Constructor
Knight::Knight(Color c) : Piece(KNIGHT, c) {}

/* Determine if this is a valid move based on the rules of the Knight. */
bool Knight::isValidMove(const Board *board, const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords) const
{
	if (board->isKnightMove(fromCoords, toCoords))
	{
		return true;
	}
	else
	{
		return false;
	}
}