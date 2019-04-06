#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include "Board.hpp"
#include "Piece.hpp"
#include "Pawn.hpp"
#include "Rook.hpp"
#include "Bishop.hpp"
#include "Knight.hpp"
#include "King.hpp"
#include "Queen.hpp"


/* Constructor */
Board::Board()
{
	prepSquares();
	createPawns();
	createRooks();
	createKnights();
	createBishops();
	createQueens();
	createKings();
}

/* Unit Test Constructor
 * This creates a board with the pieces specified by argument parameters */
Board::Board(bool Pawns, bool Knights, bool Rooks, bool Bishops, bool Queens, bool Kings)
{
	prepSquares();
	if (Pawns)
		{ createPawns(); }
	if (Rooks)
		{ createRooks(); }
	if (Knights)
		{ createKnights(); }
	if (Bishops)
		{ createBishops(); }
	if (Queens)
		{ createQueens(); }
	if (Kings)
		{ createKings(); }
}

/* Squares are stored in a map which maps coordinates as a pair to a unique_ptr to a Square object. For example, the
 * location that corresponds to a8 in algebraic notation would be at std::pair<0,0>.*/
void Board::prepSquares()
{
	for (int i = 0; i < 8; i++)
	{

		for (int j = 0; j < 8; j++)
		{
			squares.insert(std::pair <std::pair <int, int>, std::unique_ptr<Square>> (std::make_pair(i, j), std::make_unique<Square>()));
		}
	}
}

/* Creates and places the appropriate Pawns on the appropriate spots to start a game. */
void Board::createPawns()
{
	// White pawns
	setPiece(std::make_pair(6, 0), std::make_unique<Pawn>(WHITE));
	setPiece(std::make_pair(6, 1), std::make_unique<Pawn>(WHITE));
	setPiece(std::make_pair(6, 2), std::make_unique<Pawn>(WHITE));
	setPiece(std::make_pair(6, 3), std::make_unique<Pawn>(WHITE));
	setPiece(std::make_pair(6, 4), std::make_unique<Pawn>(WHITE));
	setPiece(std::make_pair(6, 5), std::make_unique<Pawn>(WHITE));
	setPiece(std::make_pair(6, 6), std::make_unique<Pawn>(WHITE));
	setPiece(std::make_pair(6, 7), std::make_unique<Pawn>(WHITE));

	// Black pawns
	setPiece(std::make_pair(1, 0), std::make_unique<Pawn>(BLACK));
	setPiece(std::make_pair(1, 1), std::make_unique<Pawn>(BLACK));
	setPiece(std::make_pair(1, 2), std::make_unique<Pawn>(BLACK));
	setPiece(std::make_pair(1, 3), std::make_unique<Pawn>(BLACK));
	setPiece(std::make_pair(1, 4), std::make_unique<Pawn>(BLACK));
	setPiece(std::make_pair(1, 5), std::make_unique<Pawn>(BLACK));
	setPiece(std::make_pair(1, 6), std::make_unique<Pawn>(BLACK));
	setPiece(std::make_pair(1, 7), std::make_unique<Pawn>(BLACK));
}

/* Creates and places the appropriate Rooks on the appropriate spots to start a game. */
void Board::createRooks()
{
	// White Rooks
	setPiece(std::make_pair(7, 0), std::make_unique<Rook>(WHITE));
	setPiece(std::make_pair(7, 7), std::make_unique<Rook>(WHITE));

	// Black Rooks
	setPiece(std::make_pair(0, 0), std::make_unique<Rook>(BLACK));
	setPiece(std::make_pair(0, 7), std::make_unique<Rook>(BLACK));
}

/* Creates and places the appropriate Knights on the appropriate spots to start a game. */
void Board::createKnights()
{
	// White Knights
	setPiece(std::make_pair(7, 1), std::make_unique<Knight>(WHITE));
	setPiece(std::make_pair(7, 6), std::make_unique<Knight>(WHITE));

	// Black Knights
	setPiece(std::make_pair(0, 1), std::make_unique<Knight>(BLACK));
	setPiece(std::make_pair(0, 6), std::make_unique<Knight>(BLACK));
}

/* Creates and places the appropriate Bishops on the appropriate spots to start a game. */
void Board::createBishops()
{
	// White Bishops
	setPiece(std::make_pair(7, 2), std::make_unique<Bishop>(WHITE));
	setPiece(std::make_pair(7, 5), std::make_unique<Bishop>(WHITE));

	// Black Bishops
	setPiece(std::make_pair(0, 2), std::make_unique<Bishop>(BLACK));
	setPiece(std::make_pair(0, 5), std::make_unique<Bishop>(BLACK));
}

