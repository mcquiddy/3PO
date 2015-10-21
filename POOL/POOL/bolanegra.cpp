#include <cassert>
#include <cmath>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QList>
#include <QPainter>
#include "bolanegra.h"
#include <math.h>
//#include <Poolgame.h>
//extern Poolgame * juego;

BolaNegra::BolaNegra(QGraphicsItem *parent, QGraphicsScene *scene, int pX, int pY): QGraphicsItem(parent),speed_X(0.0), speed_Y(0.0), escena(scene){
  assert(escena && "La inicializacion de una escena deber ser Administrada");
  bolasound = new QMediaPlayer();
  posXini=pX;
  posYini=pY;


 playlist =  new QMediaPlaylist();
 playlist->addMedia(QUrl(TIRO_SOUND));
 bolasound->setPlaylist(playlist);
 playlist->setCurrentIndex(-1);

   escena->addItem(this);
   fuerza=0;
   angulo=0;
   friccion=FRICCION;

   posX=pX;
   posY=pY;
   this->setPos(posX,posY);

}

void BolaNegra::advance(int /* phase */)
{
    //Menor fuerza debido ala friccion
        fuerza=fuerza-friccion;

     if(fuerza<=0){
         this->setPosicion(posXini,posYini);
         return;
     }
    //para actualizar los angulos la formula es
      // 4,3 y 2 caudrante= angulo + angulo del cuadrante donde quiere llegar -  angulo cudrante donde esta
      // 1 cuadrante = angulo donde quiere llegar - angulo
      //Colision contra los bordes de la escena
      if (x() + speed_X + (boundingRect().width() * 0.5) > BOLA_MAX_X){


         colisionRight();
          CalFuerza();

      }
      else if (x() + speed_X - (boundingRect().width() * 0.5) < BOLA_MIN_X){



    colisionLeft();
     CalFuerza();
      }
      if (y() + speed_Y + (boundingRect().height() * 0.5) > BOLA_MAX_Y){


    colisionDown();
     CalFuerza();
      }
      else if (y() + speed_Y - (boundingRect().width() * 0.5) < BOLA_MIN_Y) {

           colisionUp();
           CalFuerza();
      }
    this->setPosicion(x() + speed_X, y() + speed_Y);

      //Colision con otro item
      const QList<QGraphicsItem *> others = collidingItems();

      if (others.isEmpty()) return;
      else{
      const QGraphicsItem * const other = others[0];
      lista<BolaNegra *> *bolas = List_Bola_Negra;
      for(int i=1; i<=bolas->length();i++){
//if(((other->x())!= (this->posX ))&( (other->y())!= (this->posY))){
      if(((other->x()) ==(bolas->rove(i)->get_data()->getPosx())) & ((other->y()) ==  (bolas->rove(i)->get_data()->getPosy())) ){

          bolas->rove(i)->get_data()->setFuerzaAngule(angulo,fuerza);
          bolas->rove(i)->get_data()->CalFuerza();
      if (this->x() <= other->x()){

          colisionRight();
           CalFuerza();
      }
      else if (this->x() >= other->x()){

          colisionLeft();
           CalFuerza();
      }
      if (this->y() <= other->y()) {
          colisionDown();
           CalFuerza();
      }
      else if (this->y() >= other->y()){

          colisionUp();
           CalFuerza();
      }
      bolasound->pause();
     bolasound->play();
      break;
     }
    //  }
    }

      this->setPos(x() + speed_X, y() + speed_Y);
     //bolasound->pause();




      }


}

QRectF BolaNegra::boundingRect() const{
    return QRectF(BOLA_CORDENADA_X,BOLA_CORDENADA_Y,BOLA_WIDTH,BOLA_HEIGHT);
}

void BolaNegra::setListas(lista<BolaNegra *> *pList_Bola_Negra)
{
 List_Bola_Negra=pList_Bola_Negra;
}

void BolaNegra::setSpeedX(double pSx)
{
    speed_X=pSx;
}

void BolaNegra::setSpeedY(double pSy)
{
    speed_Y=pSy;
}

double BolaNegra::getSpeedX()
{
    return this->speed_X;
}

double BolaNegra::getSpeedY()
{
    return this->speed_Y;
}

void BolaNegra::setPosicion(int pX, int pY)
{
    posX=pX;
    posY=pY;
    this->setPos(posX,posY);
}

int BolaNegra::getPosx()
{
    return this->posX;
}

