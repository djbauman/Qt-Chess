#include "display.h"

Display::Display()
{
    // Connect Game signal with Display slot
    QObject::connect(&game, SIGNAL(sendResponse(QString)), this, SLOT(getResponse(QString)));
    DisplayScene = new QGraphicsScene();
    setup();
    placePieces();
    turnColor = WHITE;
}

void Display::setup()
{
    int j = 0;
    int k = 0;
    bool black = true;
    for(int i=0; i<64; i++)
    {
        QString spacename = spaces[i];
        Space * s = new Space(j,k);
        s->setRect(j,k,50,50); //x loc, y loc, width, height

        // Color squares
        if (i % 8 == 0)
        {
            black = !black;
        }

        if (black)
        {
            s->setBrush(Qt::lightGray);
        }
        black = !black;

        s->setName(spacename);
        spaceList.append(s);
        DisplayScene->addItem(s);
        // Connect Space signal with Game slot
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
    match->setPos(425, 0);
    DisplayScene->addItem(match);

    QString toMove = "White's turn";
    turn = new QGraphicsTextItem();
    turn->setPlainText(toMove);
    turn->setPos(425, 100);
    DisplayScene->addItem(turn);

    QString state = "";
    check = new QGraphicsTextItem();
    check->setPlainText(state);
    check->setPos(425, 200);
    DisplayScene->addItem(check);
}

void Display::placePieces()
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


QGraphicsScene* Display::getScene()
{
    return DisplayScene;
}

// Get a response from the Game object and change the
// images of pieces on the board appropriately
void Display::getResponse(QString response)
{
    std::string responseString = response.toStdString();

    if (responseString.compare("Check") == 0)
    {
        qDebug() << "Check";
        check->setPlainText("Check!");
    }
    else
    {
        check->setPlainText("");
    }

    // If response was "Invalid Move", ignore it
    if (responseString.compare("Invalid Move") == 0)
    {
        qDebug() << "Invalid Move";
        return;
    }
    else if (responseString.compare("Checkmate") == 0)
    {
        qDebug() << "Checkmate!";
        check->setPlainText("Checkmate!");
        return;
    }
    else if (responseString.compare("Stalemate") == 0)
    {
        qDebug() << "Stalemate!";
        check->setPlainText("Stalemate!");
        return;
    }
    // Otherwise, use the response from Game to move the correct pieces
    else
    {
        qDebug() << "Display got permission from Game to move icons.";
//        qDebug() << "The response Game sent back was " << response;
        if (response == "Castle White Kingside")
        {
            qDebug() << "Display needs to castle white kingside.";
            QString tempKing = spaceList[60]->getImage();
            spaceList[60]->clearImage();
            QString tempRook = spaceList[63]->getImage();
            spaceList[63]->clearImage();

            spaceList[62]->setImage(tempKing);
            spaceList[61]->setImage(tempRook);
        } else if (response == "Castle White Queenside")
        {
            qDebug() << "Display needs to castle white queenside.";
            QString tempKing = spaceList[60]->getImage();
            spaceList[60]->clearImage();
            QString tempRook = spaceList[56]->getImage();
            spaceList[56]->clearImage();

            spaceList[58]->setImage(tempKing);
            spaceList[59]->setImage(tempRook);
        } else if (response == "Castle Black Kingside")
        {
            qDebug() << "Display needs to castle black kingside.";
            QString tempKing = spaceList[4]->getImage();
            spaceList[4]->clearImage();
            QString tempRook = spaceList[7]->getImage();
            spaceList[7]->clearImage();

            spaceList[6]->setImage(tempKing);
            spaceList[5]->setImage(tempRook);
        } else if (response == "Castle Black Queenside")
        {
            qDebug() << "Display needs to castle black queenside.";
            QString tempKing = spaceList[4]->getImage();
            spaceList[4]->clearImage();
            QString tempRook = spaceList[0]->getImage();
            spaceList[0]->clearImage();

            spaceList[2]->setImage(tempKing);
            spaceList[3]->setImage(tempRook);
        }
        else
        {
            QString firstSpace = "";
            QString secondSpace = "";
            firstSpace += response[0];
            firstSpace += response[1];
            secondSpace += response[2];
            secondSpace += response[3];

            QString temp;
            for (int i=0; i<spaceList.length(); i++ )
            {
                if (spaceList[i]->getName() == firstSpace)
                {
                    temp = spaceList[i]->getImage();
                    spaceList[i]->clearImage();
                }
            }
            for (int i=0; i<spaceList.length(); i++ )
            {
                if (spaceList[i]->getName() == secondSpace)
                {
                    spaceList[i]->setImage(temp);
                }
            }
        }

        if (turnColor == WHITE)
        {
            turnColor = BLACK;
            turn->setPlainText("Black's Turn");
        }
        else
        {
            turnColor = WHITE;
            turn->setPlainText("White's Turn");
        }
    }

}
