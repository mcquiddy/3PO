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
    int count;
    int num_generaciones;
    int proba_mutacion;
    int proba_inversion;
    int distancia;
    connectgui * facade;
    bool flag_nacimiento;
    bool flag_newCrossover;
    void newTiro();
    Node<tiro*> *PapaActual;
    Node<tiro*> *MamaActual;


    int genActual;
        lista<lista<tiro*>*> generaciones;
        lista<tiro *> *fitness(lista<tiro*> *antepasados);
        void fitness(tiro* hijo,int distancia);

        tiro *  crossover(tiro *padre,tiro *madre);
  QThread workerThread;


public slots:
  void newGeneration();
  void setDistancia(int pDistancia);

};

#endif // POBLACION_H
