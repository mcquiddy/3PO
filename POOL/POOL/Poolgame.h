#ifndef POOLGAME_H
#define POOLGAME_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QMediaPlayer>
#include <QSound>
#include <QMediaPlaylist>
#include <Poolconstants.h>
#include <string.h>
#include <sstream>
#include <QThread>
#include <QObject>
#include <bola.h>
#include <QPoint>
#include "palo.h"
#include <QSerialPort>
#include <QByteArray>
#include <iostream>
/**
 * @brief The Game class
 * Esta clase es el manejador de toda la interfaz del juego
 */
class Poolgame :  public QGraphicsView
{
    Q_OBJECT

public:
    Poolgame(QWidget *parent = 0);
    int x;//eje x del arduino
    int y;//eje y del arduino
    int button;//valor button
    int speed;//fuerza con que se dispara la bola
    QGraphicsScene *   escena;
    Bola * bola;
    Palo *palo;
    QPoint pos;
    static Poolgame* getInstance();
    void GameOver();
    void addPalo(int pPosx,int pPosy);

private slots:
    void readSerial();
    void Analog();


private:

    static Poolgame* unicPool;
    QSerialPort *arduino;
    static const quint16 vendor_id = 9025;
    static const quint16 productId = 66;
    QByteArray serialData;//bytes de datos recibidos por arduino
    QString data;//bytes recibidos del arduino se convierten en qstring



};




#endif // POOLGAME_H
