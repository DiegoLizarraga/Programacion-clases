/*
 * Implementación de análisis de grafos dirigido
 * Diego Martín Lizárraga Sánchez A01647334
 */

#include "MyGraph.h"
#include <queue>
#include <algorithm>

using namespace std;

/*
 * Constructor que recibe una matriz de adyacencia
 * Complejidad: O(V²)
 */
MyGraph::MyGraph(vector<vector<int>>& matriz) {
    loadGraph(matriz);
    this->numVertices = matriz.size();
}

/*
 * Carga el grafo en la matriz de adyacencia
 * Complejidad: O(V²) donde V = número de vértices
 */
void MyGraph::loadGraph(vector<vector<int>>& matriz) {
    this->matriz = matriz;
    this->numVertices = matriz.size();
}

/*
 * Función auxiliar recursiva para DFS (recorrido básico)
 * Complejidad: O(V + E)
 */
void MyGraph::DFSUtil(int nodo, vector<bool>& visited) {
    visited[nodo] = true;
    cout << nodo;
    
    int n = matriz.size();
    bool primero = true;
    
    for (int i = 0; i < n; i++) {
        if (matriz[nodo][i] == 1 && !visited[i]) {
            cout << ",";
            DFSUtil(i, visited);
            primero = false;
        }
    }
}

/*
 * Recorrido DFS (Depth-First Search)
 * Complejidad: O(V + E)
 */
void MyGraph::DFS(int nodoInicial) {
    int n = matriz.size();
    vector<bool> visited(n, false);
    DFSUtil(nodoInicial, visited);
    cout << endl;
}

/*
 * Función auxiliar iterativa para BFS usando cola
 * Complejidad: O(V + E)
 */
void MyGraph::BFS(int nodoInicial) {
    int n = matriz.size();
    vector<bool> visited(n, false);
    queue<int> cola;
    
    visited[nodoInicial] = true;
    cola.push(nodoInicial);
    
    bool primero = true;
    
    while (!cola.empty()) {
        int actual = cola.front();
        cola.pop();
        
        if (!primero) {
            cout << ",";
        }
        cout << actual;
        primero = false;
        
        for (int i = 0; i < n; i++) {
            if (matriz[actual][i] == 1 && !visited[i]) {
                visited[i] = true;
                cola.push(i);
            }
        }
    }
    cout << endl;
}

/*
 * Función auxiliar DFS para detectar ciclos
 * Usa 3 estados:
 * - 0: No visitado
 * - 1: Visitado (en proceso, en la pila de recursión)
 * - 2: Completamente procesado
 * 
 * Complejidad: O(V + E)
 * Si encuentra un nodo en estado 1, hay ciclo
 */
void MyGraph::DFSUtilCiclo(int nodo, vector<int>& estado, bool& tieneCiclo) {
    estado[nodo] = 1;  // Marcamos como en proceso
    
    for (int i = 0; i < numVertices; i++) {
        if (matriz[nodo][i] == 1) {
            if (estado[i] == 1) {
                // Encontramos un ciclo (back edge)
                tieneCiclo = true;
                return;
            }
            if (estado[i] == 0) {
                DFSUtilCiclo(i, estado, tieneCiclo);
                if (tieneCiclo) return;
            }
        }
    }
    
    estado[nodo] = 2;  // Marcamos como completamente procesado
}

/*
 * Determina si el grafo es un árbol (DAG sin ciclos)
 * 
 * Un grafo es un árbol si:
 * 1. No tiene ciclos (es un DAG)
 * 
 * Complejidad: O(V + E)
 * Retorna: true si no hay ciclos, false si los hay
 * 
 * Algoritmo:
 * Usa DFS con 3 estados para detectar back edges (ciclos)
 */
