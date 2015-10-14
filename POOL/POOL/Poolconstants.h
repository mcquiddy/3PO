#ifndef POOLCONSTANTS_H
#define POOLCONSTANTS_H
#include <QString>
#include <QGraphicsItem>
/**
  Variables constantes que se utiliza en toda la interfaz
  */
//***********************GAME******************
const int WINDOWS_WIDTH=800;
const int WINDOWS_HEIGHT=600;
const int WINDOWS_POSX=0;
const int WINDOWS_POSY=0;

const float BOLA_WIDTH=20.0;
const float BOLA_HEIGHT=20.0;
const float BOLA_CORDENADA_X=0;
const float BOLA_CORDENADA_Y=0;

const int BOLA_BLANCA_MIN_X=250;
const int BOLA_BLANCA_MIN_Y=125;
const int BOLA_NEGRA_MIN_X=250;
const int BOLA_NEGRA_MIN_Y=125;
const int BOLA_TIRO_MIN_X=125;
const int BOLA_TIRO_MIN_Y=125;

const int BOLA_BLANCA_MAX_X=675;
const int BOLA_BLANCA_MAX_Y=475;
const int BOLA_NEGRA_MAX_X=675;
const int BOLA_NEGRA_MAX_Y=475;
const int BOLA_TIRO_MAX_X=205;
const int BOLA_TIRO_MAX_Y=475;


const int BOLA_MAX_X=695;
const int BOLA_MIN_X=105;
const int BOLA_MAX_Y=495;
const int BOLA_MIN_Y=100;

const int TOTAL_BOLA_NEGRA=10;
const QString WINDOWS_BACKGROUND_IMAGE=":/images/images/pool.png";
const QString BOLA_BLANCA_IMAGE=":/images/images/bola_blanca.png";
const QString BOLA_NEGRA_IMAGE=":/images/images/bola_negra.png";
const QString BOLA_TIRO_IMAGE=":/images/images/bola_tiro.png";
const QString WINDOWS_BACKGROUND_SOUND="qrc:/images/BgSound.mp3";
#endif // POOLCONSTANTS_H
