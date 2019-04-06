#ifndef CAPSTONE_BOARD_HPP
#define CAPSTONE_BOARD_HPP

#include <map>
#include <memory>
#include <vector>
#include "Square.hpp"

// Forward declaration to avoid circular dependency
class Piece;

/* The Board is the intermediary through which pieces are accessed and manipulated. It's primary data source is an
 * map which maps algebraic chess locations (as strings) to Squares. Each Square has the capability of holding a
 * single Piece. */

class Board {
public:
	// Constructors
	Board();
	Board(bool Pawns, bool Knights, bool Rooks, bool Bishops, bool Queens, bool Kings);

	// General
	void printBoard();
	void printBoardAlgebraicAxes();
	Piece* getPiece(const std::pair<int, int> &coords) const;
	bool movePiece(const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords);
	void setRook(const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords);
	void revertLastMove();

	// Board and movement attributes
	bool isOnBoard(const std::pair<int, int> &coords) const;
	bool isValidMove(const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords) const;
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

	// Pieces and locations
	std::vector<Piece*> getPieces(Color color) const;
	std::vector<std::pair<int,int>> getPieceLocations(Color color) const;
	std::pair<int,int> getKingLocation(Color color) const;
	std::vector<std::pair<int,int>> getLocations() const;

	// Conversions
	std::pair<int, int> algebraicToInt(std::string algebraicCoords) const;
	std::string intToAlgebraic(std::pair<int, int> intCoords) const;

	// Printing
	void printMoves();
	void printCapturedPieces();

	// Destructor
	~Board();

private:
	// Members
	std::map<std::pair<int, int>, std::unique_ptr<Square>> squares;
	std::vector<std::pair<std::pair<int, int>,std::pair<int, int>>> moves;
	std::map<size_t, std::unique_ptr<Piece>> capturedPieces;

	// Preparation
	void prepSquares();
	void createPawns();
	void createRooks();
	void createKnights();
	void createBishops();
	void createQueens();
	void createKings();

	// Piece manipulation
	std::unique_ptr<Piece> setPiece(const std::pair<int, int> &coords, std::unique_ptr<Piece> piece);
	void forceMovePiece(const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords);
};

#endif
