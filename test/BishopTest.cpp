#define CATCH_CONFIG_MAIN

#include "../include/catch.hpp"
#include "../source/Board.hpp"

TEST_CASE("Eight types of Queen moves")
{
	Board B = Board(false, false, false, true, false, false);
	//Usage -- Board(bool Pawns, bool Knights, bool QUEENs, bool Bishops, bool Queens, bool Kings);

	// SW Diagonal
	REQUIRE(B.movePiece(std::make_pair(0, 2), std::make_pair(2,0)) == true);
	REQUIRE(B.getPiece(std::make_pair(2,0))->getColor() == BLACK);
	REQUIRE(B.getPiece(std::make_pair(2,0))->getMoved() == true);
	REQUIRE(B.getPiece(std::make_pair(2,0))->getType() == BISHOP);

	// SE Diagonal
	REQUIRE(B.movePiece(std::make_pair(2, 0), std::make_pair(4,2)) == true);
	REQUIRE(B.getPiece(std::make_pair(4,2))->getColor() == BLACK);
	REQUIRE(B.getPiece(std::make_pair(4,2))->getMoved() == true);
	REQUIRE(B.getPiece(std::make_pair(4,2))->getType() == BISHOP);

	// NE Diagonal
	REQUIRE(B.movePiece(std::make_pair(4,2), std::make_pair(2,4)) == true);
	REQUIRE(B.getPiece(std::make_pair(2,4))->getColor() == BLACK);
	REQUIRE(B.getPiece(std::make_pair(2,4))->getMoved() == true);
	REQUIRE(B.getPiece(std::make_pair(2,4))->getType() == BISHOP);

	// NW Diagonal
	REQUIRE(B.movePiece(std::make_pair(2,4), std::make_pair(0,2)) == true);
	REQUIRE(B.getPiece(std::make_pair(0,2))->getColor() == BLACK);
	REQUIRE(B.getPiece(std::make_pair(0,2))->getMoved() == true);
	REQUIRE(B.getPiece(std::make_pair(0,2))->getType() == BISHOP);

}

TEST_CASE("Capturing Pieces")
{
	Board B = Board(false, false, false, true, false, false);

	// Take Piece
	REQUIRE(B.movePiece(std::make_pair(0, 2), std::make_pair(5, 7)) == true);
	REQUIRE(B.movePiece(std::make_pair(5, 7), std::make_pair(7, 5)) == true);
	REQUIRE(B.getPiece(std::make_pair(7, 5))->getColor() == BLACK);
	REQUIRE(B.getPiece(std::make_pair(7, 5))->getMoved() == true);
	REQUIRE(B.getPiece(std::make_pair(7, 5))->getType() == BISHOP);
}

TEST_CASE("Illegal Moves")
{
	Board B = Board(true, false, false, true, false, false);

	REQUIRE(B.movePiece(std::make_pair(0, 2), std::make_pair(0, 0)) == false);
	REQUIRE(B.getPiece(std::make_pair(0, 2))->getColor() == BLACK);
	REQUIRE(B.getPiece(std::make_pair(0, 2))->getMoved() == false);
	REQUIRE(B.getPiece(std::make_pair(0, 2))->getType() == BISHOP);


}