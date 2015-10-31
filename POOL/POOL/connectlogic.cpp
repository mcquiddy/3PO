#include "connectlogic.h"
#include <core.h>
//extern Core * nucleo;
connectLogic::connectLogic()
{
    nucleo=Core::getInstance();
}

void connectLogic::setDistancia(int Distancia)
{
    nucleo->Aldeanos->setDistancia(Distancia);
}

void connectLogic::GameOver()
{
    nucleo->GameOver();
}
