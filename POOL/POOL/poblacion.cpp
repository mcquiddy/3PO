#include "poblacion.h"


tiro *Poblacion::crossover(tiro *padre, tiro *madre)
{

    std::bitset<12> papaAngulo(padre->get_angulo());
    std::bitset<12> mamaAngulo(madre->get_angulo());
    std::bitset<12> hijoAngulo;
    std::bitset<12> papaFuerza(padre->get_fuerza());
    std::bitset<12> mamaFuerza(madre->get_fuerza());
    std::bitset<12> hijoFuerza;

    if(papaAngulo.size()==mamaAngulo.size()){
        for(int i=0;i<papaAngulo.size();i++){
            if(i<papaAngulo.size()/2){
                hijoAngulo[i]=papaAngulo[i];
            }
            else{
                hijoAngulo[i]=mamaAngulo[i];
            }
        }
    }

      if(papaFuerza.size()==mamaFuerza.size()){
        for(int i=0;i<papaFuerza.size();i++){
            if(i<papaFuerza.size()/2){
                hijoFuerza[i]=papaFuerza[i];
            }
            else{
                hijoFuerza[i]=mamaFuerza[i];
            }
        }
    }

    int angulo=(int)hijoAngulo.to_ulong();
    int fuerza=(int)hijoFuerza.to_ulong();
    tiro* newTiro=new tiro(madre,padre,angulo%360,fuerza%10,contadorId,genActual);
    return newTiro;

}

void Poblacion::newGeneration()
{
    lista<tiro*> *newGeneracion=new lista<tiro*>();
    if(genActual==0){
        for(int i=0;i<4;i++){
            tiro* newTiro=new tiro(contadorId,genActual);
            newGeneracion->insert_tail(newTiro);
            while(flag_nacimiento){
                usleep(800);
            }
            flag_nacimiento=true;
            contadorId++;
        }
        genActual++;
    }
    else{
        Node<tiro*> *tempPapa=(fitness(generaciones.get_tail()->get_data()))->get_head();
        while(tempPapa->get_next()!=NULL)
        {
            Node<tiro*> *tempMama=tempPapa->get_next();
            while(tempMama!=NULL)
            {
                tiro *newTiro=crossover(tempPapa->get_data(),tempMama->get_data());
                newGeneracion->insert_tail(newTiro);
                while(flag_nacimiento){
                       usleep(800);
                }
                flag_nacimiento=true;
                tempMama=tempMama->get_next();
            }
            tempPapa=tempPapa->get_next();
        }
    }
    generaciones.insert_tail(newGeneracion);
}

lista<tiro *> *Poblacion::fitness(lista<tiro *> *antepasados)
{
    Node<tiro*> *temp=antepasados->get_head();
    Node<tiro*> *swap=temp->get_next();
    bool flag_cambio=true;
    while(flag_cambio){
        while(temp->get_next()!=NULL){

            if(temp->get_data()->get_distancia()>swap->get_data()->get_distancia()){
                if(temp==antepasados->get_head()){
                    temp->set_next(swap->get_next());
                    swap->set_next(temp);
                    swap->set_prev(temp->get_prev());
                    temp->set_prev(swap);
                    temp->get_next()->set_prev(temp);
                }
                else if(swap==antepasados->get_tail()){
                    temp->set_next(swap->get_next());
                    swap->set_next(temp);
                    swap->set_prev(temp->get_prev());
                    temp->set_prev(swap);
                    swap->get_prev()->set_next(swap);

                }

                else{
                    temp->set_next(swap->get_next());
                    swap->set_next(temp);
                    swap->set_prev(temp->get_prev());
                    temp->get_next()->set_prev(temp);
                    temp->set_prev(swap);
                    swap->get_prev()->set_next(swap);
            }
                flag_cambio=true;
                temp=antepasados->get_head();
                swap=temp->get_next();
        }
            temp=temp->get_next();
            swap=temp->get_next();
        }

    }
    temp=antepasados->get_head();
    lista<tiro*> *Aptos=new lista<tiro*>();
    for(int i=0;i<4;i++){
        Aptos->insert_tail(temp->get_data());
        temp=temp->get_next();
    }
    return Aptos;
}

Poblacion::Poblacion()
{
    this->flag_nacimiento=true;
    this->genActual=0;
    this->contadorId=0;
}


