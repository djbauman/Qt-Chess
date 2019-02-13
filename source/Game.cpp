#include "Game.hpp"

void Game::run()
{
	std::cout << "Starting board for move testing\n";
	board.printBoard();

	std::cout << "Testing pawns moving 1 space\n";
	board.movePiece(std::make_pair(6, 0), std::make_pair(5, 0));
	board.printBoard();
	board.movePiece(std::make_pair(1, 1), std::make_pair(2, 1));
	board.printBoard();

	std::cout << "Testing pawns moving 2 spaces\n";
	board.movePiece(std::make_pair(6, 4), std::make_pair(4, 4));
	board.printBoard();
	board.movePiece(std::make_pair(1, 3), std::make_pair(3, 3));
	board.printBoard();

	std::cout << "Testing pawn capture (enemy)\n";
	board.movePiece(std::make_pair(4, 4), std::make_pair(3, 3));
	board.printBoard();

	std::cout << "Testing pawn capture (friendly) (should fail)\n";
	board.movePiece(std::make_pair(6, 1), std::make_pair(5, 0));
	board.printBoard();

	std::cout << "Testing pawn moving backwards (white) (should fail)\n";
	board.movePiece(std::make_pair(5, 0), std::make_pair(6, 0));
	board.printBoard();

	std::cout << "Testing pawn moving backwards (black) (should fail)\n";
	board.movePiece(std::make_pair(2, 1), std::make_pair(1, 1));
	board.printBoard();

	std::cout << "Testing already moved pawn moving 2 squares (should fail)\n"; // Error, doesn't fail
	board.movePiece(std::make_pair(5, 0), std::make_pair(3, 0));
	board.printBoard();

	std::cout << "Testing bishop moving forward\n";
	board.movePiece(std::make_pair(0, 2), std::make_pair(1, 1));
	board.printBoard();

	std::cout << "Testing bishop capturing\n";
	board.movePiece(std::make_pair(1, 1), std::make_pair(3, 3));
	board.printBoard();

	std::cout << "Testing bishop moving into friendly piece (should fail)\n";
	board.movePiece(std::make_pair(3, 3), std::make_pair(1, 5));
	board.printBoard();

	std::cout << "Testing rook moving vertically\n";
	board.movePiece(std::make_pair(7, 0), std::make_pair(5, 0));
	board.printBoard();

	std::cout << "Testing rook moving horizontally\n";
	board.movePiece(std::make_pair(0, 0), std::make_pair(0, 3));
	board.printBoard();

	std::cout << "Testing rook moving into friendly piece (should fail)\n";
	board.movePiece(std::make_pair(0, 3), std::make_pair(0, 5));
	board.printBoard();

	std::cout << "Testing rook moving through piece (should fail)\n";
	board.movePiece(std::make_pair(0, 7), std::make_pair(0, 4));
	board.printBoard();

	std::cout << "Testing rook capturing\n";
	board.movePiece(std::make_pair(3, 3), std::make_pair(5, 5));
	board.printBoard();
	board.movePiece(std::make_pair(5, 0), std::make_pair(5, 5));
	board.printBoard();

	std::cout << "Testing Queen Move\n";
	board.movePiece(std::make_pair(0, 3), std::make_pair(4, 3));
	board.printBoard();
	board.movePiece(std::make_pair(4, 3), std::make_pair(6, 5));
	board.printBoard();

	std::cout << "Testing Queen Move Error\n";
	board.movePiece(std::make_pair(6, 5), std::make_pair(0, 3));
	board.printBoard();

	std::cout << "Testing Queen Diag Other\n";
	board.movePiece(std::make_pair(6, 5), std::make_pair(4, 7));
	board.printBoard();

}