#include "Game.hpp"

void Game::run()
{
	board.printBoard();
	board.movePiece(std::make_pair(6, 0), std::make_pair(6, 1));
	board.printBoard();
}