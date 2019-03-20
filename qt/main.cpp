#include "space.h"
#include "engine.h"

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGridLayout>
#include <QFrame>
#include <QGraphicsPixmapItem>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Test Counter signals/slots
//    Counter counter1, counter2;
//    QObject::connect(&counter1, &Counter::valueChanged, &counter2, &Counter::setValue);
//    counter1.setValue(12);
    Engine engine1;

    // create scene on the heap
    QGraphicsScene * scene = new QGraphicsScene();

    //QWidget mainWidget;
    //QGridLayout *board = new QGridLayout(&mainWidget);

    Space * a8 = new Space("a8", 0, 0);
    a8->setRect(0,0,50,50); //x loc, y loc, width, height
    a8->setImage(":/images/white-pawn-small.png");
    scene->addItem(a8);

    QObject::connect(a8, SIGNAL(sendSignal(QString)), &engine1, SLOT(getInput(QString)));

//    // Add a PixmapItem representing a piece
//    QGraphicsPixmapItem* item = new QGraphicsPixmapItem();
//    // Offset image slightly to center it
//    item->setPos(8,3);
//    item->setPixmap(QPixmap(":/images/white-pawn-small.png"));
//    scene->addItem(item);


    Space * a7 = new Space("a7", 50, 0);
    a7->setRect(50, 0, 50, 50);
    a7->setImage(":/images/black-pawn-small.png");
    scene->addItem(a7);
    QObject::connect(a7, SIGNAL(sendSignal(QString)), &engine1, SLOT(getInput(QString)));

//    Space * a6 = new Space("a6", 0, 0);
//    a6->setRect(100, 0, 50, 50);
//    scene->addItem(a6);

//    Space * a5 = new Space("a5", 0, 0);
//    a5->setRect(150, 0, 50, 50);
//    scene->addItem(a5);

//    Space * a4 = new Space("a4", 0, 0);
//    a4->setRect(200, 0, 50, 50);
//    scene->addItem(a4);

//    Space * a3 = new Space("a3", 0, 0);
//    a3->setRect(250, 0, 50, 50);
//    scene->addItem(a3);

//    Space * a2 = new Space("a2", 0, 0);
//    a2->setRect(300, 0, 50, 50);
//    scene->addItem(a2);

//    Space * a1 = new Space("a1");
//    a1->setRect(350, 0, 50, 50);
//    scene->addItem(a1);

//    Space * b8 = new Space("b8");
//    b8->setRect(0,50,50,50);
//    scene->addItem(b8);

//    Space * b7 = new Space("b7");
//    b7->setRect(50, 50, 50, 50);
//    scene->addItem(b7);

//    Space * b6 = new Space("b6");
//    b6->setRect(100, 50, 50, 50);
//    scene->addItem(b6);

//    Space * b5 = new Space("b5");
//    b5->setRect(150, 50, 50, 50);
//    scene->addItem(b5);

//    Space * b4 = new Space("b4");
//    b4->setRect(200, 50, 50, 50);
//    scene->addItem(b4);

//    Space * b3 = new Space("b3");
//    b3->setRect(250, 50, 50, 50);
//    scene->addItem(b3);

//    Space * b2 = new Space("b2");
//    b2->setRect(300, 50, 50, 50);
//    scene->addItem(b2);

//    Space * b1 = new Space("b1");
//    b1->setRect(350, 50, 50, 50);
//    scene->addItem(b1);

//    Space * c8 = new Space("c8");
//    c8->setRect(0,100,50,50);
//    scene->addItem(c8);

//    Space * c7 = new Space("c7");
//    c7->setRect(50,100, 50, 50);
//    scene->addItem(c7);

//    Space * c6 = new Space("c6");
//    c6->setRect(100,100,50,50);
//    scene->addItem(c6);

//    Space * c5 = new Space("c5");
//    c5->setRect(150, 100, 50, 50);
//    scene->addItem(c5);

//    Space * c4 = new Space("c4");
//    c4->setRect(200, 100, 50, 50);
//    scene->addItem(c4);

//    Space * c3 = new Space("c3");
//    c3->setRect(250, 100, 50, 50);
//    scene->addItem(c3);

//    Space * c2 = new Space("c2");
//    c2->setRect(300, 100, 50, 50);
//    scene->addItem(c2);

//    Space * c1 = new Space("c1");
//    c1->setRect(350, 100, 50, 50);
//    scene->addItem(c1);

    QGraphicsView * view = new QGraphicsView(scene);
    view->show();

    return a.exec();
}
