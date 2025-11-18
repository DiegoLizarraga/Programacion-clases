/*
 * Versión modificada de MyNodoLL para tabla hash
 * Almacena pares (string key, int value)
 */

#ifndef MYNODOLL_HASHPAIR_H
#define MYNODOLL_HASHPAIR_H

#include <string>
using namespace std;

// Estructura para almacenar pares key-value
struct HashPair {
    string key;
    int value;
    
    HashPair(string k = "", int v = 0) : key(k), value(v) {}
};

// Nodo modificado para tabla hash
struct MyNodoLL {
    HashPair data;        // Cambiado de int a HashPair
    MyNodoLL* next;

    MyNodoLL(HashPair data, MyNodoLL* next) {
        this->data = data;
        this->next = next;
    }

    MyNodoLL(HashPair data) : MyNodoLL(data, nullptr) {}
    
    // Constructor alternativo para facilidad
    MyNodoLL(string key, int value) : MyNodoLL(HashPair(key, value), nullptr) {}
};

#endif