#include <QString>

#include "space.h"

Space::Space(QString input, int x, int y)
{
    name = input;
    xCoord = x;
    yCoord = y;
    image.setParentItem(this);
    image.scale();

//    setFlag(QGraphicsItem::ItemIsFocusable);
//    setFocus();

}

void Space::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if(event->buttons() == Qt::LeftButton){
        qDebug() << "You left clicked on " << QString(name) << "which is located at " << xCoord << ", " << yCoord;
        if (image.isVisible())
        {
            image.hide();
        } else {
            image.show();
        }
    emit sendSignal(name);
    }
}

// Takes a path, e.g. ":/images/board.png"
void Space::setImage(QString path)
{
    image.setPixmap(path);
    image.setPos(xCoord + 8, yCoord + 3);
    image.show();
}
