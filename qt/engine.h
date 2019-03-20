#ifndef ENGINE_H
#define ENGINE_H


#include <QObject>
#include <QDebug>

class Engine : public QObject
{
    Q_OBJECT

public slots:
    void getInput(QString input);

};

#endif // ENGINE_H
