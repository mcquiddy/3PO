#include "core.h"
#include <QTimer>
#include "connectgui.h"

#include <stdlib.h>// biblioteca para crea un numero random
#include <iostream>
using namespace std;
Core * Core::unicCore=NULL;
Core::Core()
{






}

lista<LogicBolaNegra *> Core::get_list_bolaNegra()
{
    return this->List_Bola_Negra;
}

lista<LogicBolaBlanca *> Core::get_list_bolaBlanca()
{
    return this->List_Bola_Blanca;
}

lista<LogicBolaTiro *> Core::get_list_bolaTiro()
{
    return this->List_Bola_Tiro;
}

Core *Core::getInstance()
{
    if(unicCore==NULL)
        unicCore=new Core();
    return unicCore;
}

void Core::newGame()
{
    connect = new connectgui();
    Aldeanos = new Poblacion(connect);
    this->moveToThread(&workerThread);
       QObject::connect(&workerThread, SIGNAL(started()), Aldeanos, SLOT(newGeneration()));

       workerThread.start();
    //Bolas Negras
    for(int i=0; i<TOTAL_BOLA_NEGRA;i++){
    LogicBolaNegra * negra= new LogicBolaNegra();
    negra->setId(i);
    List_Bola_Negra.insert_head(negra);
    connect->BolaNegra(negra->getPosX(),negra->getPosY());
    }
    //Bola Blanca de Meta
    LogicBolaBlanca * blanca= new LogicBolaBlanca();
    List_Bola_Blanca.insert_head(blanca);
    connect->BolaBlanca(blanca->getPosX(),blanca->getPosY());
    //Bola del jugador
    LogicBolaTiro * tiro= new LogicBolaTiro();
    List_Bola_Tiro.insert_head(tiro);
   connect->BolaTiro(tiro->getPosX(),tiro->getPosY());
   connect->addPalo(tiro->getPosX()+12,tiro->getPosY()+8);
   //connect->nuevoTiro(10,120);

}

void Core::GameOver()
{
 connect->GameOver();
}