/* Creates and places the appropriate Queens on the appropriate spots to start a game. */
void Board::createQueens()
{
	// White Queen
	setPiece(std::make_pair(7, 3), std::make_unique<Queen>(WHITE));

	// Black Queen
	setPiece(std::make_pair(0, 3), std::make_unique<Queen>(BLACK));
}

/* Creates and places Kings on the appropriate spots to start a game. */
void Board::createKings()
{
	// White King
	setPiece(std::make_pair(7, 4), std::make_unique<King>(WHITE));

	// Black King
	setPiece(std::make_pair(0, 4), std::make_unique<King>(BLACK));
}

/* Sets a piece to its appropriate location in the map. */
std::unique_ptr<Piece> Board::setPiece(const std::pair<int, int> &coords, std::unique_ptr<Piece> piece)
{
	return squares[coords]->setPiece(std::move(piece));
}

/* Returns the piece at a given square. Finds the element in the map, then returns the Square part of that element, then
 * gets the piece at that square. */
Piece* Board::getPiece(const std::pair<int, int> &coords) const
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
			std::cout << " -- ";										// no piece here, so print filler
		}
		else
		{
			std::cout << *piece;										// print piece
		}

		if (i % 8 == 0)
		{
			std::cout << "\n";											// print newline every 8 columns
		}
		i++;

		// This variable is currently unused - so this silences the compiler warnings
		(void) val;
	}
	std::cout << "\n" << "\n";
}

/* Prints the board with algebraic notation along the axes. Not the prettiest code I've ever written. */
void Board::printBoardAlgebraicAxes()
{
	int iterator = 1;
	int row = 8;
	std::cout << "    a   b   c   d   e   f   g   h" << "\n\n";
	for (auto const &[key, val] : squares)								// loop over contents of squares
	{
		if ((iterator - 1) % 8 == 0)
		{
			std::cout << row << "  ";									// print row number at beginning of column
		}

		const Piece* piece = squares.find(key)->second->getPiece();		// get the piece at the square
		if (piece == nullptr)
		{
			std::cout << " -- ";										// no piece here, so print filler
		}
		else
		{
			std::cout << *piece;										// print piece
		}

		if (iterator % 8 == 0)
		{
			std::cout << "  " << row;									// print row number at end of column
			row--;
			std::cout << '\n';											// print newline every 8 columns
		}
		iterator++;

		// This variable is currently unused - so this silences the compiler warnings
		(void) val;
	}
	std::cout << '\n';
	std::cout << "    a   b   c   d   e   f   g   h" << '\n';
}

/* Attempts to move a piece from one location to another. Checks the following:
 * - If origin and destination are on the board
 * - If destination is occupied by piece of same color as piece at origin
 * - If this is a valid move for the piece at the the origin
 * Note that this function does not check gameplay characteristics like check and checkmate.
 * */
bool Board::movePiece(const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords)
{
	if (isValidMove(fromCoords, toCoords))
	{
		// All checks have passed so we can set the piece

		// If the piece represents a capture (i.e., destination is occupied), then save captured piece
		if (squares[toCoords]->getPiece() != nullptr)
		{
			size_t index = moves.size();
			capturedPieces.insert(std::pair<int, std::unique_ptr<Piece>>(index, setPiece(toCoords, nullptr)));
		}

		// When the interior setPiece() function is called it sets the piece currently at that location (fromCoords) to
		// nullptr and then returns a pointer to the piece that was previously at that location. That piece is then assigned
		// to the square referenced by the parameter toCoords. Properly handles absence of a piece at a location.
		setPiece(toCoords, setPiece(fromCoords, nullptr));

		// Record that piece has moved
		getPiece(toCoords)->incrementMoves();
		moves.emplace_back(fromCoords, toCoords);

		return true;
	}

	return false;
}

/* Converts algebraic coordinates to integer coordinates. For example: "a8" -> "0,0" */
std::pair<int, int> Board::algebraicToInt(std::string algebraicCoords) const
{
	int col = algebraicCoords[0] - 'a'; 			// shift ascii letter to integer
	int row = 8 - (algebraicCoords[1] - '0');		// shift ascii letter to integer and flip
	return std::make_pair(row,col);
}

