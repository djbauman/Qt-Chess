#include <QDebug>
#include<QObject>

#ifndef ENGINE_H
#define ENGINE_H

class Engine : public QObject
{
    Q_OBJECT
public:
    Engine();

public slots:
    void getInput(QString input);

signals:
    void sendResponse(int response);
};

#endif // ENGINE_H
