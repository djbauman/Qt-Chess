#ifndef CAPSTONE_PIECECONTROLLER_HPP
#define CAPSTONE_PIECECONTROLLER_HPP

#include <iostream>
#include <string>
#include "Board.hpp"

class PieceController
{
public:
	bool movePiece(Board*, std::string, std::string, Color);
	PieceController();
private:
	bool movePawn(Board*, std::string, std::string, Color);
	bool attackPawn(Board*, std::string, std::string, Color);
	bool moveRook(Board*, std::string, std::string, Color);
	bool moveKnight(Board*, std::string, std::string, Color);
	bool moveBishop(Board*, std::string, std::string, Color);
	bool moveQueen(Board*, std::string, std::string, Color);
	void makeMove(Board*, std::string, std::string, Color);

};

#endif
