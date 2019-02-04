#include <iostream>
#include <string>
#include "Board.hpp"

// Constructor
Board::Board()
{
	setMap();
	setBoard();

}

// Associates the spaces of a chess board with the array
void Board::setMap()
{
	squares.resize(8, std::vector<Square>(8));

	for (int i = 0; i < 8; i++) 
	{
		for (int j = 0; j < 8; j++) 
		{
			squareMap[spaces[i + j]] = squares[i][j];
		}
	}
}

// Print function
void Board::printBoard()
{
	int i = 0;
	for (std::string space : spaces) 
	{

		std::cout << squareMap[space].getPiece() << ' ';

		i++;
		if (i == 8) 
		{
			i = 0;
			std::cout<<'\n';
		}
	}
}

/* Converts the given coordinates to an element and then places the given piece at that element. */
void Board::setPiece(const std::string &coords, Piece piece)
{
	squareMap[coords].setPiece(piece);
}

/* Returns the piece at a given square. */
Piece Board::getPiece(const std::string &coords)
{
	return squareMap[coords].getPiece();
}

Piece Board::getPieceByIndex(const int i, const int j)
{
	return squares[i][j].getPiece();
}

/* Returns the the vector indices from a bord space. */
int* Board::coordToIndex(std::string coords)
{
	char let = coords[0];
	char* num = &coords[1];
	int indicies[2];
	indicies[0] = let - 97;
	indicies[1] = 8-std::atoi(num);
	return indicies;
}

// Places the appropriate pieces on the appropriate spots to start a chess game
void Board::setBoard()
{
	// White Rook Placement
	Piece wr1{ ROOK, WHITE };
	Board::setPiece("a1", wr1);

	// White Knight Placement
	Piece wn1{ KNIGHT , WHITE };
	Board::setPiece("b1", wn1);

	// White Bishop Placement
	Piece wb1{ BISHOP , WHITE };
	Board::setPiece("c1", wb1);

	// White King Placement
	Piece wk{ KING , WHITE };
	Board::setPiece("d1", wk);

	// White Queen Placement
	Piece wq{ QUEEN ,WHITE };
	Board::setPiece("e1", wq);

	// White Bishop Placement
	Piece wb2{ BISHOP , WHITE };
	Board::setPiece("f1", wb2);

	// White Knight Placement
	Piece wn2{ KNIGHT, WHITE };
	Board::setPiece("g1", wn2);

	// White Rook Placement
	Piece wr2{ ROOK , WHITE };
	Board::setPiece("h1", wr2);

	// White Pawn Placement
	Piece wp1{ PAWN , WHITE };
	Board::setPiece("a2", wp1);
	Piece wp2{ PAWN , WHITE };
	Board::setPiece("b2", wp2);
	Piece wp3{ PAWN , WHITE };
	Board::setPiece("c2", wp3);
	Piece wp4{ PAWN , WHITE };
	Board::setPiece("d2", wp4);
	Piece wp5{ PAWN , WHITE };
	Board::setPiece("e2", wp5);
	Piece wp6{ PAWN , WHITE };
	Board::setPiece("f2", wp6);
	Piece wp7{ PAWN , WHITE };
	Board::setPiece("g2", wp7);
	Piece wp8{ PAWN , WHITE };
	Board::setPiece("h2", wp8);

	// Black Rook Placement
	Piece br1{ ROOK , BLACK };
	Board::setPiece("a8", br1);

	// Black Knight Placement
	Piece bn1{ KNIGHT , BLACK };
	Board::setPiece("b8", bn1);

	// Black Bishop Placement
	Piece bb1{ BISHOP , BLACK };
	Board::setPiece("c8", bb1);

	// Black King Placement
	Piece bk{ KING , BLACK };
	Board::setPiece("d8", bk);

	// Black Queen Placement
	Piece bq{ QUEEN , BLACK };
	Board::setPiece("e8", bq);

	// Black Bishop Placement
	Piece bb2{ BISHOP , BLACK };
	Board::setPiece("f8", bb2);

	// Black Knight Placement
	Piece bn2{ KNIGHT , BLACK };
	Board::setPiece("g8", bn2);

	// Black Rook Placement
	Piece br2{ ROOK , BLACK };
	Board::setPiece("h8", br2);

	// Black Pawn Placement
	Piece bp1{ PAWN , BLACK };
	Board::setPiece("a7", bp1);
	Piece bp2{ PAWN , BLACK };
	Board::setPiece("b7", bp2);
	Piece bp3{ PAWN , BLACK };
	Board::setPiece("c7", bp3);
	Piece bp4{ PAWN , BLACK };
	Board::setPiece("d7", bp4);
	Piece bp5{ PAWN , BLACK };
	Board::setPiece("e7", bp5);
	Piece bp6{ PAWN , BLACK };
	Board::setPiece("f7", bp6);
	Piece bp7{ PAWN , BLACK };
	Board::setPiece("g7", bp7);
	Piece bp8{ PAWN , BLACK };
	Board::setPiece("h7", bp8);

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (squares[i][j].getPiece().getType() != NONE)
			{
				continue;
			}
			else {
				Piece blankPiece{ NONE , OPEN };
				squares[i][j].setPiece(blankPiece);
			}
		}
	}
}

// Destructor
Board::~Board() = default;
