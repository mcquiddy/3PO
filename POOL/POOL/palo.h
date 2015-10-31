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
#include "bola.h"
using namespace std;
class Palo: public QObject,public QGraphicsPixmapItem
{

    Q_OBJECT
public:
    Palo(QGraphicsItem * parent, int pPosX, int pPosY,Bola * pBola);

     void setPosicion(int pX, int pY, int button);
Bola * bola;

private:
    QImage image;
    qreal posX;
    qreal posY;
    //qreal angulo;
    qreal posPaloX;
    qreal posPaloY;
    qreal posPaloXIni;
    qreal posPaloYIni;
     double rad = 1;
    double a,b;

    qreal angulo;
    qreal hipotenusa;
    qreal disparo=0.5;
    qreal anguloAux;

    qreal posXInicial;
    qreal posYInicial;

};

#endif // PALO_H
