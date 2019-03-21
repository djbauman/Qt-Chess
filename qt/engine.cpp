#include "engine.h"

Engine::Engine(){

}

void Engine::getInput(QString input)
{
    qDebug() << "Signal received by slot in: " << input;
}
