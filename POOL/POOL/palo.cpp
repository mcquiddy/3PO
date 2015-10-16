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
    posPaloX=400;
    posPaloY=300;
    this->setPos(posPaloX,posPaloY);
}


void Palo::setPosicion(int pX, int pY, int speed){

   //control 2

     posX=pX-337;
     angulo+=posX/100;
      this->setRotation(angulo);
    // posY=(pY-327);
    hipotenusa= (pY-327)/30;

     //anguloAux=angulo;
    // while(anguloAux>=90){
      //   anguloAux-=90;
     //}

     if(angulo>0 & angulo<90){

     //cout<<(hipotenusa*cos(angulo))<<","<<hipotenusa*sin(anguloAux)<<endl;
     //if(hipotenusa*cos(anguloAux)<0){

     posPaloX+=(hipotenusa*cos(angulo));
     posPaloY+=(hipotenusa*sin(angulo));
     //cout<<hipotenusa*cos(anguloAux)<<","<<hipotenusa*sin(anguloAux)<<endl;
     this->setPos(posPaloX,posPaloY);

     }









    /*
     if (speed!=0 & impulso==false){//guarda la posicion donde se empezo a impulsar el palo
         impulso=true;
        posXImpulso=posPaloX;


     }
     if (speed!=0 & impulso==true){//mientras el boton se mantiene presionado, se realiza el impulso
         posPaloX+=5;
         this->setPos(posPaloX,posPaloY);

     }
     if (speed==0 & impulso==true){//realiza el golpe desde donde se dejo de presionar el boton hasta la posicion inicial
         while(posPaloX >= posXImpulso){
             posPaloX-=8;
         }
         this->setPos(posPaloX-8,posPaloY);

     }



*/

    //control 1 se documenta lo demas





     //cout<<" angulo "<<angulo<<endl;
   /* //Si esta en el segundo cuadrante se le suma 180
    if(posX<0 & posY>0){
        angulo=angulo+180;

    }
    else if(posX<0 & posY<0){
        angulo=angulo-180;
    }

cout<<" despues "<<angulo<<endl;
    this->setRotation(angulo);
*/
}
