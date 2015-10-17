#ifndef BOLANEGRA_H
#define BOLANEGRA_H

#include <QGraphicsItem>
#include <QBrush>
#include "Poolconstants.h"
#include <QMediaPlayer>
#include <QSound>
#include <QMediaPlaylist>
#include "linked_list.h"
struct QGraphicsScene;

struct BolaNegra : public QGraphicsItem
{
  BolaNegra(QGraphicsItem *parent, QGraphicsScene *scene);

  ///Movimiento de la bola
  void advance(int phase);

  ///Retorna el canvas de la bola
  QRectF boundingRect() const;
  lista<BolaNegra * >  * List_Bola_Negra;

 void setListas( lista<BolaNegra * >  * pList_Bola_Negra);

  void setSpeedX(double pSx);
  void setSpeedY(double pSy);
  double getSpeedX();
  double getSpeedY();
void setPosicion(int pX, int pY);
int getPosx();
int getPosy();
  ///Pinta la bola
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
  void setFuerzaAngule(qreal pAngulo,double pFuerza);
  void CalFuerza();
  void colisionUp();
  void colisionLeft();
  void colisionDown();
  void colisionRight();
  QMediaPlayer * bolasound;
   QMediaPlaylist * playlist;
  private:

  ///Velocidad horizontal (delta x)
  double speed_X;


  ///Velocidada Vertical (delta y)
  double speed_Y;

  ///La escena donde se muestra la bola
  QGraphicsScene * const escena;

  int posX;
  int posY;
  qreal angulo;
  double fuerza;
  double friccion;

};
#endif // BOLANEGRA_H
