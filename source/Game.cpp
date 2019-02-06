#include "Game.hpp"

void Game::run()
{
	board.printBoard();

	board.movePiece("a2", "a3");

	board.printBoard();
}