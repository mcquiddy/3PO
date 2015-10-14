#ifndef BOLATIRO_H
#define BOLATIRO_H
#include <QGraphicsItem>
#include <QBrush>
#include "Poolconstants.h"
struct QGraphicsScene;

struct BolaTiro : public QGraphicsItem
{
  BolaTiro(QGraphicsItem *parent, QGraphicsScene *scene);

  ///Movimiento de la bola
  void advance(int phase);

  ///Retorna el canvas de la bola
  QRectF boundingRect() const;


  ///Pinta la bola
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

  private:

  ///Velocidad horizontal (delta x)
  double speed_X;


  ///Velocidada Vertical (delta y)
  double speed_Y;

  ///La escena donde se muestra la bola
  QGraphicsScene * const escena;

};


#endif // BOLATIRO_H
