/*
 * IPHashTable.cpp
 * Implementación de la tabla hash
 */

#include "IPHashTable.h"
#include <iostream>

using namespace std;

// Constructor
IPHashTable::IPHashTable() {
    this->size = 0;
    this->sizeA = 601;  // Número primo para mejor distribución
    this->tabla = new IPLinkedList[this->sizeA];
}

// Destructor
IPHashTable::~IPHashTable() {
    delete[] tabla;
}

// Calcula posición en el arreglo usando función hash
int IPHashTable::getPos(string key) {
    size_t hashC = hash<string>{}(key);
    int hashCode = static_cast<int>(hashC);
    return abs(hashCode) % this->sizeA;
}

// Verifica si está vacía
bool IPHashTable::isEmpty() {
    return this->size == 0;
}

// Inserta o actualiza un registro
void IPHashTable::put(string key, IPRecord value) {
    // Verificar factor de carga y hacer rehashing si es necesario
    double factorCarga = static_cast<double>(size) / sizeA;
    if (factorCarga >= 0.75) {
        rehashing();
    }
    
    int pos = getPos(key);
    IPLinkedList& lista = tabla[pos];
    
    // Buscar si la clave ya existe
    IPNodoLL* curr = lista.head;
    while (curr != nullptr) {
        if (curr->data.key == key) {
            // Actualizar valor existente
            curr->data.value = value;
            return;
        }
        curr = curr->next;
    }
    
    // No existe, insertar nuevo par
    IPHashPair newPair(key, value);
    lista.insertFirst(newPair);
    this->size++;
}

// Obtiene el registro de una IP
IPRecord* IPHashTable::get(string key) {
    int pos = getPos(key);
    IPLinkedList& lista = tabla[pos];
    return lista.find(key);
}

// Verifica si existe una IP
bool IPHashTable::contains(string key) {
    return get(key) != nullptr;
}

// Obtiene el número de elementos
int IPHashTable::getSize() const {
    return this->size;
}

// Rehashing - duplica el tamaño y redistribuye todos los elementos
void IPHashTable::rehashing() {
    int oldSizeA = this->sizeA;
    IPLinkedList* oldTabla = this->tabla;
    
    // Crear nueva tabla con tamaño 2*sizeA + 1 (mantener impar/primo)
    this->sizeA = 2 * oldSizeA + 1;
    this->tabla = new IPLinkedList[this->sizeA];
    this->size = 0;
    
    // Reinsertar todos los elementos
    for (int i = 0; i < oldSizeA; i++) {
        IPLinkedList& lista = oldTabla[i];
        IPNodoLL* curr = lista.head;
        
        while (curr != nullptr) {
            string key = curr->data.key;
            IPRecord value = curr->data.value;
            
            // Calcular nueva posición e insertar
            int newPos = getPos(key);
            IPHashPair pair(key, value);
            tabla[newPos].insertFirst(pair);
            this->size++;
            
            curr = curr->next;
        }
    }
    
    // Liberar la tabla antigua
    delete[] oldTabla;
}