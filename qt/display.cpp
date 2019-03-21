#include "Display.h"

Display::Display()
{
    // Connect Engine signal with Display slot
    QObject::connect(&engine, SIGNAL(sendResponse(int)), this, SLOT(getResponse(int)));
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
        // Connect Space signal with Engine slot
        QObject::connect(s, SIGNAL(sendSignal(QString)), &engine, SLOT(getInput(QString)));

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
    spaceList[0]->setImage(":/images/black-pawn-small.png");
    spaceList[1]->setImage(":/images/black-pawn-small.png");
    spaceList[2]->setImage(":/images/black-pawn-small.png");
    spaceList[3]->setImage(":/images/black-pawn-small.png");
    spaceList[4]->setImage(":/images/black-pawn-small.png");
    spaceList[5]->setImage(":/images/black-pawn-small.png");
    spaceList[6]->setImage(":/images/black-pawn-small.png");
    spaceList[7]->setImage(":/images/black-pawn-small.png");
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
    qDebug() << "Display: Response from Engine is " << response;
}

// Receive signal from Engine indicating result of the move

