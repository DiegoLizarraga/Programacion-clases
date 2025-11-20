/*
 * IPLinkedList.cpp
 * Implementación de la lista enlazada
 */

#include "IPLinkedList.h"

// Constructor
IPLinkedList::IPLinkedList() : head(nullptr), size(0) {}

// Destructor - libera toda la memoria
IPLinkedList::~IPLinkedList() {
    IPNodoLL* curr = head;
    while (curr != nullptr) {
        IPNodoLL* temp = curr;
        curr = curr->next;
        delete temp;
    }
}

// Verifica si está vacía
bool IPLinkedList::isEmpty() const { 
    return size == 0; 
}

// Retorna el tamaño
int IPLinkedList::length() const { 
    return size; 
}

// Inserta al inicio
void IPLinkedList::insertFirst(IPHashPair data) {
    IPNodoLL* nvo = new IPNodoLL(data, head);
    head = nvo;
    size++;
}

// Busca por clave y retorna puntero al valor
IPRecord* IPLinkedList::find(string key) {
    IPNodoLL* curr = head;
    while (curr != nullptr) {
        if (curr->data.key == key) {
            return &(curr->data.value);
        }
        curr = curr->next;
    }
    return nullptr;
}

// Actualiza el valor de una clave existente
bool IPLinkedList::update(string key, IPRecord newValue) {
    IPNodoLL* curr = head;
    while (curr != nullptr) {
        if (curr->data.key == key) {
            curr->data.value = newValue;
            return true;
        }
        curr = curr->next;
    }
    return false;
}

// Elimina el elemento en la posición pos
void IPLinkedList::removeAt(int pos) {
    if (pos < 0 || pos >= size) return;
    
    if (pos == 0) {
        IPNodoLL* temp = head;
        head = head->next;
        delete temp;
        size--;
        return;
    }
    
    IPNodoLL* curr = head;
    for (int i = 0; i < pos - 1; i++) {
        curr = curr->next;
    }
    
    IPNodoLL* temp = curr->next;
    curr->next = temp->next;
    delete temp;
    size--;
}