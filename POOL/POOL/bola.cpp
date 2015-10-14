#include "bola.h"
#include <QTimer>
#include <iostream>


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
     escena->addItem(blanca);
     List_Bola_Blanca.insert_head(blanca);
}

void Bola::newBolaNegra(int pId, int pX, int pY)
{
    BolaNegra * negra= new BolaNegra(0,escena);
    pos.setX(pX);
    pos.setY(pY);
    negra->setPos(pos);
    escena->addItem(negra);
    List_Bola_Negra.insert_head(negra);
}

void Bola::newBolaTiro(int pX, int pY)
{
    BolaTiro * tiro= new BolaTiro(0,escena);
    pos.setX(pX);
    pos.setY(pY);
    tiro->setPos(pos);
    escena->addItem(tiro);
    List_Bola_Tiro.insert_head(tiro);
}
