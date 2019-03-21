#include "counter.h"

void Counter::setValue(int value)
{
    if (value != m_value) {
        m_value = value;
        emit valueChanged(value);
    }
}

void Counter::getInput(QString input)
{
    qDebug() << "Signal received by slot in: " << input;
}
