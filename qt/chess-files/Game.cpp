#include <vector>
#include <string>
#include <sstream>
#include "Game.hpp"

/* Basic implementation of chess. */
void Game::run()
{
	// Set up turn-based game
	std::string input;
	int currentMove = 1;
	Color toMove = getTurn(currentMove);

	// Print instructions
	std::cout << "Welcome to Chara Chess. Enter moves as space-separated strings (e.g. e2 e4) or exit to quit." << '\n';

	// Repeat until game is finished
	while (true)
	{
		// Determine if a player is in check
		if (isInCheckMate(toMove))
		{
			std::cout << printColor(toMove) << " is in checkmate. Game over." << '\n';
			break;
		}

		// Determine if a player is in check
		if (isInStalemate(toMove))
		{
			std::cout << printColor(toMove) << " is in stalemate. Draw." << '\n';
			break;
		}

		// Print board
		printBoard();

		// Get first input
		std::cout << printColor(toMove) << "'s turn. Enter move: ";
		std::getline(std::cin, input);

		// Handle non-move commands
		if (input == "exit")
		{
			break;
		}
		else if (input == "moves")
		{
			board.printMoves();
			continue;
		}
		else if (input == "revert")
		{
			if (currentMove > 1)
			{
				board.revertLastMove();
				currentMove--;
				toMove = getTurn(currentMove);
			}
			else
			{
				std::cout << "Can't revert - already at beginning of game." << '\n';
			}
			continue;
		}
		else if (input == "captures")
		{
			board.printCapturedPieces();
			continue;
		}

		// Convert input to a move
		std::string buf;					// for parsing input
		std::stringstream ss(input);       	// insert the string into a stream
		std::vector<std::string> tokens; 	// create vector to hold substrings
		while (ss >> buf)
		{
			tokens.push_back(buf);
		}
		std::pair<int, int> from = board.algebraicToInt(tokens[0]); 	// convert substring to pair
		std::pair<int, int> to = board.algebraicToInt(tokens[1]);		// convert substring to pair

    // Verify that a piece was selected
		if (board.getPiece(from) == nullptr)
		{
			std::cout << "Error: No piece at this starting square" << '\n';
			continue;
		}

		// Verify that the correct player is moving
		if (board.getPiece(from)->getColor() != toMove)
		{
			std::cout << "Error: It's " << printColor(toMove) << "'s turn." << '\n';
			continue;
		}

		// Check if this is an attempted castle and handle accordingly
		if (board.getPiece(from)->getType() == KING && board.getMoveLength(from, to) > 1)
		{
			if (castle(toMove, from, to))
			{
				currentMove++;
				toMove = getTurn(currentMove);
			}
			else
			{
				std::cout << "Error: This is an invalid castle." << '\n';
			}

			// We've already handled the move, so skip rest of loop and start from top
			continue;
		}

		// Attempt move piece
		if (board.movePiece(from, to))
		{
			// Verify that move doesn't put player in check, else switch players
			if (isInCheck(toMove))
			{
				// If move puts player in check, print error, revert move, and let player enter different move
				std::cout << "Error: This leaves " << printColor(toMove) << " in check.\n";
				board.revertLastMove();
				continue;
			}
			else
			{
				currentMove++;
				toMove = getTurn(currentMove);
			}
		}
		else
		{
			std::cout << "Error: Invalid move.\n";
		}
	}
}

void Game::guiRun()
{
    return;
}

