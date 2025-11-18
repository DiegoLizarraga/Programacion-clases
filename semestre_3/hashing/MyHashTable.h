/*
 * MyHashTable.h
 * Tabla hash con encadenamiento - Compatible con tu MyLinkedList existente
 * 
 * Autor: Diego Martin Lizarraga Sanchez - A01647334
 * Fecha: 17 Noviembre 2025
 */

#ifndef MYHASHTABLE_H
#define MYHASHTABLE_H

#include "MyLinkedList.h"
#include <string>
#include <functional>

using namespace std;

class MyHashTable {
public:
    MyLinkedList* tabla;  // Arreglo de listas enlazadas
    int size;             // Cantidad de elementos almacenados
    int sizeA;            // Tamaño del arreglo
    
    /*
     * Calcula posición en el arreglo para una clave
     * Complejidad: O(1)
     * Supuesto: Factor de carga < 0.75, hash equitativo
     */
    int getPos(string key);
    
    /*
     * Crece el arreglo al doble + 1 y redistribuye
     * Complejidad: O(n) donde n es número de elementos
     * Supuesto: Factor de carga < 0.75, hash equitativo
     */
    void rehashing();
    
    /*
     * Constructor - Tamaño inicial 11
     * Complejidad: O(1)
     * Supuesto: Factor de carga < 0.75, hash equitativo
     */
    MyHashTable();
    
    /*
     * Destructor
     * Complejidad: O(n + m) donde n=elementos, m=tamaño arreglo
     * Supuesto: Factor de carga < 0.75, hash equitativo
     */
    ~MyHashTable();
    
    /*
     * Verifica si está vacía
     * Complejidad: O(1)
     * Supuesto: Factor de carga < 0.75, hash equitativo
     */
    bool isEmpty();
    
    /*
     * Inserta o actualiza par key-value
     * Complejidad: O(1) promedio
     * Supuesto: Factor de carga < 0.75, hash equitativo
     */
    void put(string key, int value);
    
    /*
     * Obtiene valor asociado a clave
     * Complejidad: O(1) promedio
     * Supuesto: Factor de carga < 0.75, hash equitativo
     */
    int get(string key);
    
    /*
     * Elimina par key-value
     * Complejidad: O(1) promedio
     * Supuesto: Factor de carga < 0.75, hash equitativo
     */
    void remove(string key);
};

#endif