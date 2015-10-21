#include <cassert>
#include <cmath>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QList>
#include <QPainter>
#include "bolablanca.h"

BolaBlanca::BolaBlanca(QGraphicsItem *parent, QGraphicsScene *scene, int pX, int pY): QGraphicsItem(parent),speed_X(0.0), speed_Y(0.0), escena(scene){
  assert(escena && "La inicializacion de una escena deber ser Administrada");
   escena->addItem(this);
   posXini=pX;
   posYini=pY;

   bolasound = new QMediaPlayer();

  playlist = new QMediaPlaylist();



  posX=pX;
  posY=pY;
  this->setPos(posX,posY);


}

void BolaBlanca::advance(int /* phase */)
{


}

QRectF BolaBlanca::boundingRect() const{
  return QRectF(BOLA_CORDENADA_X,BOLA_CORDENADA_Y,BOLA_WIDTH,BOLA_HEIGHT);
}

void BolaBlanca::setSpeedX(double pSx)
{
    speed_X=pSx;
}

void BolaBlanca::setSpeedY(double pSy)
{
    speed_Y=pSy;
}

double BolaBlanca::getSpeedX()
{
    return this->speed_X;
}

double BolaBlanca::getSpeedY()
{
 return this->speed_Y;
}

void BolaBlanca::setPosicion(int pX, int pY)
{
    posX=pX;
    posY=pY;
    this->setPos(posX,posY);
}

int BolaBlanca::getPosx()
{
    return this->posX;
}

int BolaBlanca::getPosy()
{
    return this->posY;
}
void BolaBlanca::paint(QPainter *painter,const QStyleOptionGraphicsItem * ,QWidget *)
{



  QLinearGradient myColor;
  myColor.setColorAt(1,Qt::white);

  QRect dimension;
  dimension.setRect(BOLA_CORDENADA_X,BOLA_CORDENADA_Y,BOLA_WIDTH,BOLA_HEIGHT);

  QPainterPath myForma;
  myForma.addEllipse(dimension);

  painter->setBrush(myColor);
  painter->drawEllipse(dimension);
  painter->setRenderHint(QPainter::Antialiasing,true);


}

