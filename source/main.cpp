#include <iostream>
#include "Board.hpp"
#include "PieceController.hpp"

using std::cout;
using std::endl;

int main()
{
	Board B;
	PieceController P;

	P.movePiece(&B, "a2", "a4", WHITE);

	P.movePiece(&B, "b8", "c6", BLACK);

	P.movePiece(&B, "a1", "a3", WHITE);

	B.printBoard();
	return 0;
}
