#define private public // for testing private methods
#define CATCH_CONFIG_MAIN

#include "../include/catch.hpp"
#include "../source/Board.hpp"

TEST_CASE("Coord and Element Conversion")
{
	Board board;

	REQUIRE(board.coordsToElement("a1") == 56);
	REQUIRE(board.coordsToElement("a8") == 0);
	REQUIRE(board.coordsToElement("h1") == 63);
	REQUIRE(board.coordsToElement("h8") == 7);
	REQUIRE(board.coordsToElement("c6") == 18);

	REQUIRE(board.elementToCoords(56) == "a1");
	REQUIRE(board.elementToCoords(0) == "a8");
	REQUIRE(board.elementToCoords(63) == "h1");
	REQUIRE(board.elementToCoords(7) == "h8");
	REQUIRE(board.elementToCoords(18) == "c6");
}

TEST_CASE("Set and Get Pieces")
{
	Board board;
	Piece pieceA{};
	Piece pieceB{};

	pieceA.setType(KING);
	board.setPiece("e1", pieceA);

	pieceB = board.getPiece("e1");

	// TODO: Need to overload == operator so we're actually comparing objects and not just types.
	REQUIRE(pieceA.getType() == pieceB.getType());
}