/*
 * MyHeap.cpp
 * Implementacion de la Max-Heap (fila priorizada actº 3.2)
 * Diego Lizarraga A01647334
 */

#include "MyHeap.h"
#include <iostream>
using namespace std;

/*
 * Constructor del Heap
 * Inicializa el arreglo con tamaño 7
 * Precondición: Ninguna
 * Postcondición: El heap está inicializado y vacío
 */
MyHeap::MyHeap() {
    this->len = 7;
    this->size = 0;
    this->values = new int[len];
}

/*
 * Expande el arreglo cuando está lleno
 * Solo se expande cuando el nuevo valor no cabe en el arreglo
 * Crece al tamaño 2*n+1
 * Mejor caso: O(1) si hay espacio
 * Peor caso: O(n) cuando necesita expandir y copiar
 */
void MyHeap::expand() {
    if (this->size < this->len) {
        return;  // No necesita expandir
    }
    
    // Crear un nuevo arreglo más grande
    int newLen = 2 * len + 1;
    int* newValues = new int[newLen];
    
    // Copiar los valores del arreglo anterior
    for (int i = 0; i < size; i++) {
        newValues[i] = values[i];
    }
    
    // Liberar el arreglo anterior
    delete[] values;
    
    // Asignar el nuevo arreglo
    values = newValues;
    len = newLen;
}

/*
 * Reordena hacia arriba (sift-up)
 * Compara el nodo con su padre y lo intercambia si es mayor
 * Mejor caso: O(1)
 * Peor caso: O(log n)
 */
void MyHeap::heapifyUp(int index) {
    while (index > 0) {
        int parentIndex = (index - 1) / 2;
        
        if (values[index] > values[parentIndex]) {
            // Intercambiar
            int temp = values[index];
            values[index] = values[parentIndex];
            values[parentIndex] = temp;
            index = parentIndex;
        } else {
            break;
        }
    }
}

/*
 * Reordena hacia abajo (sift-down)
 * Compara el nodo con sus hijos y lo intercambia con el mayor si es necesario
 * Mejor caso: O(1)
 * Peor caso: O(log n)
 */
void MyHeap::heapifyDown(int index) {
    while (true) {
        int largest = index;
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        
        // Comparar con hijo izquierdo
        if (leftChild < size && values[leftChild] > values[largest]) {
            largest = leftChild;
        }
        
        // Comparar con hijo derecho
        if (rightChild < size && values[rightChild] > values[largest]) {
            largest = rightChild;
        }
        
        // Si el nodo no es el mayor, intercambiar y continuar
        if (largest != index) {
            int temp = values[index];
            values[index] = values[largest];
            values[largest] = temp;
            index = largest;
        } else {
            break;
        }
    }
}

/*
 * Inserta un valor en la fila priorizada
 * Parámetro n: valor a insertar
 * Mejor caso: O(1) cuando se inserta en la raíz
 * Peor caso: O(log n) cuando toca expandir y reordenar
 * Precondición: n es un entero
 * Postcondición: El valor se inserta y la fila contiene un nuevo dato
 */
void MyHeap::push(int n) {
    // Expandir si es necesario
    expand();
    
    // Agregar el nuevo valor al final
    values[size] = n;
    size++;
    
    // Reordenar hacia arriba
    heapifyUp(size - 1);
}

/*
 * Elimina el valor con mayor prioridad del heap
 * Mejor caso: O(log n)
 * Peor caso: O(log n)
 * Precondición: La fila debe contener al menos 1 dato
 * Postcondición: La fila queda sin el dato con mayor prioridad
 */
void MyHeap::pop() {
    if (size == 0) {
        return;
    }
    
    // Mover el último elemento a la raíz
    values[0] = values[size - 1];
    size--;
    
    // Reordenar hacia abajo si quedan elementos
    if (size > 0) {
        heapifyDown(0);
    }
}

/*
 * Regresa el valor con mayor prioridad sin eliminarlo
 * Retorna: El dato que tiene mayor prioridad dentro de la fila priorizada
 * Mejor caso: O(1)
 * Peor caso: O(1)
 * Precondición: La fila debe contener al menos 1 dato
 * Postcondición: Nada cambia
 */
int MyHeap::top() {
    if (size == 0) {
        return -1;  // O lanzar una excepción
    }
    return values[0];
}

/*
 * Verifica si el heap está vacío
 * Retorna: true si el heap está vacío, false en caso contrario
 * Mejor caso: O(1)
 * Peor caso: O(1)
 * Precondición: Nada
 * Postcondición: No cambia nada
 */
bool MyHeap::isEmpty() {
    return size == 0;
}

/*
 * Regresa cuántos elementos están almacenados en el heap
 * Retorna: cantidad de datos en el heap
 * Mejor caso: O(1)
 * Peor caso: O(1)
 * Precondición: Nada
 * Postcondición: No cambia nada
 */
int MyHeap::length() {
    return size;
}

/*
 * Imprime los atributos del heap
 * Debe ser la implementación que se muestra abajo
 * No cambiar nada
 */
void MyHeap::imprimir() {
    cout << "árbol size: " << "<" << this->size << "<" << " len:" << "<this->" << len << "<endl;";
    for (int i = 0; i < this->size; i++) {
        cout << values[i] << ",";
    }
    cout << endl;
}