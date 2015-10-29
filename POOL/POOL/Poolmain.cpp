
#include <QApplication>
#include <iostream>
//#include "Poolgame.h"
#include "poblacion.h"
#include "core.h"
using namespace std;
//Poolgame *game;
Core * core;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//     game = new Poolgame();
//     game->show();
     core = new Core();
     Poblacion Aldeanos;

    return a.exec();
}
