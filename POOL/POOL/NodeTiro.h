#ifndef NODETIRO_H
#define NODETIRO_H
template <typename T>
class NodeTiro {
private:
    NodeTiro<T>* next_node;
    NodeTiro<T>* prev_node;
    NodeTiro<T>* padre_izq;
    NodeTiro<T>* padre_der;
    T data;

public:
    NodeTiro(T dato, NodeTiro<T> *pNodePIzq, NodeTiro<T> *pNodePDer) ;
    T get_data();
    void set_next(NodeTiro* next_node);
    void set_prev(NodeTiro* prev_node);
    NodeTiro* get_next();
    NodeTiro* get_prev();
};
/**
 * Constructor of a Node
 * Setting nex_node and prev_node as 0 or NULL
 */
template<typename T>
NodeTiro<T>::NodeTiro(T dato,NodeTiro<T>*  pNodePIzq,NodeTiro<T>*  pNodePDer){
    this->data=dato;
    this->next_node=0;
    this->prev_node=0;
    this->padre_izq= pNodePIzq;
    this->padre_der= pNodePDer;
}
/**
 * Getters and setters
 */
template<typename T>
/**
 * @brief Node<T>::get_next
 * @return
 */
NodeTiro<T>* NodeTiro<T>::get_next(){
    return this->next_node;
}
template<typename T>
/**
 * @brief Node<T>::get_prev
 * @return
 */
NodeTiro<T>* NodeTiro<T>::get_prev(){
    return this->prev_node;
}
template<typename T>
void NodeTiro<T>::set_next(NodeTiro<T>* new_next_node){
    this->next_node=new_next_node;
}
template<typename T>
void NodeTiro<T>::set_prev(NodeTiro<T>* new_prev_node){
    this->prev_node=new_prev_node;
}
template<typename T>
T NodeTiro<T>::get_data(){
    return this->data;
}
#endif // NODETIRO_H