/* For trying out different chess play configurations. */
void Game::testRun()
{
	std::cout << "Starting board for move testing\n";
	board.printBoardAlgebraicAxes();

	std::cout << "Testing pawns moving 1 space\n";
	board.movePiece(std::make_pair(6, 0), std::make_pair(5, 0));
	board.printBoardAlgebraicAxes();
	board.movePiece(std::make_pair(1, 1), std::make_pair(2, 1));
	board.printBoardAlgebraicAxes();

	std::cout << "Testing pawns moving 2 spaces\n";
	board.movePiece(std::make_pair(6, 4), std::make_pair(4, 4));
	board.printBoardAlgebraicAxes();
	board.movePiece(std::make_pair(1, 3), std::make_pair(3, 3));
	board.printBoardAlgebraicAxes();

	std::cout << "Testing pawn capture (enemy)\n";
	board.movePiece(std::make_pair(4, 4), std::make_pair(3, 3));
	board.printBoardAlgebraicAxes();

	std::cout << "Testing pawn capture (friendly) (should fail)\n";
	board.movePiece(std::make_pair(6, 1), std::make_pair(5, 0));
	board.printBoardAlgebraicAxes();

	std::cout << "Testing pawn moving backwards (white) (should fail)\n";
	board.movePiece(std::make_pair(5, 0), std::make_pair(6, 0));
	board.printBoardAlgebraicAxes();

	std::cout << "Testing pawn moving backwards (black) (should fail)\n";
	board.movePiece(std::make_pair(2, 1), std::make_pair(1, 1));
	board.printBoardAlgebraicAxes();

	std::cout << "Testing already moved pawn moving 2 squares (should fail)\n"; // Error, doesn't fail
	board.movePiece(std::make_pair(5, 0), std::make_pair(3, 0));
	board.printBoardAlgebraicAxes();

	std::cout << "Testing bishop moving forward\n";
	board.movePiece(std::make_pair(0, 2), std::make_pair(1, 1));
	board.printBoardAlgebraicAxes();

	std::cout << "Testing bishop capturing\n";
	board.movePiece(std::make_pair(1, 1), std::make_pair(3, 3));
	board.printBoardAlgebraicAxes();

	std::cout << "Testing bishop moving into friendly piece (should fail)\n";
	board.movePiece(std::make_pair(3, 3), std::make_pair(1, 5));
	board.printBoardAlgebraicAxes();

	std::cout << "Testing rook moving vertically\n";
	board.movePiece(std::make_pair(7, 0), std::make_pair(5, 0));
	board.printBoardAlgebraicAxes();

	std::cout << "Testing rook moving horizontally\n";
	board.movePiece(std::make_pair(0, 0), std::make_pair(0, 3));
	board.printBoardAlgebraicAxes();

	std::cout << "Testing rook moving into friendly piece (should fail)\n";
	board.movePiece(std::make_pair(0, 3), std::make_pair(0, 5));
	board.printBoardAlgebraicAxes();

	std::cout << "Testing rook moving through piece (should fail)\n";
	board.movePiece(std::make_pair(0, 7), std::make_pair(0, 4));
	board.printBoardAlgebraicAxes();

	std::cout << "Testing rook capturing\n";
	board.movePiece(std::make_pair(3, 3), std::make_pair(5, 5));
	board.printBoardAlgebraicAxes();
	board.movePiece(std::make_pair(5, 0), std::make_pair(5, 5));
	board.printBoardAlgebraicAxes();

	std::cout << "Testing Queen Move\n";
	board.movePiece(std::make_pair(0, 3), std::make_pair(4, 3));
	board.printBoardAlgebraicAxes();
	board.movePiece(std::make_pair(4, 3), std::make_pair(6, 5));
	board.printBoardAlgebraicAxes();

	std::cout << "Testing Queen Move Error\n";
	board.movePiece(std::make_pair(6, 5), std::make_pair(0, 3));
	board.printBoardAlgebraicAxes();

	std::cout << "Testing Queen Diag Other\n";
	board.movePiece(std::make_pair(6, 5), std::make_pair(4, 7));
	board.printBoardAlgebraicAxes();
}

/* Determines whether a player is in check based on qualities of the Board. */
bool Game::isInCheck(Color defendingColor) const
{
	// We'll use this to get the opposing sides' pieces
	Color attackingColor;
	if (defendingColor == WHITE)
	{
		attackingColor = BLACK;
	}
	else
	{
		attackingColor = WHITE;
	}

	// Get locations of defending king and attacking pieces
	std::pair<int, int> kingLocation = board.getKingLocation(defendingColor);
	std::vector<std::pair<int, int>> pieceLocations = board.getPieceLocations(attackingColor);

	for (auto attackingPiece : pieceLocations)
	{
		if (board.isValidMove(attackingPiece, kingLocation))
		{
			return true;
		}
	}

	// When you come at the king, you best not miss
	return false;
}

/* Returns true if a player is in checkmate. The conditions of checkmate are:
 * - In check
 * - No legal moves */
