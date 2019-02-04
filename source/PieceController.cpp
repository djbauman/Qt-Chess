#include "PieceController.hpp"

PieceController::PieceController() 
{

}

bool PieceController::movePiece(Board *B, std::string startCord, std::string endCord, Color player) 
{

	Piece pieceCheck = B->getPiece(startCord);
	if (pieceCheck.getColor() == player) {
		bool moveCheck = false;
		switch (pieceCheck.getType()) {
		case PAWN:
			moveCheck = movePawn(B, startCord, endCord, player);
			return moveCheck;
		case ROOK:
			moveCheck = moveRook(B, startCord, endCord, player);
			break;
		case KNIGHT:
			break;
		case BISHOP:
			break;
		case QUEEN:
			break;
		case KING:
			break;
		default:
			return false;
		}
	}
	return false;
}

bool PieceController::movePawn(Board* B, std::string startCord, std::string endCord, Color player) 
{

	makeMove(B, startCord, endCord, player);
	return false;
};
bool PieceController::attackPawn(Board* B, std::string startCord, std::string endCord, Color player) 
{

	return false;
}
bool PieceController::moveRook(Board* B, std::string startCord, std::string endCord, Color player) 
{

	// Check that either row or column are the same
	int startRow, startCol, endRow, endCol;
	int* start = B->coordToIndex(startCord);
	startCol = start[0];
	startRow = start[1];
	int* end = B->coordToIndex(endCord);
	endCol = end[0];
	endRow = end[1];

	// Check that destination square is open
	if (B->getPiece(endCord).getColor() == player) {
		return false;
	}

	// Moving Left or Right
	if (startRow == endRow)
	{
		// Moving Left
		if (startCol > endCol)
		{
			for (int i = startCol - 1; i < endCol + 1; i--)
			{
				if (B->getPiece(endCord).getType() != NONE) {
					return false; //piece in the way
				}
			}

			// Valid Move
			makeMove(B, startCord, endCord, player);
			return true;
		}

		// Moving Right
		else if(endCol > startCol)
		{
			for (int i = startCol + 1; i < endCol - 1; i++)
			{
				if (B->getPieceByIndex(startCol, i).getType() != NONE) {
					return false; //piece in the way
				}
			}

			// Valid Move
			makeMove(B, startCord, endCord, player);
			return true;
		}
		else {
			return false;
		}
	}

	// Moving Up or Down
	else if (startCol == endCol) 
	{
		// Moving Up
		if (startRow > endRow)
		{
			for (int i = startRow-1; i < endRow+1; i--) 
			{
				if (B->getPieceByIndex(i, endCol).getType() != NONE) {
					return false; //piece in the way
				}
			}

			// Valid Move
			makeMove(B, startCord, endCord, player);
			return true;
		}

		// Moving Down
		else if (endRow > startRow)
		{
			for (int i = startRow; i < endRow-1; i++)
			{
				if (B->getPieceByIndex(i, endCol).getType() != NONE) {
					return false; //piece in the way
				}

			}

			// Valid Move
			makeMove(B, startCord, endCord, player);
			return true;
		}
	}

	// Invalid Move
	return false;
}
bool PieceController::moveKnight(Board* B, std::string startCord, std::string endCord, Color player) 
{
	return false;
}
bool PieceController::moveBishop(Board* B, std::string startCord, std::string endCord, Color player) 
{
	return false;
}
bool PieceController::moveQueen(Board* B, std::string startCord, std::string endCord, Color player) 
{
	return false;
}

void PieceController::makeMove(Board* B, std::string startCord, std::string endCord, Color player) 
{
	Piece moving = B->getPiece(startCord);
	B->setPiece(endCord, moving);
	Piece empty = Piece(NONE, OPEN);
	B->setPiece(startCord, empty);
}