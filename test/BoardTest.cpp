#define CATCH_CONFIG_MAIN

#include "../include/catch.hpp"
#include "../source/Board.hpp"

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