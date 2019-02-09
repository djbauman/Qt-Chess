#include "Game.hpp"

void Game::run()
{
	std::cout << "Starting board for Pawn Bowl 2019" << std::endl;
	board.printBoard();
	board.movePiece(std::pair{6,0}, std::pair{4, 0});
	board.printBoard();
	board.movePiece(std::pair{1,0}, std::pair{3, 0});
	board.printBoard();
	board.movePiece(std::pair{6,1}, std::pair{4, 1});
	board.printBoard();
	board.movePiece(std::pair{3,0}, std::pair{4, 1});
	board.printBoard();
	std::cout << "Capture!" << std::endl;
	board.movePiece(std::pair{4,0}, std::pair{4, 1});
}