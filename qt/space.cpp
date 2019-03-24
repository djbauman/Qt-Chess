#include "space.h"

Space::Space(int x, int y)
{
    xCoord = x;
    yCoord = y;
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
    piece.setParentItem(this);
}

void Space::mousePressEvent(QGraphicsSceneMouseEvent *ev){
    if(ev->buttons() == Qt::LeftButton){
        qDebug() << "You clicked " << name;
        //topLevelItem()->collectMove(name);
    }
    emit sendSignal(name);
}

void Space::setName(QString n){
    name = n;
}

QString Space::getName(){
    return name;
}

void Space::setImage(QString path)
{
    piece.setPixmap(path);
//    piece.setPos(xCoord +8, yCoord+3); // offset if necessary
    piece.setPos(xCoord, yCoord);
    piece.show();
}

void Space::clearImage()
{
    piece.hide();
}