bool Game::isInCheckMate(Color defendingColor)
{
	if (isInCheck(defendingColor))
	{
		std::vector<std::pair<int, int>> pieceLocations = board.getPieceLocations(defendingColor);
		std::vector<std::pair<int, int>> locations = board.getLocations();

		for (auto const &pieceLocation : pieceLocations)
		{
			for (auto const &location : locations)
			{
				// Attempt move piece
				if (board.movePiece(pieceLocation, location))
				{
					// If player is no longer in check, then there's hope! Revert move and return false.
					if (!isInCheck(defendingColor))
					{
						board.revertLastMove();
						return false;
					}

					// We'll also need to revert the last move if the player was still in check.
					board.revertLastMove();
				}
			}
		}
	}
	else
	{
		return false;
	}

	// No other options for defendingColor, so return true for isCheckMate
	return true;
}

/* Returns true if a player is in stalemate. The conditions of stalemate are:
 * - Not in check
 * - No legal moves */
bool Game::isInStalemate(Color defendingColor)
{
	if (isInCheck(defendingColor))
	{
		return false;
	}
	else
	{
		std::vector<std::pair<int, int>> pieceLocations = board.getPieceLocations(defendingColor);
		std::vector<std::pair<int, int>> locations = board.getLocations();

		for (auto const &pieceLocation : pieceLocations)
		{
			for (auto const &location : locations)
			{
				// Attempt move piece
				if (board.movePiece(pieceLocation, location))
				{
					// If player is still not in check after this move, then revert move and return false.
					if (!isInCheck(defendingColor))
					{
						board.revertLastMove();
						return false; // not in stalemate
					}

					// We'll also need to revert the last move if the player was still in check.
					board.revertLastMove();
				}
			}
		}
	}

	// No other options for defendingColor, so return true for isStalemate
	return true;
}

/* If valid castling, carries out and returns true, else returns false. Castling requires:
 * - The king and the chosen rook are on the player's first rank.
 * - Neither the king nor the chosen rook has previously moved.
 * - There are no pieces between the king and the chosen rook.
 * - The king is not currently in check.
 * - The king does not pass through a square that is attacked by an enemy piece.
 * - The king does not end up in check. */
bool Game::castle(const Color toMove, const std::pair<int, int> from, const std::pair<int, int> to)
{
	// Get the rook we're going to castle with and intermediate location
	Piece* rook;
	std::pair<int,int> intermediateLocation;
	std::pair<int,int> rookLocation;
	if (to == board.algebraicToInt("g8"))
	{
		rookLocation = board.algebraicToInt("h8");
		intermediateLocation = board.algebraicToInt("f8");
	}
	else if (to == board.algebraicToInt("c8"))
	{
		rookLocation = board.algebraicToInt("a8");
		intermediateLocation = board.algebraicToInt("d8");
	}
	else if (to == board.algebraicToInt("g1"))
	{
		rookLocation = board.algebraicToInt("h1");
		intermediateLocation = board.algebraicToInt("f1");
	}
	else if (to == board.algebraicToInt("c1"))
	{
		rookLocation = board.algebraicToInt("a1");
		intermediateLocation = board.algebraicToInt("d1");
	}
	else
	{
		return false;
	}

	// Get a pointer to the rook
	rook = board.getPiece(rookLocation);

	// Check if there is a clear path and that destination is clear and that it's a horizontal move
	if (!board.isPathClear(from, rookLocation) || !board.isHorizontalMove(from, to))
	{
		return false;
	}

	// Verify that king is not in check
	if (isInCheck(toMove))
	{
		return false;
	}

	// Verify that king and concerned rook haven't moved yet
	if (board.getPiece(from)->getMoved() || rook->getMoved())
	{
		return false;
	}

	// Carry out move, stepping back if king ends up in check
	// First step for king
	if (board.movePiece(from, intermediateLocation))
	{
		// Verify that move doesn't put player in check
		if (isInCheck(toMove))
		{
			// If move puts player in check, revert move, and let player enter different move
			board.revertLastMove();
			return false;
		}

	}
	// Second step for king
	if (board.movePiece(intermediateLocation, to))
	{
		// Verify that move doesn't put player in check
		if (isInCheck(toMove))
		{
			// If move puts player in check, revert last two moves, and let player enter different move
			board.revertLastMove();
			board.revertLastMove();
			return false;
		}
	}

	// At this point the king has moved legally and we can set the rook and return true
	board.setRook(rookLocation, intermediateLocation);
	return true;
}

/* Pass a move from the Game to the Board. */
bool Game::move(std::pair<int, int> fromCoords, std::pair<int, int> toCoords)
{
	return board.movePiece(fromCoords, toCoords);
}

/* Print the Board. */
void Game::printBoard()
{
	board.printBoardAlgebraicAxes();
}

