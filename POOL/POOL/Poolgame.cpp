#include "Poolgame.h"
#include <QTimer>
#include <QGraphicsSimpleTextItem>
#include <QFont>
#include <QImage>
#include <QMouseEvent>
#include <iostream>
#include <QDebug>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <string>
#include <QMessageBox>

using namespace std;

Poolgame * Poolgame::unicPool=NULL;

Poolgame::Poolgame(QWidget *parent){

     escena = new QGraphicsScene();///crear escena del pool
     escena->setSceneRect(WINDOWS_POSX,WINDOWS_POSY,WINDOWS_WIDTH,WINDOWS_HEIGHT);
     setBackgroundBrush(QBrush(QImage(WINDOWS_BACKGROUND_IMAGE)));
     setScene(escena);/// visualizar la escena
     setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); /// Le quita los scrolls
     setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
     setFixedSize(WINDOWS_WIDTH,WINDOWS_HEIGHT);

     QMediaPlayer * music = new QMediaPlayer();/// play music de fondo
     music->setMedia(QUrl(WINDOWS_BACKGROUND_SOUND));
   // music->setMedia(QUrl(TIRO_SOUND));
     music->play();

     bola= new Bola(escena);


    ///movimiento de las bolas
     QTimer * const timer = new QTimer(this);
     QObject::connect(timer,SIGNAL(timeout()),escena,SLOT(advance()));
     timer->setInterval(20);
     timer->start();
     escena->addEllipse(298,400 , 2, 2,  QPen(), QBrush(Qt::SolidPattern));

//    bola->newBolaBlanca(150,300);
//    bola->newBolaNegra(1,200,300);
//    bola->newBolaTiro(300,400);
    Analog();
    show();

}
/**
 * @brief Poolgame::getInstance
 *
 * @return
 */
Poolgame *Poolgame::getInstance()
{
    if(unicPool==NULL)
        unicPool=new Poolgame();
    return unicPool;
}

void Poolgame::GameOver()
{
    QMessageBox::information(this, "FINALIZADO!","La Bola Roja a Chocado con la Bola Blanca");
}

void Poolgame::addPalo(int pPosx, int pPosy)
{
    palo=new Palo(0,pPosx,pPosy,bola);
    escena->addItem(palo);
}

/**
 * @brief Poolgame::readSerial
 * Lee los datos que envia el arduino, espera a obtener suficientes
 * para sacar el movimiento del eje x,y y del boton
 */
void Poolgame::readSerial()
{

    serialData = arduino->readAll();
    data = data + QString::fromStdString(serialData.data());
    serialData.clear();
    QStringList lista = data.split("/");
    if(lista.length()>=3){
       // lista= data.split("/");
        data=lista.takeAt(1);
        lista=data.split("*");
        if(lista.length()==3){
            x=std::atoi(lista.takeAt(0).toStdString().c_str());
            y=std::atoi(lista.takeAt(0).toStdString().c_str());
            button=std::atoi(lista.takeAt(0).toStdString().c_str());
            if(((x>=0) & (x<=700)) & ((y>=0) & (y<=700))){
                //cout<<x<<","<<y<<","<<speed<<endl;
                data="";
                palo->setPosicion(x,y,button);
            }
            else{
               cout<< "datos invalidos"<<endl;
            }
        }
        else{
            data="";
            cout<<"se corrige error al inicio"<<endl;
        }

    }

}

/**
 * @brief Poolgame::Analog
 * inicia la conexion y se encarga de establecerla o
 * indicar en caso que haya un error, mantiene un hilo
 * que recibe los datos,
 */
void Poolgame::Analog(){
    arduino = new QSerialPort(this);
    data = "";

    /**
     *   identifica que el arduino este conectado
     */
    bool arduino_is_available = false;
    QString arduino_uno_port_name;

    /// Para cada puerto serial disponible
    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
        ///revisa que el puerto serial tengo los puertos vendor_id y porductId
        if(serialPortInfo.hasProductIdentifier() && serialPortInfo.hasVendorIdentifier()){
            ///revisa que productId y vendor_id coincide con arduino uno
            if((serialPortInfo.productIdentifier() == productId)
                && (serialPortInfo.vendorIdentifier() == vendor_id)){
                ///arduino uno esta disponible en este puerto
                arduino_is_available = true;
                arduino_uno_port_name = serialPortInfo.portName();
                }
        }
    }
    if(arduino_is_available){
        qDebug() << "Found the arduino port...\n";
        arduino->setPortName(arduino_uno_port_name);
        arduino->open(QSerialPort::ReadOnly);
        arduino->setBaudRate(QSerialPort::Baud9600);
        arduino->setDataBits(QSerialPort::Data8);
        arduino->setFlowControl(QSerialPort::NoFlowControl);
        arduino->setParity(QSerialPort::NoParity);
        arduino->setStopBits(QSerialPort::OneStop);
        QObject::connect(arduino, SIGNAL(readyRead()), this, SLOT(readSerial()));
    }
    else{
        qDebug() << "no se pudo encontrar el puerto de Arduino.\n";
        QMessageBox::information(this, "Error en puerto Serial", "No se puede abrir el puerto serial de arduino.");
    }
}


