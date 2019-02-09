#define CATCH_CONFIG_MAIN

#include "../include/catch.hpp"
#include "../source/Board.hpp"
#include "../source/Game.hpp"

TEST_CASE("Move types")
{
	Board board;

	// Vertical moves
	REQUIRE(board.isVerticalMove(std::make_pair(0,0), std::make_pair(0,0)) == true);
	REQUIRE(board.isVerticalMove(std::make_pair(3,2), std::make_pair(0,2)) == true);
	REQUIRE(board.isVerticalMove(std::make_pair(0,0), std::make_pair(4,0)) == true);
	REQUIRE(board.isVerticalMove(std::make_pair(3,2), std::make_pair(1,4)) == false);

	// Horizontal moves
	REQUIRE(board.isHorizontalMove(std::make_pair(0,0), std::make_pair(0,0)) == true);
	REQUIRE(board.isHorizontalMove(std::make_pair(2,0), std::make_pair(2,4)) == true);
	REQUIRE(board.isHorizontalMove(std::make_pair(3,4), std::make_pair(3,0)) == true);
	REQUIRE(board.isHorizontalMove(std::make_pair(4,0), std::make_pair(0,4)) == false);

	// Diagonal moves
	REQUIRE(board.isDiagonalMove(std::make_pair(0,0), std::make_pair(0,0)) == true);
	REQUIRE(board.isDiagonalMove(std::make_pair(0,0), std::make_pair(4,4)) == true);
	REQUIRE(board.isDiagonalMove(std::make_pair(0,0), std::make_pair(0,2)) == false);
	REQUIRE(board.isDiagonalMove(std::make_pair(0,0), std::make_pair(3,0)) == false);
	REQUIRE(board.isDiagonalMove(std::make_pair(0,2), std::make_pair(4,1)) == false);
}

TEST_CASE("Move lengths")
{
	Board board;

	// Vertical move lengths
	REQUIRE(board.getMoveLength(std::make_pair(0,0), std::make_pair(0,0)) == 0);
	REQUIRE(board.getMoveLength(std::make_pair(0,0), std::make_pair(4,0)) == 4);

	// Horizontal move lengths
	REQUIRE(board.getMoveLength(std::make_pair(0,0), std::make_pair(0,0)) == 0);
	REQUIRE(board.getMoveLength(std::make_pair(0,0), std::make_pair(3,0)) == 3);

	// Diagonal move lengths
	REQUIRE(board.getMoveLength(std::make_pair(0,0), std::make_pair(0,0)) == 0);
	REQUIRE(board.getMoveLength(std::make_pair(3,3), std::make_pair(1,1)) == 2);
}

TEST_CASE("Clear and obstructed paths")
{
	Board board;

	// TODO: These tests depend on a board only populated with pawns. As we add more pieces to our constructor for
	// 		Board, these tests will no longer be accurate.

	// Clear paths
	REQUIRE(board.isPathClear(std::make_pair(0,0), std::make_pair(0,0)) == true); // same location
	REQUIRE(board.isPathClear(std::make_pair(1,0), std::make_pair(1,1)) == true); // adjacent location
	REQUIRE(board.isPathClear(std::make_pair(1,3), std::make_pair(6,3)) == true);	// N->S vertical
	REQUIRE(board.isPathClear(std::make_pair(0,0), std::make_pair(0,7)) == true); // W->E horizontal
	REQUIRE(board.isPathClear(std::make_pair(2,2), std::make_pair(5,5)) == true); // NW->SE diagonal
	REQUIRE(board.isPathClear(std::make_pair(5,5), std::make_pair(2,2)) == true); // SE->NW diagonal
	REQUIRE(board.isPathClear(std::make_pair(6,6), std::make_pair(1,1)) == true); // SE->NW diagonal
	REQUIRE(board.isPathClear(std::make_pair(1,1), std::make_pair(6,6)) == true); // NW->SE diagonal
	REQUIRE(board.isPathClear(std::make_pair(6,1), std::make_pair(1,6)) == true); // SW->NE diagonal

	// Obstructed paths
	REQUIRE(board.isPathClear(std::make_pair(0,2), std::make_pair(2,2)) == false); // N->S vertical
	REQUIRE(board.isPathClear(std::make_pair(0,3), std::make_pair(7,3)) == false); // N->S vertical
	REQUIRE(board.isPathClear(std::make_pair(1,0), std::make_pair(1,2)) == false); // W->E horizontal
	REQUIRE(board.isPathClear(std::make_pair(0,0), std::make_pair(7,7)) == false); // NW->SE diagonal
	REQUIRE(board.isPathClear(std::make_pair(7,7), std::make_pair(0,0)) == false); // SE->NW diagonal
	REQUIRE(board.isPathClear(std::make_pair(7,0), std::make_pair(0,7)) == false); // SW->NE diagonal
	REQUIRE(board.isPathClear(std::make_pair(3,2), std::make_pair(4,7)) == false); // not vertical, horizontal, nor diagonal
}

TEST_CASE("Foreward moves")
{
	Board board;
	const Piece *whitePawn = board.getPiece(std::make_pair(6,7));
	const Piece *blackPawn = board.getPiece(std::make_pair(1,7));

	// Forward movement
	REQUIRE(board.isForwardMove(std::make_pair(6,7), std::make_pair(5,7), whitePawn) == true);
	REQUIRE(board.isForwardMove(std::make_pair(1,7), std::make_pair(2,7), blackPawn) == true);

	// Backward movement
	REQUIRE(board.isForwardMove(std::make_pair(6,7), std::make_pair(7,7), whitePawn) == false);
	REQUIRE(board.isForwardMove(std::make_pair(1,7), std::make_pair(0,7), blackPawn) == false);
}

TEST_CASE("Pawn moves")
{
	// TODO: Implement unit tests for isValidMove() for Pawn
}
