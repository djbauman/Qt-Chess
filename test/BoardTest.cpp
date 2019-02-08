#define CATCH_CONFIG_MAIN

#include "../include/catch.hpp"
#include "../source/Board.hpp"
#include "../source/Game.hpp"

TEST_CASE("Move types")
{
	Board board;

	// Vertical moves
	REQUIRE(board.isVerticalMove(std::pair{3,2}, std::pair{0,2}) == true);
	REQUIRE(board.isVerticalMove(std::pair{0,0}, std::pair{4,0}) == true);
	REQUIRE(board.isVerticalMove(std::pair{0,0}, std::pair{0,0}) == true);
	REQUIRE(board.isVerticalMove(std::pair{3,2}, std::pair{1,4}) == false);

	// Horizontal moves
	REQUIRE(board.isHorizontalMove(std::pair{2,0}, std::pair{2,4}) == true);
	REQUIRE(board.isHorizontalMove(std::pair{3,4}, std::pair{3,0}) == true);
	REQUIRE(board.isHorizontalMove(std::pair{0,0}, std::pair{0,0}) == true);
	REQUIRE(board.isHorizontalMove(std::pair{4,0}, std::pair{0,4}) == false);

	// Diagonal moves
	REQUIRE(board.isDiagonalMove(std::pair{0,0}, std::pair{4,4}) == true);
	REQUIRE(board.isDiagonalMove(std::pair{0,0}, std::pair{0,0}) == true);
	REQUIRE(board.isDiagonalMove(std::pair{0,0}, std::pair{0,2}) == false);
	REQUIRE(board.isDiagonalMove(std::pair{0,0}, std::pair{3,0}) == false);
	REQUIRE(board.isDiagonalMove(std::pair{0,2}, std::pair{4,1}) == false);
}