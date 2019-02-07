#ifndef CAPSTONE_PIECE_HPP
#define CAPSTONE_PIECE_HPP

#include <ostream>

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
	Piece(Type, Color);
	void setColor(Color color);
	void setType(Type type);
	void setMoved(bool moved);
	Color getColor() const;
	Type getType() const;
	bool getMoved() const;
	virtual bool isValidMove(const std::string &fromCoords, const std::string &toCoords) = 0;
	friend std::ostream& operator<< (std::ostream &out, const Piece &piece);
	virtual ~Piece() = default;
protected:
	Color color;
	Type type;
	bool moved;
	char typeToChar(Type type) const;
	char colorToChar(Color color) const;
};

#endif
