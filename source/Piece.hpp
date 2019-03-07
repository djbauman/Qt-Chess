#ifndef CAPSTONE_PIECE_HPP
#define CAPSTONE_PIECE_HPP

#include <ostream>

// Forward declaration to avoid circular dependency
class Board;

/* The Piece class is an abstract class from which specific pieces (Pawn, Rook, etc.) will inherit. */

enum Type
{
	PAWN,
	KNIGHT,
	BISHOP,
	ROOK,
	QUEEN,
	KING
};

enum Color
{
	WHITE,
	BLACK
};

class Piece
{
public:
	// Constructor
	Piece(Type, Color);

	void setColor(Color color);
	void setType(Type type);
	void incrementMoves();
	void decrementMoves();
	Color getColor() const;
	Type getType() const;
	bool getMoved() const;
	virtual bool isValidMove(const Board *board, const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords) const = 0;
	friend std::ostream& operator<< (std::ostream &out, const Piece &piece);

	// Destructor
	virtual ~Piece() = default;
protected:
	Color color;
	Type type;
	int moves;
	char typeToChar(Type type) const;
	char colorToChar(Color color) const;
};

#endif
