#include "logicbolatiro.h"
#include <stdlib.h>// biblioteca para crea un numero random

LogicBolaTiro::LogicBolaTiro()
{
    //Numero random
    rangeNumberX=0;
    rangeNumberY=0;
    srand((unsigned)time(0));
    rangeNumberX = (rand() % (BOLA_TIRO_MAX_X-BOLA_TIRO_MIN_X)) + BOLA_TIRO_MIN_X;
    rangeNumberY = (rand() % (BOLA_TIRO_MAX_Y-BOLA_TIRO_MIN_Y)) + BOLA_TIRO_MIN_Y;

}

int LogicBolaTiro::getPosX()
{
    return this->rangeNumberX;
}

int LogicBolaTiro::getPosY()
{
  return this->rangeNumberY;
}