bool MyGraph::isTree() {
    vector<int> estado(numVertices, 0);  // 0: no visitado, 1: en proceso, 2: hecho
    bool tieneCiclo = false;
    
    // Ejecutar DFS desde cada nodo no visitado
    for (int i = 0; i < numVertices; i++) {
        if (estado[i] == 0) {
            DFSUtilCiclo(i, estado, tieneCiclo);
            if (tieneCiclo) {
                return false;
            }
        }
    }
    
    return true;  // No hay ciclos, es un DAG
}

/*
 * Ordenamiento topológico usando Algoritmo de Kahn
 * 
 * Complejidad: O(V + E)
 * 
 * Algoritmo:
 * 1. Calcular grado de entrada para cada vértice
 * 2. Encolar todos los vértices con grado de entrada 0
 * 3. Mientras la cola no esté vacía:
 *    - Desencolar vértice V
 *    - Agregarlo al resultado
 *    - Para cada vértice W adyacente a V:
 *      * Decrementar grado de entrada de W
 *      * Si grado de W es 0, encolarlo
 * 4. Si resultado no contiene todos los vértices, hay ciclos
 * 
 * Precondición: El grafo es un DAG (sin ciclos)
 * Postcondición: Retorna vector con orden topológico
 */
vector<int> MyGraph::topologicalSort() {
    vector<int> resultado;
    
    // Verificar si es un DAG (sin ciclos)
    if (!isTree()) {
        return resultado;  // Retornar vacío si hay ciclos
    }
    
    // Calcular grado de entrada para cada vértice
    vector<int> inDegree(numVertices, 0);
    
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            if (matriz[i][j] == 1) {
                inDegree[j]++;
            }
        }
    }
    
    // Crear cola y enqueue todos los vértices con grado de entrada 0
    queue<int> cola;
    for (int i = 0; i < numVertices; i++) {
        if (inDegree[i] == 0) {
            cola.push(i);
        }
    }
    
    // Procesar vértices en orden topológico
    while (!cola.empty()) {
        int nodo = cola.front();
        cola.pop();
        resultado.push_back(nodo);
        
        // Reducir grado de entrada de nodos adyacentes
        for (int i = 0; i < numVertices; i++) {
            if (matriz[nodo][i] == 1) {
                inDegree[i]--;
                if (inDegree[i] == 0) {
                    cola.push(i);
                }
            }
        }
    }
    
    // Verificar si todos los vértices fueron procesados
    if (resultado.size() != numVertices) {
        resultado.clear();
    }
    
    return resultado;
}

/*
 * Imprime el orden topológico en formato ascendente
 * 
 * Complejidad: O(V + E) por topologicalSort() + O(V) por impresión
 * 
 * Formato: nodo1,nodo2,nodo3,...,nodoN (sin espacios)
 */
void MyGraph::printTopologicalOrder() {
    vector<int> orden = topologicalSort();
    
    if (orden.empty()) {
        cout << "El grafo contiene ciclos, no se puede ordenar topologicamente." << endl;
        return;
    }
    
    for (int i = 0; i < orden.size(); i++) {
        if (i > 0) cout << ",";
        cout << orden[i];
    }
    cout << endl;
}

/*
 * ANÁLISIS DE COMPLEJIDADES
 * ==========================
 * 
 * loadGraph():            O(V²) - Copia de matriz
 * 
 * DFS(nodo):              O(V + E)
 *   - Visita cada vértice una vez
 *   - Examina cada arista una vez
 * 
 * BFS(nodo):              O(V + E)
 *   - Usa cola para recorrer por niveles
 *   - Visita cada vértice una vez
 * 
 * isTree():               O(V + E)
 *   - DFS con detección de ciclos
 *   - Detecta back edges en O(V + E)
 * 
 * topologicalSort():      O(V + E)
 *   - isTree(): O(V + E)
 *   - Calcular inDegree: O(V + E)
 *   - Procesar cola: O(V + E)
 *   - Total: O(V + E)
 * 
 * printTopologicalOrder(): O(V + E)
 *   - Llamar topologicalSort: O(V + E)
 *   - Imprimir resultado: O(V)
 */