/* Converts integer coordinates to algebraic coordinates. For example: "0,0" -> "a8" */
std::string Board::intToAlgebraic(std::pair<int, int> intCoords) const
{
	char row = static_cast<char>(8 - intCoords.first + '0');	// shift int to ascii letter and flip
	char col = static_cast<char>(intCoords.second + 'a');		// shift int to ascii letter
	std::string coords = std::string() + col + row;     		// form string from chars
	return coords;
}

/* Checks if a given location is on the board */
bool Board::isOnBoard(const std::pair<int, int> &coords) const
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

/* Returns true if the destination is occupied by a piece of same color as the origin, false otherwise. */
bool Board::isOccupiedSameColor(const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords) const
{
	const Piece *fromPiece = getPiece(fromCoords);
	Color fromColor;
	if (fromPiece != nullptr)
	{
		fromColor = fromPiece->getColor();
	}
	else
	{
		return false;
	}

	const Piece *toPiece = getPiece(toCoords);
	Color toColor;
	if (toPiece != nullptr)
	{
		toColor = toPiece->getColor();
	}
	else
	{
		return false;
	}

	return fromColor == toColor;
}

/* Returns true if the destination is occupied by a piece of different color as the origin, false otherwise. */
bool Board::isOccupiedDifferentColor(const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords) const
{
	const Piece *fromPiece = getPiece(fromCoords);
	Color fromColor;
	if (fromPiece != nullptr)
	{
		fromColor = fromPiece->getColor();
	}
	else
	{
		return false;
	}

	const Piece *toPiece = getPiece(toCoords);
	Color toColor;
	if (toPiece != nullptr)
	{
		toColor = toPiece->getColor();
	}
	else
	{
		return false;
	}

	return fromColor != toColor;
}

/* If the column remains unchanged over the course of the move, then it's a vertical move. */
bool Board::isVerticalMove(const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords) const
{
	return fromCoords.second == toCoords.second;
}

/* If the row remains unchanged over the course of the move, then it's a horizontal move. */
bool Board::isHorizontalMove(const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords) const
{
	return fromCoords.first == toCoords.first;
}

/* If the (absolute value of the) horizontal movement is equal to the (absolute value of the) vertical movement,
 * then the movement is diagonal. */
bool Board::isDiagonalMove(const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords) const
{
	int verticalDifference = toCoords.first - fromCoords.first;
	int horizontalDifference = toCoords.second - fromCoords.second;

	return abs(verticalDifference) == abs(horizontalDifference);
}

/* Returns the number of steps necessary to complete a move from one locations a to b. If a and b are the same location
 * then it returns 0, if adjacent, 1, etc. Moving up one square and to the right one square (i.e. a diagonal move to
 * the northeast) would return 1, rather than sqrt(2). Let's not get crazy. */
int Board::getMoveLength(const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords) const
{
	if (isVerticalMove(fromCoords, toCoords))
	{
		return abs(toCoords.first - fromCoords.first);
	}
	else if (isHorizontalMove(fromCoords, toCoords))
	{
		return abs(toCoords.second - fromCoords.second);
	}
	else if (isDiagonalMove(fromCoords, toCoords))
	{
		// We've already verified that this is a diagonal move, so we can just return the difference along one axis
		return abs(toCoords.first - fromCoords.first);
	}
	else
	{
		// Measuring non-linear distance is essentially undefined, so we'll return -1
		return -1;
	}
}

/* Checks whether there is a clear path between two points. Note that this only checks the intermediate spaces. In
 * other words, if the destination (as recorded in toCoords) is occupied, but all spaces between are empty, then this
 * function will still evaluate to true. The thinking behind this is that for all pieces except the pawn (which has its
 * own rule specified in the Pawn class) whether a piece occupies its destination doesn't prevent its movement, it only
 * determines whether that movement results in a capture. */
