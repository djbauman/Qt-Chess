#ifndef CAPSTONE_KING_HPP
#define CAPSTONE_KING_HPP

#include "Board.hpp"
#include "Piece.hpp"

class King : public Piece
{
public:
	King(Color c);
	bool isValidMove(const Board *board, const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords) const override;
	~King() override = default;
};

#endif
