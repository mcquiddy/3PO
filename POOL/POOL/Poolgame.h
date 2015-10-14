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
/**
 * @brief The Game class
 * Esta clase es el manejador de toda la interfaz del juego
 */
class Poolgame :  public QGraphicsView
{
    Q_OBJECT

public:
    Poolgame(QWidget *parent = 0);
    QGraphicsScene *   escena;
    Bola * bola;
    QPoint pos;
    static Poolgame* getInstance();
private:
        static Poolgame* unicPool;

};


#endif // POOLGAME_H
