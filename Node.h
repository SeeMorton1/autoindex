//
// Created by Conner Morton on 9/19/2020.
//

#ifndef INC_20F_AUTO_IDX_NODE_H
#define INC_20F_AUTO_IDX_NODE_H
template <typename T>
class LinkedList;

template <typename T>
class Node{
    friend class LinkedList<T>;
public:
    Node* next;
    Node* prev;
    Node(T);
    Node();
    T getData();
    void setNext(Node* n);
private:
    T data;

};
template <typename T>
Node<T>::Node(T in) {
    data = in;
    next = 0;
}
template <typename T>
Node<T>::Node(){
    data = nullptr;
    next = nullptr;
}
template <typename T>
T Node<T>::getData() {return data;}

template <typename T>
void Node<T>::setNext(Node* n){
    next = n;
}
#endif //INC_20F_AUTO_IDX_NODE_H

