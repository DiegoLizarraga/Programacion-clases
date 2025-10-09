#include "MyStack.h"

MyStack::MyStack(){}
MyStack::~MyStack(){}

void MyStack::push(int valor){
    this->lista.insertFirst(valor);
}

void MyStack::pop(){
    try{
        this->lista.removeFirst();
    }
    catch(invalid_argument ex){
        throw invalid_argument("No se puede hacer un pop de un stack vacia");
    }
}

int MyStack::top(){
    try{
        return this->lista.first();
    }
    catch(invalid_argument ex){
        throw invalid_argument("No se puede hacer un top de un stack vacia");
    }
}

int MyStack::lenght(){
    return this->lista.length();
}

bool MyStack::isEmpty(){
    return this->lista.isEmpty();
}

void MyStack::flush(){

}

