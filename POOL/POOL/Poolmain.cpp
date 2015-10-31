
#include <QApplication>
#include <iostream>
//#include "Poolgame.h"

#include "core.h"
using namespace std;
//Poolgame *game;
Core * core;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//     game = new Poolgame();
//     game->show();
     core = Core::getInstance();
     core->newGame();


    return a.exec();
}
