#include "connectgui.h"



connectgui::connectgui()
{
}

void connectgui::BolaBlanca(int pX, int pY)
{
    pool->bola->newBolaBlanca(pX,pY);
}

void connectgui::BolaNegra(int pId, int pX, int pY)
{
    pool->bola->newBolaNegra(pId,pX,pY);
}

void connectgui::BolaTiro(int pX, int pY)
{
    pool->bola->newBolaTiro(pX,pY);
}

