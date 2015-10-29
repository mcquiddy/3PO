#ifndef CORE_H
#define CORE_H
#include "connectgui.h"
#include "Poolconstants.h"
#include "linked_list.h"
#include "Node.h"
#include "logicbolanegra.h"
#include "logicbolablanca.h"
#include "logicbolatiro.h"
#include "poblacion.h"

class Core
{
public:
    Core();
    lista<LogicBolaNegra * >   List_Bola_Negra;
    lista<LogicBolaTiro * >   List_Bola_Tiro;
    lista<LogicBolaBlanca * >   List_Bola_Blanca;
    connectgui * connect;
    lista<LogicBolaNegra *> get_list_bolaNegra();
    lista<LogicBolaBlanca * > get_list_bolaBlanca();
    lista<LogicBolaTiro * > get_list_bolaTiro();
};

#endif // CORE_H
