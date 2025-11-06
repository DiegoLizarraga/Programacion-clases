/*
Edgar Francisco Arechiga Nuño A01647054
Diego Martín Lizárraga Sánchez A01647334
Aldo Emiliano Galván Gómez A07106914
*/

#include "GestorBitacora.h"
using namespace std;

// * Funcion main del programa
// * Gestiona la carga de logs, su ordenamiento y búsquedas dadas por el usuario y el rango de fechas

int main() {
    char opc;           //opcion para seguir o salir del programa
    GestorBitacora gestor; 
    int contador = 0;   // Contador para evitar sobrescribir archivos de salida
    bool valid = true;

    // Lectura de salidas para evitar sobrescribir
    do {
        contador++;
        if (!ifstream("salida" + to_string(contador) + "-eq3.txt")) {
            valid = false; // Encontrar el primer número disponible
        }
    } while (valid);
    gestor.setNumeroBusqueda(contador);
    
    // Carga el archivo
    if (!gestor.cargarArchivo("bitacoraOrdenada2.3-eq3.txt")) {
        if (!gestor.cargarArchivo("bitacora.txt")) {
            cerr << "Error: No se pudo cargar ningún archivo de bitácora." << endl;
            return 1; // Salir con error
        }
        // Ordenar por fecha y guardar
        gestor.ordenar();
        gestor.guardarOrdenado();
    }
    
    cout << "Archivo cargado y ordenado exitosamente." << endl;

    // Bucle while para las busquedas interactivas
    do {
        cout << "\n=== Sistema de Analisis de Bitacora - Equipo 3 ===" << endl;
        gestor.realizarBusquedaIP();
        
        // Preguntar si se busca otra busqueda
        cout << endl << "¿Desea realizar otra busqueda? (s/n): ";
        cin >> opc;
        while (opc != 's' && opc != 'S' && opc != 'n' && opc != 'N'){
            cout << "Introduzca un valor valido (s/n)" << endl;
            cin >> opc;
        }
        if (opc == 's' || opc == 'S') {
                contador++;
                gestor.setNumeroBusqueda(contador); // Incrementar contador por si hay un nuevo archivo
            }
        else {
            cout << "Saliendo de papulandia :,v." << endl;
        }
    } while (opc == 's' || opc == 'S');
    
    return 0; // Salir del programa
}

/**

GeeksforGeeks. (2025, 23 julio). Linked List data structure. GeeksforGeeks. https://www.geeksforgeeks.org/dsa/linked-list-data-structure/

Dynamic memory. (s. f.). Cplusplus. Recuperado 9 de octubre de 2025, de https://cplusplus.com/doc/tutorial/dynamic/

GeeksforGeeks. (2025b, agosto 26). Merge Sort for Linked Lists. GeeksforGeeks. https://www.geeksforgeeks.org/dsa/merge-sort-for-linked-list/

Open-Ai (Grok-4) Grok. https://grok.com/share/bGVnYWN5_9c2dbe41-afb5-4691-ae10-496a4ce0fea5

**/
