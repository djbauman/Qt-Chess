#define CATCH_CONFIG_MAIN

#include "../include/catch.hpp"
#include "../source/Board.hpp"
#include "../source/Game.hpp"

TEST_CASE("Check and checkmate condition with Scholar's Mate")
{
	Game game;
	Board board; 	// only used for coordinate conversions

	// Neither black nor white is in check
	REQUIRE(game.isInCheck(WHITE) == false);
	REQUIRE(game.isInCheck(BLACK) == false);

	// Neither black nor white is in checkmate
	REQUIRE(game.isInCheckMate(WHITE) == false);
	REQUIRE(game.isInCheckMate(BLACK) == false);

	// Set up a check situation (scholar's mate)
	game.move(board.algebraicToInt("e2"), board.algebraicToInt("e4"));
	game.move(board.algebraicToInt("e7"), board.algebraicToInt("e5"));
	game.move(board.algebraicToInt("f1"), board.algebraicToInt("c4"));
	game.move(board.algebraicToInt("b8"), board.algebraicToInt("c6"));
	game.move(board.algebraicToInt("d1"), board.algebraicToInt("h5"));
	game.move(board.algebraicToInt("g8"), board.algebraicToInt("f6"));
	game.move(board.algebraicToInt("h5"), board.algebraicToInt("f7"));

	// White is not in check nor checkmate
	REQUIRE(game.isInCheck(WHITE) == false);
	REQUIRE(game.isInCheckMate(WHITE) == false);

	// Black is now in check and in checkmate
	REQUIRE(game.isInCheck(BLACK) == true);
	REQUIRE(game.isInCheckMate(BLACK) == true);
}

TEST_CASE("Stalemate condition")
{
	Game game;
	Board board; 	// only used for coordinate conversions

	// Neither black nor white is in stalemate
	REQUIRE(game.isInStalemate(WHITE) == false);
	REQUIRE(game.isInStalemate(BLACK) == false);

	// Set up a stalemate situation
	game.move(board.algebraicToInt("e2"), board.algebraicToInt("e3"));
	game.move(board.algebraicToInt("a7"), board.algebraicToInt("a5"));
	game.move(board.algebraicToInt("d1"), board.algebraicToInt("h5"));
	game.move(board.algebraicToInt("a8"), board.algebraicToInt("a6"));
	game.move(board.algebraicToInt("h5"), board.algebraicToInt("a5"));
	game.move(board.algebraicToInt("h7"), board.algebraicToInt("h5"));
	game.move(board.algebraicToInt("h2"), board.algebraicToInt("h4"));
	game.move(board.algebraicToInt("a6"), board.algebraicToInt("h6"));
	game.move(board.algebraicToInt("a5"), board.algebraicToInt("c7"));
	game.move(board.algebraicToInt("f7"), board.algebraicToInt("f6"));
	game.move(board.algebraicToInt("c7"), board.algebraicToInt("d7"));
	game.move(board.algebraicToInt("e8"), board.algebraicToInt("f7"));
	game.move(board.algebraicToInt("d7"), board.algebraicToInt("b7"));
	game.move(board.algebraicToInt("d8"), board.algebraicToInt("d3"));
	game.move(board.algebraicToInt("b7"), board.algebraicToInt("b8"));
	game.move(board.algebraicToInt("d3"), board.algebraicToInt("h7"));
	game.move(board.algebraicToInt("b8"), board.algebraicToInt("c8"));
	game.move(board.algebraicToInt("f7"), board.algebraicToInt("g6"));
	game.move(board.algebraicToInt("c8"), board.algebraicToInt("e6"));

	// White is not in stalemate
	REQUIRE(game.isInStalemate(WHITE) == false);

	// Black is now in stalemate
	REQUIRE(game.isInStalemate(BLACK) == true);
}

TEST_CASE("Castling white")
{
	Game game;
	Board board; 	// only used for coordinate conversions

	// Set up an invalid castling
	game.move(board.algebraicToInt("e2"), board.algebraicToInt("e4"));
	game.move(board.algebraicToInt("e7"), board.algebraicToInt("e5"));
	game.move(board.algebraicToInt("f1"), board.algebraicToInt("a6"));
	game.move(board.algebraicToInt("f8"), board.algebraicToInt("c5"));
	game.move(board.algebraicToInt("g1"), board.algebraicToInt("h3"));
	game.move(board.algebraicToInt("c5"), board.algebraicToInt("d4"));
	game.move(board.algebraicToInt("f2"), board.algebraicToInt("f3"));
	game.move(board.algebraicToInt("d4"), board.algebraicToInt("e3"));

	// Attempt to castle - should return false because leaves king in check
	REQUIRE(game.castle(WHITE, board.algebraicToInt("e1"), board.algebraicToInt("g1")) == false);

	// Set up a valid castling
	game.move(board.algebraicToInt("h3"), board.algebraicToInt("f2"));
	game.move(board.algebraicToInt("d8"), board.algebraicToInt("h4"));

	// Attempt to castle - should succeed
	REQUIRE(game.castle(WHITE, board.algebraicToInt("e1"), board.algebraicToInt("g1")) == true);
}

TEST_CASE("Castling black")
{
	Game game;
	Board board; 	// only used for coordinate conversions

	// Set up an invalid castling
	game.move(board.algebraicToInt("e2"), board.algebraicToInt("e3"));
	game.move(board.algebraicToInt("b8"), board.algebraicToInt("a6"));
	game.move(board.algebraicToInt("d1"), board.algebraicToInt("g4"));
	game.move(board.algebraicToInt("e7"), board.algebraicToInt("e6"));
	game.move(board.algebraicToInt("h2"), board.algebraicToInt("h3"));
	game.move(board.algebraicToInt("d8"), board.algebraicToInt("h4"));
	game.move(board.algebraicToInt("g2"), board.algebraicToInt("g3"));
	game.move(board.algebraicToInt("d7"), board.algebraicToInt("d6"));
	game.move(board.algebraicToInt("f2"), board.algebraicToInt("f3"));
	game.move(board.algebraicToInt("c8"), board.algebraicToInt("d7"));
	game.move(board.algebraicToInt("g4"), board.algebraicToInt("g5"));

	// Attempt to castle - should return false because leaves king in check
	REQUIRE(game.castle(BLACK, board.algebraicToInt("e8"), board.algebraicToInt("c8")) == false);

	// Set up a valid castling
	game.move(board.algebraicToInt("f7"), board.algebraicToInt("f6"));
	game.move(board.algebraicToInt("d2"), board.algebraicToInt("d3"));

	// Attempt to castle - should succeed
	REQUIRE(game.castle(BLACK, board.algebraicToInt("e8"), board.algebraicToInt("c8")) == true);
}
