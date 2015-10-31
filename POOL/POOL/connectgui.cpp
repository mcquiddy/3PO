#include "connectgui.h"
#include <Poolgame.h>
//extern Poolgame * pool;

connectgui::connectgui()
{
}

void connectgui::BolaBlanca(int pX, int pY)
{
    pool->bola->newBolaBlanca(pX,pY);
}

void connectgui::BolaNegra( int pX, int pY)
{
    pool->bola->newBolaNegra(pX,pY);
}

void connectgui::BolaTiro(int pX, int pY)
{
    pool->bola->newBolaTiro(pX,pY);
}

void connectgui::nuevoTiro(int fuerza, int angulo, bool pTiro)
{
    pool->bola->nuevoTiro(fuerza,angulo,pTiro);
}

void connectgui::GameOver()
{
    pool->GameOver();
}

void connectgui::addPalo(int pPosx, int pPosy)
{
    pool->addPalo(pPosx,pPosy);
}

