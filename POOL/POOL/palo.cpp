#include "palo.h"
#include <QDebug>
#include <QList>
#include <stdlib.h>// biblioteca para crea un numero random
#include <QGraphicsScene>
#include <QString>
#include <QPainter>
Palo::Palo(QGraphicsItem *parent):QObject(),QGraphicsPixmapItem(parent)
{
    image.load(PALO_POOL_IMAGE);

    setPixmap(QPixmap::fromImage(image));
    this->setPos(400,300);
}


void Palo::setPosicion(int pX, int pY)
{
    posY=pY-490;
    posX=pX-505;
    angulo= qAtan2(posY,posX);

    angulo=(angulo*180)/3.14;//Convertir de radianes a grados
    cout<<" angulo "<<angulo<<endl;
    //Si esta en el segundo cuadrante se le suma 180
    if(posX<0 & posY>0){
        angulo=angulo+180;

    }
    else if(posX<0 & posY<0){
        angulo=angulo-180;
    }
cout<<" despues "<<angulo<<endl;
    this->setRotation(angulo);

}