bool Board::isPathClear(const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords) const
{
	// Gather some information about the move
	int moveLength = getMoveLength(fromCoords, toCoords);
	bool isVertical = isVerticalMove(fromCoords, toCoords);
	bool isHorizontal = isHorizontalMove(fromCoords, toCoords);
	bool isDiagonal = isDiagonalMove(fromCoords, toCoords);
	bool movingSouth = fromCoords.first < toCoords.first; 			// "south" meaning from black side to white side
	bool movingEast = fromCoords.second < toCoords.second;			// "east" meaning from white left to white right

	// If same or adjacent location, then path is definitely clear
	if (moveLength == 0 || moveLength == 1)
	{
		return true;
	}

	// Check intermediate locations between fromCoords and toCoords for vacancy
	std::pair<int,int> fromTemp = fromCoords;
	std::pair<int,int> toTemp = toCoords;
	if (isVertical)
	{
		// We can halve the number of for-loops if we swap the start and end points depending on the direction of travel
		if (!movingSouth)
		{
			std::swap(fromTemp, toTemp);
		}

		for (int i = fromTemp.first + 1; i < toTemp.first; i++)
		{
			if (isOccupied(std::make_pair(i, fromTemp.second)))
			{
				return false;
			}
		}

		// Checked all intermediate locations and found them to be empty, so can return true
		return true;
	}
	else if (isHorizontal)
	{
		// We can halve the number of for-loops if we swap the start and end points depending on the direction of travel
		if (!movingEast)
		{
			std::swap(fromTemp, toTemp);
		}

		for (int i = fromTemp.second + 1; i < toTemp.second; i++)
		{
			if (isOccupied(std::make_pair(fromTemp.first, i)))
			{
				return false;
			}
		}

		// Checked all intermediate locations and found them to be empty, so can return true
		return true;
	}
	else if (isDiagonal)
	{
		if (movingSouth == movingEast) 			// moving southeast or northwest
		{
			// loop assumes southeast travel, swap if that's not the case
			if (!movingSouth && !movingEast)
			{
				std::swap(fromTemp, toTemp);
			}

			int col = fromTemp.second + 1;
			for (int row = fromTemp.first + 1; row < toTemp.first; row++)
			{
				if (isOccupied(std::make_pair(row, col)))
				{
					return false;
				}
				col++;
			}

			// Checked all intermediate locations and found them to be empty, so can return true
			return true;

		}
		else if (movingSouth != movingEast)		// moving northeast or southwest
		{
			// loop assumes northeast travel, swap if that's not the case
			if (movingSouth && !movingEast)
			{
				std::swap(fromTemp, toTemp);
			}

			int col = fromTemp.second + 1;
			for (int row = fromTemp.first - 1; row > toTemp.first; row--)
			{
				if (isOccupied(std::make_pair(row, col)))
				{
					return false;
				}
				col++;
			}

			// Checked all intermediate locations and found them to be empty, so can return true
			return true;
		}
	}

	// path is neither vertical, horizontal, nor diagonal, so it's not a clear path
	return false;
}

/* Determines, based on a piece's color, whether a particular move represents forward movement for that piece. Note that
 * the move does not have to be vertical - diagonal moves can be forward too as long as they are not diagonally backward. */
