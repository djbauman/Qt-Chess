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
	// TODO: This is only partway filled. We could either list these out (over 64 lines) or create a loop which
	//		creates these dynamically.

	squares.insert(std::make_pair("a1", std::make_unique<Square>()));
	squares.insert(std::make_pair("b1", std::make_unique<Square>()));
	squares.insert(std::make_pair("a2", std::make_unique<Square>()));
	squares.insert(std::make_pair("b2", std::make_unique<Square>()));
	squares.insert(std::make_pair("a3", std::make_unique<Square>()));
	squares.insert(std::make_pair("b3", std::make_unique<Square>()));
}

/* Creates and places the appropriate pieces on the appropriate spots to start a game. */
void Board::prepPieces()
{
	// TODO: Fill out the rest of the pieces.

	// White Pawn Placement
	setPiece("a2", std::make_unique<Pawn>(WHITE));
	setPiece("b2", std::make_unique<Pawn>(WHITE));
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

/* Print contents of board. */
void Board::printBoard()
{
	// TODO: This currently just prints the board as a list of coordinates. Eventually we'll want to turn this into
	// 		an actual board.

	// Iterate over the map and print each element. If there's a piece there, print the piece.
	for (const auto &element : squares) {

		if (element.second->getPiece() == nullptr) {
			std::cout << element.first;
		}
		else
		{
			std::cout << element.first << " " << *element.second->getPiece();
		}
		std::cout << std::endl;
	}
}

/* Moves a piece at one coordinate to another coordinate. */
bool Board::movePiece(const std::string &fromCoords, const std::string &toCoords)
{
	// TODO: Implement error checking. If there is no piece at the from location, or if squares don't exist,
	//  	program will crash.

	// When the interior setPiece() function is called it sets the piece currently at that location (fromCoords) to
	// nullptr and then returns a pointer to the piece that was previously at that location. That piece is then assigned
	// to the square referenced by the parameter toCoords.
	setPiece(toCoords, setPiece(fromCoords, nullptr));
	return false;
}

/* Destructor */
Board::~Board() = default;
