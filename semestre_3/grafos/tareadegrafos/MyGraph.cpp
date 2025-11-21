#include "MyGraph.h"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
 * Constructor del grafo
 * Complejidad: O(V²) por la copia de la matriz
 */
MyGraph::MyGraph(vector<vector<int>>& matriz) {
    loadGraph(matriz);
}

/*
 * Carga el grafo en la matriz de adyacencia
 * Complejidad: O(V²) donde V = número de vértices
 */
void MyGraph::loadGraph(vector<vector<int>>& matriz) {
    this->matriz = matriz;
}

/*
 * Función auxiliar recursiva para DFS
 * Complejidad: O(V + E)
 * 
 * Algoritmo:
 * 1. Marcar nodo actual como visitado
 * 2. Imprimir nodo actual
 * 3. Explorar recursivamente todos los vecinos no visitados
 * 
 */
void MyGraph::DFSUtil(int nodo, vector<bool>& visited) {
    // Marcar el nodo actual como visitado
    visited[nodo] = true;
    cout << nodo;
    
    // Recorrer todos los vértices adyacentes
    int n = matriz.size();
    bool primero = true;
    
    for (int i = 0; i < n; i++) {
        // Si hay arista (matriz[nodo][i] == 1) y no ha sido visitado
        if (matriz[nodo][i] == 1 && !visited[i]) {
            cout << ",";
            DFSUtil(i, visited);
            primero = false;
        }
    }
}

/*
 * Recorrido DFS (Depth-First Search / Profundidad)
 * Complejidad: O(V + E) donde V = vértices, E = aristas
 * 
 * Algoritmo:
 * 1. Inicializar todos los nodos como no visitados
 * 2. Llamar a DFSUtil desde el nodo inicial
 */
void MyGraph::DFS(int nodoInicial) {
    int n = matriz.size();
    vector<bool> visited(n, false);
    
    // Iniciar DFS desde el nodo inicial
    DFSUtil(nodoInicial, visited);
    cout << endl;
}

/*
 * Función auxiliar iterativa para BFS usando cola
 * Complejidad: O(V + E)
 * 
 * Algoritmo:
 * 1. Crear una cola y encolar el nodo inicial
 * 2. Marcar nodo inicial como visitado
 * 3. Mientras la cola no esté vacía:
 *    a. Desencolar un nodo
 *    b. Imprimir el nodo
 *    c. Encolar todos sus vecinos no visitados
 * 
 */
void MyGraph::BFSUtil(int nodo, vector<bool>& visited) {
    int n = matriz.size();
    queue<int> cola;
    
    // Marcar el nodo inicial como visitado y encolarlo
    visited[nodo] = true;
    cola.push(nodo);
    
    bool primero = true;
    
    while (!cola.empty()) {
        // Desencolar un vértice
        int actual = cola.front();
        cola.pop();
        
        // Imprimir el nodo actual
        if (!primero) {
            cout << ",";
        }
        cout << actual;
        primero = false;
        
        // Obtener todos los vértices adyacentes no visitados
        for (int i = 0; i < n; i++) {
            if (matriz[actual][i] == 1 && !visited[i]) {
                visited[i] = true;
                cola.push(i);
            }
        }
    }
}

/*
 * Recorrido BFS (Breadth-First Search / Anchura)
 * Complejidad: O(V + E) donde V = vértices, E = aristas
 * 
 * @param nodoInicial: Nodo desde el cual iniciar el recorrido
 */
void MyGraph::BFS(int nodoInicial) {
    int n = matriz.size();
    vector<bool> visited(n, false);
    
    // Iniciar BFS desde el nodo inicial
    BFSUtil(nodoInicial, visited);
    cout << endl;
}

/*
 * ANÁLISIS DE COMPLEJIDADES
 * ==========================
 * 
 * DFS (Depth-First Search):
 * - Complejidad Temporal: O(V + E)
 *   * V = número de vértices (cada vértice se visita una vez)
 *   * E = número de aristas (cada arista se examina una vez)
 * - Complejidad Espacial: O(V)
 *   * Vector visited: O(V)
 *   * Pila de recursión: O(V) en el peor caso (grafo lineal)
 * 
 * BFS (Breadth-First Search):
 * - Complejidad Temporal: O(V + E)
 *   * V = número de vértices (cada vértice se visita una vez)
 *   * E = número de aristas (cada arista se examina una vez)
 * - Complejidad Espacial: O(V)
 *   * Vector visited: O(V)
 *   * Cola: O(V) en el peor caso (todos los nodos en un nivel)
 * 
 * loadGraph():
 * - Complejidad Temporal: O(V²)
 *   * Copia de matriz de adyacencia V×V
 * - Complejidad Espacial: O(V²)
 *   * Almacenamiento de la matriz
 * 
 * NOTA: Para matriz de adyacencia, examinar todos los vecinos
 * de un nodo requiere O(V), por lo que la complejidad real es O(V²)
 * en algunos casos, pero se expresa como O(V + E) considerando que
 * E puede ser hasta V².
 */