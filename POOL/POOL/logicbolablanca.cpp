#include "logicbolablanca.h"
#include <stdlib.h>// biblioteca para crea un numero random

LogicBolaBlanca::LogicBolaBlanca()
{
    //Numero random
    rangeNumberX=0;
    rangeNumberY=0;
    srand((unsigned)time(0));
    rangeNumberX = (rand() % (BOLA_BLANCA_MAX_X-BOLA_BLANCA_MIN_X)) + BOLA_BLANCA_MIN_X;
    rangeNumberY = (rand() % (BOLA_BLANCA_MAX_Y-BOLA_BLANCA_MIN_Y)) + BOLA_BLANCA_MIN_Y;

}

int LogicBolaBlanca::getPosX()
{
    return this->rangeNumberX;

}

int LogicBolaBlanca::getPosY()
{
   return this->rangeNumberY;
}
