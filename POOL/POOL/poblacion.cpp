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
    tiro* newTiro=new tiro(madre,padre,angulo%360,fuerza%10,contadorId,genActual,facade);
    return newTiro;

}

void Poblacion::newGeneration()
{
    lista<tiro*> *nuevaGeneracion= new lista<tiro*>();

    if(generaciones.length()>=1){
        cout<<"Haciendo fitness"<<endl;

        PapaActual=(fitness(generaciones.get_tail()->get_data()))->get_head();
          MamaActual=PapaActual->get_next();
        cout<<"Hice fitness"<<endl;
          Node<tiro*> *temp=PapaActual;
        for(int i=1;i<=4;i++){
            cout<<" PapaActual "<<temp->get_data()->get_distancia()<<" gen actual "<<genActual<<endl;
            temp=temp->get_next();

        }
        count=0;
    }
    this->generaciones.insert_tail(nuevaGeneracion);
    newTiro();


}



void Poblacion::setDistancia(int pDistancia)
{
    distancia=pDistancia;
    generaciones.get_tail()->get_data()->get_tail()->get_data()->set_distancia(distancia);
     cout<<" setear distancia "<<pDistancia<<endl;
    newTiro();

}

lista<tiro *> *Poblacion::fitness(lista<tiro *> *antepasados)
{
   // antepasados->print_list();
    Node<tiro*> *temp=antepasados->get_head();
    Node<tiro*> *swap;


        while(temp->get_next()!=NULL){
            swap=temp->get_next();
            if(temp->get_data()->get_distancia()>swap->get_data()->get_distancia()){
                cout<<" temp "<<temp->get_data()->get_distancia()<<" swap "<<swap->get_data()->get_distancia()<<endl;
                antepasados->swap(temp,swap);
                temp=antepasados->get_head();
                swap=temp->get_next();
            }
            else{
                temp=temp->get_next();


            }

        }


    temp=antepasados->get_head();
    lista<tiro*> *Aptos=new lista<tiro*>();
    for(int i=0;i<4;i++){
        Aptos->insert_tail(temp->get_data());
        // cout<<" nuevo "<<temp->get_data()->get_distancia()<<endl;
        temp=temp->get_next();

    }
    return Aptos;
}

Poblacion::Poblacion(connectgui *pfacade)
{
    this->flag_nacimiento=true;
    this->genActual=0;
    this->contadorId=0;
    this->distancia=0;
    this->facade=pfacade;

}

void Poblacion::newTiro()
{
    if(generaciones.length()<=1){
        if(generaciones.get_tail()->get_data()->length()<4){
            tiro* newTiro=new tiro(contadorId,genActual,facade);


            generaciones.get_tail()->get_data()->insert_tail(newTiro);
            contadorId++;
        }
        else{
            genActual++;
            cout<<"Tamano de la primera generacion: "<<generaciones.get_tail()->get_data()->length()<<endl;
            newGeneration();
        }
    }
    else{
        //cout<<" papa distancia "<<PapaActual->get_data()->get_distancia()<<endl;

        if(PapaActual->get_next()!=NULL){



            if(MamaActual!=NULL){
                 // cout<<" mama distancia "<<MamaActual->get_data()->get_distancia()<<endl;
                tiro *Tironuevo=crossover(PapaActual->get_data(),MamaActual->get_data());
                //cout<<" crossover "<<Tironuevo->get_distancia()<<" count "<<count<<endl;
                     cout<<" count "<<count;
                generaciones.get_tail()->get_data()->insert_tail(Tironuevo);
                MamaActual=MamaActual->get_next();
                  contadorId++;
                  if(MamaActual==NULL){
                    count++;
                     PapaActual=PapaActual->get_next();
                     if(PapaActual->get_next()!=NULL){
                        MamaActual=PapaActual->get_next();
                     }
                  }


            }


        }


        else{
            cout<<" aumento generacion "<<endl;
            genActual++;
            newGeneration();
        }
}

}


