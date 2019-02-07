#include <iostream>
#include <memory>
#include "Board.hpp"
#include "Pawn.hpp"

/* Constructor */
Board::Board()
{
	prepSquares();
	prepPieces();
}

/* Squares are stored in a map which maps algebraic locations (as a string) to a unique_ptr to a Square object. */
void Board::prepSquares()
{
	// TODO: Wrap these in a loop

	squares.insert(std::make_pair("a1", std::make_unique<Square>()));
	squares.insert(std::make_pair("a2", std::make_unique<Square>()));
	squares.insert(std::make_pair("a3", std::make_unique<Square>()));
	squares.insert(std::make_pair("a4", std::make_unique<Square>()));
	squares.insert(std::make_pair("a5", std::make_unique<Square>()));
	squares.insert(std::make_pair("a6", std::make_unique<Square>()));
	squares.insert(std::make_pair("a7", std::make_unique<Square>()));
	squares.insert(std::make_pair("a8", std::make_unique<Square>()));

	squares.insert(std::make_pair("b1", std::make_unique<Square>()));
	squares.insert(std::make_pair("b2", std::make_unique<Square>()));
	squares.insert(std::make_pair("b3", std::make_unique<Square>()));
	squares.insert(std::make_pair("b4", std::make_unique<Square>()));
	squares.insert(std::make_pair("b5", std::make_unique<Square>()));
	squares.insert(std::make_pair("b6", std::make_unique<Square>()));
	squares.insert(std::make_pair("b7", std::make_unique<Square>()));
	squares.insert(std::make_pair("b8", std::make_unique<Square>()));

	squares.insert(std::make_pair("c1", std::make_unique<Square>()));
	squares.insert(std::make_pair("c2", std::make_unique<Square>()));
	squares.insert(std::make_pair("c3", std::make_unique<Square>()));
	squares.insert(std::make_pair("c4", std::make_unique<Square>()));
	squares.insert(std::make_pair("c5", std::make_unique<Square>()));
	squares.insert(std::make_pair("c6", std::make_unique<Square>()));
	squares.insert(std::make_pair("c7", std::make_unique<Square>()));
	squares.insert(std::make_pair("c8", std::make_unique<Square>()));

	squares.insert(std::make_pair("d1", std::make_unique<Square>()));
	squares.insert(std::make_pair("d2", std::make_unique<Square>()));
	squares.insert(std::make_pair("d3", std::make_unique<Square>()));
	squares.insert(std::make_pair("d4", std::make_unique<Square>()));
	squares.insert(std::make_pair("d5", std::make_unique<Square>()));
	squares.insert(std::make_pair("d6", std::make_unique<Square>()));
	squares.insert(std::make_pair("d7", std::make_unique<Square>()));
	squares.insert(std::make_pair("d8", std::make_unique<Square>()));

	squares.insert(std::make_pair("e1", std::make_unique<Square>()));
	squares.insert(std::make_pair("e2", std::make_unique<Square>()));
	squares.insert(std::make_pair("e3", std::make_unique<Square>()));
	squares.insert(std::make_pair("e4", std::make_unique<Square>()));
	squares.insert(std::make_pair("e5", std::make_unique<Square>()));
	squares.insert(std::make_pair("e6", std::make_unique<Square>()));
	squares.insert(std::make_pair("e7", std::make_unique<Square>()));
	squares.insert(std::make_pair("e8", std::make_unique<Square>()));

	squares.insert(std::make_pair("f1", std::make_unique<Square>()));
	squares.insert(std::make_pair("f2", std::make_unique<Square>()));
	squares.insert(std::make_pair("f3", std::make_unique<Square>()));
	squares.insert(std::make_pair("f4", std::make_unique<Square>()));
	squares.insert(std::make_pair("f5", std::make_unique<Square>()));
	squares.insert(std::make_pair("f6", std::make_unique<Square>()));
	squares.insert(std::make_pair("f7", std::make_unique<Square>()));
	squares.insert(std::make_pair("f8", std::make_unique<Square>()));

	squares.insert(std::make_pair("g1", std::make_unique<Square>()));
	squares.insert(std::make_pair("g2", std::make_unique<Square>()));
	squares.insert(std::make_pair("g3", std::make_unique<Square>()));
	squares.insert(std::make_pair("g4", std::make_unique<Square>()));
	squares.insert(std::make_pair("g5", std::make_unique<Square>()));
	squares.insert(std::make_pair("g6", std::make_unique<Square>()));
	squares.insert(std::make_pair("g7", std::make_unique<Square>()));
	squares.insert(std::make_pair("g8", std::make_unique<Square>()));

	squares.insert(std::make_pair("h1", std::make_unique<Square>()));
	squares.insert(std::make_pair("h2", std::make_unique<Square>()));
	squares.insert(std::make_pair("h3", std::make_unique<Square>()));
	squares.insert(std::make_pair("h4", std::make_unique<Square>()));
	squares.insert(std::make_pair("h5", std::make_unique<Square>()));
	squares.insert(std::make_pair("h6", std::make_unique<Square>()));
	squares.insert(std::make_pair("h7", std::make_unique<Square>()));
	squares.insert(std::make_pair("h8", std::make_unique<Square>()));
}

