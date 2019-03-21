#ifndef COUNTER_H
#define COUNTER_H

#include <QObject>
#include <QDebug>

class Counter : public QObject
{
    Q_OBJECT

public:
    Counter() { m_value = 0; }

    int value() const { return m_value; }

    // Slots that other objects can send signals to
public slots:
    void setValue(int value);
    void getInput(QString input);

    // Signals to emit to other objects
signals:
    void valueChanged(int newValue);

private:
    int m_value;
};

#endif // COUNTER_H
