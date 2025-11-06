/*
Edgar Francisco Arechiga Nuño A01647054
Diego Martín Lizárraga Sánchez A01647334
Aldo Emiliano Galván Gómez A07106914
*/

#ifndef GESTOR_BITACORA_H
#define GESTOR_BITACORA_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "NodoRegistro.h"

using namespace std;

// La clase GestorBitacora gestiona una colección de registros
// de bitácora usando lista enlazada. También logra cargas los logs desde un archivo. 
class GestorBitacora {
private:
    NodoRegistro* head; // Cabeza de la lista enlazada
    NodoRegistro* tail; // Cola de la lista enlazada
    int size; // Tamaño de la lista
    int numeroEquipo; // Indice del equipo nosotros el 3 :D
    int numeroBusqueda; // Contador para los nombres de los archivos finales

    // Uso del algoritmo merge sort para ordenar los registros
    // Complejidad: O(n log n) en todos los casos
    NodoRegistro* mergesort(NodoRegistro* head);
    
    // Divide la lista en dos mitades
    // Complejidad: O(n)
    NodoRegistro* dividirLista(NodoRegistro* head);
    
    // Mezcla dos listas ordenadas en una sola
    // Complejidad: O(n)
    NodoRegistro* mezcla(NodoRegistro* left, NodoRegistro* right);

    // Se comparan dos registros por IP y devuelve true si el primer registro es anterior al segundo registro
    // Complejidad: O(1)
    bool comparar(NodoRegistro* a, NodoRegistro* b); 

    // Parsea una IP en formato string (###.###.###.###) y devuelve los octetos y puerto
    // Complejidad: O(1)
    void parsearIPBusqueda(const string& ipStr, int& oct1, int& oct2, int& oct3, int& oct4, int& port);
    
    // Busca logs en el rango de IPs dados por el usuario usando búsqueda optimizada
    // Complejidad: O(log n + k) donde k es el número de resultados
    // Se detiene cuando encuentra el inicio del rango y cuando pasa el final
    NodoRegistro* buscarEnRangoIP(const string& ipInicio, const string& ipFin);
    
    // Encuentra el primer nodo que cumple con la condición de inicio usando búsqueda binaria
    // Complejidad: O(log n)
    NodoRegistro* buscarInicio(long long valorInicio);
    
    // Convierte la lista enlazada a un vector temporal para búsqueda binaria
    // Complejidad: O(n)
    vector<NodoRegistro*> listaAVector();
    
public:
    GestorBitacora(); // Constructor
    ~GestorBitacora(); // Destructor

    // Carga los archivos de texto - Complejidad: O(n)
    bool cargarArchivo(const string& nombreArchivo);
    
    // Se establece el numero de la cantidad de archivos de busqueda para los archivos de salida
    void setNumeroBusqueda(int numero);
    
    // Obtiene el numero de busqueda 
    int getNumeroBusqueda() const;
    
    // Ordena los registros - Complejidad: O(n log n)
    void ordenar();
    
    // Ordena el archivo "bitacoraOrdenada1.3-eq<numeroEquipo>.txt" - Complejidad: O(n)
    void guardarOrdenado();
    
    // Guarda los resultados de la busqueda en el archivo resultado - Complejidad: O(k) donde k es número de resultados
    void guardarResultados(NodoRegistro* resultados, int numeroSalida);
    
    // Menu de solicitud de IP inicial y final para buscar registros - Complejidad: O(log n + k)
    void realizarBusquedaIP();
    

    //ta muy variado a ver si no toca meter mas
};

#endif