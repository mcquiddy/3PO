#include <cassert>
#include <cmath>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QList>
#include <QPainter>
#include "bolanegra.h"

BolaNegra::BolaNegra(QGraphicsItem *parent, QGraphicsScene *scene): QGraphicsItem(parent),speed_X(8.0), speed_Y(1.0), escena(scene){
  assert(escena && "La inicializacion de una escena deber ser Administrada");
   escena->addItem(this);

}

void BolaNegra::advance(int /* phase */)
{
  //Colision contra los bordes de la escena
  if (x() + speed_X + (boundingRect().width() * 0.5) > BOLA_MAX_X) speed_X = -std::abs(speed_X);
  else if (x() + speed_X - (boundingRect().width() * 0.5) < BOLA_MIN_X) speed_X = std::abs(speed_X);
  if (y() + speed_Y + (boundingRect().height() * 0.5) > BOLA_MAX_Y) speed_Y = -std::abs(speed_Y);
  else if (y() + speed_Y - (boundingRect().width() * 0.5) < BOLA_MIN_X) speed_Y = std::abs(speed_Y);
 // this->setPos(x() + speed_X, y() + speed_Y);

  //Colision con otro item
  const QList<QGraphicsItem *> others = collidingItems();
  if (others.isEmpty()) return;
  const QGraphicsItem * const other = others[0];
  if (this->x() < other->x()) speed_X = -std::abs(speed_X);
  else if (this->x() > other->x()) speed_X =  std::abs(speed_X);
  if (this->y() < other->y()) speed_Y = -std::abs(speed_Y);
  else if (this->y() > other->y()) speed_Y =  std::abs(speed_Y);
  //this->setPos(x() + speed_X, y() + speed_Y);
  //this->setPos(x() + speed_X, y() + speed_Y);

}

QRectF BolaNegra::boundingRect() const{
  return QRectF(BOLA_CORDENADA_X,BOLA_CORDENADA_Y,BOLA_WIDTH,BOLA_HEIGHT);
}

void BolaNegra::paint(QPainter *painter,const QStyleOptionGraphicsItem * ,QWidget *)
{



  QLinearGradient myColor;
  myColor.setColorAt(1,Qt::black);

  QRect dimension;
  dimension.setRect(BOLA_CORDENADA_X,BOLA_CORDENADA_Y,BOLA_WIDTH,BOLA_HEIGHT);

  QPainterPath myForma;
  myForma.addEllipse(dimension);

  painter->setBrush(myColor);
  painter->drawEllipse(dimension);
  painter->setRenderHint(QPainter::Antialiasing,true);


}

