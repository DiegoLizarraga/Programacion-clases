
/* IPHashTable.h
 * Tabla hash con encadenamiento para almacenar registros de IPs
 * 
 * Equipo 3:
 * Edgar Francisco Arechiga Nuño A01647054
 * Diego Martín Lizárraga Sánchez A01647334
 * Aldo Emiliano Galván Gómez A07106914
 */

#ifndef IPHASHTABLE_H
#define IPHASHTABLE_H

#include <string>
#include <functional>
#include "IPLinkedList.h"

using namespace std;

class IPHashTable {
public:
    IPLinkedList* tabla;
    int size;
    int sizeA;
    
    // Constructor - Tamaño inicial 11 (primo)
    // Complejidad: O(1)
    IPHashTable();
    
    // Destructor
    // Complejidad: O(n + m)
    ~IPHashTable();
    
    // Calcula posición usando función hash
    // Complejidad: O(1)
    int getPos(string key);
    
    // Verifica si está vacía
    // Complejidad: O(1)
    bool isEmpty();
    
    // Inserta o actualiza un registro de IP
    // Complejidad: O(1) promedio
    void put(string key, IPRecord value);
    
    // Obtiene el registro de una IP
    // Complejidad: O(1) promedio
    // Retorna nullptr si no existe
    IPRecord* get(string key);
    
    // Verifica si existe una IP
    // Complejidad: O(1) promedio
    bool contains(string key);
    
    // Obtiene el número de elementos
    // Complejidad: O(1)
    int getSize() const;
    
private:
    // Rehashing - duplica tamaño y redistribuye
    // Complejidad: O(n)
    void rehashing();
};

#endif

