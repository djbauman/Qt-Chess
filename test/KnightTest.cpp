#define CATCH_CONFIG_MAIN

#include "../include/catch.hpp"
#include "../source/Board.hpp"
#include "../source/Game.hpp"

TEST_CASE("Eight possible knight move types")
{
	Board B;
	// Up-right
	REQUIRE(B.movePiece(std::make_pair(7, 1), std::make_pair(5, 2)) == true);
	// Right-up
	REQUIRE(B.movePiece(std::make_pair(5, 2), std::make_pair(4, 4)) == true);
	// Left-up
	REQUIRE(B.movePiece(std::make_pair(4, 4), std::make_pair(3, 2)) == true);
	// Right-down
	REQUIRE(B.movePiece(std::make_pair(3,2), std::make_pair(4, 4)) == true);
	// Left-down
	REQUIRE(B.movePiece(std::make_pair(4, 4), std::make_pair(5, 2)) == true);
	// Up-left
	REQUIRE(B.movePiece(std::make_pair(7, 6), std::make_pair(5, 5)) == true);
	// Down-left
	REQUIRE(B.movePiece(std::make_pair(0, 6), std::make_pair(2, 5)) == true);
	// Down-right
	REQUIRE(B.movePiece(std::make_pair(0, 1), std::make_pair(2, 2)) == true);
}

TEST_CASE("Captures")
{
	Board B;

	// Positioning for capture
	REQUIRE(B.movePiece(std::make_pair(7, 1), std::make_pair(5, 2)) == true);
	REQUIRE(B.movePiece(std::make_pair(5, 2), std::make_pair(3, 3)) == true);
	
	// Capturing pawn
	REQUIRE(B.movePiece(std::make_pair(3, 3), std::make_pair(1, 4)) == true);

	// Capturing knight
	REQUIRE(B.movePiece(std::make_pair(1, 4), std::make_pair(0, 6)) == true);

}

TEST_CASE("Illegal moves")
{
	Board B;

	// Moving in ways not allowed by knights
	REQUIRE(B.movePiece(std::make_pair(7, 1), std::make_pair(5, 1)) == false);
	REQUIRE(B.movePiece(std::make_pair(7, 1), std::make_pair(4, 2)) == false);

	// Moving to squares occupied by friendly pieces
	REQUIRE(B.movePiece(std::make_pair(7, 1), std::make_pair(6, 3)) == false);
	REQUIRE(B.movePiece(std::make_pair(0, 6), std::make_pair(1, 4)) == false);
}