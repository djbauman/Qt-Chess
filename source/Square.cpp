#include <iostream>
#include <memory>
#include "Square.hpp"

Piece* Square::getPiece() const
{
	return piece.get();
}

/* Takes a pieces and associates it with a square. Returns the piece that use to occupy the square, if any. */
std::unique_ptr<Piece> Square::setPiece(std::unique_ptr<Piece> piece)
{
	// Get the piece that was previously occupying this square, if any
	std::unique_ptr<Piece> old = std::move(this->piece);

	// Take the piece that was passed in as an argument and associate it with this square.
	this->piece = std::move(piece);

	// If the square was previously occupied, this will return unique pointer to that piece, otherwise it returns nullptr
	return old;
}
