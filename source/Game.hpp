#ifndef CAPSTONE_GAME_HPP
#define CAPSTONE_GAME_HPP

#include <iostream>
#include "Board.hpp"

class Game
{
public:
	void run();
	void testRun();
private:
	Board board;
};

#endif