int BolaNegra::getPosy()
{
    return this->posY;
}
void BolaNegra::paint(QPainter *painter,const QStyleOptionGraphicsItem * ,QWidget *)
{



  QLinearGradient myColor;
  myColor.setColorAt(1,Qt::black);

  QRect dimension;
  dimension.setRect(BOLA_CORDENADA_X,BOLA_CORDENADA_Y,BOLA_WIDTH,BOLA_HEIGHT);

  QPainterPath myForma;
  myForma.addEllipse(dimension);

  painter->setBrush(myColor);
  painter->drawEllipse(dimension);
  painter->setRenderHint(QPainter::Antialiasing,true);


}

void BolaNegra::setFuerzaAngule(qreal pAngulo, double pFuerza)
{
    fuerza=pFuerza;
    angulo=pAngulo;
}

void BolaNegra::CalFuerza()
{
    speed_X=  cos(angulo* PI / 180.0)*fuerza;
    speed_X=floorf(speed_X * 100) / 100;//Redeondear a dos digitos
    speed_Y= sin(angulo* PI / 180.0)*fuerza;
    speed_Y=floorf(speed_Y * 100) / 100;//Redeondear a dos digitos


 if((angulo<=PRIMER_CUADRANTE) & (angulo>0)){//si esta en el primer cuadrante
    speed_Y=std::abs(speed_Y);
    speed_X=-std::abs(speed_X);
 }
 else if((angulo<=SEGUNDO_CUADRANTE) & (angulo>PRIMER_CUADRANTE)){//si esta en el segundo cuadrante
     speed_Y=std::abs(speed_Y);
     speed_X=std::abs(speed_X);
 }
 else if((angulo<=TERCER_CUADRANTE) & (angulo>SEGUNDO_CUADRANTE)){//si esta en el tercer cuadrante
     speed_Y=-std::abs(speed_Y);
     speed_X=std::abs(speed_X);
 }
 else if((angulo<=CUARTO_CUADRANTE) & (angulo>TERCER_CUADRANTE)){//si esta en el cuarto cuadrante
     speed_Y=-std::abs(speed_Y);
     speed_X=-std::abs(speed_X);
 }
}

void BolaNegra::colisionUp()
{
    if((angulo<=CUARTO_CUADRANTE) & (angulo>TERCER_CUADRANTE)){// viene del cuarto cuadrante
         angulo=angulo+PRIMER_CUADRANTE-CUARTO_CUADRANTE;//primer cuadrante
    }
     else  if((angulo<=TERCER_CUADRANTE) & (angulo>SEGUNDO_CUADRANTE)){// viene del tercer cuadrante
      angulo=angulo+SEGUNDO_CUADRANTE-TERCER_CUADRANTE;//segundo cuadrante
    }
}

void BolaNegra::colisionLeft()
{
    if((angulo<=PRIMER_CUADRANTE) & (angulo>0)){//viene del primer cuadrante
       angulo=SEGUNDO_CUADRANTE-angulo;//segundo cuadrante
     }
     else if((angulo<=CUARTO_CUADRANTE )& (angulo>TERCER_CUADRANTE)){// viene del cuarto cuadrante
         angulo=angulo+TERCER_CUADRANTE-CUARTO_CUADRANTE;//tercer cuadrante
     }
}

void BolaNegra::colisionDown()
{
    if((angulo<=SEGUNDO_CUADRANTE) & (angulo>PRIMER_CUADRANTE)){//viene del segundo cuadrante
         angulo=angulo+TERCER_CUADRANTE-SEGUNDO_CUADRANTE;//tercer cuadrante
    }
     else if((angulo<=PRIMER_CUADRANTE) & (angulo>0)){//viene del primer cuadrante
      angulo=CUARTO_CUADRANTE-angulo;//cuarto cuadrante
    }
}

void BolaNegra::colisionRight()
{
    if((angulo<=SEGUNDO_CUADRANTE) & (angulo>PRIMER_CUADRANTE)){//viene del segundo cuadrante
         angulo=angulo+PRIMER_CUADRANTE-SEGUNDO_CUADRANTE;//primer cuadrante
     }
      else if((angulo<=TERCER_CUADRANTE) & (angulo>SEGUNDO_CUADRANTE)){// viene del tercer cuadrante
       angulo=angulo+CUARTO_CUADRANTE-TERCER_CUADRANTE;//cuarto cuadrante
     }
}
