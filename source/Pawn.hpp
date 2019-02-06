#ifndef CAPSTONE_PAWN_HPP
#define CAPSTONE_PAWN_HPP

#include "Piece.hpp"

class Pawn : public Piece
{
public:
	Pawn(Color c);
	bool movePiece() override;
	~Pawn() override = default;
};

#endif
