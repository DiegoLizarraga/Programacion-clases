// Diego Martin Lizarraga Sanchez - A01647334

#ifndef MYLINKEDLIST_H
#define MYLINKEDLIST_H

#include <iostream>
using namespace std;

struct Node {
    int data;
    MyNodoLL* next;

    MyNodoLL(int data,MyNodoLL* next){
        this->data = data;
        this->next = next;
    }

    MyNodoLL(int data): MyNodoLL(data,nullptr) {
        
    }
    
};

class MyLinkedList {
private:
//me dijo que quitara todo lo que estaba en private

public:
    int size;
    MyNodoLL* head;
    MyNodoLL* tail;

    //constructor
    MyLinkedList();
    //detructor
    ~MyLinkedList();
    
    // Retorna el tamaño de la lista - Complejidad: O(1)
    int length();
    // Verifica si la lista está vacía - Complejidad: O(1)
    bool isEmpty();
    // Retorna el primer elemento - Complejidad: O(1)
    int first();
    // Retorna el último elemento - Complejidad: O(1)
    int last();
    // Retorna el elemento en la posición pos - Complejidad: O(n)
    int getAt(int pos);
    
    // Modifica el elemento en la posición pos - Complejidad: O(n)
    void setAt(int pos, int data);
    
    // Inserta un elemento al inicio - Complejidad: O(1)
    void insertFirst(int data);
    
    // Inserta un elemento al final - Complejidad: O(1)
    void insertLast(int data);
    
    // Inserta un elemento en la posición pos - Complejidad: O(n)
    void insertAt(int pos, int data);
    

    //////estas son las funciones que me dijo que pusiera

    // Elimina el primer elemento - Complejidad: O(1)
    void removeFirst();
    
    // Elimina el último elemento - Complejidad: O(n)
    void removeLast();
    
    // Elimina el elemento en la posición pos - Complejidad: O(n)
    void removeAt(int pos);
    
    // Sobrecarga del operador << - Complejidad: O(n)
    //me base en esa publicacion para implementarlo
    //para hacer esto me base en esto https://stackoverflow.com/questions/21995521/what-is-friend-ostream
    friend ostream& operator<<(ostream& os, const MyLinkedList& ll);//nose si es asi pero 
};


#endif