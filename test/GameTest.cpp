#define CATCH_CONFIG_MAIN

#include "../include/catch.hpp"
#include "../source/Board.hpp"
#include "../source/Game.hpp"

TEST_CASE("Check condition")
{
	Game game;

	// Neither black nor white is in check
	REQUIRE(game.isInCheck(WHITE) == false);
	REQUIRE(game.isInCheck(BLACK) == false);

	// Set up a check situation (scholar's mate)
	game.move(std::make_pair(6,4), std::make_pair(4,4)); 	// white pawn to e4
	game.move(std::make_pair(1,4), std::make_pair(3,4));	// black pawn to e5
	game.move(std::make_pair(7,5), std::make_pair(4,2));	// white bishop to c4
	game.move(std::make_pair(0,1), std::make_pair(2,2));	// black knight to c6
	game.move(std::make_pair(7,3), std::make_pair(3,7));	// white queen to h5
	game.move(std::make_pair(0,6), std::make_pair(2,5));	// black knight to f6
	game.move(std::make_pair(3,7), std::make_pair(1,5));	// white queen to f7

	// White is still not in check
	REQUIRE(game.isInCheck(WHITE) == false);

	// Black is now in check
	REQUIRE(game.isInCheck(BLACK) == true);

}
