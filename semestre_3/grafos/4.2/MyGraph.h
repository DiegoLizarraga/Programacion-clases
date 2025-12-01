/*
 * Clase para analisis de grafos dirigidos (DAG y orden topológico)
 * Diego Martín Lizárraga Sánchez A01647334
 */

#ifndef MYGRAPH_H
#define MYGRAPH_H

#include <vector>
#include <iostream>

using namespace std;

class MyGraph {
private:
    vector<vector<int>> matriz;
    int numVertices;
    
    // Método auxiliar para DFS - detecta ciclos
    void DFSUtil(int nodo, vector<bool>& visited);
    void DFSUtilCiclo(int nodo, vector<int>& estado, bool& tieneCiclo);
    
public:
    /*
     * Constructor que recibe una matriz de adyacencia
     * Complejidad: O(V²)
     */
    MyGraph(vector<vector<int>>& matriz);
    
    /*
     * Carga el grafo en la matriz de adyacencia
     * Complejidad: O(V²)
     */
    void loadGraph(vector<vector<int>>& matriz);
    
    /*
     * Recorrido DFS desde un nodo inicial
     * Complejidad: O(V + E)
     */
    void DFS(int nodoInicial);
    
    /*
     * Recorrido BFS desde un nodo inicial
     * Complejidad: O(V + E)
     */
    void BFS(int nodoInicial);
    
    /*
     * Determina si el grafo es un árbol (DAG sin ciclos)
     * Retorna: true si es un árbol, false si tiene ciclos
     * Complejidad: O(V + E)
     * Precondición: El grafo debe estar correctamente cargado
     */
    bool isTree();
    
    /*
     * Realiza ordenamiento topológico usando algoritmo de Kahn
     * Retorna: vector con el orden topológico de los nodos
     * Complejidad: O(V + E)
     * Precondición: El grafo debe ser un DAG (sin ciclos)
     */
    vector<int> topologicalSort();
    
    /*
     * Imprime el orden topológico en formato ascendente
     * Formato: nodo1,nodo2,nodo3,...,nodoN
     * Complejidad: O(V)
     */
    void printTopologicalOrder();
};

#endif