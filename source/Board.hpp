#ifndef CAPSTONE_BOARD_HPP
#define CAPSTONE_BOARD_HPP

#include <map>
#include <memory>
#include "Square.hpp"

// Forward declaration to avoid circular dependency
class Piece;

/* The Board is the intermediary through which pieces are accessed and manipulated. It's primary data source is an
 * map which maps algebraic chess locations (as strings) to Squares. Each Square has the capability of holding a
 * single Piece. */

class Board {
public:
	// Constructor
	Board();

	// General
	void printBoard();
	Piece* getPiece(const std::pair<int, int> &coords) const;
	bool movePiece(const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords);

	// Board and movement attributes
	bool isOccupied(const std::pair<int, int> &coords) const;
	bool isOccupiedSameColor(const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords) const;
	bool isOccupiedDifferentColor(const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords) const;
	bool isVerticalMove(const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords) const;
	bool isHorizontalMove(const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords) const;
	bool isDiagonalMove(const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords) const;
	bool isForwardMove(const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords, const Piece* piece) const;
	bool isKnightMove(const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords) const;
	bool isPathClear(const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords) const;
	int getMoveLength(const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords) const;
	bool isValidCastle(const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords) const;

	// Destructor
	~Board();
private:
	// Members
	std::map<std::pair<int, int>, std::unique_ptr<Square>> squares;

	// Preparation
	void prepSquares();
	void prepPieces();

	// Piece manipulation
	std::unique_ptr<Piece> setPiece(const std::pair<int, int> &coords, std::unique_ptr<Piece> piece);
	bool isOnBoard(const std::pair<int, int> &coords);

	// Utility functions
	std::pair<int, int> algebraicToInt(std::string algebraicCoords) const;
	std::string intToAlgebraic(std::pair<int, int> intCoords) const;
};

#endif
