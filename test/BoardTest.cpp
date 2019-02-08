#define CATCH_CONFIG_MAIN

#include "../include/catch.hpp"
#include "../source/Board.hpp"
#include "../source/Game.hpp"

TEST_CASE("Move types")
{
	Board board;

	// Vertical moves
	REQUIRE(board.isVerticalMove(std::pair{0,0}, std::pair{0,0}) == true);
	REQUIRE(board.isVerticalMove(std::pair{3,2}, std::pair{0,2}) == true);
	REQUIRE(board.isVerticalMove(std::pair{0,0}, std::pair{4,0}) == true);
	REQUIRE(board.isVerticalMove(std::pair{3,2}, std::pair{1,4}) == false);

	// Horizontal moves
	REQUIRE(board.isHorizontalMove(std::pair{0,0}, std::pair{0,0}) == true);
	REQUIRE(board.isHorizontalMove(std::pair{2,0}, std::pair{2,4}) == true);
	REQUIRE(board.isHorizontalMove(std::pair{3,4}, std::pair{3,0}) == true);
	REQUIRE(board.isHorizontalMove(std::pair{4,0}, std::pair{0,4}) == false);

	// Diagonal moves
	REQUIRE(board.isDiagonalMove(std::pair{0,0}, std::pair{0,0}) == true);
	REQUIRE(board.isDiagonalMove(std::pair{0,0}, std::pair{4,4}) == true);
	REQUIRE(board.isDiagonalMove(std::pair{0,0}, std::pair{0,2}) == false);
	REQUIRE(board.isDiagonalMove(std::pair{0,0}, std::pair{3,0}) == false);
	REQUIRE(board.isDiagonalMove(std::pair{0,2}, std::pair{4,1}) == false);
}

TEST_CASE("Move lengths")
{
	Board board;

	// Vertical move lengths
	REQUIRE(board.getMoveLength(std::pair{0,0}, std::pair{0,0}) == 0);
	REQUIRE(board.getMoveLength(std::pair{0,0}, std::pair{4,0}) == 4);

	// Horizontal move lengths
	REQUIRE(board.getMoveLength(std::pair{0,0}, std::pair{0,0}) == 0);
	REQUIRE(board.getMoveLength(std::pair{0,0}, std::pair{3,0}) == 3);

	// Diagonal move lengths
	REQUIRE(board.getMoveLength(std::pair{0,0}, std::pair{0,0}) == 0);
	REQUIRE(board.getMoveLength(std::pair{3,3}, std::pair{1,1}) == 2);
}

TEST_CASE("Clear and obstructed paths")
{
	Board board;

	// TODO: These tests depend on a board only populated with pawns. As we add more pieces to our constructor for
	// 		Board, these tests will no longer be accurate.

	// Clear paths
	REQUIRE(board.isPathClear(std::pair{0,0}, std::pair{0,0}) == TRUE); // same location
	REQUIRE(board.isPathClear(std::pair{1,0}, std::pair{1,1}) == TRUE); // adjacent location
	REQUIRE(board.isPathClear(std::pair{1,3}, std::pair{6,3}) == TRUE);	// N->S vertical
	REQUIRE(board.isPathClear(std::pair{0,0}, std::pair{0,7}) == TRUE); // W->E horizontal
	REQUIRE(board.isPathClear(std::pair{2,2}, std::pair{5,5}) == TRUE); // NW->SE diagonal
	REQUIRE(board.isPathClear(std::pair{5,5}, std::pair{2,2}) == TRUE); // SE->NW diagonal
	REQUIRE(board.isPathClear(std::pair{6,6}, std::pair{1,1}) == TRUE); // SE->NW diagonal
	REQUIRE(board.isPathClear(std::pair{1,1}, std::pair{6,6}) == TRUE); // NW->SE diagonal
	REQUIRE(board.isPathClear(std::pair{6,1}, std::pair{1,6}) == TRUE); // SW->NE diagonal

	// Obstructed paths
	REQUIRE(board.isPathClear(std::pair{0,2}, std::pair{2,2}) == FALSE); // N->S vertical
	REQUIRE(board.isPathClear(std::pair{0,3}, std::pair{7,3}) == FALSE); // N->S vertical
	REQUIRE(board.isPathClear(std::pair{1,0}, std::pair{1,2}) == FALSE); // W->E horizontal
	REQUIRE(board.isPathClear(std::pair{0,0}, std::pair{7,7}) == FALSE); // NW->SE diagonal
	REQUIRE(board.isPathClear(std::pair{7,7}, std::pair{0,0}) == FALSE); // SE->NW diagonal
	REQUIRE(board.isPathClear(std::pair{7,0}, std::pair{0,7}) == FALSE); // SW->NE diagonal
	REQUIRE(board.isPathClear(std::pair{3,2}, std::pair{4,7}) == FALSE); // not vertical, horizontal, or diagonal
}