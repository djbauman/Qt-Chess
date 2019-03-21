#include "engine.h"

Engine::Engine()
{

}

void Engine::getInput(QString input)
{
    qDebug() << "Engine saw that " << input << "was clicked, and will now respond.";
    emit sendResponse(17);
}