/* Creates and places the appropriate pieces on the appropriate spots to start a game. */
void Board::prepPieces()
{
	// TODO: Fill out the rest of the pieces.

	// White pawns
	setPiece("a2", std::make_unique<Pawn>(WHITE));
	setPiece("b2", std::make_unique<Pawn>(WHITE));
	setPiece("c2", std::make_unique<Pawn>(WHITE));
	setPiece("d2", std::make_unique<Pawn>(WHITE));
	setPiece("e2", std::make_unique<Pawn>(WHITE));
	setPiece("f2", std::make_unique<Pawn>(WHITE));
	setPiece("g2", std::make_unique<Pawn>(WHITE));
	setPiece("h2", std::make_unique<Pawn>(WHITE));

	// Black pawns
	setPiece("a7", std::make_unique<Pawn>(BLACK));
	setPiece("b7", std::make_unique<Pawn>(BLACK));
	setPiece("c7", std::make_unique<Pawn>(BLACK));
	setPiece("d7", std::make_unique<Pawn>(BLACK));
	setPiece("e7", std::make_unique<Pawn>(BLACK));
	setPiece("f7", std::make_unique<Pawn>(BLACK));
	setPiece("g7", std::make_unique<Pawn>(BLACK));
	setPiece("h7", std::make_unique<Pawn>(BLACK));
}

/* Sets a piece to its appropriate location in the map. */
std::unique_ptr<Piece> Board::setPiece(const std::string &coords, std::unique_ptr<Piece> piece)
{
	return squares[coords]->setPiece(std::move(piece));
}

/* Returns the piece at a given square. Finds the element in the map, then returns the Square part of that element, then
 * gets the piece at that square. */
const Piece* Board::getPiece(const std::string &coords) const
{
	return squares.find(coords)->second->getPiece();
}

/* Print contents of board with black on top and white on bottom by creating a series of coordinates and then finding
 * the pieces at those coordinates. */
void Board::printBoard()
{
	const std::string letters = "abcdefgh";
	for (int i = 8; i >= 1; i--) 	// for iterating over numerals 1 through 8
	{
		for (int j = 0; j < 8; j++) // for iterating over letters a through g
		{
			std::string coords = letters[j] + std::to_string(i);			// create coordinates
			const Piece* piece = squares.find(coords)->second->getPiece();	// get piece (or nullptr) at that coordinate
			if (piece == nullptr) {
				std::cout << "   ";											// no piece here so print empty space
			}
			else
			{
				std::cout << *piece;										// print piece
			}
			std::cout << " ";												// print spacing to separate pieces
		}
		std::cout << std::endl;												// move to next line
	}
}

/* Moves a piece at one coordinate to another coordinate. */
bool Board::movePiece(const std::string &fromCoords, const std::string &toCoords)
{
	// TODO: Improve error checking by verifying that coordinates are valid.

	std::cout << "Attempting to move from " << fromCoords << " to " << toCoords << std::endl;

	// When the interior setPiece() function is called it sets the piece currently at that location (fromCoords) to
	// nullptr and then returns a pointer to the piece that was previously at that location. That piece is then assigned
	// to the square referenced by the parameter toCoords. Properly handles absence of a piece at a location.
	if (getPiece(fromCoords) != nullptr)
	{
		setPiece(toCoords, setPiece(fromCoords, nullptr));
		return true;
	}
	else
	{
		std::cout << "Error: Cannot move from " << fromCoords << " because there's no piece there" << std::endl;
		return false;
	}
}

/* Destructor */
Board::~Board() = default;
