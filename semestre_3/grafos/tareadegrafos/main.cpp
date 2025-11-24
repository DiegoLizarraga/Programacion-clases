#include "MyGraph.h"
#include <iostream>
#include <vector>

using namespace std;
//Diego Martin Lizarraga Sanchez A01647334

int main() {
    // Ejemplo de matriz de adyacencia
    // Grafo de ejemplo con 5 nodos (0-4)
    //
    //     0
    //    / \
    //   1   2
    //  / \   \
    // 3   4   (vuelve a 0)
    //
    // Matriz de adyacencia 5x5:
    vector<vector<int>> matriz = {
        {0, 1, 1, 0, 0},  // Nodo 0 conectado a 1 y 2
        {0, 0, 0, 1, 1},  // Nodo 1 conectado a 3 y 4
        {1, 0, 0, 0, 0},  // Nodo 2 conectado a 0
        {0, 0, 0, 0, 0},  // Nodo 3 sin conexiones salientes
        {0, 0, 0, 0, 0}   // Nodo 4 sin conexiones salientes
    };
    
    // Instanciar el grafo con la matriz creada previamente
    MyGraph grafo(matriz);
    
    // Imprimir recorrido DFS iniciando desde el nodo 0
    grafo.DFS(0);
    
    // Imprimir recorrido BFS iniciando desde el nodo 0
    grafo.BFS(0);
    
    return 0;
}

