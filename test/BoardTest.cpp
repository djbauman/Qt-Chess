#define CATCH_CONFIG_MAIN

#include "../include/catch.hpp"
#include "../source/Board.hpp"
#include "../source/Game.hpp"

TEST_CASE("Move types")
{
	Board board;

	// Vertical moves
	CHECK(board.isVerticalMove(std::make_pair(0,0), std::make_pair(0,0)) == true);
	CHECK(board.isVerticalMove(std::make_pair(3,2), std::make_pair(0,2)) == true);
	CHECK(board.isVerticalMove(std::make_pair(0,0), std::make_pair(4,0)) == true);
	CHECK(board.isVerticalMove(std::make_pair(3,2), std::make_pair(1,4)) == false);

	// Horizontal moves
	CHECK(board.isHorizontalMove(std::make_pair(0,0), std::make_pair(0,0)) == true);
	CHECK(board.isHorizontalMove(std::make_pair(2,0), std::make_pair(2,4)) == true);
	CHECK(board.isHorizontalMove(std::make_pair(3,4), std::make_pair(3,0)) == true);
	CHECK(board.isHorizontalMove(std::make_pair(4,0), std::make_pair(0,4)) == false);

	// Diagonal moves
	CHECK(board.isDiagonalMove(std::make_pair(0,0), std::make_pair(0,0)) == true);
	CHECK(board.isDiagonalMove(std::make_pair(0,0), std::make_pair(4,4)) == true);
	CHECK(board.isDiagonalMove(std::make_pair(0,0), std::make_pair(0,2)) == false);
	CHECK(board.isDiagonalMove(std::make_pair(0,0), std::make_pair(3,0)) == false);
	CHECK(board.isDiagonalMove(std::make_pair(0,2), std::make_pair(4,1)) == false);
}

TEST_CASE("Move lengths")
{
	Board board;

	// Vertical move lengths
	CHECK(board.getMoveLength(std::make_pair(0,0), std::make_pair(0,0)) == 0);
	CHECK(board.getMoveLength(std::make_pair(0,0), std::make_pair(4,0)) == 4);

	// Horizontal move lengths
	CHECK(board.getMoveLength(std::make_pair(0,0), std::make_pair(0,0)) == 0);
	CHECK(board.getMoveLength(std::make_pair(0,0), std::make_pair(3,0)) == 3);

	// Diagonal move lengths
	CHECK(board.getMoveLength(std::make_pair(0,0), std::make_pair(0,0)) == 0);
	CHECK(board.getMoveLength(std::make_pair(3,3), std::make_pair(1,1)) == 2);
}

TEST_CASE("Starting board clear and obstructed paths")
{
	Board board;

	// Clear paths
	CHECK(board.isPathClear(std::make_pair(0,0), std::make_pair(0,0)) == true); 	// same location
	CHECK(board.isPathClear(std::make_pair(1,0), std::make_pair(1,1)) == true); 	// adjacent location
	CHECK(board.isPathClear(std::make_pair(1,3), std::make_pair(5,3)) == true);	// N->S vertical
	CHECK(board.isPathClear(std::make_pair(2,0), std::make_pair(2,7)) == true); 	// W->E horizontal
	CHECK(board.isPathClear(std::make_pair(2,2), std::make_pair(5,5)) == true); 	// NW->SE diagonal
	CHECK(board.isPathClear(std::make_pair(5,5), std::make_pair(2,2)) == true); 	// SE->NW diagonal
	CHECK(board.isPathClear(std::make_pair(2,2), std::make_pair(5,5)) == true); 	// NW->SE diagonal
	CHECK(board.isPathClear(std::make_pair(5,1), std::make_pair(3,3)) == true); 	// SW->NE diagonal
	CHECK(board.isPathClear(std::make_pair(5,0), std::make_pair(2,3)) == true); 	// off-center diagonal
	CHECK(board.isPathClear(std::make_pair(4,6), std::make_pair(2,4)) == true); 	// off-center diagonal

	// Obstructed paths
	CHECK(board.isPathClear(std::make_pair(0,2), std::make_pair(2,2)) == false); 	// N->S vertical
	CHECK(board.isPathClear(std::make_pair(0,3), std::make_pair(7,3)) == false); 	// N->S vertical
	CHECK(board.isPathClear(std::make_pair(1,0), std::make_pair(1,2)) == false); 	// W->E horizontal
	CHECK(board.isPathClear(std::make_pair(0,0), std::make_pair(7,7)) == false); 	// NW->SE diagonal
	CHECK(board.isPathClear(std::make_pair(7,7), std::make_pair(0,0)) == false); 	// SE->NW diagonal
	CHECK(board.isPathClear(std::make_pair(7,0), std::make_pair(0,7)) == false); 	// SW->NE diagonal
	CHECK(board.isPathClear(std::make_pair(3,7), std::make_pair(0,4)) == false); 	// off-center diagonal
	CHECK(board.isPathClear(std::make_pair(4,6), std::make_pair(7,3)) == false); 	// off-center diagonal
	CHECK(board.isPathClear(std::make_pair(3,2), std::make_pair(4,7)) == false); 	// not vertical, horizontal, nor diagonal
}

TEST_CASE("Forward moves")
{
	Board board;
	const Piece *whitePawn = board.getPiece(std::make_pair(6,7));
	const Piece *blackPawn = board.getPiece(std::make_pair(1,7));

	// Forward movement
	CHECK(board.isForwardMove(std::make_pair(6,7), std::make_pair(5,7), whitePawn) == true);
	CHECK(board.isForwardMove(std::make_pair(1,7), std::make_pair(2,7), blackPawn) == true);

	// Backward movement
	CHECK(board.isForwardMove(std::make_pair(6,7), std::make_pair(7,7), whitePawn) == false);
	CHECK(board.isForwardMove(std::make_pair(1,7), std::make_pair(0,7), blackPawn) == false);
}

TEST_CASE("Pawn moves")
{
	// TODO: Implement unit tests for isValidMove() for Pawn
}
