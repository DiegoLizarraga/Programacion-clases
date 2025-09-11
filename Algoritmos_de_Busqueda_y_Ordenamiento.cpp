#include <iostream>
#include <vector>
using namespace std;

/*
 * Matrícula: [TU_MATRÍCULA]
 * Nombre: [TU_NOMBRE]
 * 
 * Programa que implementa algoritmos de ordenamiento y búsqueda
 * contando las comparaciones específicas de cada algoritmo.
 */

/**
 * Ordenamiento por inserción
 * Complejidad: O(n²) en el peor caso, O(n) en el mejor caso
 * @param arr: vector a ordenar
 * @return: número de comparaciones realizadas
 */
int ordenaInsercion(vector<int>& arr) {
    int comparaciones = 0;
    int n = arr.size();
    
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        // Contar comparaciones para determinar si hacer intercambio
        while (j >= 0 && (++comparaciones, arr[j] > key)) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    return comparaciones;
}

/**
 * Ordenamiento burbuja
 * Complejidad: O(n²)
 * @param arr: vector a ordenar
 * @return: número de comparaciones realizadas
 */
int ordenaBurbuja(vector<int>& arr) {
    int comparaciones = 0;
    int n = arr.size();
    
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            // Contar comparaciones para determinar si hacer intercambio
            comparaciones++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
    return comparaciones;
}

// Variable global para contar comparaciones en merge sort
int comparacionesMerge = 0;

/**
 * Función auxiliar para mezclar dos subarreglos
 * @param arr: vector original
 * @param left: índice izquierdo
 * @param mid: índice medio
 * @param right: índice derecho
 */
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    vector<int> leftArr(n1), rightArr(n2);
    
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];
    
    int i = 0, j = 0, k = left;
    
    // Contar comparaciones mientras ambas sublistas tienen elementos
    while (i < n1 && j < n2) {
        comparacionesMerge++; // Comparación para decidir de cuál sublista tomar
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    
    // Copiar elementos restantes (sin comparaciones adicionales)
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

/**
 * Función recursiva de merge sort
 * @param arr: vector a ordenar
 * @param left: índice izquierdo
 * @param right: índice derecho
 */
void mergeSortRecursive(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSortRecursive(arr, left, mid);
        mergeSortRecursive(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

/**
 * Ordenamiento por mezcla
 * Complejidad: O(n log n)
 * @param arr: vector a ordenar
 * @return: número de comparaciones realizadas
 */
int ordenaMerge(vector<int>& arr) {
    comparacionesMerge = 0;
    mergeSortRecursive(arr, 0, arr.size() - 1);
    return comparacionesMerge;
}

/**
 * Búsqueda secuencial
 * Complejidad: O(n)
 * @param arr: vector donde buscar
 * @param valor: valor a buscar
 * @param comparaciones: referencia para contar comparaciones
 * @return: posición del elemento o -1 si no se encuentra
 */
int busqSecuencial(const vector<int>& arr, int valor, int& comparaciones) {
    comparaciones = 0;
    for (int i = 0; i < arr.size(); i++) {
        comparaciones++; // Comparación para ver si encontró el valor
        if (arr[i] == valor) {
            return i;
        }
    }
    return -1;
}

/**
 * Búsqueda binaria
 * Complejidad: O(log n)
 * @param arr: vector ordenado donde buscar
 * @param valor: valor a buscar
 * @param comparaciones: referencia para contar comparaciones
 * @return: posición del elemento o -1 si no se encuentra
 */
int busqBinaria(const vector<int>& arr, int valor, int& comparaciones) {
    comparaciones = 0;
    int left = 0, right = arr.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        comparaciones++; // Comparación para ver si encontró el valor
        if (arr[mid] == valor) {
            return mid;
        }
        
        comparaciones++; // Comparación para decidir hacia qué lado buscar
        if (arr[mid] < valor) {
            left = mid + 1;
        } else {
            right = mid - 1;
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
}
