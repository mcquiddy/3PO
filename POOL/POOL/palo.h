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
     void setPosicion(int pX, int pY, int speed);
private:
    QImage image;
    qreal posX;
    qreal posY;
    qreal angulo;
    qreal posPaloX;
    qreal posPaloY;


    qreal hipotenusa;
    qreal anguloAux;
    bool impulso=false;
    qreal posXImpulso;
    qreal aux;
};

#endif // PALO_H
