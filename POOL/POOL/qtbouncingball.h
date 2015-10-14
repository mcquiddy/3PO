#ifndef QTBOUNCINGBALL_H
#define QTBOUNCINGBALL_H

#include <QGraphicsItem>
#include <QBrush>

struct QGraphicsScene;

struct QtBouncingRect : public QGraphicsItem
{
  QtBouncingRect(QGraphicsItem *parent, QGraphicsScene *scene);

  ///Make the balls move
  void advance(int phase);

  ///Thanks compiler for reminding me to add this method!
  QRectF boundingRect() const;


  ///Thanks compiler for reminding me to add this method!
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

  private:
  ///Use simplified physics in this example
  ///Horizontal speed (delta x)
  double speed_X;

  ///Use simplified physics in this example
  ///Vertical speed (delta y)
  double speed_Y;

  ///The scene this class is in
  QGraphicsScene * const escena;
   //QPainterPath p;
};

#endif // QTBOUNCINGBALL_H
