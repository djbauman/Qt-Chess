#include "display.h"

Display::Display()
{
    // Connect Game signal with Display slot
//    QObject::connect(&engine, SIGNAL(sendResponse(int)), this, SLOT(getResponse(int)));
    QObject::connect(&game, SIGNAL(sendResponse(int)), this, SLOT(getResponse(int)));
    DisplayScene = new QGraphicsScene();
    setup();
    placePiece();
}

void Display::setup()
{
    int j = 0;
    int k = 0;
    for(int i=0; i<64; i++)
    {
        QString spacename = spaces[i];
        Space * s = new Space(j,k);
        s->setRect(j,k,50,50); //x loc, y loc, width, height
        s->setBrush(Qt::lightGray);
        s->setName(spacename);
        spaceList.append(s);
        DisplayScene->addItem(s);
        // Connect Space signal with Game slot
//        QObject::connect(s, SIGNAL(sendSignal(QString)), &engine, SLOT(getInput(QString)));
        QObject::connect(s, SIGNAL(sendSignal(QString)), &game, SLOT(getInput(QString)));

        j += 50;
        if (j == 400)
        {
            j = 0;
            k += 50;
        }
    }

    QString matchText = "Player 1 vs Player 2";
    QGraphicsTextItem * match = new QGraphicsTextItem();
    match->setPlainText(matchText);
    match->setPos(400, 0);
    DisplayScene->addItem(match);
}

void Display::placePiece()
{
    spaceList[0]->setImage(":/images/50px/BlackRook.png");
    spaceList[1]->setImage(":/images/50px/BlackKnight.png");
    spaceList[2]->setImage(":/images/50px/BlackBishop.png");
    spaceList[3]->setImage(":/images/50px/BlackQueen.png");
    spaceList[4]->setImage(":/images/50px/BlackKing.png");
    spaceList[5]->setImage(":/images/50px/BlackBishop.png");
    spaceList[6]->setImage(":/images/50px/BlackKnight.png");
    spaceList[7]->setImage(":/images/50px/BlackRook.png");
    spaceList[8]->setImage(":/images/50px/BlackPawn.png");
    spaceList[9]->setImage(":/images/50px/BlackPawn.png");
    spaceList[10]->setImage(":/images/50px/BlackPawn.png");
    spaceList[11]->setImage(":/images/50px/BlackPawn.png");
    spaceList[12]->setImage(":/images/50px/BlackPawn.png");
    spaceList[13]->setImage(":/images/50px/BlackPawn.png");
    spaceList[14]->setImage(":/images/50px/BlackPawn.png");
    spaceList[15]->setImage(":/images/50px/BlackPawn.png");


    spaceList[48]->setImage(":/images/50px/WhitePawn.png");
    spaceList[49]->setImage(":/images/50px/WhitePawn.png");
    spaceList[50]->setImage(":/images/50px/WhitePawn.png");
    spaceList[51]->setImage(":/images/50px/WhitePawn.png");
    spaceList[52]->setImage(":/images/50px/WhitePawn.png");
    spaceList[53]->setImage(":/images/50px/WhitePawn.png");
    spaceList[54]->setImage(":/images/50px/WhitePawn.png");
    spaceList[55]->setImage(":/images/50px/WhitePawn.png");
    spaceList[56]->setImage(":/images/50px/WhiteRook.png");
    spaceList[57]->setImage(":/images/50px/WhiteKnight.png");
    spaceList[58]->setImage(":/images/50px/WhiteBishop.png");
    spaceList[59]->setImage(":/images/50px/WhiteQueen.png");
    spaceList[60]->setImage(":/images/50px/WhiteKing.png");
    spaceList[61]->setImage(":/images/50px/WhiteBishop.png");
    spaceList[62]->setImage(":/images/50px/WhiteKnight.png");
    spaceList[63]->setImage(":/images/50px/WhiteRook.png");
}



void Display::collectMove(QString m)
{
    move+=m;
    if (move.length()==4)
    {
        qDebug() << move;
        move = "";
    }
}

QGraphicsScene* Display::getScene()
{
    return DisplayScene;
}

void Display::getResponse(int response)
{
    qDebug() << "Display: Got a response of " << response;
}

// Receive signal from Engine indicating result of the move

