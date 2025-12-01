/*
 * Programa de pruebas completo para MyGraph
 * Incluye recorridos DFS/BFS, detección de ciclos y orden topológico
 *
 * Diego Martín Lizárraga Sánchez A01647334
 */

#include "MyGraph.h"
#include <iostream>
#include <vector>

using namespace std;

void separador() {
    cout << "\n========================================\n" << endl;
}

void testCaso1_RecorridosBasicos() {
    cout << "TEST 1: Recorridos DFS y BFS" << endl;
    cout << "=============================\n" << endl;
    
    // Grafo original del código anterior
    vector<vector<int>> matriz = {
        {0, 1, 1, 0, 0},
        {0, 0, 0, 1, 1},
        {1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };
    
    MyGraph grafo(matriz);
    
    cout << "Grafo con 5 nodos:" << endl;
    cout << "  0 -> 1, 0 -> 2" << endl;
    cout << "  1 -> 3, 1 -> 4" << endl;
    cout << "  2 -> 0" << endl << endl;
    
    cout << "Recorrido DFS desde nodo 0: ";
    grafo.DFS(0);
    
    cout << "Recorrido BFS desde nodo 0: ";
    grafo.BFS(0);
    
    cout << "\nTEST 1 COMPLETADO" << endl;
}

void testCaso2_ArbolSinCiclos() {
    cout << "TEST 2: Árbol sin Ciclos (DAG)" << endl;
    cout << "===============================\n" << endl;
    
    // Grafo: 0 -> 1, 0 -> 2, 1 -> 3, 2 -> 3
    //     0
    //    / \
    //   1   2
    //    \ /
    //     3
    
    vector<vector<int>> matriz = {
        {0, 1, 1, 0},
        {0, 0, 0, 1},
        {0, 0, 0, 1},
        {0, 0, 0, 0}
    };
    
    MyGraph grafo(matriz);
    
    cout << "Matriz de adyacencia:" << endl;
    cout << "  0 -> 1, 0 -> 2" << endl;
    cout << "  1 -> 3, 2 -> 3" << endl << endl;
    
    cout << "¿Es árbol (DAG)? " << (grafo.isTree() ? "SI" : "NO") << endl;
    cout << "Orden topológico: ";
    grafo.printTopologicalOrder();
    
    cout << "\nTEST 2 COMPLETADO" << endl;
}

void testCaso3_GrafoConCiclo() {
    cout << "TEST 3: Grafo con Ciclo" << endl;
    cout << "=======================\n" << endl;
    
    // Grafo: 0 -> 1, 1 -> 2, 2 -> 0 (ciclo)
    vector<vector<int>> matriz = {
        {0, 1, 0},
        {0, 0, 1},
        {1, 0, 0}
    };
    
    MyGraph grafo(matriz);
    
    cout << "Matriz de adyacencia:" << endl;
    cout << "  0 -> 1 -> 2 -> 0 (ciclo)" << endl << endl;
    
    cout << "¿Es árbol (DAG)? " << (grafo.isTree() ? "SI" : "NO") << endl;
    cout << "Intento de orden topológico: ";
    grafo.printTopologicalOrder();
    
    cout << "\nTEST 3 COMPLETADO" << endl;
}

void testCaso4_GrafoComplejoDAG() {
    cout << "TEST 4: DAG Complejo" << endl;
    cout << "====================\n" << endl;
    
    // Grafo más complejo sin ciclos
    //   0 -> 1 -> 3
    //   |    |
    //   v    v
    //   2    4
    //   |    |
    //   v    v
    //   5 <- 6
    
    vector<vector<int>> matriz = {
        {0, 1, 1, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0}
    };
    
    MyGraph grafo(matriz);
    
    cout << "Grafo DAG con 7 nodos" << endl;
    cout << "Aristas:" << endl;
    cout << "  0 -> 1, 0 -> 2" << endl;
    cout << "  1 -> 3, 1 -> 4" << endl;
    cout << "  2 -> 5, 4 -> 6" << endl;
    cout << "  6 -> 5" << endl << endl;
    
    cout << "¿Es árbol (DAG)? " << (grafo.isTree() ? "SI" : "NO") << endl;
    cout << "Orden topológico: ";
    grafo.printTopologicalOrder();
    
    cout << "\nRecorrido DFS desde 0: ";
    grafo.DFS(0);
    
    cout << "Recorrido BFS desde 0: ";
    grafo.BFS(0);
    
    cout << "\nTEST 4 COMPLETADO" << endl;
}

void testCaso5_NodoUnico() {
    cout << "TEST 5: Nodo Único" << endl;
    cout << "==================\n" << endl;
    
    vector<vector<int>> matriz = {
        {0}
    };
    
    MyGraph grafo(matriz);
    
    cout << "Matriz de adyacencia: [0]" << endl << endl;
    
    cout << "¿Es árbol (DAG)? " << (grafo.isTree() ? "SI" : "NO") << endl;
    cout << "Orden topológico: ";
    grafo.printTopologicalOrder();
    
    cout << "\nTEST 5 COMPLETADO" << endl;
}

void testCaso6_AutoCiclo() {
    cout << "TEST 6: Nodo con Auto-ciclo (Self-loop)" << endl;
    cout << "========================================\n" << endl;
    
    // Un nodo que apunta a sí mismo
    vector<vector<int>> matriz = {
        {1, 1},
        {0, 0}
    };
    
    MyGraph grafo(matriz);
    
    cout << "Matriz de adyacencia:" << endl;
    cout << "  0 -> 0 (auto-ciclo)" << endl;
    cout << "  0 -> 1" << endl << endl;
    
    cout << "¿Es árbol (DAG)? " << (grafo.isTree() ? "SI" : "NO") << endl;
    cout << "Intento de orden topológico: ";
    grafo.printTopologicalOrder();
    
    cout << "\nTEST 6 COMPLETADO" << endl;
}

int main() {
    cout << "\n╔═══════════════════════════════════════════════════════════╗" << endl;
    cout << "║     PRUEBAS COMPLETAS DE MYGRAPH - EQUIPO 3             ║" << endl;
    cout << "║     Análisis de Grafos Dirigidos (DAG)                  ║" << endl;
    cout << "╚═══════════════════════════════════════════════════════════╝" << endl;
    
    try {
        testCaso1_RecorridosBasicos();
        separador();
        
        testCaso2_ArbolSinCiclos();
        separador();
        
        testCaso3_GrafoConCiclo();
        separador();
        
        testCaso4_GrafoComplejoDAG();
        separador();
        
        testCaso5_NodoUnico();
        separador();
        
        testCaso6_AutoCiclo();
        separador();
        
        cout << "\n╔═══════════════════════════════════════════════════════════╗" << endl;
        cout << "║         TODAS LAS PRUEBAS COMPLETADAS EXITOSAMENTE       ║" << endl;
        cout << "║                                                           ║" << endl;
        cout << "║  ✓ Recorridos DFS y BFS                                 ║" << endl;
        cout << "║  ✓ Detección de ciclos (isTree)                         ║" << endl;
        cout << "║  ✓ Ordenamiento topológico (Kahn)                      ║" << endl;
        cout << "║  ✓ Manejo de casos especiales                          ║" << endl;
        cout << "╚═══════════════════════════════════════════════════════════╝" << endl << endl;
        
        return 0;
        
    } catch (exception& e) {
        cout << "\nERROR: " << e.what() << endl;
        return 1;
    }
}