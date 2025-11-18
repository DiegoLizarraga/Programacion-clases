/*
 * MyLinkedList.cpp - Versión modificada para HashTable
 * Implementación de métodos para manejar pares key-value
 * 
 * Modificado por: Diego Martin Lizarraga Sanchez - A01647334
 * Fecha: Noviembre 2025
 */

#include "MyLinkedList.h"
#include <stdexcept>

using namespace std;

/*
 * Constructor
 * Complejidad: O(1)
 */
MyLinkedList::MyLinkedList() {
    this->size = 0;
    this->head = this->tail = nullptr;
}

/*
 * Destructor - Libera toda la memoria
 * Complejidad: O(n)
 */
MyLinkedList::~MyLinkedList() {
    MyNodoLL* curr = this->head;
    while (curr != nullptr) {
        MyNodoLL* temp = curr;
        curr = curr->next;
        delete temp;
    }
    this->head = this->tail = nullptr;
    this->size = 0;
}

/*
 * Retorna el tamaño de la lista
 * Complejidad: O(1)
 */
int MyLinkedList::length() {
    return this->size;
}

/*
 * Verifica si la lista está vacía
 * Complejidad: O(1)
 */
bool MyLinkedList::isEmpty() {
    return this->size == 0;
}

/*
 * Inserta un par al inicio
 * Complejidad: O(1)
 */
void MyLinkedList::insertFirst(HashPair data) {
    MyNodoLL* nvo = new MyNodoLL(data, this->head);
    this->head = nvo;
    this->size++;
    if (this->size == 1) {
        this->tail = nvo;
    }
}

/*
 * Inserta un par al final
 * Complejidad: O(1)
 */
void MyLinkedList::insertLast(HashPair data) {
    MyNodoLL* nvo = new MyNodoLL(data, nullptr);
    if (this->size == 0) {
        this->head = this->tail = nvo;
    } else {
        this->tail->next = nvo;
        this->tail = nvo;
    }
    this->size++;
}

/*
 * Elimina el primer elemento
 * Complejidad: O(1)
 */
void MyLinkedList::removeFirst() {
    if (this->size == 0) {
        throw invalid_argument("Error: lista vacia");
    }
    MyNodoLL* temp = this->head;
    this->head = this->head->next;
    delete temp;
    this->size--;
    if (this->size == 0) {
        this->tail = nullptr;
    }
}

/*
 * Elimina el elemento en la posición pos
 * Complejidad: O(n)
 */
void MyLinkedList::removeAt(int pos) {
    if (pos < 0 || pos >= this->size) {
        throw out_of_range("Error: posicion invalida");
    }
    
    if (pos == 0) {
        removeFirst();
        return;
    }
    
    MyNodoLL* curr = this->head;
    MyNodoLL* prev = nullptr;
    for (int i = 0; i < pos; i++) {
        prev = curr;
        curr = curr->next;
    }
    
    if (prev != nullptr) {
        prev->next = curr->next;
    }
    if (curr == this->tail) {
        this->tail = prev;
    }
    delete curr;
    this->size--;
}

/*
 * Busca una clave y retorna su valor
 * Complejidad: O(n) - recorre la lista hasta encontrar la clave
 */
int MyLinkedList::findValue(string key) {
    MyNodoLL* curr = this->head;
    while (curr != nullptr) {
        if (curr->data.key == key) {
            return curr->data.value;
        }
        curr = curr->next;
    }
    throw invalid_argument("Error: clave no encontrada");
}

/*
 * Verifica si existe una clave
 * Complejidad: O(n)
 */
bool MyLinkedList::containsKey(string key) {
    MyNodoLL* curr = this->head;
    while (curr != nullptr) {
        if (curr->data.key == key) {
            return true;
        }
        curr = curr->next;
    }
    return false;
}

/*
 * Actualiza el valor de una clave existente
 * Complejidad: O(n)
 * Retorna true si encontró y actualizó, false si no existe
 */
bool MyLinkedList::updateValue(string key, int newValue) {
    MyNodoLL* curr = this->head;
    while (curr != nullptr) {
        if (curr->data.key == key) {
            curr->data.value = newValue;
            return true;
        }
        curr = curr->next;
    }
    return false;
}

/*
 * Sobrecarga del operador <<
 * Complejidad: O(n)
 */
ostream& operator<<(ostream& os, const MyLinkedList& ll) {
    MyNodoLL* curr = ll.head;
    while (curr != nullptr) {
        os << "(" << curr->data.key << ":" << curr->data.value << ")";
        if (curr->next != nullptr) {
            os << " -> ";
        }
        curr = curr->next;
    }
    return os;
}