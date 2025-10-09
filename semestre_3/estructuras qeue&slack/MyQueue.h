#ifndef MYQUEUE
#define MYQUEUE

#include "MyLinkedList.h"
#include "MyLinkedList.cpp"

class MyQueue{
    private:
        MyLinkedList lista;
    public:
        MyQueue();
        ~MyQueue();
        void enqueue(int valor);
        void dequeue();
        int peek();
        bool isEmpty();
        int lenght();
        void flush();

};

#endif