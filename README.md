# Cpp-Chess-Gui

### Repository Contents

C:.
│   .gitattributes
│   CMakeLists.txt
│   LICENSE
│   README.md
│
├───include
│       catch.hpp
│
├───source
│       Board.cpp
│       Board.hpp
│       Piece.cpp
│       Piece.hpp
│       Square.cpp
│       Square.hpp
│
└───test
        BoardTest.cpp
        TestRunner.cpp

### Chess Engine Outline

namespace CppChess{
	
	class PieceController{
	private:
		
	public:
		//return false if they could not make the move
		bool movePawn(Board);
		bool moveRook(Board);
		bool moveKnight(Board);
		bool moveBishop(Board);
		bool moveQueen(Board);
		std::vector convertNotation();
	}

/*-----------------------------------------------------------------------------------------------------------------------------------------*/
	class Piece{
	private:
		type color; //black or white
		type pieceType
		bool hasMoved;
	public:

		Piece(piecetype, color){

		}
		~Piece();

		std::string GetType(); //return what piece it is, i.e. rook, bishop ect.

		type GetColor();
		bool getHasMoved(); //We need this for pawns, rooks, and kings
	}

/*-----------------------------------------------------------------------------------------------------------------------------------------*/
	class BoardSpace{
	private:
		Piece currentPiece;
		type color;

	public:
		type getCurrentPiece();
		type getColor();
	}

/*-----------------------------------------------------------------------------------------------------------------------------------------*/
	class Board{
	private:
		std::vector<BoardSpace> Board;

	public:
		Board();
		~Board();
		std::string getBoard();
		bool inCheck();
		bool inCheckMate();
		bool validateMoveCheck(); //this will evaluate if the move that was just made put the player in check, and thus trigger a mechanism to go back
		bool inStaleMate();
		void makeMove();
		bool checkPlayerPiece();
		void makeMove();
		void promotePawn();
		void castle();
	}

/*-----------------------------------------------------------------------------------------------------------------------------------------*/
	class Game{
	private:
		Board currentBoard;
		Player P1;
		Player P2;

	public:
		Chess();
		~Chess();

		void newGame();
		void getMove();
		void printBoard();
		type checkGamestate(); //return checkmate, stalemate

	}

}