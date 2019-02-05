#include "PieceController.hpp"

PieceController::PieceController() 
{

}

bool PieceController::movePiece(Board *B, std::string startCord, std::string endCord, Color player) 
{

	Piece pieceCheck = B->getPiece(startCord);
	if (pieceCheck.getColor() == player) {
		switch (pieceCheck.getType()) {
		case PAWN:
			return movePawn(B, startCord, endCord, player);
		case ROOK:
			return moveRook(B, startCord, endCord, player);
		case KNIGHT:
			return moveKnight(B, startCord, endCord, player);
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

bool PieceController::movePawn(Board* B, std::string start, std::string end, Color turn)
{
	// This code gets int values for start (X,Y) and end (X,Y)
	std::tuple<int, int> from = B->getIndex(start);
	std::tuple<int, int> to = B->getIndex(end);
	int startX = std::get<0>(from);
	int startY = std::get<1>(from);
	int endX = std::get<0>(to);
	int endY = std::get<1>(to);
	
	// Temporary print statements for testing
	std::cout << "trying to move from " << start << " to " << end << std::endl;
	std::cout << "converted to an index this is " << startY << "," << startX << " to " << endY << "," << endX << std::endl;

	if (turn == WHITE)
	{
		// Check possible move types
		// 1) Moving forward one square, and that square is unoccupied
		if ((startX == endX) && (startY == endY + 1) && (B->getPiece(end).getType() == NOPIECE))
		{
			makeMove(B, start, end, turn);
			return true;
		}
		// 2) Moving forward two squares (if pawn hasn't yet moved, and end square is unoccupied)
		else if ((startX == endX) && (startY == endY + 2) && ((B->getPiece(start).getMoved() == false)) && (B->getPiece(end).getType() == NOPIECE))
		{
			makeMove(B, start, end, turn);
			return true;
		}
		// 3) Moving diagonally/forward one square, and capturing enemy piece
		else if ((startY == endY + 1) && (startX == endX - 1 || startX == endX + 1) && ((B->getPiece(end).getColor() != turn) && B->getPiece(end).getColor() != NOCOLOR))
		{
			makeMove(B, start, end, turn);
			return true;
		}

		// If not one of the legal moves above, print error and return false
		std::cout << "Not a legal move." << std::endl << std::endl;
		return false;
	}
	// Same thing for BLACK turn (how to reduce this duplication?)
	else if (turn == BLACK)
	{
		if ((startX == endX) && (startY == endY - 1) && (B->getPiece(end).getType() == NOPIECE))
		{
			makeMove(B, start, end, turn);
			return true;
		}
		else if ((startX == endX) && (startY == endY - 2) && ((B->getPiece(start).getMoved() == false)) && (B->getPiece(end).getType() == NOPIECE))
		{
			makeMove(B, start, end, turn);
			return true;
		}
		else if ((startY == endY - 1) && (startX == endX - 1 || startX == endX + 1) && ((B->getPiece(end).getColor() != turn) && B->getPiece(end).getColor() != NOCOLOR))
		{
			makeMove(B, start, end, turn);
			return true;
		}
		std::cout << "Not a legal move." << std::endl << std::endl;
		return false;

	}
};

bool PieceController::attackPawn(Board* B, std::string startCord, std::string endCord, Color player) 
{

	return false;
}


// There are eight possible knight moves: two squares in one direction, and one square perpendicularly
bool PieceController::moveKnight(Board* B, std::string start, std::string end, Color turn)
{
	std::tuple<int, int> from = B->getIndex(start);
	std::tuple<int, int> to = B->getIndex(end);
	int startX = std::get<0>(from);
	int startY = std::get<1>(from);
	int endX = std::get<0>(to);
	int endY = std::get<1>(to);

	// Temporary print statements for testing
	std::cout << "trying to move from " << start << " to " << end << std::endl;
	std::cout << "converted to an index this is " << startY << "," << startX << " to " << endY << "," << endX << std::endl;

	if (((startY == endY - 2) || (startY == endY + 2)) && ((startX == endX - 1) || (startX == endX + 1)) && (B->getPiece(end).getColor() != turn))
	{
		makeMove(B, start, end, turn);
		return true;
	}
	else if (((startX == endX - 2) || (startX == endX + 2)) && ((startY == endY - 1) || (startY == endY + 1)) && (B->getPiece(end).getColor() != turn))
	{
		makeMove(B, start, end, turn);
		return true;
	}

	std::cout << "Not a valid move." << std::endl;
	return false;
}



bool PieceController::moveRook(Board* B, std::string startCord, std::string endCord, Color player) 
{

	// Check that either row or column are the same
	//int startRow, startCol, endRow, endCol;
	//int* start = B->coordToIndex(startCord);
	//startCol = start[0];
	//startRow = start[1];
	//int* end = B->coordToIndex(endCord);
	//endCol = end[0];
	//endRow = end[1];

	std::tuple<int, int> from = B->getIndex(startCord);
	std::tuple<int, int> to = B->getIndex(endCord);
	int startCol = std::get<0>(from);
	int startRow = std::get<1>(from);
	int endCol = std::get<0>(to);
	int endRow = std::get<1>(to);


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
				if (B->getPiece(endCord).getType() != NOPIECE) {
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
				if (B->getPieceByIndex(startCol, i).getType() != NOPIECE) {
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
				if (B->getPieceByIndex(i, endCol).getType() != NOPIECE) {
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
				if (B->getPieceByIndex(i, endCol).getType() != NOPIECE) {
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
	Piece empty = Piece(NOPIECE, NOCOLOR);
	B->setPiece(startCord, empty);
}