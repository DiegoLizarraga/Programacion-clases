/*
 * IPLinkedList.h
 * Lista enlazada para manejar colisiones en la tabla hash
 * 
 * Equipo 3:
 * Edgar Francisco Arechiga Nuño A01647054
 * Diego Martín Lizárraga Sánchez A01647334
 * Aldo Emiliano Galván Gómez A07106914
 */

#ifndef IPLINKEDLIST_H
#define IPLINKEDLIST_H

#include "IPHashPair.h"

using namespace std;

// Nodo para la lista enlazada
struct IPNodoLL {
    IPHashPair data;
    IPNodoLL* next;
    
    IPNodoLL(IPHashPair d, IPNodoLL* n = nullptr) : data(d), next(n) {}
};

class IPLinkedList {
public:
    IPNodoLL* head;
    int size;
    
    // Constructor
    IPLinkedList();
    
    // Destructor
    ~IPLinkedList();
    
    // Verifica si está vacía - O(1)
    bool isEmpty() const;
    
    // Retorna el tamaño - O(1)
    int length() const;
    
    // Inserta al inicio - O(1)
    void insertFirst(IPHashPair data);
    
    // Busca por clave - O(n) pero n es pequeño por factor de carga
    IPRecord* find(string key);
    
    // Actualiza o retorna false si no existe - O(n)
    bool update(string key, IPRecord newValue);
    
    // Elimina por índice - O(n)
    void removeAt(int pos);
};

#endif

