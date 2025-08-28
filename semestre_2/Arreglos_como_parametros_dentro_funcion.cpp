#include <iostream>
using namespace std;

// no hay diferencias entre ellos(ambas aceptan arreglos/punteros)
//void funcion1(int arr[], int size);  
//void funcion2(int* arr, int size);   

// Implementación de funcion1 (notación de arreglo)
void funcion1(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";  // Acceso con sintaxis de arreglo
    }
}

// Implementación de funcion2 (notación de puntero)
void funcion2(int* arr, int size) {
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";  // ¡Misma sintaxis de arreglo funciona!
        // También podríamos usar: cout << *(arr + i) << " ";
    }
}


int main() {
    int numeros[] = {12, 45, 2, 89, 33, 76};
    int tam = sizeof(numeros) / sizeof(numeros[0]);

    // Ambas funciones funcionan exactamente igual
    cout << "Usando funcion1 (notacion arreglo): ";
    funcion1(numeros, tam);  // Pasa el arreglo (decae a puntero)
    
    cout << "\nUsando funcion2 (notacion puntero): ";
    funcion2(numeros, tam);  // Pasa el mismo puntero
    
    return 0;
}
