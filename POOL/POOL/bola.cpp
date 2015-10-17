#include "bola.h"
#include <QTimer>
#include <iostream>
#include <cassert>
#include <cmath>

using namespace std;
Bola::Bola(QGraphicsScene *scene):  escena(scene)
{

}



void Bola::newBolaBlanca(int pX, int pY)
{
     BolaBlanca * blanca= new BolaBlanca(0,escena);

     pos.setX(pX);
     pos.setY(pY);
     blanca->setPos(pos);

     List_Bola_Blanca.insert_head(blanca);
}

void Bola::newBolaNegra( int pX, int pY)
{
    BolaNegra * negra= new BolaNegra(0,escena);

    negra->setPosicion(pX,pY);
    negra->setListas(&List_Bola_Negra);

    List_Bola_Negra.insert_head(negra);
}

void Bola::newBolaTiro(int pX, int pY)
{
    BolaTiro * tiro= new BolaTiro(0,escena);
    pos.setX(pX);
    pos.setY(pY);
    tiro->setPos(pos);
    tiro->setListas(&List_Bola_Negra, &List_Bola_Blanca);

    List_Bola_Tiro.insert_head(tiro);
}



lista<BolaNegra *> *Bola::getBolasNegras()
{
    return &(this->List_Bola_Negra);
}
