#define CATCH_CONFIG_MAIN

#include "../include/catch.hpp"
#include "../source/Board.hpp"

TEST_CASE("Eight types of Queen moves")
{
	Board B = Board(false, false, false, false, true, false);
	//Usage -- Board(bool Pawns, bool Knights, bool QUEENs, bool Bishops, bool Queens, bool Kings);

	// Down
	REQUIRE(B.movePiece(std::make_pair(0, 3), std::make_pair(3,3)) == true);
	REQUIRE(B.getPiece(std::make_pair(3, 3))->getColor() == BLACK);
	REQUIRE(B.getPiece(std::make_pair(3, 3))->getMoved() == true);
	REQUIRE(B.getPiece(std::make_pair(3, 3))->getType() == QUEEN);

	// Left
	REQUIRE(B.movePiece(std::make_pair(3, 3), std::make_pair(3, 0)) == true);
	REQUIRE(B.getPiece(std::make_pair(3, 0))->getColor() == BLACK);
	REQUIRE(B.getPiece(std::make_pair(3, 0))->getMoved() == true);
	REQUIRE(B.getPiece(std::make_pair(3, 0))->getType() == QUEEN);

	// Right
	REQUIRE(B.movePiece(std::make_pair(3, 0), std::make_pair(3, 7)) == true);
	REQUIRE(B.getPiece(std::make_pair(3, 7))->getColor() == BLACK);
	REQUIRE(B.getPiece(std::make_pair(3, 7))->getMoved() == true);
	REQUIRE(B.getPiece(std::make_pair(3, 7))->getType() == QUEEN);

	// Up
	REQUIRE(B.movePiece(std::make_pair(3, 7), std::make_pair(0, 7)) == true);
	REQUIRE(B.getPiece(std::make_pair(0, 7))->getColor() == BLACK);
	REQUIRE(B.getPiece(std::make_pair(0, 7))->getMoved() == true);
	REQUIRE(B.getPiece(std::make_pair(0, 7))->getType() == QUEEN);

	// NW Diagonal
	REQUIRE(B.movePiece(std::make_pair(7, 3), std::make_pair(4, 0)) == true);
	REQUIRE(B.getPiece(std::make_pair(4, 0))->getColor() == WHITE);
	REQUIRE(B.getPiece(std::make_pair(4, 0))->getMoved() == true);
	REQUIRE(B.getPiece(std::make_pair(4, 0))->getType() == QUEEN);

	// NE Diagonal
	REQUIRE(B.movePiece(std::make_pair(4, 0), std::make_pair(0, 4)) == true);
	REQUIRE(B.getPiece(std::make_pair(0, 4))->getColor() == WHITE);
	REQUIRE(B.getPiece(std::make_pair(0, 4))->getMoved() == true);
	REQUIRE(B.getPiece(std::make_pair(0, 4))->getType() == QUEEN);

	// SE Diagonal
	REQUIRE(B.movePiece(std::make_pair(0, 4), std::make_pair(3, 7)) == true);
	REQUIRE(B.getPiece(std::make_pair(3, 7))->getColor() == WHITE);
	REQUIRE(B.getPiece(std::make_pair(3, 7))->getMoved() == true);
	REQUIRE(B.getPiece(std::make_pair(3, 7))->getType() == QUEEN);

	// SW Diagonal
	REQUIRE(B.movePiece(std::make_pair(3, 7), std::make_pair(7, 3)) == true);
	REQUIRE(B.getPiece(std::make_pair(7, 3))->getColor() == WHITE);
	REQUIRE(B.getPiece(std::make_pair(7, 3))->getMoved() == true);
	REQUIRE(B.getPiece(std::make_pair(7, 3))->getType() == QUEEN);
}

TEST_CASE("Capturing Pieces")
{
	Board B = Board(false, false, false, false, true, false);

	// Take Piece
	REQUIRE(B.movePiece(std::make_pair(0, 3), std::make_pair(7, 3)) == true);

	REQUIRE(B.getPiece(std::make_pair(7, 3))->getColor() == BLACK);
	REQUIRE(B.getPiece(std::make_pair(7, 3))->getMoved() == true);
	REQUIRE(B.getPiece(std::make_pair(7, 3))->getType() == QUEEN);
}

TEST_CASE("Illegal Moves")
{
	Board B = Board(true, false, true, false, true, false);
	//Board(bool Pawns, bool Knights, bool QUEENs, bool Bishops, bool Queens, bool Kings);

	REQUIRE(B.movePiece(std::make_pair(0, 3), std::make_pair(0, 0)) == false);
	REQUIRE(B.getPiece(std::make_pair(0, 3))->getColor() == BLACK);
	REQUIRE(B.getPiece(std::make_pair(0, 3))->getMoved() == false);
	REQUIRE(B.getPiece(std::make_pair(0, 3))->getType() == QUEEN);

	REQUIRE(B.movePiece(std::make_pair(7, 3), std::make_pair(3, 3)) == false);
	REQUIRE(B.getPiece(std::make_pair(7, 3))->getColor() == WHITE);
	REQUIRE(B.getPiece(std::make_pair(7, 3))->getMoved() == false);
	REQUIRE(B.getPiece(std::make_pair(7, 3))->getType() == QUEEN);
}