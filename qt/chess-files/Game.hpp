#ifndef CAPSTONE_GAME_HPP
#define CAPSTONE_GAME_HPP

#include <QDebug>
#include <QObject>

#include <iostream>
#include "Board.hpp"

class Game : public QObject
{
    Q_OBJECT
public:
	// Start game
	void run();
	void testRun();

	// Movement
	bool move(std::pair<int,int> fromCoords, std::pair<int,int> toCoords);

	// Attributes
	bool isInCheck(Color defendingColor) const;
	bool isInCheckMate(Color defendingColor);
	Color getTurn(int moveNumber) const;

	// Utilities
	void printBoard();
	std::string printColor(Color color);

private:
	Board board;


// Qt Signaling
public slots:
    void getInput(QString input);

signals:
    void sendResponse(int response);

};


#endif
