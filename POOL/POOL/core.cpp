#include "core.h"
#include <QTimer>

#include <stdlib.h>// biblioteca para crea un numero random
#include <iostream>
using namespace std;
Core::Core()
{
    connect = new connectgui();
    Aldeanos = new Poblacion(connect);

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
   //connect->nuevoTiro(10,120);

   this->moveToThread(&workerThread);
      QObject::connect(&workerThread, SIGNAL(started()), Aldeanos, SLOT(newGeneration()));
                   workerThread.start();





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
