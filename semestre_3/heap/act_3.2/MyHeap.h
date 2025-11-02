/*
 * MyHeap.h
 * Implementacion de un Max-Heap (fila priorizada)
 * de:Diego Lizarraga A01647334
 * Fecha: 2 de noviemnbre de 2025
 * 
 * Complejidad de operaciones:
 * push() - Mejor: O(1), Peor: O(log n)
 * pop() - O(log n)
 * top() - O(1)
 * isEmpty() - O(1)
 * length() - O(1)
 */

#ifndef MYHEAP_H
#define MYHEAP_H

class MyHeap {
private:
    int* values;      // Arreglo donde se guardaran los valores del HEAP
    int size;         // Representa cuantos valores tiene almacenado el Heap
    int len;          // Representa el tamaño o capacidad máxima actual del arreglo
    
    // Métodos auxiliares privados
    void heapifyUp(int index);      // Reorder hacia arriba
    void heapifyDown(int index);    // Reorder hacia abajo
    void expand();                   // Expande el arreglo cuando sea necesario
    
public:
    // Constructor: Inicializa el arreglo con tamaño 
    MyHeap();
    
    // Insertar un valor en la fila priorizada
    void push(int n);
    
    // Elimina un valor del heap
    void pop();
    
    // Regresa quien es el siguiente elemento en salir
    int top();
    
    // Verifica si la fila está vacía
    bool isEmpty();
    
    // Regresa la cantidad de datos que tiene el heap
    int length();
    
    // Imprime los atributos del heap
    void imprimir();
};

#endif