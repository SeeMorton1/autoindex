//
// Created by Conner Morton on 9/19/2020.
//
//TODO: If nothing can fix my String popping, then I would like to start working on the Linked List.

#ifndef INC_20F_AUTO_IDX_LINKEDLIST_H
#define INC_20F_AUTO_IDX_LINKEDLIST_H
#include "Node.h"
#include <iostream>
#include <fstream>
#include "DSString.h"

template <typename T>
class LinkedList{
private:
    int size; Node<T>* head; Node<T>* tail;
public:
    LinkedList(){
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    ~LinkedList(){
        Node<T> * curr = head;
        Node<T> *t;
        while(curr!=0){
            t = curr;
            curr = curr->next;
            delete t;
        }
    }
    //copy constructor nmot sure if working

    LinkedList(const LinkedList<T>& copy){
        const Node<T>* curr = copy.head;
        Node<T> *temp = nullptr;
        if(curr!= nullptr){
            head = new Node<T>(curr->data);
            temp = head;
            curr= curr->next;
        }
        while(curr!= nullptr){
            Node<T>* newTemp = new Node<T>(curr->data);
            temp->next=newTemp;
            curr=curr->next;
        }
    }
    //not working but need a placeholder
    LinkedList<T> &operator = (const LinkedList<T>& copy){
        LinkedList<T> temp(copy);
        std::swap(temp.head,head);
        return *this;
    }
    Node<T>* getHead(){
        return this->head;
    }
    Node<T>* getTail(){
        return this->tail;
    }
    void pushBack(T node){

        if(head == nullptr){
            Node<T>* curr = new Node<T>(node);
            head = curr;
            tail = curr;
        }else {
            Node<T> *curr = new Node<T>(node);
            tail->next = curr;
            tail = curr;
        }
    }
    void pushBegin(T in){
        if(head==nullptr&&tail==nullptr){
            auto *n = new Node<T>(in);
            head = n;
            tail = n;
        }else{
            auto *n = new Node<T> (in);
            tail->next = n;
            tail= n;
        }
    }
    //alphabetically sort into the new node
    void newNode(T in){
        if(head==nullptr&&tail==nullptr){
            pushBegin(in);
        }else{
            if(in <head->getData()){
                pushBack(in);
            }else if(in>=tail->getData()){
                pushBack(in);
            }else{
                Node<T> *curr = head;
                auto *n = new Node<T>(in);
                while(head!=tail){
                    if((n->getData()<curr->next->data)&&(n->data>=curr->data)){
                        Node<T> *setup = curr->next;
                        curr->next = n;
                        n->next = setup;
                        break;
                    }
                    curr = curr->next;
                }
            }
        }
    }


    void print(){
        if (head== nullptr&&tail== nullptr) {
            std::cout << "List is currently empty" << std::endl;
        } else {
            Node<T> *curr = head;
            while (curr != NULL) {
                T in = curr->getData();
                std::cout << in << " ";
                curr = curr->next;
            }
            std::cout << std::endl;
        }
    }

    Node<T>* search(T elem){
        Node<T>* t = this->head;
        while(t!=nullptr){
            if(t->getData()==elem){
                return t;
            }
            t = t->next;
        }
        return head;
    }




};



#endif //INC_20F_AUTO_IDX_LINKEDLIST_H
