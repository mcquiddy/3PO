#include "core.h"
#include <QTimer>

#include <stdlib.h>// biblioteca para crea un numero random
#include <iostream>
using namespace std;
Core::Core()
{
    connect = new connectgui();
    //Bolas Negras
    for(int i=0; i<TOTAL_BOLA_NEGRA;i++){
    LogicBolaNegra * negra= new LogicBolaNegra();
    negra->setId(i);
    List_Bola_Negra.insert_head(negra);
    connect->BolaNegra(negra->getId(),negra->getPosX(),negra->getPosY());
    }
    //Bola Blanca de Meta
    LogicBolaBlanca * blanca= new LogicBolaBlanca();
    List_Bola_Blanca.insert_head(blanca);
    connect->BolaBlanca(blanca->getPosX(),blanca->getPosY());
    //Bola del jugador
    LogicBolaTiro * tiro= new LogicBolaTiro();
    List_Bola_Tiro.insert_head(tiro);
    connect->BolaTiro(tiro->getPosX(),tiro->getPosY());



}
