/*
 * MyHeap.h
 * Implementación de un Heap (Fila Priorizada)
 * Autor: Diego Lizarraga A01647334
 * Fecha: 2/11/2025
 * Un Heap es como una fila en el banco, pero en lugar de ser 
 * "primero en entrar, primero en salir", aquí el que tiene MÁS PRIORIDAD
 * (el número más grande) sale primero.
 */

#ifndef MYHEAP_H
#define MYHEAP_H

class MyHeap {
private:
    int* values;      // Array donde guardamos los números
    int size;         // Cuántos números tenemos guardados ahora
    int len;          // Cuántos números podemos guardar en total
    
    // Métodos que nos ayudan a mantener el orden
    void heapifyUp(int index);      // Sube un elemento si es necesario
    void heapifyDown(int index);    // Baja un elemento si es necesario
    void expand();                   // Agrandamos el array cuando está lleno
    
public:
    // Creamos el Heap vacío
    MyHeap();
    
    // Agregamos un número al Heap
    void push(int n);
    
    // Sacamos el número más importante (el más grande)
    void pop();
    
    // Vemos cuál es el número más importante sin sacarlo
    int top();
    
    // Preguntamos si el Heap está vacío
    bool isEmpty();
    
    // Vemos cuántos números tenemos guardados
    int length();
    
    // Mostramos lo que hay dentro del Heap
    void imprimir();
};

#endif