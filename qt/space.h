#ifndef SPACE_H
#define SPACE_H

#include <QGraphicsSceneMouseEvent>
#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QString>
#include <QDebug> // for testing and debugging

class Space : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
private:
    QString name;
    QGraphicsPixmapItem image;
    int xCoord;
    int yCoord;

public:
    Space(QString, int, int);
    void setImage(QString);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

signals:
    QString sendSignal(QString name);
};

#endif // SPACE_H
