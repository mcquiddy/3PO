#include "palo.h"
#include <QDebug>
#include <QList>
#include <stdlib.h>// biblioteca para crea un numero random
#include <QGraphicsScene>
#include <QString>
#include <QPainter>
/**
 * @brief Palo::Palo
 * @param *parent
 * Interface del Palo
 */

Palo::Palo(QGraphicsItem *parent, int pPosX, int pPosY, Bola *pBola):QObject(),QGraphicsPixmapItem(parent)
{
    image.load("/home/mcquiddy/git/3PO/POOL/POOL/images/paloPool.png");
    setPixmap(QPixmap::fromImage(image));
//    posPaloX=600;
//    posPaloY=300;
    bola=pBola;
    posPaloX=pPosX;
    posPaloY=pPosY;
    posPaloXIni=pPosX;
    posPaloYIni=pPosY;
    this->setPos(posPaloX,posPaloY);
}

/**
 * @brief Palo::setPosicion
 * @param pX
 * valor obtenido del arduino, representa el cambio en x
 * @param pY
 * valor obtenido del arduino, representa el cambio en y
 */
void Palo::setPosicion(int pX, int pY, int button){

    double cambioX;
    double cambioY;
     posX=pX-338;
     posY=pY-328;

    if((posX)>=10 || posX<=-10){
         cout<<posX<<endl;
         angulo+=posX/100;
         this->setRotation(angulo);
         posPaloX=posPaloXIni-(2*sqrt(97)*cos((3.14/180)*(66.03-(-1*angulo))))+15*cos(((3.14/180)*(angulo)));
         posPaloY=posPaloYIni-(2*sqrt(97)*sin((3.14/180)*(66.03-(-1*angulo))))+15*sin(((3.14/180)*(angulo)));
         this->setPos(posPaloX,posPaloY);
    }

    if((posY)>=10 || posY<=-10){
        hipotenusa=posY/50;
        if (((disparo+hipotenusa/10)<10) & ((disparo+hipotenusa/10)>0.5) ){//rango en el que se puede mover el palo para tomar impulso
             disparo+=hipotenusa/10;
             //cout<<disparo<<endl;
             cambioX=hipotenusa*cos((angulo*PI)/180);//el movimiento del analogo es la hipotenusa,  con el l valor que se obtiene se calcula, el cambio por separado para x y para y
             cambioY=hipotenusa*sin((angulo*PI)/180);

             posPaloX+=(cambioX);
             posPaloY+=(cambioY);
             this->setPos(posPaloX,posPaloY);
        }if(button==0){
            if(angulo<0){
                 cout<<"up "<<angulo<<endl;
                bola->nuevoTiro(disparo,-angulo,false);
            }
            else{
                 cout<<"hola "<<angulo<<endl;
                bola->nuevoTiro(disparo,360-angulo,false);
            }

            this->setPos(posPaloXIni,posPaloYIni);
          }

    }

 }
