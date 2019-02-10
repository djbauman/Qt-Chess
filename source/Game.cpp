#include "Game.hpp"

void Game::run()
{
	std::cout << "Starting board for Rook Bowl 2019" << std::endl;
	board.printBoard();
	board.movePiece(std::make_pair(6,0), std::make_pair(4, 0));
	board.printBoard();
	board.movePiece(std::make_pair(1,0), std::make_pair(3, 0));
	board.printBoard();
	board.movePiece(std::make_pair(6,1), std::make_pair(4, 1));
	board.printBoard();
	board.movePiece(std::make_pair(3,0), std::make_pair(4, 1));
	board.printBoard();
	std::cout << "Capture!" << std::endl;
	board.movePiece(std::make_pair(4,0), std::make_pair(4, 1));

	std::cout << "Enter the Rook....." << std::endl;
	board.movePiece(std::make_pair(0, 0), std::make_pair(4, 0));
	board.printBoard();
	std::cout << "Oh shit son!" << std::endl;

	board.movePiece(std::make_pair(7, 0), std::make_pair(4, 0));
	board.printBoard();
	std::cout << "What uppppppp" << std::endl;

	board.movePiece(std::make_pair(4, 0), std::make_pair(4, 4));
	board.printBoard();
	std::cout << "That should not work" << std::endl;

	board.movePiece(std::make_pair(4, 0), std::make_pair(4, 1));
	board.printBoard();
	std::cout << "That should" << std::endl;

	board.movePiece(std::make_pair(4, 1), std::make_pair(4, 4));
	board.printBoard();
	std::cout << "That should" << std::endl;

	board.movePiece(std::make_pair(4, 4), std::make_pair(6, 6));
	board.printBoard();
	std::cout << "That should not" << std::endl;

}