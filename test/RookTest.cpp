#define CATCH_CONFIG_MAIN

#include "../include/catch.hpp"
#include "../source/Board.hpp"

TEST_CASE("Four types of Rook move types")
{
	Board B = Board(false, false, true, false, false, false);
	//Usage -- Board(bool Pawns, bool Knights, bool Rooks, bool Bishops, bool Queens, bool Kings);

	// Down
	REQUIRE(B.movePiece(std::make_pair(0, 0), std::make_pair(5, 0)) == true);
	REQUIRE(B.getPiece(std::make_pair(5, 0))->getColor() == BLACK);
	REQUIRE(B.getPiece(std::make_pair(5, 0))->getMoved() == true);
	REQUIRE(B.getPiece(std::make_pair(5, 0))->getType() == ROOK);

	// Left
	REQUIRE(B.movePiece(std::make_pair(0, 7), std::make_pair(0, 0)) == true);
	REQUIRE(B.getPiece(std::make_pair(0, 0))->getColor() == BLACK);
	REQUIRE(B.getPiece(std::make_pair(0, 0))->getMoved() == true);
	REQUIRE(B.getPiece(std::make_pair(0, 0))->getType() == ROOK);

	// Up
	REQUIRE(B.movePiece(std::make_pair(7, 7), std::make_pair(3, 7)) == true);
	REQUIRE(B.getPiece(std::make_pair(3, 7))->getColor() == WHITE);
	REQUIRE(B.getPiece(std::make_pair(3, 7))->getMoved() == true);
	REQUIRE(B.getPiece(std::make_pair(3, 7))->getType() == ROOK);

	// Right
	REQUIRE(B.movePiece(std::make_pair(7, 0), std::make_pair(7, 7)) == true);
	REQUIRE(B.getPiece(std::make_pair(7, 7))->getColor() == WHITE);
	REQUIRE(B.getPiece(std::make_pair(7, 7))->getMoved() == true);
	REQUIRE(B.getPiece(std::make_pair(7, 7))->getType() == ROOK);
}

TEST_CASE("Capturing Pieces")
{
	Board B = Board(false, false, true, false, true, false);

	// Take Piece
	REQUIRE(B.movePiece(std::make_pair(0, 0), std::make_pair(1, 0)) == true);
	REQUIRE(B.movePiece(std::make_pair(1, 0), std::make_pair(1, 3)) == true);
	REQUIRE(B.movePiece(std::make_pair(1, 3), std::make_pair(7, 3)) == true);

	REQUIRE(B.getPiece(std::make_pair(7, 3))->getColor() == BLACK);
	REQUIRE(B.getPiece(std::make_pair(7, 3))->getMoved() == true);
	REQUIRE(B.getPiece(std::make_pair(7, 3))->getType() == ROOK);
}

TEST_CASE("Illegal Moves")
{
	Board B = Board(false, false, true, false, false, false);
	//Board(bool Pawns, bool Knights, bool Rooks, bool Bishops, bool Queens, bool Kings);

	REQUIRE(B.movePiece(std::make_pair(0, 0), std::make_pair(1, 1)) == false);
	REQUIRE(B.getPiece(std::make_pair(0, 0))->getColor() == BLACK);
	REQUIRE(B.getPiece(std::make_pair(0, 0))->getMoved() == false);
	REQUIRE(B.getPiece(std::make_pair(0, 0))->getType() == ROOK);

	REQUIRE(B.movePiece(std::make_pair(7, 7), std::make_pair(5, 4)) == false);
	REQUIRE(B.getPiece(std::make_pair(7, 7))->getColor() == WHITE);
	REQUIRE(B.getPiece(std::make_pair(7, 7))->getMoved() == false);
	REQUIRE(B.getPiece(std::make_pair(7, 7))->getType() == ROOK);
}