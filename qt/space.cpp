#include "space.h"

Space::Space(int x, int y)
{
    xCoord = x;
    yCoord = y;
//    setFlag(QGraphicsItem::ItemIsFocusable);
//    setFocus();
    piece.setParentItem(this);
}

// When clicked, space name is sent to Display's slot
void Space::mousePressEvent(QGraphicsSceneMouseEvent *ev){
    if(ev->buttons() == Qt::LeftButton){
        qDebug() << "You clicked " << name;
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
    image = path;
    piece.setPixmap(path);
    piece.setPos(xCoord, yCoord);
    piece.show();
}

QString Space::getImage()
{
    return image;

}
void Space::clearImage()
{
    piece.hide();
}
