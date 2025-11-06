/*
Edgar Francisco Arechiga Nuño A01647054
Diego Martín Lizárraga Sánchez A01647334
Aldo Emiliano Galván Gómez A07106914
*/

#ifndef NODO_REGISTRO_H
#define NODO_REGISTRO_H

#include <iostream>
#include <string>
#include <sstream>
#include <map>

using namespace std;

// Nodo para la lista enlazada de registros
struct NodoRegistro {
    string mes; 
    int dia;
    string hora;
    string ip;
    int octeto1, octeto2, octeto3, octeto4;
    int puerto;
    string razon;
    string lineaCompleta;
    int mesNumerico;
    NodoRegistro* next;
    
    NodoRegistro(const string& linea, NodoRegistro* next = nullptr);
    
    // Función auxiliar para obtener el valor compuesto de IP para comparaciones
    long long getValorIP() const;
};

#endif