#include "palo.h"
#include <QDebug>
#include <QList>
#include <stdlib.h>// biblioteca para crea un numero random
#include <QGraphicsScene>
#include <QString>
#include <QPainter>
Palo::Palo(QGraphicsItem *parent):QObject(),QGraphicsPixmapItem(parent)
{
    image.load("/home/geovanny/git/3PO/POOL/POOL/images/paloPool.png");

    setPixmap(QPixmap::fromImage(image));
    posPaloX=300;
    posPaloY=400;
    this->setPos(posPaloX,posPaloY);
}


void Palo::setPosicion(int pX, int pY, int speed){
    double cambioX;
    double cambioY;

     posX=pX-337;
     posY=pY-327;
    if((posX)>=1.5  || posX<=-1.5){
     angulo+=posX/100;
     this->setRotation(angulo);

    }

 if((posY)>=1.5  || posY<=-1.5){



    hipotenusa=posY/50;

        if ( (disparo+hipotenusa/10)<10 & (disparo+hipotenusa/10)>0 ){
        disparo+=hipotenusa/10;

         cout<<disparo<<endl;
        cambioX=hipotenusa*cos((angulo*PI)/180);
        cambioY=hipotenusa*sin((angulo*PI)/180);
             cout<<"a"<<endl;

             posPaloX+=(cambioX);
             posPaloY+=(cambioY);
}
          this->setPos(posPaloX,posPaloY);
    }




 }






