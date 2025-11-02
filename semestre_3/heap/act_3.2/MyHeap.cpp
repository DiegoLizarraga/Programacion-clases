/*
 * MyHeap.cpp
 * Implementación de un Heap (Fila Priorizada)
 * Autor: Diego Lizarraga A01647334
 * Fecha: 2/11/2025
 * Aquí están todos los detalles de cómo funciona el Heap
 */

#include "MyHeap.h"
#include <iostream>
using namespace std;

/*
 * Constructor del Heap
 * Inicializa los atributos. El atributo values se inicializa como un 
 * arreglo vacío tamaño 7.
 * 
 * Mejor caso: O(1)
 * Peor caso: O(1)
 * 
 * Precondición: Ninguna
 * Postcondición: El Heap está inicializado y vacío
 */
MyHeap::MyHeap() {
    this->len = 7;
    this->size = 0;
    this->values = new int[len];
}

/*
 * Expande el arreglo cuando está lleno
 * Solo cuando el nuevo valor no cabe en el arreglo se crece al tamaño 2*n+1. 
 * Se copian los primeros 7 valores del arreglo original.
 * 
 * Mejor caso: O(1) - si hay espacio disponible
 * Peor caso: O(n) - cuando necesita copiar todos los elementos
 * 
 * Precondición: size <= len
 * Postcondición: El arreglo tiene más capacidad o sigue igual
 */
void MyHeap::expand() {
    if (this->size < this->len) {
        return;
    }
    
    int newLen = 2 * len + 1;
    int* newValues = new int[newLen];
    
    for (int i = 0; i < size; i++) {
        newValues[i] = values[i];
    }
    
    delete[] values;
    values = newValues;
    len = newLen;
}

/*
 * Sube un elemento si es más grande que su padre
 * Cuando agregamos un número nuevo, empieza abajo y sube si es más 
 * grande que su padre. Repite hasta que encuentra su lugar correcto.
 * 
 * Mejor caso: O(1) - si está en su posición correcta
 * Peor caso: O(log n) - si debe subir hasta la raíz
 * 
 * Precondición: index es un índice válido en el arreglo
 * Postcondición: El elemento está en su posición correcta subiendo
 */
void MyHeap::heapifyUp(int index) {
    while (index > 0) {
        int parentIndex = (index - 1) / 2;
        
        if (values[index] > values[parentIndex]) {
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
 * Baja un elemento si es más pequeño que alguno de sus hijos
 * Cuando sacamos el número más importante, ponemos el último número 
 * allí y lo dejamos bajar si es más pequeño que alguno de sus hijos.
 * 
 * Mejor caso: O(1) - si está en su posición correcta
 * Peor caso: O(log n) - si debe bajar hasta una hoja
 * 
 * Precondición: index es un índice válido en el arreglo
 * Postcondición: El elemento está en su posición correcta bajando
 */
void MyHeap::heapifyDown(int index) {
    while (true) {
        int largest = index;
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        
        if (leftChild < size && values[leftChild] > values[largest]) {
            largest = leftChild;
        }
        
        if (rightChild < size && values[rightChild] > values[largest]) {
            largest = rightChild;
        }
        
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
 * Agrega un dato a la fila priorizada. Solo cuando el nuevo valor no cabe 
 * en el arreglo se crece el arreglo al tamaño 2*n+1.
 * 
 * Mejor caso: O(1) - si se inserta en la raíz
 * Peor caso: O(log n) - si debe subir hasta la raíz
 * 
 * Precondición: n es un entero válido
 * Postcondición: La fila priorizada contiene un nuevo dato
 */
void MyHeap::push(int n) {
    expand();
    values[size] = n;
    size++;
    heapifyUp(size - 1);
}

/*
 * Elimina un valor del heap
 * Se elimina un valor del heap. No es necesario nunca decrementar 
 * el tamaño del arreglo.
 * 
 * Mejor caso: O(log n)
 * Peor caso: O(log n)
 * 
 * Precondición: La fila priorizada contiene al menos 1 dato
 * Postcondición: La fila priorizada queda sin el dato con mayor prioridad
 */
void MyHeap::pop() {
    if (size == 0) {
        return;
    }
    
    values[0] = values[size - 1];
    size--;
    
    if (size > 0) {
        heapifyDown(0);
    }
}

/*
 * Regresa quien es el siguiente elemento en salir
 * Regresa el valor del dato que esta con mayor prioridad en la fila priorizada.
 * 
 * Mejor caso: O(1)
 * Peor caso: O(1)
 * 
 * Precondición: La fila priorizada contiene al menos 1 dato
 * Postcondición: Nada
 */
int MyHeap::top() {
    if (size == 0) {
        return -1;
    }
    return values[0];
}

/*
 * Verifica si la fila está vacía
 * Regresa true si el heap está vacío caso contrario regresa false.
 * 
 * Mejor caso: O(1)
 * Peor caso: O(1)
 * 
 * Precondición: Nada
 * Postcondición: Nada
 */
bool MyHeap::isEmpty() {
    return size == 0;
}

/*
 * Regresa la cantidad de datos que tiene el heap
 * Regresa cuántos elementos están almacenado el heap. OJO: NO EL TAMAÑO.
 * 
 * Mejor caso: O(1)
 * Peor caso: O(1)
 * 
 * Precondición: Nada
 * Postcondición: Nada
 */
int MyHeap::length() {
    return size;
}

/*
 * Imprime los atributos del heap
 * Debe ser la implementación que se muestra abajo. No cambiar nada.
 * 
 * Mejor caso: O(n)
 * Peor caso: O(n)
 * 
 * Precondición: Nada
 * Postcondición: Nada
 */
void MyHeap::imprimir() {
    cout << "árbol size: " << "<" << this->size << "<" << " len:" << "<this->" << len << "<endl;";
    for (int i = 0; i < this->size; i++) {
        cout << values[i] << ",";
    }
    cout << endl;
}