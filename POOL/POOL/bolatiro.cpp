#include "bolatiro.h"
#include <cassert>
#include <cmath>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QList>
#include <QPainter>
#include <math.h>

#include <QMessageBox>



BolaTiro::BolaTiro(QGraphicsItem *parent, QGraphicsScene *scene, int pX, int pY): QGraphicsItem(parent), escena(scene){
  assert(escena && "La inicializacion de una escena deber ser Administrada");
  bolasound = new QMediaPlayer();
  posXini=pX;
  posYini=pY;
flagNewTiro=false;
  facade=new connectLogic();


// bolasound->setMedia(QUrl(TIRO_SOUND));
   escena->addItem(this);

   friccion=FRICCION;

  fuerza=0;
  angulo=0;
   CalFuerza();
   playlist =  new QMediaPlaylist();
   playlist->addMedia(QUrl(TIRO_SOUND));
   bolasound->setPlaylist(playlist);
   playlist->setCurrentIndex(-1);

   posX=pX;
   posY=pY;
   this->setPos(posX,posY);

cout<<"primero "<<endl;
}

void BolaTiro::advance(int /* phase */)
{

//Menor fuerza debido ala friccion
    fuerza=fuerza-friccion;


 if(fuerza<=0){


     if(flagNewTiro){


         double pX=(List_Bola_Blanca->get_head()->get_data()->getPosx() )-this->x();
         double pY=(List_Bola_Blanca->get_head()->get_data()->getPosy() )-this->y();

         double sumaCuadrados=pow(pX,2)+pow(pY,2);

         int distancia=sqrt(sumaCuadrados);
         flagNewTiro=false;
         facade->setDistancia(distancia);
     }
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

 this->setPos(x() + speed_X, y() + speed_Y);
//cout<<"disminuyo"<<x()<<" "<<y()<<" speed_x "<<speed_X<<" speed_y "<<speed_Y<<endl;
  //Colision con otro item
  const QList<QGraphicsItem *> others = collidingItems();

  if (others.isEmpty()) return;
  else{
  const QGraphicsItem * const other = others[0];
  lista<BolaNegra *> *bolas = List_Bola_Negra;
   Node<BolaBlanca *> *blanca = List_Bola_Blanca->get_head();
  for(int i=1; i<=bolas->length();i++){
      if(((other->x()) ==(blanca->get_data()->getPosx())) & ((other->y()) ==  (blanca->get_data()->getPosy())) ){


       flagNewTiro=false;
       this->setPosicion(posXini,posYini);
       return;
      // facade->GameOver();

      }
   else{
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
  }
}

  this->setPos(x() + speed_X, y() + speed_Y);
 //bolasound->pause();
return;



  }

}

QRectF BolaTiro::boundingRect() const{
    return QRectF(BOLA_CORDENADA_X,BOLA_CORDENADA_Y,BOLA_WIDTH,BOLA_HEIGHT);
}

void BolaTiro::setListas(lista<BolaNegra *> *pList_Bola_Negra, lista<BolaBlanca *> *pList_Bola_Blanca)
{
    List_Bola_Blanca=pList_Bola_Blanca;
    List_Bola_Negra=pList_Bola_Negra;
}

void BolaTiro::setSpeedX(double pSx)
{
    speed_X=pSx;
}

void BolaTiro::setSpeedY(double pSy)
{
    speed_Y=pSy;
}

double BolaTiro::getSpeedX()
{
    return this->speed_X;
}

double BolaTiro::getSpeedY()
{
 return this->speed_Y;
}

void BolaTiro::setPosicion(int pX, int pY)
{
    posX=pX;
    posY=pY;
    this->setPos(posX,posY);
}

int BolaTiro::getPosx()
{
    return this->posX;
}

int BolaTiro::getPosy()
{
    return this->posY;
}
void BolaTiro::paint(QPainter *painter,const QStyleOptionGraphicsItem * ,QWidget *)
{



  QLinearGradient myColor;
  myColor.setColorAt(1,Qt::red);

  QRect dimension;
  dimension.setRect(BOLA_CORDENADA_X,BOLA_CORDENADA_Y,BOLA_WIDTH,BOLA_HEIGHT);

  QPainterPath myForma;
  myForma.addEllipse(dimension);

  painter->setBrush(myColor);
  painter->drawEllipse(dimension);
  painter->setRenderHint(QPainter::Antialiasing,true);


}

void BolaTiro::CalFuerza()
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

void BolaTiro::setFuerzaAngule(qreal pAngulo, int pFuerza, bool pTiro)
{
    this->fuerza=(double)pFuerza;
    this->angulo=pAngulo;
    this->flagNewTiro=pTiro;
     CalFuerza();

    //cout<<" fuerza seteada "<<this->fuerza<<endl;
}

void BolaTiro::colisionUp()
{
    if((angulo<=CUARTO_CUADRANTE) & (angulo>TERCER_CUADRANTE)){// viene del cuarto cuadrante
         angulo=angulo+PRIMER_CUADRANTE-CUARTO_CUADRANTE;//primer cuadrante
    }
     else  if((angulo<=TERCER_CUADRANTE) & (angulo>SEGUNDO_CUADRANTE)){// viene del tercer cuadrante
      angulo=angulo+SEGUNDO_CUADRANTE-TERCER_CUADRANTE;//segundo cuadrante
    }
}

void BolaTiro::colisionLeft()
{
    if((angulo<=PRIMER_CUADRANTE) & (angulo>0)){//viene del primer cuadrante
       angulo=SEGUNDO_CUADRANTE-angulo;//segundo cuadrante
     }
     else if((angulo<=CUARTO_CUADRANTE )& (angulo>TERCER_CUADRANTE)){// viene del cuarto cuadrante
         angulo=angulo+TERCER_CUADRANTE-CUARTO_CUADRANTE;//tercer cuadrante
     }
}

void BolaTiro::colisionDown()
{
    if((angulo<=SEGUNDO_CUADRANTE) & (angulo>PRIMER_CUADRANTE)){//viene del segundo cuadrante
         angulo=angulo+TERCER_CUADRANTE-SEGUNDO_CUADRANTE;//tercer cuadrante
    }
     else if((angulo<=PRIMER_CUADRANTE) & (angulo>0)){//viene del primer cuadrante
      angulo=CUARTO_CUADRANTE-angulo;//cuarto cuadrante
    }
}

void BolaTiro::colisionRight()
{
    if((angulo<=SEGUNDO_CUADRANTE) & (angulo>PRIMER_CUADRANTE)){//viene del segundo cuadrante
         angulo=angulo+PRIMER_CUADRANTE-SEGUNDO_CUADRANTE;//primer cuadrante
     }
      else if((angulo<=TERCER_CUADRANTE) & (angulo>SEGUNDO_CUADRANTE)){// viene del tercer cuadrante
       angulo=angulo+CUARTO_CUADRANTE-TERCER_CUADRANTE;//cuarto cuadrante
     }
}

