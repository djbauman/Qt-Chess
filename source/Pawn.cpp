#include <iostream>
#include "Pawn.hpp"

// Constructor
Pawn::Pawn(Color c) : Piece(PAWN, c) {}

// Move piece
bool Pawn::movePiece()
{
	return false;
}
