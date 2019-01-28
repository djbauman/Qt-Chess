#ifndef CAPSTONE_BOARD_HPP
#define CAPSTONE_BOARD_HPP

#include <array>
#include "Piece.hpp"
#include "Square.hpp"

/* The Board is the intermediary through which pieces are accessed and manipulated. It's primary data source is an
 * array of Squares. Each Square has the capability of holding a single Piece. */

class Board {
public:
	Board();
	void printBoard();
	Piece getPiece(const std::string &coords);
	bool movePiece(const std::string &fromCoords, const std::string &toCoords);
	~Board();
private:
	int coordsToElement(const std::string &coords);
	std::string elementToCoords(int element);
	void setPiece(const std::string &coords, Piece piece);
	std::array<Square, 64> squares;
};

#endif
