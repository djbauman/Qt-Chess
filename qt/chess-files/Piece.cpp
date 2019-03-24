#include <iostream>
#include "Board.hpp"
#include "Piece.hpp"

/* Default constructor */
Piece::Piece(Type t, Color c)
{
	type = t;
	color = c;
	moves = 0;
}

/* Override << operator to print out the type and color of the piece. */
std::ostream &operator<<(std::ostream &out, const Piece &piece)
{
	// This has to use a getter because this is a friend function
	out << " " << piece.colorToChar(piece.getColor()) << piece.typeToChar(piece.getType()) << " ";
	return out;
}

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
	return moves > 0;
}

void Piece::incrementMoves()
{
	moves++;
}

void Piece::decrementMoves()
{
	moves--;
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
		default: return ' ';
	}
}

char Piece::colorToChar(Color color) const
{
	switch(color)
	{
		case WHITE: return 'W';
		case BLACK: return 'B';
		default: return ' ';
	}
}
