#include "Square.hpp"

const Piece &Square::getPiece() const
{
	return piece;
}

void Square::setPiece(const Piece &piece)
{
	Square::piece = piece;
}
