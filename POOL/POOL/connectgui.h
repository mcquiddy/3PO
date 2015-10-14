#ifndef CONNECTGUI_H
#define CONNECTGUI_H
#include <iostream>
#include <QObject>
#include <Poolgame.h>
#include <string>
#include <cstdio>
#include <cstdlib>
using namespace std;
class connectgui
{

protected:
    Poolgame* pool=Poolgame::getInstance();
public:
    connectgui();

public slots:
    void BolaBlanca(int pX, int pY);
    void BolaNegra(int pId, int pX, int pY);
    void BolaTiro(int pX, int pY);
//    void setPosBolaBlanca(int pX, int pY);
//    void setPosBolaNegra(int pId,int pX, int pY);
//    void setPosBolaTiro(int pX, int pY);


};

#endif // CONNECTGUI_H
