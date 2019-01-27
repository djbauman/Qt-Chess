#include <iostream>
#include "Board.hpp"

// Constructor
Board::Board()
{
    // TODO: This is just a proposal of how the constructor for this class might be used. The two choices, as I see them,
    //  would be to either assign the pieces their starting positions and colors in this constructor or to have a separate
    //  function which initializes these things which is then called from the Board constructor or from the game class.
    squares = {};
    Piece p{};
    p.setColor(WHITE);
    p.setType(KING);
    Board::setPiece("e1", p);
}

// Print board
void Board::printBoard()
{
    for (int i = 0; i < squares.size(); ++i)
    {
        if (i % 8 == 0 && i != 0)
        {
            std::cout << std::endl;
        }
        std::cout << squares[i].getPiece() << " ";
    }
}

/* Treats the passed string as algebraic chess coordinates ("a1" or "e7") and then uses the integer values of chars and
 * digits to convert the coordinates to the appropriate position in the the squares array. A map would probably be more
 * straightforward than what I've written here, but this is more concise and serves our purposes for now. */
int Board::coordsToElement(const std::string &coords)
{
    char col = coords[0];
    char row = coords[1];
    col -= 41; // convert from ASCII letter
    row -= 49; // convert from ASCII number
    int element = col - (row * 8);
    return element;
}

/* Uses the integer values of chars and digits to convert the element position to the appropriate algebraic chess
 * notation ("a1" or "e7"). A map would probably be more straightforward than what I've written here, but this is more
 * concise and serves our purposes for now. */
std::string Board::elementToCoords(int element)
{
    auto col = static_cast<char>((element % 8) + 97);   // convert integer to ASCII letter
    auto row = static_cast<char>(56 - (element / 8));   // convert integer to ASCII digit
    std::string coords = std::string() + col + row;     // form string from chars
    return coords;
}

/* Converts the given coordinates to an element and then places the given piece at that element. */
void Board::setPiece(const std::string &coords, Piece piece)
{
    int element = coordsToElement(coords);
    squares[element].setPiece(piece);
}

/* Returns the piece at a given square. */
Piece Board::getPiece(const std::string &coords)
{
    int element = coordsToElement(coords);
    return squares[element].getPiece();
}

// Destructor
Board::~Board() = default;
