#ifndef POBLACION_H
#define POBLACION_H
#include "linked_list.h"
#include "tiro.h"

#include <unistd.h>
#include <bitset>

class Poblacion
{
private:
    int contadorId;
    int num_generaciones;
    int proba_mutacion;
    int proba_inversion;
    
    bool flag_nacimiento;
    int genActual;
    
    void fitness(tiro* hijo,int distancia);
    lista<lista<tiro*>*> generaciones;
    tiro *  crossover(tiro *padre,tiro *madre);


public:
    void newGeneration();
    lista<tiro *> *fitness(lista<tiro*> *antepasados);
    Poblacion();
};

#endif // POBLACION_H
