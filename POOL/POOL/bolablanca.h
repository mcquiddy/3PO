#ifndef BOLABLANCA_H
#define BOLABLANCA_H


#include <QGraphicsItem>
#include <QBrush>
#include "Poolconstants.h"
#include <QMediaPlayer>
#include <QSound>
#include <QMediaPlaylist>
struct QGraphicsScene;

struct BolaBlanca : public QGraphicsItem
{
  BolaBlanca(QGraphicsItem *parent, QGraphicsScene *scene);

  ///Movimiento de la bola
  void advance(int phase);

  void setSpeedX(double pSx);
  void setSpeedY(double pSy);
  double getSpeedX();
  double getSpeedY();

  void setPosicion(int pX, int pY);
  int getPosx();
  int getPosy();
  ///Retorna el canvas de la bola
  QRectF boundingRect() const;


  ///Pinta la bola
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
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
};




#endif // BOLABLANCA_H
