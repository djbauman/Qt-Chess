#include <iostream>
#include <memory>
#include "Square.hpp"

const Piece* Square::getPiece() const
{
	return piece.get();
}

std::unique_ptr<Piece> Square::setPiece(std::unique_ptr<Piece> piece)
{
	std::unique_ptr<Piece> old = std::move(this->piece);
	this->piece = std::move(piece);
	return std::move(old);
}
