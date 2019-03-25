#ifndef SPACE_H
#define SPACE_H

#include <QDebug>
#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QImage>
#include <QBrush>
#include <string>

class Space: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Space(int x, int y);
    void mousePressEvent(QGraphicsSceneMouseEvent *e);
    void setName(QString );
    QString getName();
    void setImage(QString path);
    QString getImage();
    void clearImage();

private:
    QString name;
    QGraphicsPixmapItem piece;
    QString image;
    int xCoord;
    int yCoord;


signals:
    QString sendSignal(QString name);
};

#endif // SPACE_H
