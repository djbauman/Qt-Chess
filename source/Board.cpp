#include <iostream>
#include <memory>
#include "Board.hpp"
#include "Piece.hpp"
#include "Pawn.hpp"

/* Constructor */
Board::Board()
{
	prepSquares();
	prepPieces();
}

/* Squares are stored in a map which maps coordinates as a pair to a unique_ptr to a Square object. For example, the
 * location that corresponds to a8 in algebraic notation would be at std::pair<0,0>.*/
void Board::prepSquares()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			squares.insert(std::pair{std::pair{i, j}, std::make_unique<Square>()});
		}
	}
}

/* Creates and places the appropriate pieces on the appropriate spots to start a game. */
void Board::prepPieces()
{
	// TODO: Fill out the rest of the pieces.

	// White pawns
	setPiece(std::pair{6, 0}, std::make_unique<Pawn>(WHITE));
	setPiece(std::pair{6, 1}, std::make_unique<Pawn>(WHITE));
	setPiece(std::pair{6, 2}, std::make_unique<Pawn>(WHITE));
	setPiece(std::pair{6, 3}, std::make_unique<Pawn>(WHITE));
	setPiece(std::pair{6, 4}, std::make_unique<Pawn>(WHITE));
	setPiece(std::pair{6, 5}, std::make_unique<Pawn>(WHITE));
	setPiece(std::pair{6, 6}, std::make_unique<Pawn>(WHITE));
	setPiece(std::pair{6, 7}, std::make_unique<Pawn>(WHITE));

	// Black pawns
	setPiece(std::pair{1, 0}, std::make_unique<Pawn>(BLACK));
	setPiece(std::pair{1, 1}, std::make_unique<Pawn>(BLACK));
	setPiece(std::pair{1, 2}, std::make_unique<Pawn>(BLACK));
	setPiece(std::pair{1, 3}, std::make_unique<Pawn>(BLACK));
	setPiece(std::pair{1, 4}, std::make_unique<Pawn>(BLACK));
	setPiece(std::pair{1, 5}, std::make_unique<Pawn>(BLACK));
	setPiece(std::pair{1, 6}, std::make_unique<Pawn>(BLACK));
	setPiece(std::pair{1, 7}, std::make_unique<Pawn>(BLACK));
}

/* Sets a piece to its appropriate location in the map. */
std::unique_ptr<Piece> Board::setPiece(const std::pair<int, int> &coords, std::unique_ptr<Piece> piece)
{
	return squares[coords]->setPiece(std::move(piece));
}

/* Returns the piece at a given square. Finds the element in the map, then returns the Square part of that element, then
 * gets the piece at that square. */
const Piece* Board::getPiece(const std::pair<int, int> &coords) const
{
	return squares.find(coords)->second->getPiece();
}

/* Print contents of board with black on top and white on bottom by creating a series of coordinates and then finding
 * the pieces at those coordinates. */
void Board::printBoard()
{
	int i = 1;
	for (auto const &[key, val] : squares)								// loop over contents of squares
	{
		const Piece* piece = squares.find(key)->second->getPiece();		// get the piece at the square
		if (piece == nullptr)
		{
			std::cout << "   ";											// no piece here, so print filler
		}
		else
		{
			std::cout << *piece;										// print piece
		}
		std::cout << " ";

		if (i % 8 == 0)
		{
			std::cout << std::endl;										// print newline every 8 columns
		}
		i++;
	}
}

