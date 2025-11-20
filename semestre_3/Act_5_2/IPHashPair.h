/*
 * IPHashPair.h
 * Estructura para almacenar pares clave-valor en la tabla hash
 * 
 * Equipo 3:
 * Edgar Francisco Arechiga Nuño A01647054
 * Diego Martín Lizárraga Sánchez A01647334
 * Aldo Emiliano Galván Gómez A07106914
 */

#ifndef IPHASHPAIR_H
#define IPHASHPAIR_H

#include <string>
#include "IPRecord.h"

using namespace std;

struct IPHashPair {
    string key;        // IP sin puerto
    IPRecord value;    // Registro completo de la IP
    
    // Constructor por defecto
    IPHashPair() : key(""), value(IPRecord()) {}
    
    // Constructor con parámetros
    IPHashPair(string k, IPRecord v) : key(k), value(v) {}
};

#endif