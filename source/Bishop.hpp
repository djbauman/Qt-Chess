#ifndef CAPSTONE_BISHOP_HPP
#define CAPSTONE_BISHOP_HPP

#include "Board.hpp"
#include "Piece.hpp"

class Bishop : public Piece
{
public:
	Bishop(Color c);
	bool isValidMove(const Board *board, const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords) const override;
	~Bishop() override = default;
};

#endif