#ifndef CAPSTONE_GAME_HPP
#define CAPSTONE_GAME_HPP

#include <iostream>
#include "Board.hpp"

class Game
{
public:
	// Start game
	void run();
	void testRun();

	// Movement
	bool move(std::pair<int,int> fromCoords, std::pair<int,int> toCoords);

	// Attributes
	bool isInCheck(Color defendingColor) const;

	// Utilities
	void printBoard();

private:
	Board board;
};

#endif
