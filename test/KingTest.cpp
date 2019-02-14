#define CATCH_CONFIG_MAIN

#include "../include/catch.hpp"
#include "../source/Board.hpp"
#include "../source/Game.hpp"



TEST_CASE("Eight possible king move types (excluding castling)")
{
	Board B;
	// Moving pawns out of the way
	B.movePiece(std::make_pair(6, 3), std::make_pair(4, 3));
	B.movePiece(std::make_pair(6, 4), std::make_pair(4, 4));
	B.movePiece(std::make_pair(6, 5), std::make_pair(4, 5));

	// Moving the king in all 8 directions
	// Up
	REQUIRE(B.movePiece(std::make_pair(7, 4), std::make_pair(6, 4)) == true);
	// Left
	REQUIRE(B.movePiece(std::make_pair(6, 4), std::make_pair(6, 3)) == true);
	// Right
	REQUIRE(B.movePiece(std::make_pair(6, 3), std::make_pair(6, 4)) == true);
	// Down
	REQUIRE(B.movePiece(std::make_pair(6, 4), std::make_pair(7, 4)) == true);
	// Up-left
	REQUIRE(B.movePiece(std::make_pair(7, 4), std::make_pair(6, 3)) == true);
	// Down-right
	REQUIRE(B.movePiece(std::make_pair(6, 3), std::make_pair(7, 4)) == true);
	// Up-right
	REQUIRE(B.movePiece(std::make_pair(7, 4), std::make_pair(6, 5)) == true);
	// Down-left
	REQUIRE(B.movePiece(std::make_pair(6, 5), std::make_pair(7, 4)) == true);

}

TEST_CASE("Captures")
{
	Board B;

	// Positioning pawns to be captured
	B.movePiece(std::make_pair(6, 3), std::make_pair(4, 3));
	B.movePiece(std::make_pair(6, 4), std::make_pair(4, 4));
	B.movePiece(std::make_pair(1, 3), std::make_pair(3, 3));
	B.movePiece(std::make_pair(1, 4), std::make_pair(3, 4));

	// Positioning king to capture pawns
	B.movePiece(std::make_pair(7, 4), std::make_pair(6, 4));
	B.movePiece(std::make_pair(6, 4), std::make_pair(5, 4));
	B.movePiece(std::make_pair(5, 4), std::make_pair(4, 5));

	// Capturing pawns
	REQUIRE(B.movePiece(std::make_pair(4, 5), std::make_pair(3, 4)) == true);
	REQUIRE(B.movePiece(std::make_pair(3, 4), std::make_pair(3, 3)) == true);

}

TEST_CASE("Illegal moves")
{
	Board B;

	// Attempting to move King into friendly pieces
	REQUIRE(B.movePiece(std::make_pair(7, 4), std::make_pair(6, 4)) == false);
	REQUIRE(B.movePiece(std::make_pair(7, 4), std::make_pair(7, 3)) == false);
	REQUIRE(B.movePiece(std::make_pair(7, 4), std::make_pair(7, 5)) == false);

	// Moving multiple squares and through pieces
	REQUIRE(B.movePiece(std::make_pair(7, 4), std::make_pair(4, 4)) == false);

}