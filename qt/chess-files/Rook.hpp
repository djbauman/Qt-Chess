#ifndef CAPSTONE_ROOK_HPP
#define CAPSTONE_ROOK_HPP

#include "Board.hpp"
#include "Piece.hpp"

class Rook : public Piece
{
public:
	Rook(Color c);
	bool isValidMove(const Board *board, const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords) const override;
	~Rook() override = default;
};

#endif
