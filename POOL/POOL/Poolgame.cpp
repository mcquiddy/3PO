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
   // music->setMedia(QUrl(TIRO_SOUND));
    music->play();
    bola= new Bola(escena);
    palo=new Palo();
    escena->addItem(palo);
    //movimiento de las bolas
QTimer * const timer = new QTimer(this);
QObject::connect(timer,SIGNAL(timeout()),escena,SLOT(advance()));
timer->setInterval(20);
timer->start();

//    bola->newBolaBlanca(150,300);
//    bola->newBolaNegra(1,200,300);
//    bola->newBolaTiro(300,400);
    show();
   // Analog();
}

Poolgame *Poolgame::getInstance()
{
    if(unicPool==NULL)
        unicPool=new Poolgame();
    return unicPool;
}

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
            speed=std::atoi(lista.takeAt(0).toStdString().c_str());
            if(((x>=0) & (x<=700)) & ((y>=0) & (y<=700))){
                //cout<<x<<","<<y<<","<<speed<<endl;

                data="";
                palo->setPosicion(x,y);
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

void Poolgame::Analog()
{
    arduino = new QSerialPort(this);
    data = "";


    /*
     *   identifica que el arduino este conectado
     */
    bool arduino_is_available = false;
    QString arduino_uno_port_name;
    //
    //  For each available serial port
    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
        //  check if the serialport has both a product identifier and a vendor identifier
        if(serialPortInfo.hasProductIdentifier() && serialPortInfo.hasVendorIdentifier()){
            //  check if the product ID and the vendor ID match those of the arduino uno
            if((serialPortInfo.productIdentifier() == arduino_uno_product_id)
                    && (serialPortInfo.vendorIdentifier() == arduino_uno_vendor_id)){
                arduino_is_available = true; //    arduino uno is available on this port
                arduino_uno_port_name = serialPortInfo.portName();
            }
        }
    }

    /*
     *  Open and configure the arduino port if available
     */
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


    }else{
        qDebug() << "Couldn't find the correct port for the arduino.\n";
        QMessageBox::information(this, "Serial Port Error", "Couldn't open serial port to arduino.");
    }
}


