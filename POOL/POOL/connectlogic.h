#ifndef CONNECTLOGIC_H
#define CONNECTLOGIC_H

#include <iostream>
#include <QObject>
#include <string>
#include <cstdio>
#include <cstdlib>

class Core;
using namespace std;
class connectLogic
{
protected:
    Core* nucleo;
public:
    connectLogic();
   void setDistancia(int Distancia);
   void GameOver();
};


#endif // CONNECTLOGIC_H
