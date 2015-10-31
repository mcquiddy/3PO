#ifndef BOLATIRO_H
#define BOLATIRO_H
#include <QGraphicsItem>
#include <QBrush>
#include "Poolconstants.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "linked_list.h"
#include "bolanegra.h"
#include "bolablanca.h"
#include "qmath.h"
#include <QMediaPlayer>
#include <QSound>
#include <QMediaPlaylist>
#include "connectlogic.h"

using namespace std;

struct QGraphicsScene;

struct BolaTiro :public QGraphicsItem

{


  BolaTiro(QGraphicsItem *parent, QGraphicsScene *scene,int pX, int pY);
  lista<BolaNegra * >  * List_Bola_Negra;
  lista<BolaBlanca * > *  List_Bola_Blanca;
  ///Movimiento de la bola
  void advance(int phase);

  ///Retorna el canvas de la bola
  QRectF boundingRect() const;
 void setListas( lista<BolaNegra * >  * pList_Bola_Negra,lista<BolaBlanca * > *  pList_Bola_Blanca);
  void setSpeedX(double pSx);
  void setSpeedY(double pSy);
  double getSpeedX();
  double getSpeedY();
  void setPosicion(int pX, int pY);
  int getPosx();
  int getPosy();
  ///Pinta la bola
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
  void CalFuerza();
  void setFuerzaAngule(qreal pAngulo, int pFuerza);
  void colisionUp();
  void colisionLeft();
  void colisionDown();
  void colisionRight();
  QMediaPlayer * bolasound;
  QMediaPlaylist * playlist;
  connectLogic *  facade;
  private:

  ///Velocidad horizontal (delta x)
  double speed_X;


  ///Velocidada Vertical (delta y)
  double speed_Y;

  ///La escena donde se muestra la bola
  QGraphicsScene * const escena;
  int posX;
  int posY;
  int posXini;
  int posYini;
  bool flagNewTiro;
////Calcular los movimiento y las fuerzas

  qreal angulo;
  double fuerza;
  double friccion;

};


#endif // BOLATIRO_H
