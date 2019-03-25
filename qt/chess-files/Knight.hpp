#ifndef CAPSTONE_KNIGHT_HPP
#define CAPSTONE_KNIGHT_HPP

#include "Board.hpp"
#include "Piece.hpp"

class Knight : public Piece
{
public:
	Knight(Color c);
	bool isValidMove(const Board *board, const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords) const override;
	~Knight() override = default;
};

#endif
