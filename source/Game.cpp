#include <vector>
#include <string>
#include <sstream>
#include "Game.hpp"

/* Basic implementation of chess. No players, no checkmate, etc. */
void Game::run()
{

	// TODO: Make turn-based
	// TODO: Check game state (check, stalemate, etc.)

	std::string input;

	board.printBoardAlgebraicAxes();
	std::cout << "Enter a space-separated move (like e6 e5): ";
	std::getline(std::cin, input);

	while (input != "-1")
	{
		std::string buf;					// for parsing input
		std::stringstream ss(input);       	// insert the string into a stream
		std::vector<std::string> tokens; 	// create vector to hold substrings

		while (ss >> buf)
		{
			tokens.push_back(buf);
		}

		std::pair<int, int> from = board.algebraicToInt(tokens[0]); 	// convert substring to pair
		std::pair<int, int> to = board.algebraicToInt(tokens[1]);		// convert substring to pair

		board.movePiece(from, to);

		board.printBoardAlgebraicAxes();
		std::cout << "Enter a space-separated move (like e6 e5): ";
		std::getline(std::cin, input);
	}
}

/* For trying out different chess play configurations. */
void Game::testRun()
{
	std::cout << "Starting board for move testing\n";
	board.printBoardAlgebraicAxes();

	std::cout << "Testing pawns moving 1 space\n";
	board.movePiece(std::make_pair(6, 0), std::make_pair(5, 0));
	board.printBoardAlgebraicAxes();
	board.movePiece(std::make_pair(1, 1), std::make_pair(2, 1));
	board.printBoardAlgebraicAxes();

	std::cout << "Testing pawns moving 2 spaces\n";
	board.movePiece(std::make_pair(6, 4), std::make_pair(4, 4));
	board.printBoardAlgebraicAxes();
	board.movePiece(std::make_pair(1, 3), std::make_pair(3, 3));
	board.printBoardAlgebraicAxes();

	std::cout << "Testing pawn capture (enemy)\n";
	board.movePiece(std::make_pair(4, 4), std::make_pair(3, 3));
	board.printBoardAlgebraicAxes();

	std::cout << "Testing pawn capture (friendly) (should fail)\n";
	board.movePiece(std::make_pair(6, 1), std::make_pair(5, 0));
	board.printBoardAlgebraicAxes();

	std::cout << "Testing pawn moving backwards (white) (should fail)\n";
	board.movePiece(std::make_pair(5, 0), std::make_pair(6, 0));
	board.printBoardAlgebraicAxes();

	std::cout << "Testing pawn moving backwards (black) (should fail)\n";
	board.movePiece(std::make_pair(2, 1), std::make_pair(1, 1));
	board.printBoardAlgebraicAxes();

	std::cout << "Testing already moved pawn moving 2 squares (should fail)\n"; // Error, doesn't fail
	board.movePiece(std::make_pair(5, 0), std::make_pair(3, 0));
	board.printBoardAlgebraicAxes();

	std::cout << "Testing bishop moving forward\n";
	board.movePiece(std::make_pair(0, 2), std::make_pair(1, 1));
	board.printBoardAlgebraicAxes();

	std::cout << "Testing bishop capturing\n";
	board.movePiece(std::make_pair(1, 1), std::make_pair(3, 3));
	board.printBoardAlgebraicAxes();

	std::cout << "Testing bishop moving into friendly piece (should fail)\n";
	board.movePiece(std::make_pair(3, 3), std::make_pair(1, 5));
	board.printBoardAlgebraicAxes();

	std::cout << "Testing rook moving vertically\n";
	board.movePiece(std::make_pair(7, 0), std::make_pair(5, 0));
	board.printBoardAlgebraicAxes();

	std::cout << "Testing rook moving horizontally\n";
	board.movePiece(std::make_pair(0, 0), std::make_pair(0, 3));
	board.printBoardAlgebraicAxes();

	std::cout << "Testing rook moving into friendly piece (should fail)\n";
	board.movePiece(std::make_pair(0, 3), std::make_pair(0, 5));
	board.printBoardAlgebraicAxes();

	std::cout << "Testing rook moving through piece (should fail)\n";
	board.movePiece(std::make_pair(0, 7), std::make_pair(0, 4));
	board.printBoardAlgebraicAxes();

	std::cout << "Testing rook capturing\n";
	board.movePiece(std::make_pair(3, 3), std::make_pair(5, 5));
	board.printBoardAlgebraicAxes();
	board.movePiece(std::make_pair(5, 0), std::make_pair(5, 5));
	board.printBoardAlgebraicAxes();

	std::cout << "Testing Queen Move\n";
	board.movePiece(std::make_pair(0, 3), std::make_pair(4, 3));
	board.printBoardAlgebraicAxes();
	board.movePiece(std::make_pair(4, 3), std::make_pair(6, 5));
	board.printBoardAlgebraicAxes();

	std::cout << "Testing Queen Move Error\n";
	board.movePiece(std::make_pair(6, 5), std::make_pair(0, 3));
	board.printBoardAlgebraicAxes();

	std::cout << "Testing Queen Diag Other\n";
	board.movePiece(std::make_pair(6, 5), std::make_pair(4, 7));
	board.printBoardAlgebraicAxes();
}

bool Game::isInCheck(Color defendingColor) const
{
	// We'll use this to get the opposing sides' pieces
	Color attackingColor;
	if (defendingColor == WHITE)
	{
		attackingColor = BLACK;
	}
	else
	{
		attackingColor = WHITE;
	}

	// Get locations of defending king and attacking pieces
	std::pair<int, int> kingLocation = board.getKingLocation(defendingColor);
	std::vector<std::pair<int, int>> pieceLocations = board.getPieceLocations(attackingColor);

	for (auto attackingPiece : pieceLocations)
	{
		if (board.isValidMove(attackingPiece, kingLocation))
		{
			return true;
		}
	}

	// When you come at the king, you best not miss
	return false;
}

bool Game::move(std::pair<int, int> fromCoords, std::pair<int, int> toCoords)
{
	return board.movePiece(fromCoords, toCoords);
}

void Game::printBoard()
{
	board.printBoardAlgebraicAxes();
}
