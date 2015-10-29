#include "tiro.h"


tiro::tiro(int id, int generacion, connectgui *pfacade)
{
    this->angulo=rand()%360 +1;
    this->fuerza= rand()%15 +1;
    this->generacion=generacion;
    this->facade=pfacade;
    padre=NULL;
    madre=NULL;
    facade->nuevoTiro(10,120);
    
}

int tiro::get_distancia()
{
    return this->distancia;
}

int tiro::get_angulo()
{
    return this->angulo;
}

int tiro::get_fuerza()
{
    return this->fuerza;
}

tiro::tiro(tiro *mama, tiro *papa, int angulo, int fuerza, int id, int generacion)
{
    this->madre=mama;
    this->padre=papa;
    this->angulo=angulo;
    this->fuerza=fuerza;
    this->generacion=generacion;
    this->id=id;
   // facade.nuevoTiro(fuerza,angulo);
}


void tiro::set_distancia(int distancia)
{
    this->distancia=distancia;
}
