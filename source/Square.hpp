#ifndef CAPSTONE_SQUARE_HPP
#define CAPSTONE_SQUARE_HPP

#include "Piece.hpp"

/* The Square is currently just a container for a piece, but this responsibility may grow in the future. */

class Square
{
protected:
	Piece piece;
public:
	void setPiece(const Piece &piece);
	const Piece &getPiece() const;
};

#endif
