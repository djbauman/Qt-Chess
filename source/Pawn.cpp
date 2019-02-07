#include <iostream>
#include "Pawn.hpp"

// Constructor
Pawn::Pawn(Color c) : Piece(PAWN, c) {}

// Move piece
bool Pawn::isValidMove(const std::string &fromCoords, const std::string &toCoords)
{
	return false;
}
