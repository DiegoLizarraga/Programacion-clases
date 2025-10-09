#include "MyBST.h"


MyBST::MyBST(){
    this->root = nullptr;
    this->size = 0;
}


int MyBST::length(){
    return this->size;
}

bool MyBST::isEmpty(){
    return this->size == 0;
}

//implementar a insercon de manera iterativa o recursiva
bool MYBST::insert(int data){
    if(this->root == nullptr){
        this->root = new MyNodeBST(data);
        this->size++;
        return true;
    }

    MyNodeBST* current = this->root;
    MyNodeBST* parent = nullptr;

    while(current != nullptr){
        if(current->valor == data){
            return false; //el valor ya existe
        }else if(data < current->valor){
            parent = current;
            current = current->izq;
        }else{
            parent = current;
            current = current->der;
        }
    }

    if(data < parent->valor){
        parent->izq = new MyNodeBST(data);
    }else{
        parent->der = new MyNodeBST(data);
    }
    this->size++;
    return true;
}


bool MyBST::search(int valor){
    MyNodeBST* current = this->root;
    while(current != nullptr){
        if(current->valor == valor){
            return true;
        }else if(valor < current->valor){
            current = current->izq;
        }else{
            current = current->der;
        }
    }

    return false;
}


//implementacion recursiva de la funcion
bool searchRec(int data, MyNodeBST *current){
    //implementar la bsiqueda de manera recursiva
    if(current == nullptr){
        return false;
    }
    if(current->valor == data){
        return true;
    }else if(data < current->valor){
        return searchRec(data, current->izq);
    }else{
        return searchRec(data, current->der);
    }
    
}

bool MyBST::searchRec(int data){
    return searchRec(data, this->root);
}

