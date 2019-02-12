#ifndef CAPSTONE_SQUARE_HPP
#define CAPSTONE_SQUARE_HPP

#include <memory>
#include "Piece.hpp"

/* The Square is currently just a container for a Piece, but this responsibility may grow in the future. */

class Square
{
public:
	Piece* getPiece() const;
	std::unique_ptr<Piece> setPiece(std::unique_ptr<Piece> piece);
protected:
	std::unique_ptr<Piece> piece;
};

#endif
