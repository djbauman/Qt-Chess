#ifndef CAPSTONE_GAME_HPP
#define CAPSTONE_GAME_HPP

#include <QDebug>
#include <QObject>
#include <QString>
#include <iostream>
#include "Board.hpp"

class Game : public QObject
{
    Q_OBJECT
public:
	// Start game
	void run();
    void guiRun();
	void testRun();

	// Movement
	bool move(std::pair<int,int> fromCoords, std::pair<int,int> toCoords);
	bool castle(Color toMove, std::pair<int, int> from, std::pair<int, int> to);

	// Attributes
	bool isInCheck(Color defendingColor) const;
	bool isInCheckMate(Color defendingColor);
	bool isInStalemate(Color defendingColor);
	Color getTurn(int moveNumber) const;

	// Utilities
	void printBoard();
	std::string printColor(Color color);

private:
	Board board;
    QString guimove;
    std::string move1 = "";
    std::string move2 = "";
    Color guiTurn = WHITE;
    void switchGuiTurn();
    void resetMoves();

    // Qt Signaling
public slots:
    void getInput(QString input);

signals:
    void sendResponse(QString response);
};

#endif
