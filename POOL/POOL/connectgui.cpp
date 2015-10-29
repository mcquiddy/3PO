#include "connectgui.h"



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

void connectgui::nuevoTiro(int fuerza, int angulo)
{
    pool->bola->nuevoTiro(fuerza,angulo);
}

