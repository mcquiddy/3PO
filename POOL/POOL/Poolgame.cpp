#include "Poolgame.h"
#include <QTimer>
#include <QGraphicsSimpleTextItem>
#include <QFont>
#include <QImage>
#include <QMouseEvent>
#include <iostream>
#include <QDebug>

using namespace std;

Poolgame * Poolgame::unicPool=NULL;
Poolgame::Poolgame(QWidget *parent)
{
    //crear escena del pool
     escena = new QGraphicsScene();
     escena->setSceneRect(WINDOWS_POSX,WINDOWS_POSY,WINDOWS_WIDTH,WINDOWS_HEIGHT);
    setBackgroundBrush(QBrush(QImage(WINDOWS_BACKGROUND_IMAGE)));
     // visualizar la escena
     setScene(escena);
     // Le quita los scrolls
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
     setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(WINDOWS_WIDTH,WINDOWS_HEIGHT);


    // play music de fondo
    QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(QUrl(WINDOWS_BACKGROUND_SOUND));
    music->play();

    //movimiento de las bolas
QTimer * const timer = new QTimer(this);
QObject::connect(timer,SIGNAL(timeout()),escena,SLOT(advance()));
timer->setInterval(20);
timer->start();
 bola= new Bola(escena);
//    bola->newBolaBlanca(150,300);
//    bola->newBolaNegra(1,200,300);
//    bola->newBolaTiro(300,400);




    show();
}

Poolgame *Poolgame::getInstance()
{
    if(unicPool==NULL)
        unicPool=new Poolgame();
    return unicPool;
}


