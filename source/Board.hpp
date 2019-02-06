#ifndef CAPSTONE_BOARD_HPP
#define CAPSTONE_BOARD_HPP

#include <array>
#include <vector>
#include <map>
#include "Piece.hpp"
#include "Square.hpp"

/* The Board is the intermediary through which pieces are accessed and manipulated. It's primary data source is an
 * map which maps algebraic chess locations (as strings) to Squares. Each Square has the capability of holding a
 * single Piece. */

class Board {
public:
	Board();
	void printBoard();
	const Piece* getPiece(const std::string &coords) const;
	std::unique_ptr<Piece> setPiece(const std::string &coords, std::unique_ptr<Piece> piece);
	~Board();
private:
	void prepSquares();
	void prepPieces();
	std::map<std::string, std::unique_ptr<Square>> squares;
};

#endif
