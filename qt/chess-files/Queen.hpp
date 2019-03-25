#ifndef CAPSTONE_QUEEN_HPP
#define CAPSTONE_QUEEN_HPP

#include "Board.hpp"
#include "Piece.hpp"

class Queen : public Piece
{
public:
	Queen(Color c);
	bool isValidMove(const Board *board, const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords) const override;
	~Queen() override = default;
};

#endif
