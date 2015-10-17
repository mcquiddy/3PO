#ifndef BOLA_H
#define BOLA_H
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <Poolconstants.h>
#include "linked_list.h"
#include <QObject>
#include <iostream>
#include <QThread>
#include "Node.h"
#include "bolablanca.h"
#include "bolanegra.h"
#include "bolatiro.h"
#include <QGraphicsScene>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <QPoint>
using namespace std;
class Bola:public QObject
{
    Q_OBJECT
public:
    Bola(QGraphicsScene *scene);
   void newBolaBlanca(int pX, int pY);
   void newBolaNegra(int pX, int pY);
   void newBolaTiro(int pX, int pY);
   ///Movimiento de la bola

   lista<BolaNegra *> *getBolasNegras();
//   void setPosBolaBlanca(int pX, int pY);
//   void setPosBolaNegra(int pId,int pX, int pY);
//   void setPosBolaTiro(int pX, int pY);
QPoint pos;
QGraphicsScene * const escena;


lista<BolaNegra * >   List_Bola_Negra;
lista<BolaTiro * >   List_Bola_Tiro;
lista<BolaBlanca * >   List_Bola_Blanca;
};

#endif // BOLA_H
