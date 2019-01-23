#include "Piece.hpp"

/* Override << operator to print out the type and color of the piece. */
std::ostream &operator<<(std::ostream &out, const Piece &piece)
{
    // TODO: These are pretty meaningless as enum values right now (00 is a white pawn) so this will need to be modified.
    out << piece.getColor() << piece.getType(); // using a getter because this is a friend function

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

bool Piece::isMoved() const
{
    return moved;
}

void Piece::setMoved(bool moved)
{
    Piece::moved = moved;
}
