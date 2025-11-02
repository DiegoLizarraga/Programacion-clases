//nomas es de prueb

#include "MyHeap.h"
#include <iostream>
using namespace std;

int main() {
    
    
    MyHeap heap;
    
    // Prueba 1: Verificar que el heap está vacío
    cout << "Prueba 1: Heap vacio" << endl;
    cout << "¿Esta vacio? " << (heap.isEmpty() ? "Sí" : "No") << endl;
    cout << "Longitud: " << heap.length() << endl << endl;
    
    // Prueba 2: Insertar valores
    cout << "Prueba 2: Insertar valores [12, 60, 72, 70, 56, 32, 62, 92, 45, 30, 65]" << endl;
    int values[] = {12, 60, 72, 70, 56, 32, 62, 92, 45, 30, 65};
    for (int i = 0; i < 11; i++) {
        heap.push(values[i]);
    }
    cout << "Despues de insertar:" << endl;
    heap.imprimir();
    cout << "Longitud: " << heap.length() << endl << endl;
    
    // Prueba 3: Top (sin eliminar)
    cout << "Prueba 3: Ver el valor con mayor prioridad (top)" << endl;
    cout << "Top: " << heap.top() << endl << endl;
    
    // Prueba 4: Pop (eliminar)
    cout << "Prueba 4: Eliminar el valor con mayor prioridad" << endl;
    heap.pop();
    cout << "Despues de pop:" << endl;
    heap.imprimir();
    cout << "Nuevo top: " << heap.top() << endl << endl;
    
    // Prueba 5: Eliminar más valores
    cout << "Prueba 5: Eliminar varios valores en orden" << endl;
    while (!heap.isEmpty()) {
        cout << "Eliminando: " << heap.top() << " -> ";
        heap.pop();
        if (!heap.isEmpty()) {
            cout << "Nuevo top: " << heap.top() << endl;
        } else {
            cout << "Heap vacío" << endl;
        }
    }
    cout << endl;
    
    // Prueba 6: Insertar nuevos valores después de vaciar
    cout << "Prueba 6: Insertar nuevos valores [8, 5, 4, 3, 9, 6, 2]" << endl;
    int values2[] = {8, 5, 4, 3, 9, 6, 2};
    for (int i = 0; i < 7; i++) {
        heap.push(values2[i]);
    }
    heap.imprimir();
    cout << "Longitud: " << heap.length() << endl << endl;
    
    // Prueba 7: Expansión del arreglo
    cout << "Prueba 7: Insertar más valores para probar expansion" << endl;
    for (int i = 10; i <= 25; i++) {
        heap.push(i);
    }
    cout << "Despuees de insertar muchos valores:" << endl;
    heap.imprimir();
    cout << "Longitud: " << heap.length() << endl << endl;
    
    // Prueba 8: Verificar que sigue siendo un heap válido
    cout << "Prueba 8: Descargar el heap completo" << endl;
    while (!heap.isEmpty()) {
        cout << heap.top() << " ";
        heap.pop();
    }
    cout << endl << "Heap vacio" << endl;
    
    return 0;
}