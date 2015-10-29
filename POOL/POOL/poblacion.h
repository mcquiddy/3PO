#ifndef POBLACION_H
#define POBLACION_H
#include "linked_list.h"
#include "tiro.h"

#include <unistd.h>
#include <bitset>
#include <QObject>
#include <QThread>
#include "connectgui.h"
class Poblacion:public QObject
{
Q_OBJECT
public:
    Poblacion(connectgui * pfacade);
private:
    int contadorId;
    int num_generaciones;
    int proba_mutacion;
    int proba_inversion;
    connectgui * facade;
    bool flag_nacimiento;
    int genActual;
        lista<lista<tiro*>*> generaciones;
        lista<tiro *> *fitness(lista<tiro*> *antepasados);
        void fitness(tiro* hijo,int distancia);

        tiro *  crossover(tiro *padre,tiro *madre);
  QThread workerThread;


public slots:
  void newGeneration();

};

#endif // POBLACION_H