/* Moves a piece at one coordinate to another coordinate. */
bool Board::movePiece(const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords)
{
	std::cout << "Attempting to move from "
	<< fromCoords.first << "," << fromCoords.second
	<< " to " << toCoords.first << "," << toCoords.second << std::endl;

	// Check if from and to locations are on the board
	if (!isOnBoard(fromCoords) || !isOnBoard(toCoords))
	{
		std::cout << "Error: Coords are out of bounds" << std::endl;
		return false;
	}

	// Check if from location is occupied
	if (!isOccupied(fromCoords))
	{
		std::cout << "Error: Cannot move from "
		<< fromCoords.first << "," << fromCoords.second
		<< " because there's no piece there" << std::endl;
		return false;
	}

	// Check if this is a valid move for this piece
	const Piece *piece = getPiece(fromCoords);
	if (!piece->isValidMove(this, fromCoords, toCoords))
	{
		std::cout << "Error: This is an invalid move for this type of piece";
		return false;
	}

	// All other checks have passed to we can set the piece

	// When the interior setPiece() function is called it sets the piece currently at that location (fromCoords) to
	// nullptr and then returns a pointer to the piece that was previously at that location. That piece is then assigned
	// to the square referenced by the parameter toCoords. Properly handles absence of a piece at a location.
	setPiece(toCoords, setPiece(fromCoords, nullptr));
	return true;
}

std::pair<int, int> Board::algebraicToInt(std::string algebraicCoords) const
{
	// TODO: Implement. Commented out code below may be helpful.
//	const std::string letters = "abcdefgh";
//	for (int i = 8; i >= 1; i--) 	// for iterating over numerals 1 through 8
//	{
//		for (int j = 0; j < 8; j++) // for iterating over letters a through g
//		{
//			std::pair<int,int> coords = std::make_pair(letters[j] - '0', i);// create coordinates
//			const Piece* piece = squares.find(coords)->second->getPiece();	// get piece (or nullptr) at that coordinate
//			if (piece == nullptr) {
//				std::cout << "   ";											// no piece here so print empty space
//			}
//			else
//			{
//				std::cout << *piece;										// print piece
//			}
//			std::cout << " ";												// print spacing to separate pieces
//		}
//		std::cout << std::endl;												// move to next line
//	}
	return std::pair<int, int>();
}

std::string Board::intToAlgebraic(std::pair<int, int> intCoords) const
{
	// TODO: Implement. Commented out code below may be helpful.
//	const std::string letters = "abcdefgh";
//	for (int i = 8; i >= 1; i--) 	// for iterating over numerals 1 through 8
//	{
//		for (int j = 0; j < 8; j++) // for iterating over letters a through g
//		{
//			std::pair<int,int> coords = std::make_pair(letters[j] - '0', i);// create coordinates
//			const Piece* piece = squares.find(coords)->second->getPiece();	// get piece (or nullptr) at that coordinate
//			if (piece == nullptr) {
//				std::cout << "   ";											// no piece here so print empty space
//			}
//			else
//			{
//				std::cout << *piece;										// print piece
//			}
//			std::cout << " ";												// print spacing to separate pieces
//		}
//		std::cout << std::endl;												// move to next line
//	}
//	return std::pair<int, int>();
	return std::string();
}

/* Checks if a given location is on the board */
bool Board::isOnBoard(const std::pair<int, int> &coords)
{
	if (coords.first < 0 || coords.first > 7)
	{
		return false;
	}
	else if (coords.second < 0 || coords.second > 7)
	{
		return false;
	}
	else
	{
		return true;
	}
}

/* Checks if a particular square is occupied. Returns true if so, false otherwise. */
bool Board::isOccupied(const std::pair<int, int> &coords) const
{
	return getPiece(coords) != nullptr;
}

/* If the column remains unchanged over the course of the move, then it's a vertical move. */
bool Board::isVerticalMove(const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords)
{
	return fromCoords.second == toCoords.second;
}

/* If the row remains unchanged over the course of the move, then it's a horizontal move. */
bool Board::isHorizontalMove(const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords)
{
	return fromCoords.first == toCoords.first;
}

/* If the (absolute value of the) horizontal movement is equal to the (absolute value of the) vertical movement,
 * then the movement is diagonal. */
bool Board::isDiagonalMove(const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords)
{
	int verticalDifference = toCoords.first - fromCoords.first;
	int horizontalDifference = toCoords.second - fromCoords.second;

	return abs(verticalDifference) == abs(horizontalDifference);
}

/* Destructor */
Board::~Board() = default;
