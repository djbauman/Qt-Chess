#ifndef CAPSTONE_GAME_HPP
#define CAPSTONE_GAME_HPP

#include <iostream>
#include "Board.hpp"

class Game
{
public:
	void run();
private:
	Board board;
};

#endif
