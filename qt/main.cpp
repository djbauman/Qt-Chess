#include "space.h"
#include "display.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QGridLayout>
#include <QFrame>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Display D;
    // create scene on the heap
    // QGraphicsScene * scene = new chessgame();
//    QGraphicsView * view = new QGraphicsView(scene);

    QGraphicsView* view = new QGraphicsView(D.getScene());

    // Connect signals


    view->show();


    return a.exec();
}
