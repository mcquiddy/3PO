#include "logicbolanegra.h"
#include <stdlib.h>// biblioteca para crea un numero random
#include "iostream"
using namespace std;
LogicBolaNegra::LogicBolaNegra()
{
    id=0;//id de la bola

     //Numero random
    posX=0;
    posY=0;
    posX=(rand() % (BOLA_NEGRA_MAX_X- BOLA_NEGRA_MIN_X)) + BOLA_NEGRA_MIN_X;
    posY=(rand() % (BOLA_NEGRA_MAX_Y-BOLA_NEGRA_MIN_Y)) + BOLA_NEGRA_MIN_Y;



}

void LogicBolaNegra::setId(int pId)
{
    id=pId;

}

int LogicBolaNegra::getId()
{
    return this->id;
}

int LogicBolaNegra::getPosX()
{
    return this->posX;
}

void LogicBolaNegra::setPosX(int pX)
{
    posX=pX;
    cout<<" x "<<posX<<endl;
}

void LogicBolaNegra::setPosY(int pY)
{
            posY=pY;
              cout<<" y "<<posY<<endl;

}

int LogicBolaNegra::getPosY()
{
    return this->posY;
}
