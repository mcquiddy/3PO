#ifndef TIRO_GENETICO_H
#define TIRO_GENETICO_H
#include "stdlib.h"
#include "connectgui.h"

class tiro
{
private:

    int fuerza;
    int angulo;
    int id;

    int distancia;
    int generacion;
    
    tiro* padre;
    tiro* madre;
    connectgui * facade;
    

public:
    tiro(tiro* mama, tiro* papa, int angulo, int fuerza, int id, int generacion);
    tiro(int id,int generacion,connectgui * pfacade);
    void mutacion();
    void inversion();
    void set_distancia(int distancia);
    int get_distancia();
    int get_angulo();
    int get_fuerza();
};

#endif // TIRO_GENETICO_H
