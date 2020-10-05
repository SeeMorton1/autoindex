//
// Created by Conner Morton on 9/17/20.
//
#include <iostream>
#include "DSString.h"
#ifndef INC_20F_AUTO_IDX_DSVECTOR_H
#define INC_20F_AUTO_IDX_DSVECTOR_H

template <typename T>
class DSVector {
    T *vector;
    int cap;
    int currSize;
public:
    class iterator{
    private:
        T* p;
    public:
        iterator(){
            p = nullptr;
        }
        explicit iterator(T *temp){
            p = temp;
        }
        bool operator==(const iterator &c)const{
            if(p==c.p){
                return true;
            }
            return false;

        }
        bool operator!=(const iterator& c)const{
            if(p!=c.p){
                return true;
            }
            return false;
        }
        T operator*() const{
            return *p;
        }
        iterator &operator++(){
            ++p;
            return *this;
        }
    };
    void reserve(int newCap){
        if(newCap<=cap)return;
        if(newCap>(cap*2)){
            cap = newCap;
        }else{
            cap = cap*2;
        }
        T *c = new T[cap];
        for(unsigned i = 0;i<currSize;i++){
            c[i] = vector[i];
        }
        delete[] vector;
        vector = c;

    }

    //Rule of three: Constructor, Destructor, Copy constructor plus a copy assignment operator

    //constructor
    DSVector(){
        vector = new T[1];
        cap = 1;
        currSize = 0;
    }
    //destructor
    ~DSVector(){
        delete[] vector;
    }
    //copy constructor
    DSVector(const DSVector<T> &copy){
        cap = copy.cap;
        currSize = copy.currSize;
        vector = new T[cap];
        for(unsigned i = 0; i<currSize;i++)vector[i] = copy.vector[i];
    }
    //Copy assignment operator
    DSVector<T> &operator =(const DSVector<T> &copy){
        if(this != copy){
            currSize=copy.currSize;
            cap = copy.cap;
            vector = new T[cap];
            for(unsigned i = 0;i<currSize;i++)vector[i] = copy.vector[i];
        }
        return *this;
    }
    //Vector position getter
    T &operator[] (int n){
        if(n>currSize-1){
            std::cout<<"Out of bounds"<<std::endl;
            exit(0);
        }
        return *(vector+n);
    }

    T *begin() const{
        return vector;
    }
    T *end() const{
        return vector+currSize;
    }


    //getters
    int getCap(){
        return cap;
    }
    int getCurrSize(){
        return currSize;
    }


    //Functions

    void pushback(T data){
        reserve(currSize+1);
        vector[currSize++] = data;
        /*
        if(currSize==cap){
            T *c = new T[cap*2];
            for(unsigned i =0;i<currSize;i++){
                c[i] = vector[i];
            }
            delete[] vector;
            cap*=2;
            vector = c;
        }
        vector[currSize++]=data;
         */
    }
    T popBack(){
        return vector[--currSize];
    /*
        T *c = new T[currSize-1];
        for(unsigned i = 0;i<currSize-1;i++) {
            c[i] = vector[i];
        }
        delete[] vector;
        currSize--;
        vector = c;
        */
    }
    T get(int index){
        return vector[index];
    }
    T getFront(){
        return vector[0];
    }
    T getBack(){
        return vector[currSize-1];
    }
    void push(int index, T data){
        if(index ==cap)pushback(data);
        else{
            reserve(currSize+1);
            vector[index]= data;
        }
    }
    char* print(){
        char *c;
        for(unsigned i = 0;i<currSize;i++)c+=vector[i];
        return (c);
    }
    void erase(unsigned index){
        if(index<currSize&&index>=0){
            for(unsigned i = index+1;i<currSize;i++){
                vector[i-1] = vector[i];
            }
            currSize--;
            if(currSize<(cap/2)){
                T* newVec  = new T[cap/2];
                for(unsigned i = 0;i<currSize;i++){
                    newVec[i] = vector[i];
                }
                if(vector!= nullptr){
                    delete[] vector;
                }
                vector = newVec;
                cap=cap/2;
            }
        }
    }
    void alphaSort(){
        for(unsigned i = 0;i<currSize-1;i++){
            for(unsigned j = 0; j<currSize-1;j++){
                if(vector[i] <vector[j]){
                    T min = vector[j];
                    vector[j] = vector[i];
                    vector[i] = min;
                }
            }
        }
    }

};

#endif //INC_20F_AUTO_IDX_DSVECTOR_H
