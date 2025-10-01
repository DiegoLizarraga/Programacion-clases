/*
Edgar Francisco Arechiga Nuño A01647054
Diego Martín Lizárraga Sánchez A01647334
Aldo Emiliano Galván Gómez A07106914
*/

#include "sort.h"
using namespace std;

// * Funcion main del programa
// * Gestiona la carga de logs, su ordenamiento y búsquedas dadas por el usario y el  rango de fechas

int main() {
    char opc;           //opcion para seguir o salir del programa
    GestorBitacora gestor; 
    int contador = 1;   // Contador para evitar sobrescribir archivos de salida

    // Lectura de salidas para evitar sobrescribir
    while (true) {
        if (!ifstream("salida" + to_string(contador) + "-eq3.txt")) {
            break; // Encontrar el primer número disponible
        }
        contador++;
    }
    gestor.setNumeroBusqueda(contador);
    
    // Carga el archivo
    if (!gestor.cargarArchivo("bitacoraOrdenada1.3-eq3.txt")) {
        if (!gestor.cargarArchivo("bitacora.txt")) {
            cerr << "Error: No se pudo cargar ningún archivo de bitácora." << endl;
            return 1; // Salir con error
        }
        // Ordenar por fecha y guardar
        gestor.ordenar();
        gestor.guardarOrdenado();
    }
    
    // Bucle while para las busquedas interactivas
    while (true) {
        cout << "=== Sistema de Analisis de Bitacora - Equipo 3 ===" << endl;
        gestor.realizarBusqueda();

        // Preguntar si se busca otra busqueda
        cout << endl << "¿Desea realizar otra busqueda? (s/n): ";
        cin >> opc;
        switch (opc) {
            case 's':
            case 'S':
                contador++;
                gestor.setNumeroBusqueda(contador); // Incrementar contador por si hay un nuevo archivo
                break;

            case 'n':
            case 'N':
                cout << "Saliendo de papulandia :,v." << endl;
                return 0; // Salir del programa
            
            default:
                cout << "Introduzca un valor valido (s/n)" << endl;
        }
    }
}
