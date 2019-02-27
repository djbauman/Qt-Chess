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

TEST_CASE("Starting board clear and obstructed paths")
{
	Board board;

	// Clear paths
	REQUIRE(board.isPathClear(std::make_pair(0,0), std::make_pair(0,0)) == true); 	// same location
	REQUIRE(board.isPathClear(std::make_pair(1,0), std::make_pair(1,1)) == true); 	// adjacent location
	REQUIRE(board.isPathClear(std::make_pair(1,3), std::make_pair(5,3)) == true);	// N->S vertical
	REQUIRE(board.isPathClear(std::make_pair(2,0), std::make_pair(2,7)) == true); 	// W->E horizontal
	REQUIRE(board.isPathClear(std::make_pair(2,2), std::make_pair(5,5)) == true); 	// NW->SE diagonal
	REQUIRE(board.isPathClear(std::make_pair(5,5), std::make_pair(2,2)) == true); 	// SE->NW diagonal
	REQUIRE(board.isPathClear(std::make_pair(2,2), std::make_pair(5,5)) == true); 	// NW->SE diagonal
	REQUIRE(board.isPathClear(std::make_pair(5,1), std::make_pair(3,3)) == true); 	// SW->NE diagonal
	REQUIRE(board.isPathClear(std::make_pair(5,0), std::make_pair(2,3)) == true); 	// off-center diagonal
	REQUIRE(board.isPathClear(std::make_pair(4,6), std::make_pair(2,4)) == true); 	// off-center diagonal

	// Obstructed paths
	REQUIRE(board.isPathClear(std::make_pair(0,2), std::make_pair(2,2)) == false); 	// N->S vertical
	REQUIRE(board.isPathClear(std::make_pair(0,3), std::make_pair(7,3)) == false); 	// N->S vertical
	REQUIRE(board.isPathClear(std::make_pair(1,0), std::make_pair(1,2)) == false); 	// W->E horizontal
	REQUIRE(board.isPathClear(std::make_pair(0,0), std::make_pair(7,7)) == false); 	// NW->SE diagonal
	REQUIRE(board.isPathClear(std::make_pair(7,7), std::make_pair(0,0)) == false); 	// SE->NW diagonal
	REQUIRE(board.isPathClear(std::make_pair(7,0), std::make_pair(0,7)) == false); 	// SW->NE diagonal
	REQUIRE(board.isPathClear(std::make_pair(3,7), std::make_pair(0,4)) == false); 	// off-center diagonal
	REQUIRE(board.isPathClear(std::make_pair(4,6), std::make_pair(7,3)) == false); 	// off-center diagonal
	REQUIRE(board.isPathClear(std::make_pair(3,2), std::make_pair(4,7)) == false); 	// not vertical, horizontal, nor diagonal
}

TEST_CASE("Forward moves")
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

TEST_CASE("Algebraic to integer coordinate translation")
{
	Board board;

	// Corners
	REQUIRE(board.algebraicToInt("a8") == std::make_pair(0,0));
	REQUIRE(board.algebraicToInt("h8") == std::make_pair(0,7));
	REQUIRE(board.algebraicToInt("a1") == std::make_pair(7,0));
	REQUIRE(board.algebraicToInt("h1") == std::make_pair(7,7));

	// Edges
	REQUIRE(board.algebraicToInt("a6") == std::make_pair(2,0));
	REQUIRE(board.algebraicToInt("g8") == std::make_pair(0,6));
	REQUIRE(board.algebraicToInt("h5") == std::make_pair(3,7));
	REQUIRE(board.algebraicToInt("d1") == std::make_pair(7,3));

	// Interior
	REQUIRE(board.algebraicToInt("c6") == std::make_pair(2,2));
	REQUIRE(board.algebraicToInt("f5") == std::make_pair(3,5));
}

TEST_CASE("Integer to algebraic coordinate translation")
{
	Board board;

	// Corners
	REQUIRE(board.intToAlgebraic(std::make_pair(0,0)) == "a8");
	REQUIRE(board.intToAlgebraic(std::make_pair(0,7)) == "h8");
	REQUIRE(board.intToAlgebraic(std::make_pair(7,0)) == "a1");
	REQUIRE(board.intToAlgebraic(std::make_pair(7,7)) == "h1");

	// Edges
	REQUIRE(board.intToAlgebraic(std::make_pair(2,0)) == "a6");
	REQUIRE(board.intToAlgebraic(std::make_pair(0,6)) == "g8");
	REQUIRE(board.intToAlgebraic(std::make_pair(3,7)) == "h5");
	REQUIRE(board.intToAlgebraic(std::make_pair(7,3)) == "d1");

	// Interior
	REQUIRE(board.intToAlgebraic(std::make_pair(2,2)) == "c6");
	REQUIRE(board.intToAlgebraic(std::make_pair(3,5)) == "f5");
}

TEST_CASE("Pieces on board collection")
{
	// Create board with pawns, bishops, and kings
	Board board(true, false, false, true, false, true);

	// Just a rudimentary check that we have the number of pieces we expect
	REQUIRE(board.getPieces(BLACK).size() == 11);
	REQUIRE(board.getPieces(WHITE).size() == 11);
}

TEST_CASE("King locations")
{
	// Create board with only kings
	Board board(false, false, false, false, false, true);

	// Starting locations
	REQUIRE(board.getKingLocation(BLACK) == std::make_pair(0,4));
	REQUIRE(board.getKingLocation(WHITE) == std::make_pair(7,4));

	// Move pieces
	board.movePiece(std::make_pair(0,4), std::make_pair(1,4));
	board.movePiece(std::make_pair(7,4), std::make_pair(7,3));

	// New locations
	REQUIRE(board.getKingLocation(BLACK) == std::make_pair(1,4));
	REQUIRE(board.getKingLocation(WHITE) == std::make_pair(7,3));
}
