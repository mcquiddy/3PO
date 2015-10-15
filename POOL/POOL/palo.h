#ifndef PALO_H
#define PALO_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include "linked_list.h"
#include <QString>
#include <QTimer>
#include <Poolconstants.h>
#include <iostream>
#include "qmath.h"
using namespace std;
class Palo: public QObject,public QGraphicsPixmapItem
{

    Q_OBJECT
public:
    Palo(QGraphicsItem * parent=0);
     void setPosicion(int pX,int pY);
private:
    QImage image;
    qreal posX;
    qreal posY;
    qreal angulo;
};

#endif // PALO_H
