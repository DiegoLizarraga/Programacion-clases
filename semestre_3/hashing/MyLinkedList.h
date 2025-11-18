/*
 * MyLinkedList.h - Versión modificada para HashTable
 * Soporta almacenar pares (string key, int value)
 * 
 * Modificado por: Diego Martin Lizarraga Sanchez - A01647334
 * Fecha: Noviembre 2025
 */

#ifndef MYLINKEDLIST_H
#define MYLINKEDLIST_H

#include <iostream>
#include <string>
using namespace std;

// Estructura para almacenar pares key-value
struct HashPair {
    string key;
    int value;
    
    HashPair(string k = "", int v = 0) : key(k), value(v) {}
};

// Nodo para la lista enlazada (ahora con HashPair)
struct MyNodoLL {
    HashPair data;      // Cambio: ahora almacena HashPair en lugar de int
    MyNodoLL* next;

    MyNodoLL(HashPair data, MyNodoLL* next){
        this->data = data;
        this->next = next;
    }

    MyNodoLL(HashPair data): MyNodoLL(data, nullptr) {}
    
    // Constructor alternativo para facilidad
    MyNodoLL(string key, int value): MyNodoLL(HashPair(key, value), nullptr) {}
};

class MyLinkedList {
public:
    int size;
    MyNodoLL* head;
    MyNodoLL* tail;

    // Constructor
    MyLinkedList();
    // Destructor
    ~MyLinkedList();
    
    // Retorna el tamaño de la lista - Complejidad: O(1)
    int length();
    
    // Verifica si la lista está vacía - Complejidad: O(1)
    bool isEmpty();
    
    // Inserta un par al inicio - Complejidad: O(1)
    void insertFirst(HashPair data);
    
    // Inserta un par al final - Complejidad: O(1)
    void insertLast(HashPair data);
    
    // Elimina el primer elemento - Complejidad: O(1)
    void removeFirst();
    
    // Elimina el elemento en la posición pos - Complejidad: O(n)
    void removeAt(int pos);
    
    // Busca una clave y retorna su valor - Complejidad: O(n)
    int findValue(string key);
    
    // Verifica si existe una clave - Complejidad: O(n)
    bool containsKey(string key);
    
    // Actualiza el valor de una clave existente - Complejidad: O(n)
    bool updateValue(string key, int newValue);
    
    // Sobrecarga del operador << - Complejidad: O(n)
    friend ostream& operator<<(ostream& os, const MyLinkedList& ll);
};

#endif