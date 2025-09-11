#include <iostream>
#include <vector>
using namespace std;

/*
 Autor: Diego Martin Lizarraga Sanchez
 A01647334
 Fecha: 10 de septiembre de 2025
 */

// Variable global para contar comparaciones en merge sort
int comparacionesMerge = 0;

/*
 Intercambia dos elementos del vector
 */
void intercambiar(vector<int>& arreglo, int i, int j) {
    int auxiliar = arreglo[i];
    arreglo[i] = arreglo[j];
    arreglo[j] = auxiliar;
}

/*
 Ordena un vector usando el algoritmo de inserción
 Complejidad: O(n²) en el peor caso, O(n) en el mejor caso
 */
int ordenaInsercion(vector<int>& arreglo) {
    int comparaciones = 0;
    int tamanio = arreglo.size();
    
    for (int i = 1; i < tamanio; i++) {
        for (int j = i - 1; j >= 0; j--) {
            comparaciones++; // Comparación para ver si debe hacer intercambio
            if (arreglo[j] > arreglo[j + 1]) {
                intercambiar(arreglo, j, j + 1);
            } else {
                break; // Si ya está en orden, salir del ciclo
            }
        }
    }
    return comparaciones;
}

/**
 Ordena un vector usando el algoritmo burbuja
 Complejidad: O(n²)
 */
int ordenaBurbuja(vector<int>& arreglo) {
    int comparaciones = 0;
    int tamanio = arreglo.size();
    bool ordenados = false;
    
    for (int i = 0; i < tamanio - 1 && !ordenados; i++) {
        ordenados = true;
        for (int j = 0; j < tamanio - i - 1; j++) {
            comparaciones++; // Comparación para determinar si hacer intercambio
            if (arreglo[j] > arreglo[j + 1]) {
                intercambiar(arreglo, j, j + 1);
                ordenados = false;
            }
        }
    }
    return comparaciones;
}

/*
 Función auxiliar para mezclar dos subarreglos ordenados
 */
void mezcla(vector<int>& arreglo, int inicio, int medio, int fin) {
    int tamanioIzq = medio - inicio + 1;
    int tamanioDer = fin - medio;
    
    vector<int> arregloIzquierdo(tamanioIzq);
    vector<int> arregloDerecho(tamanioDer);
    
    // Copiar elementos a arreglos temporales
    for (int i = 0; i < tamanioIzq; i++) {
        arregloIzquierdo[i] = arreglo[inicio + i];
    }
    for (int j = 0; j < tamanioDer; j++) {
        arregloDerecho[j] = arreglo[medio + 1 + j];
    }
    
    int indiceIzq = 0;
    int indiceDer = 0;
    int indiceMezcla = inicio;
    
    // Mezclar los arreglos temporales de vuelta al arreglo original
    // Solo contar comparaciones mientras ambas sublistas tienen elementos
    while (indiceIzq < tamanioIzq && indiceDer < tamanioDer) {
        comparacionesMerge++; // Comparación para decidir de cuál sublista tomar
        if (arregloIzquierdo[indiceIzq] <= arregloDerecho[indiceDer]) {
            arreglo[indiceMezcla] = arregloIzquierdo[indiceIzq];
            indiceIzq++;
        } else {
            arreglo[indiceMezcla] = arregloDerecho[indiceDer];
            indiceDer++;
        }
        indiceMezcla++;
    }
    
    // Copiar elementos restantes (sin comparaciones adicionales)
    while (indiceIzq < tamanioIzq) {
        arreglo[indiceMezcla] = arregloIzquierdo[indiceIzq];
        indiceIzq++;
        indiceMezcla++;
    }
    while (indiceDer < tamanioDer) {
        arreglo[indiceMezcla] = arregloDerecho[indiceDer];
        indiceDer++;
        indiceMezcla++;
    }
}

/*
 Función recursiva de merge sort
 */
void mergeSortRecursivo(vector<int>& arreglo, int inicio, int fin) {
    if (inicio < fin) {
        int medio = (inicio + fin) / 2;
        mergeSortRecursivo(arreglo, inicio, medio);
        mergeSortRecursivo(arreglo, medio + 1, fin);
        mezcla(arreglo, inicio, medio, fin);
    }
}

/*
 Ordena un vector usando el algoritmo de mezcla (merge sort)
 Complejidad: O(n log n)
 */
int ordenaMerge(vector<int>& arreglo) {
    comparacionesMerge = 0;
    mergeSortRecursivo(arreglo, 0, arreglo.size() - 1);
    return comparacionesMerge;
}

/*
 Realiza búsqueda secuencial de un valor en el vector
 Complejidad: O(n)
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

/*
 Realiza búsqueda binaria de un valor en el vector ordenado
 Complejidad: O(log n)
 */
int busqBinaria(const vector<int>& arreglo, int valor, int& comparaciones) {
    comparaciones = 0;
    int izquierda = 0;
    int derecha = arreglo.size() - 1;
    
    while (izquierda <= derecha) {
        int medio = (izquierda + derecha) / 2;
        
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