bool Board::isForwardMove(const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords, const Piece *piece) const
{
	Color pieceColor = piece->getColor();
	if (pieceColor == BLACK && fromCoords.first < toCoords.first)
	{
		return true;
	}
	else if (pieceColor == WHITE && fromCoords.first > toCoords.first)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/* Determines if a move is 2 squares in any direction, and 1 square in a perpendicular direction*/
bool Board::isKnightMove(const std::pair<int, int>& fromCoords, const std::pair<int, int>& toCoords) const
{
	int verticalDifference = abs(toCoords.first - fromCoords.first);
	int horizontalDifference = abs(toCoords.second - fromCoords.second);

	if ((verticalDifference == 2 && horizontalDifference == 1) || (verticalDifference == 1 && horizontalDifference == 2))
	{
		return true;
	}
	else
	{
		return false;
	}

}

/* Determine whether this a valid move. */
bool Board::isValidMove(const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords) const
{
	// TODO: Decide what to do about commented-out console statements.
	// std::cout << "Attempting to move from " << intToAlgebraic(fromCoords) << " to " << intToAlgebraic(toCoords) << '\n';

	// Check if from and to locations are on the board
	if (!isOnBoard(fromCoords) || !isOnBoard(toCoords))
	{
		// std::cout << "Error: Coords are out of bounds" << '\n';
		return false;
	}

	// Check if to location is occupied by piece of same color
	if (isOccupiedSameColor(fromCoords, toCoords))
	{
		// std::cout << "Error: Cannot move from " << intToAlgebraic(fromCoords) << " to " << intToAlgebraic(toCoords)
		// 		  << " because there's a friendly piece at " << intToAlgebraic(toCoords) << '\n';
		return false;
	}

	// Check if this is a valid move for this piece
	const Piece *piece = getPiece(fromCoords);
	if (piece == nullptr)
	{
		// std::cout << "Error: No piece at this starting square" << '\n';
		return false;
	}
	if (!piece->isValidMove(this, fromCoords, toCoords))
	{
		// std::cout << "Error: This is an invalid move for this piece" << '\n';
		return false;
	}

	return true;
}

/* Gathers pointers to all the pieces on the board of a particular color and arranges them in a vector.
 * Note that this vector (and the pieces therein) are for observation purposes only. In other words, this function
 * should not be used to modify the state of the pieces in the vector. */
std::vector<Piece*> Board::getPieces(Color color) const
{
	std::vector<Piece*> pieces;
	pieces.reserve(squares.size());

	for (auto const& square : squares) {
		Piece* piece = square.second->getPiece();
		if (piece != nullptr && piece->getColor() == color)
		{
			pieces.push_back(piece);
		}
	}

	return pieces;
}

/* Returns the location of the king of a particular color. Used to determine check condition. Even though this will
 * likely only be used within Board, it's currently exposed as a public method to allow unit testing. */
std::pair<int, int> Board::getKingLocation(Color color) const
{
	for (auto const& square : squares) {
		Piece* piece = square.second->getPiece();
		if (piece != nullptr && piece->getColor() == color && piece->getType() == KING)
		{
			return square.first;
		}
	}

	// The king is never removed from the board so this should never execute
	return std::make_pair(-1,-1);
}

/* Returns all locations of pieces of a particular color. */
std::vector<std::pair<int, int>> Board::getPieceLocations(Color color) const
{
	std::vector<std::pair<int, int>> pieceLocations;
	pieceLocations.reserve(squares.size());

	for (auto const& square : squares)
	{
		Piece* piece = square.second->getPiece();
		if (piece != nullptr && piece->getColor() == color)
		{
			pieceLocations.push_back(square.first);
		}
	}

	return pieceLocations;
}

/* Print the move history of the board */
void Board::printMoves()
{
	for (auto i : moves)
	{
		std::cout << intToAlgebraic(i.first) << " to " << intToAlgebraic(i.second) << '\n';
	}
}

/* Moves a piece from one location on the board to another WITHOUT ANY ERROR CHECKING OR MOVE VALIDATION. Designed to
 * be used internally for the purposes of reverting movement history. This functionality is necessary because the
 * logic of the movePiece function will only allow "valid" moves. Reversing the movement of a pawn, for example, would
 * not be a valid move, and so would be impossible without a function like this. */
void Board::forceMovePiece(const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords)
{
	// When the interior setPiece() function is called it sets the piece currently at that location (fromCoords) to
	// nullptr and then returns a pointer to the piece that was previously at that location. That piece is then assigned
	// to the square referenced by the parameter toCoords. Properly handles absence of a piece at a location.
	setPiece(toCoords, setPiece(fromCoords, nullptr));

	// Note that this function does not record that a piece has moved, nor does it add it to the list of moves on the
	// board since it is only designed to be used outside the constraints of a normal game.
}

/* Revert the last move on the board. Can be called repeatedly to reverse state to beginning of game. */
void Board::revertLastMove()
{
	// Get last move off the moves vector
	std::pair<std::pair<int, int>, std::pair<int, int>> lastMove = moves.back();

	// Reverse the last move, i.e. if it's A → B then move A ← B
	forceMovePiece(lastMove.second, lastMove.first);

	// If this move represented a capture, replace the piece that was captured
	size_t previousMove = moves.size() - 1;
	if (capturedPieces.find(previousMove) != capturedPieces.end())
	{
		// Move the piece from capturedPieces map to the board
		setPiece(lastMove.second, std::move(capturedPieces[previousMove]));

		// Erase the entry from capturedPieces map
		capturedPieces.erase(previousMove);
	}

	// Remove it from move vector
	moves.pop_back();

	// Decrement move counter in piece
	getPiece(lastMove.first)->decrementMoves();
}

/* Print all pieces in capturedPieces map. */
void Board::printCapturedPieces()
{
	for (auto& entry : capturedPieces)
	{
		std::cout << entry.first << " " << *entry.second << '\n';
	}
}

/* Returns a vector of all the locations on the board. */
std::vector<std::pair<int, int>> Board::getLocations() const
{
	std::vector<std::pair<int, int>> pieceLocations;
	pieceLocations.reserve(squares.size());

	for (auto const& square : squares)
	{
		pieceLocations.push_back(square.first);
	}

	return pieceLocations;
}

/* Allows setting of castle without checking usual move dynamics. Used for castling. */
void Board::setRook(const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords)
{
	forceMovePiece(fromCoords, toCoords);
}

/* Destructor */
Board::~Board() = default;
