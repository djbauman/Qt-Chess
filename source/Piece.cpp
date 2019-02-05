#include "Piece.hpp"

Piece::Piece() = default;

Piece::Piece(Type t, Color c)
{
	type = t;
	moved = false;
	color = c;
}

/* Override << operator to print out the type and color of the piece. */
std::ostream &operator<<(std::ostream &out, const Piece &piece)
{
	// TODO: These are pretty meaningless as enum values right now (00 is a white pawn) so this will need to be modified.
	out << piece.colorToChar(piece.getColor()) << piece.typeToChar(piece.getType()) << ' '; // using a getter because this is a friend function

	return out;
}

/* --- Getters and setters --- */
Color Piece::getColor() const
{
	return color;
}

void Piece::setColor(Color color)
{
	Piece::color = color;
}

Type Piece::getType() const
{
	return type;
}

void Piece::setType(Type type)
{
	Piece::type = type;
}

bool Piece::getMoved() const
{
	return moved;
}

void Piece::setMoved(bool moved)
{
	Piece::moved = moved;
}

/* Enum converters */
char Piece::typeToChar(Type type) const
{
	switch(type)
	{
		case PAWN: return 'P';
		case KNIGHT: return 'N';
		case BISHOP: return 'B';
		case ROOK: return 'R';
		case QUEEN: return 'Q';
		case KING: return 'K';
		case NOPIECE: return '-';
		default: return ' ';
	}
}

char Piece::colorToChar(Color color) const
{
	switch(color)
	{
		case WHITE: return 'W';
		case BLACK: return 'B';
		case NOCOLOR: return'-';
		default: return ' ';
	}
}
