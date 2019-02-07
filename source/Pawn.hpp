#ifndef CAPSTONE_PAWN_HPP
#define CAPSTONE_PAWN_HPP

#include "Board.hpp"
#include "Piece.hpp"

class Pawn : public Piece
{
public:
	Pawn(Color c);
	bool isValidMove(const Board *board, const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords) const override;
	~Pawn() override = default;
};

#endif
