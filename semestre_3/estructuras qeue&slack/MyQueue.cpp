#include "MyQueue.h"
using namespace std;

MyQueue::MyQueue(){}
MyQueue::~MyQueue(){}

bool MyQueue::isEmpty(){
    return this->lista.isEmpty();
}

int MyQueue::lenght(){
    return this->lista.length();
}

void MyQueue::enqueue(int valor){
    this->lista.insertLast(valor);
}
void MyQueue::dequeue(){
    try{
        this->lista.removeFirst();
    }
    catch(invalid_argument ex){
        throw invalid_argument("No se puede hacer un dequeue de una queue vacia");
    }
}

int MyQueue::peek(){
    return this->lista.first();

}

void MyQueue::flush(){
    
}