/* Determine whose turn it is based on the number of moves in the current game. */
Color Game::getTurn(int moveNumber) const
{
	if (moveNumber % 2 == 1)
	{
		return WHITE;
	}
	else
	{
		return BLACK;
	}
}

/* Print the string representation of a Color enum. */
std::string Game::printColor(Color color)
{
	if (color == WHITE)
	{
		return "White";
	}
	else
	{
		return "Black";
    }
}

// Change guiTurn between White/Black
void Game::switchGuiTurn()
{
    if (guiTurn == WHITE)
    {
        guiTurn = BLACK;
    }
    else {
        guiTurn = WHITE;
    }
}


// Clear move1 and move2 strings
void Game::resetMoves()
{
    move1 = "";
    move2 = "";
}


// This function is a Qt slot, a function designed to receive QObject signals.
// It receives a signal from the Display whenever a space is clicked. Upon collecting
// two spaces, the move can be executed if it is valid, or ignored if not.
void Game::getInput(QString input)
{
    qDebug() << "Game saw that " << input << "was clicked, and will now respond.";

    // If this is the first click, store it in move1
    if (move1 == "")
    {
        move1 = input.toStdString();
    }
    // If this is the second click, store it in move2
    else
    {
        move2 = input.toStdString();

        // We can now pass the move to the Game
        std::pair<int, int> from = board.algebraicToInt(move1); 	// convert substring to pair
        std::pair<int, int> to = board.algebraicToInt(move2);		// convert substring to pair

        // Verify that a piece was selected
        if (board.getPiece(from) == nullptr)
        {
            qDebug() << "No piece selected.";
            sendResponse("Invalid Move");
            resetMoves();
            return;
        }

        if (board.getPiece(from)->getColor() != guiTurn)
        {
            std::cout << "Error: It's " << printColor(guiTurn) << "'s turn." << '\n';
            qDebug() << "Game.cpp: Error: Not your turn.";
            emit sendResponse("Invalid Move");
            resetMoves();
            return;
        }

        // Check if this is an attempted castle and handle accordingly
        if (board.getPiece(from)->getType() == KING && board.getMoveLength(from, to) > 1)
        {
            if (castle(guiTurn, from, to))
            {
                switchGuiTurn();
                qDebug() << "Castled!";
                // Signal the Display to change the images appropriately
                // If it is the White King...
                if (from.first == 7)
                {
                    // If Kingside...
                    if (to.second == 6)
                    {
                        emit sendResponse("Castle White Kingside");
                    }
                    else
                    {
                        emit sendResponse("Castle White Queenside");
                    }
                }
                // else if it is the Black King...
                else if (from.first == 0)
                {
                    if (to.second == 6)
                    {
                        emit sendResponse("Castle Black Kingside");
                    }
                    else
                    {
                        emit sendResponse("Castle Black Queenside");
                    }
                }
            }
            else
            {
                std::cout << "Error: This is an invalid castle." << '\n';
                qDebug() << "Error: Invalid castle.";
            }
        }

        // Attempt to move piece
        // TODO: Check for castling here?
        else if (board.movePiece(from, to))
        {
            // Verify that move doesn't put player in check, else switch players
            if (isInCheck(guiTurn))
            {
                // If move puts player in check, print error, revert move, and let player enter different move
                std::cout << "Error: This leaves " << printColor(guiTurn) << " in check.\n";
                qDebug() << "Error: This leaves you in check.";
                board.revertLastMove();
                sendResponse("Invalid Move");
            }
            // If the move was valid, switch turns and send "Valid" response
            else
            {
                switchGuiTurn();

                // Send QString response containing the two spaces of the valid move
                QString sendStr = "";
                QString part1 = QString::fromStdString(move1);
                QString part2 = QString::fromStdString(move2);
                sendStr += part1;
                sendStr += part2;
                sendResponse(sendStr);
            }
        }
        else
        {
            std::cout << "Error: Invalid move.\n";
            qDebug() << "Error: Invalid move.";
            sendResponse("Invalid Move");
        }

        if(isInCheckMate(guiTurn)==true)
        {
            sendResponse("Checkmate");
        }
        else if (isInCheck(guiTurn)==true)
        {
            sendResponse("Check");
        }
        else if(isInStalemate(guiTurn))
        {
            sendResponse("Stalemate");
        }

        resetMoves();
    }

}
