#include <iostream>
#include <vector>
using namespace std;

/*
 Autor: Diego Martin Lizarraga Sanchez  
 A01647334
 */

// Variable global para contar comparaciones en merge sort
int comparacionesMerge = 0;

/**
 * Ordena un vector usando el algoritmo de inserción
 * Complejidad: O(n²) en el peor caso, O(n) en el mejor caso
 * @param arreglo: vector a ordenar por referencia
 * @return: número de comparaciones realizadas para determinar intercambios
 */
int ordenaInsercion(vector<int>& arreglo) {
    int comparaciones = 0;
    int tamanio = arreglo.size();
    
    for (int i = 1; i < tamanio; i++) {
        int valorActual = arreglo[i];
        int j = i - 1;
        
        // Contar comparaciones para determinar si hacer intercambio
        while (j >= 0) {
            comparaciones++;
            if (arreglo[j] > valorActual) {
                arreglo[j + 1] = arreglo[j];
                j--;
            } else {
                break;
            }
        }
        arreglo[j + 1] = valorActual;
    }
    return comparaciones;
}

/**
 * Ordena un vector usando el algoritmo burbuja
 * Complejidad: O(n²)
 * @param arreglo: vector a ordenar por referencia
 * @return: número de comparaciones realizadas para determinar intercambios
 */
int ordenaBurbuja(vector<int>& arreglo) {
    int comparaciones = 0;
    int tamanio = arreglo.size();
    
    for (int i = 0; i < tamanio - 1; i++) {
        bool huboCambio = false;
        for (int j = 0; j < tamanio - i - 1; j++) {
            // Contar comparaciones para determinar si hacer intercambio
            comparaciones++;
            if (arreglo[j] > arreglo[j + 1]) {
                swap(arreglo[j], arreglo[j + 1]);
                huboCambio = true;
            }
        }
        if (!huboCambio) {
            break;
        }
    }
    return comparaciones;
}

/**
 * Función auxiliar para mezclar dos subarreglos ordenados
 * @param arreglo: vector original
 * @param izquierda: índice izquierdo del subarreglo
 * @param medio: índice medio que separa los dos subarreglos
 * @param derecha: índice derecho del subarreglo
 */
void mezcla(vector<int>& arreglo, int izquierda, int medio, int derecha) {
    int tamanioIzq = medio - izquierda + 1;
    int tamanioDer = derecha - medio;
    
    vector<int> arregloIzq(tamanioIzq);
    vector<int> arregloDer(tamanioDer);
    
    // Copiar elementos a arreglos temporales
    for (int i = 0; i < tamanioIzq; i++) {
        arregloIzq[i] = arreglo[izquierda + i];
    }
    for (int j = 0; j < tamanioDer; j++) {
        arregloDer[j] = arreglo[medio + 1 + j];
    }
    
    int indiceIzq = 0;
    int indiceDer = 0;
    int indiceMezcla = izquierda;
    
    // Mezclar los arreglos temporales de vuelta al arreglo original
    while (indiceIzq < tamanioIzq && indiceDer < tamanioDer) {
        comparacionesMerge++; // Comparación para decidir de cuál sublista tomar
        if (arregloIzq[indiceIzq] <= arregloDer[indiceDer]) {
            arreglo[indiceMezcla] = arregloIzq[indiceIzq];
            indiceIzq++;
        } else {
            arreglo[indiceMezcla] = arregloDer[indiceDer];
            indiceDer++;
        }
        indiceMezcla++;
    }
    
    // Copiar elementos restantes del arreglo izquierdo
    while (indiceIzq < tamanioIzq) {
        arreglo[indiceMezcla] = arregloIzq[indiceIzq];
        indiceIzq++;
        indiceMezcla++;
    }
    
    // Copiar elementos restantes del arreglo derecho
    while (indiceDer < tamanioDer) {
        arreglo[indiceMezcla] = arregloDer[indiceDer];
        indiceDer++;
        indiceMezcla++;
    }
}

/**
 * Función recursiva de merge sort
 * @param arreglo: vector a ordenar
 * @param izquierda: índice izquierdo del subarreglo
 * @param derecha: índice derecho del subarreglo
 */
void mergeSortRecursivo(vector<int>& arreglo, int izquierda, int derecha) {
    if (izquierda < derecha) {
        int medio = izquierda + (derecha - izquierda) / 2;
        mergeSortRecursivo(arreglo, izquierda, medio);
        mergeSortRecursivo(arreglo, medio + 1, derecha);
        mezcla(arreglo, izquierda, medio, derecha);
    }
}

/**
 * Ordena un vector usando el algoritmo de mezcla (merge sort)
 * Complejidad: O(n log n)
 * @param arreglo: vector a ordenar por referencia
 * @return: número de comparaciones realizadas entre sublistas
 */
int ordenaMerge(vector<int>& arreglo) {
    comparacionesMerge = 0;
    mergeSortRecursivo(arreglo, 0, arreglo.size() - 1);
    return comparacionesMerge;
}

/**
 * Realiza búsqueda secuencial de un valor en el vector
 * Complejidad: O(n)
 * @param arreglo: vector donde buscar (constante)
 * @param valor: valor a buscar
 * @param comparaciones: referencia para almacenar el número de comparaciones
 * @return: posición del elemento (0-indexed) o -1 si no se encuentra
 */
int busqSecuencial(const vector<int>& arreglo, int valor, int& comparaciones) {
    comparaciones = 0;
    int tamanio = arreglo.size();
    
    for (int i = 0; i < tamanio; i++) {
        comparaciones++; // Comparación para ver si encontró el valor
        if (arreglo[i] == valor) {
            return i;
        }
    }
    return -1;
}

/**
 * Realiza búsqueda binaria de un valor en el vector ordenado
 * Complejidad: O(log n)
 * @param arreglo: vector ordenado donde buscar (constante)
 * @param valor: valor a buscar
 * @param comparaciones: referencia para almacenar el número de comparaciones
 * @return: posición del elemento (0-indexed) o -1 si no se encuentra
 */
int busqBinaria(const vector<int>& arreglo, int valor, int& comparaciones) {
    comparaciones = 0;
    int izquierda = 0;
    int derecha = arreglo.size() - 1;
    
    while (izquierda <= derecha) {
        int medio = izquierda + (derecha - izquierda) / 2;
        
        comparaciones++; // Comparación para ver si encontró el valor
        if (arreglo[medio] == valor) {
            return medio;
        }
        
        comparaciones++; // Comparación para decidir hacia qué lado buscar
        if (arreglo[medio] < valor) {
            izquierda = medio + 1;
        } else {
            derecha = medio - 1;
        }
    }
    return -1;
}

/**
 * Función principal que ejecuta el programa
 * Lee datos, ordena con diferentes algoritmos, cuenta comparaciones
 * y responde consultas de búsqueda
 */
 
 
int main(){
	vector<int> v1, v2, v3;
	int n, dato;
	cin >> n;
	for (int i=0; i<n; i++){
		cin >> dato;
		v1.push_back(dato);
		v2.push_back(dato);
		v3.push_back(dato);
	}
	cout << ordenaInsercion(v1) << " " << ordenaBurbuja(v2) << " " << ordenaMerge(v3) << endl;
	int q, pos;
	int cantBS, cantBB;
	cin >> q;
	for (int i=0; i<q; i++){
		cantBS = 0;
		cantBB = 0;
		cin >> dato;
		pos = busqSecuencial(v1, dato, cantBS);
		pos = busqBinaria(v1, dato, cantBB);
		cout << pos << " " << cantBS << " " << cantBB << endl; 
	}
return 0;	
}
