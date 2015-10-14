#include <cassert>
#include <cmath>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QList>
#include <QPainter>
#include "qtbouncingball.h"

QtBouncingRect::QtBouncingRect(QGraphicsItem *parent, QGraphicsScene *scene): QGraphicsItem(parent),speed_X(8.0), speed_Y(1.0), escena(scene){
  assert(escena && "La inicializacion de una escena deber ser Administrada");
   escena->addItem(this);

}

void QtBouncingRect::advance(int /* phase */)
{
  //Colision contra los bordes de la escena
  if (x() + speed_X + (boundingRect().width() * 0.5) > escena->width()) speed_X = -std::abs(speed_X);
  else if (x() + speed_X - (boundingRect().width() * 0.5) < 0.0) speed_X = std::abs(speed_X);
  if (y() + speed_Y + (boundingRect().height() * 0.5) > escena->height()) speed_Y = -std::abs(speed_Y);
  else if (y() + speed_Y - (boundingRect().width() * 0.5) < 0.0) speed_Y = std::abs(speed_Y);
  this->setPos(x() + speed_X, y() + speed_Y);

  //Colision con otro item
  const QList<QGraphicsItem *> others = collidingItems();
  if (others.isEmpty()) return;
  const QGraphicsItem * const other = others[0];
  if (this->x() < other->x()) speed_X = -std::abs(speed_X);
  else if (this->x() > other->x()) speed_X =  std::abs(speed_X);
  if (this->y() < other->y()) speed_Y = -std::abs(speed_Y);
  else if (this->y() > other->y()) speed_Y =  std::abs(speed_Y);
  this->setPos(x() + speed_X, y() + speed_Y);
  this->setPos(x() + speed_X, y() + speed_Y);

}

QRectF QtBouncingRect::boundingRect() const{
  return QRectF(-16.0,-16.0,32.0,32.0);
}

void QtBouncingRect::paint(QPainter *painter,const QStyleOptionGraphicsItem * ,QWidget *)
{



  QLinearGradient myColor;
  myColor.setColorAt(1,Qt::white);

  QRect dimension;
  dimension.setRect(-16.0,-16.0,32.0,32.0);

  QPainterPath myForma;
  myForma.addEllipse(dimension);

  painter->setBrush(myColor);
  painter->drawEllipse(dimension);
  painter->setRenderHint(QPainter::Antialiasing,true);


}

