#ifndef CAPSTONE_PAWN_HPP
#define CAPSTONE_PAWN_HPP

#include "Piece.hpp"

class Pawn : public Piece
{
public:
	Pawn(Color c);
	bool isValidMove(const std::string &fromCoords, const std::string &toCoords) override;
	~Pawn() override = default;
};

#endif
