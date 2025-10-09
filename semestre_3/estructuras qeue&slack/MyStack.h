#ifndef MYSTACK
#define MYSTACK

#include "MyLinkedList.h"

class MyStack{
    private:
        MyLinkedList lista;
    public:
        MyStack();
        ~MyStack();
        void push(int valor);
        void pop();
        int top();
        int lenght();
        bool isEmpty();
        void flush();      
};

#endif