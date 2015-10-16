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
     escena->addItem(blanca);
     List_Bola_Blanca.insert_head(blanca);
}

void Bola::newBolaNegra(int pId, int pX, int pY)
{
    BolaNegra * negra= new BolaNegra(0,escena);

    negra->setPosicion(pX,pY);
    escena->addItem(negra);
    List_Bola_Negra.insert_head(negra);
}

void Bola::newBolaTiro(int pX, int pY)
{
    BolaTiro * tiro= new BolaTiro(0,escena);
    pos.setX(pX);
    pos.setY(pY);
    tiro->setPos(pos);
    tiro->setListas(&List_Bola_Negra, &List_Bola_Blanca);
    escena->addItem(tiro);
    List_Bola_Tiro.insert_head(tiro);
}

void Bola::advance(int /* phase */)
{

   if (List_Bola_Negra.get_head()==NULL) return;
   else{
   for(int i=1; i<List_Bola_Negra.length();i++){
   if (List_Bola_Tiro.get_head()->get_data()->getPosx() < List_Bola_Negra.rove(i)->get_data()->getPosx()) {
       List_Bola_Tiro.get_head()->get_data()->setSpeedX(-std::abs(List_Bola_Tiro.get_head()->get_data()->getSpeedX()));

   }
   else if (List_Bola_Tiro.get_head()->get_data()->getPosx() >  List_Bola_Negra.rove(i)->get_data()->getPosx()){
 List_Bola_Tiro.get_head()->get_data()->setSpeedX(std::abs(List_Bola_Tiro.get_head()->get_data()->getSpeedX()));

   }
   if (List_Bola_Tiro.get_head()->get_data()->getPosy() <  List_Bola_Negra.rove(i)->get_data()->getPosy()){
 List_Bola_Tiro.get_head()->get_data()->setSpeedY(-std::abs(List_Bola_Tiro.get_head()->get_data()->getSpeedY()));

   }
   else if (List_Bola_Tiro.get_head()->get_data()->getPosy() >  List_Bola_Negra.rove(i)->get_data()->getPosy()){

       List_Bola_Tiro.get_head()->get_data()->setSpeedY(std::abs(List_Bola_Tiro.get_head()->get_data()->getSpeedY()));

   }
   List_Bola_Tiro.get_head()->get_data()->setPosicion( List_Bola_Tiro.get_head()->get_data()->getPosx()+ List_Bola_Tiro.get_head()->get_data()->getSpeedX(), List_Bola_Tiro.get_head()->get_data()->getPosy()+ List_Bola_Tiro.get_head()->get_data()->getSpeedY());
   //this->setPos(x() + speed_X, y() + speed_Y);

   }
   }
}

lista<BolaNegra *> *Bola::getBolasNegras()
{
    return &(this->List_Bola_Negra);
}
