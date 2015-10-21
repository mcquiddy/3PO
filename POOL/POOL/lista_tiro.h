#ifndef LISTA_TIRO_H
#define LISTA_TIRO_H
#include <iostream>
#include "NodeTiro.h"

using namespace std;

template<typename T>
class listaTiro {
private:
    NodeTiro<T>* head;
    NodeTiro<T>* tail;
    int Length;

public:
    void insert_head(T new_data, NodeTiro<T> *pNodePIzq, NodeTiro<T> *pNodePDer);
    void insert_tail(T new_data,NodeTiro<T>*  pNodePIzq,NodeTiro<T>*  pNodePDer);
    void delete_data(T data);
    bool isInList(T data);
    NodeTiro<T>* rove(int x);
    NodeTiro<T>* get_head();
    NodeTiro<T>* get_tail();
    int length();
    T* serch(T data);
    void print_list();
    listaTiro();
    virtual ~listaTiro();

    void delete_Pos(int x);



};

template<typename T>
/**
 * @brief list<T>::list
 */
listaTiro<T>::listaTiro(){
    head=NULL;
    tail=NULL;
    Length=0;
}
template<typename T>
/**
 * @brief list<T>::insert_head
 * @param new_data
 */
void listaTiro<T>::insert_head(T new_data,,NodeTiro<T>*  pNodePIzq,NodeTiro<T>*  pNodePDer){
    NodeTiro<T> *newNode=new NodeTiro<T>(new_data);
    if(this->head==NULL){
        head=newNode;
        tail=head;
    }
    else{
        NodeTiro<T>* temp=this->head;
        newNode->set_next(temp);
        temp->set_prev(newNode);
        this->head=newNode;
    }
    this->Length++;
}

template<typename T>
/**
 * @brief list<T>::insert_tail
 * @param new_data
 */
void listaTiro<T>::insert_tail(T new_data, NodeTiro<T> *pNodePIzq, NodeTiro<T> *pNodePDer){
    NodeTiro<T> *newNode=new NodeTiro<T>(new_data);
    if(this->tail==NULL){
        tail=newNode;
        head=tail;
    }
    else{
        NodeTiro<T>* temp=this->tail;
        temp->set_next(newNode);
        newNode->set_prev(temp);
        tail=newNode;
    }
    this->Length++;
}

template<typename T>
/**
 * @brief list<T>::delete_data
 * @param data
 */
void listaTiro<T>::delete_data(T data){
    if(this->Length!=0){//se cumple en caso que  solo existe un nodo(head)
            NodeTiro<T>* temp=head->get_next();
            if((temp==NULL) & ((this->head->get_data())==data)){
                delete head;
                head=NULL;
                tail=NULL;
                Length=0;

            }
            else{
                NodeTiro<T>* NextTemp=temp->get_next();
                if(this->head->get_data()==data){//se cumple en caso que el nodo a eliminar sea el head
                    temp=head->get_next();
                    delete head;
                    head=temp;
                    head->set_prev(NULL);
                    this->Length--;
                    //cout<<"delete data: "<<data<<"In head"<<endl;
                }
                 if(this->tail->get_data()==data){
                    temp=tail->get_prev();
                    delete tail;
                    tail=temp;
                    temp->set_next(NULL);
                    this->Length--;
                    //cout<<"delete data: "<<data<<"In tail"<<endl;
                }
                while(temp->get_next()!=NULL){
                    //cout<<temp->get_data()<<" es igual a "<<data<<"?"<<endl;
                    if(temp->get_data()==data){
                        temp->get_prev()->set_next(temp->get_next());
                        temp->get_next()->set_prev(temp->get_prev());
                        delete temp;
                        temp=NextTemp;
                        //cout<<"Data "<<data<<" deleted"<<endl;
                    }
                    else{
                        temp=temp->get_next();
                    }
                    NextTemp=temp->get_next();
                }
            }

    }
}

template<typename T>
/**
 * @brief list<T>::isInList
 * @param data
 * @return
 */
 NodeTiro<T>* listaTiro<T>::rove(int x){
    NodeTiro<T>* temp=this->head;
    if(this->Length>=0 && x<=this->length()){

        for(int i=1;i<x;i++){

            temp=temp->get_next();

        }
    }
    else{
       temp=NULL;

    }

    return temp;
}
template<typename T>
 bool listaTiro<T>::isInList(T data){
     bool save=false;
     if(this->Length>0){
         NodeTiro<T>* temp=this->head;
         while(temp!=NULL){
             if(temp->get_data()==data){
                 save=true;
                 break;
             }
             temp=temp->get_next();
         }
     }

     return save;
 }

template<typename T>
/**
 * @brief list<T>::serch
 * @param data
 * @return
 */
T* listaTiro<T>::serch(T data){
    if(this->isInList(data)){
        NodeTiro<T>* temp=head;
        NodeTiro<T>* result=NULL;
        while(temp->get_next()!=NULL){
            if(temp->get_data()==data){
                result=data;
            }
        }
        return result;
    }
    else{
        return NULL;
    }
}


template<typename T>
/**
 * @brief list<T>::delete_Pos
 * @param x
 */
void listaTiro<T>::delete_Pos(int x){
    if(this->Length!=0 && x<=this->length()){//se cumple en caso que  solo existe un nodo(head)
            NodeTiro<T>* temp=head->get_next();
            if((temp==NULL) & (x==1)){
                delete head;
                head=NULL;
                tail=NULL;
                Length=0;
            }
            else{

                if(x==1){//se cumple en caso que el nodo a eliminar sea el head
                    temp=head->get_next();
                    delete head;
                    head=temp;
                    head->set_prev(NULL);
                    this->Length--;

                    //cout<<"delete data: "<<data<<"In head"<<endl;
                }
                else if(x==this->length()){
                    temp=tail->get_prev();
                    delete tail;
                    tail=temp;
                    temp->set_next(NULL);
                    this->Length--;
                    //cout<<"delete data: "<<data<<"In tail"<<endl;
                }
                else{
                    temp=head;
                 for(int i=1; i<=x;i++){
                    if(i==x){
                        temp->get_prev()->set_next(temp->get_next());
                        temp->get_next()->set_prev(temp->get_prev());
                        delete temp;
                        this->Length--;
                        //cout<<"Data "<<data<<" deleted"<<endl;
                    }
                    else{
                        temp=temp->get_next();
                    }

                }
                }
            }
    }
}


template<typename T>
/**
 * @brief list<T>::get_head
 * @return
 */
NodeTiro<T>* listaTiro<T>::get_head(){
    return this->head;
}

template<typename T>
/**
 * @brief list<T>::get_tail
 * @return
 */
NodeTiro<T>* listaTiro<T>::get_tail(){
    return this->tail;
}


template<typename T>
/**
 * @brief list<T>::length
 * @return
 */
int listaTiro<T>::length(){
    return Length;
}

template<typename T>
/**
 * @brief list<T>::print_list
 */
void listaTiro<T>::print_list(){
    NodeTiro<T>* temp=this->head;
    cout<<"Cantidad de nodos: "<<this->Length<<endl;
    while(temp!=NULL){
        cout<<temp->get_data()<<" ";
        temp=temp->get_next();
    }
    cout<<endl;
}
template<typename T>
/**
 * @brief list<T>::~list
 */
listaTiro<T>::~listaTiro(){
    delete this;
}
#endif // LISTA_TIRO_H
