#ifndef CORE_H
#define CORE_H

#include "Poolconstants.h"
#include "linked_list.h"
#include "Node.h"
#include "logicbolanegra.h"
#include "logicbolablanca.h"
#include "logicbolatiro.h"
#include "poblacion.h"
#include <QObject>
#include <QThread>

class connectgui;

class Core:public QObject
{
Q_OBJECT
public:

    QThread workerThread;
    lista<LogicBolaNegra * >   List_Bola_Negra;
    lista<LogicBolaTiro * >   List_Bola_Tiro;
    lista<LogicBolaBlanca * >   List_Bola_Blanca;
    connectgui * connect;
    Poblacion * Aldeanos;
    lista<LogicBolaNegra *> get_list_bolaNegra();
    lista<LogicBolaBlanca * > get_list_bolaBlanca();
    lista<LogicBolaTiro * > get_list_bolaTiro();
    static Core* getInstance();
    void newGame();
    void GameOver();

private:
     Core();
     static Core* unicCore;
};

#endif // CORE_H
