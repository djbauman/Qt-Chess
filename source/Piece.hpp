#ifndef CAPSTONE_PIECE_HPP
#define CAPSTONE_PIECE_HPP

#include <ostream>

/* The Piece class serves primarily as a container for data. The Piece knows what type it is and what color it is, and
 * whether or not it has moved, which will be useful for castling and pawn movement. It doesn't know anything about it's
 * location, for example. That information is contained in the Board class. */

// TODO: Added temporarily so I have something to work with.
enum Type
{
	NOPIECE,
	PAWN,
	KNIGHT,
	BISHOP,
	ROOK,
	QUEEN,
	KING
};

enum Color
{
	NOCOLOR,
	WHITE,
	BLACK
};

class Piece
{
protected:
	Color color;
	Type type;
	bool moved;
	char typeToChar(Type type) const;
	char colorToChar(Color color) const;
public:
	Piece();
	Piece(Type, Color);
	void setColor(Color color);
	void setType(Type type);
	void setMoved(bool moved);
	Color getColor() const;
	Type getType() const;
	bool getMoved() const;
	friend std::ostream& operator<< (std::ostream &out, const Piece &piece);
};

#endif
