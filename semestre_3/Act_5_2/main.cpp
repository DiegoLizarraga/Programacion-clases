/*
 * Equipo 3:
 * Edgar Francisco Arechiga Nuño A01647054
 * Diego Martín Lizárraga Sánchez A01647334
 * Aldo Emiliano Galván Gómez A07106914
 * 
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "IPHashTable.h"

using namespace std;

/*
 * Extrae la IP sin puerto de una cadena
 * Entrada: "10.15.175.231:6166"
 * Salida: "10.15.175.231"
 * Complejidad: O(1)
 */
string extraerIP(const string& ipConPuerto) {
    size_t colonPos = ipConPuerto.find(':');
    if (colonPos != string::npos) {
        return ipConPuerto.substr(0, colonPos);
    }
    return ipConPuerto;
}

/*
 * Carga el archivo bitacora3.txt y construye la tabla hash
 * Formato esperado: Oct 9 10:32:24 10.15.175.231:6166 Failed password...
 * 
 * Complejidad: O(n) donde n = número de líneas
 */
bool cargarBitacora(const string& nombreArchivo, IPHashTable& tabla) {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cerr << "Error: No se pudo abrir el archivo " << nombreArchivo << endl;
        return false;
    }
    
    string linea;
    int lineasProcesadas = 0;
    
    while (getline(archivo, linea)) {
        if (linea.empty()) continue;
        
        // Parsear línea: Oct 9 10:32:24 10.15.175.231:6166 Failed password...
        istringstream iss(linea);
        string mes, ipConPuerto;
        int dia;
        string hora;
        
        iss >> mes >> dia >> hora >> ipConPuerto;
        
        // Extraer IP sin puerto
        string ip = extraerIP(ipConPuerto);
        
        // Buscar si ya existe esta IP en la tabla
        IPRecord* registro = tabla.get(ip);
        
        if (registro == nullptr) {
            // No existe, crear nuevo registro
            IPRecord nuevoRegistro(ip);
            nuevoRegistro.agregarAcceso(mes, dia, hora);
            tabla.put(ip, nuevoRegistro);
        } else {
            // Ya existe, agregar nuevo acceso
            registro->agregarAcceso(mes, dia, hora);
            // Actualizar en la tabla (importante para persistir cambios)
            tabla.put(ip, *registro);
        }
        
        lineasProcesadas++;
    }
    
    archivo.close();
    
    cout << "Archivo cargado exitosamente." << endl;
    cout << "Lineas procesadas: " << lineasProcesadas << endl;
    cout << "IPs unicas: " << tabla.getSize() << endl;
    
    return true;
}

/*
 * Ordena cronológicamente todos los registros de la tabla hash
 * Complejidad: O(n × k log k) donde:
 *   n = número de IPs únicas
 *   k = accesos promedio por IP
 */
void ordenarTodosLosRegistros(IPHashTable& tabla) {
    // Recorrer todas las posiciones de la tabla
    for (int i = 0; i < tabla.sizeA; i++) {
        IPLinkedList& lista = tabla.tabla[i];
        IPNodoLL* curr = lista.head;
        
        // Para cada nodo en la lista de colisiones
        while (curr != nullptr) {
            // Ordenar los accesos de este registro
            curr->data.value.ordenarAccesos();
            curr = curr->next;
        }
    }
    
    cout << "Registros ordenados por fecha." << endl;
}

/*
 * Consulta una IP y muestra su información
 * Formato de salida (sin espacios entre líneas):
 * XXX.XXX.XXX.XXX
 * Jun 5 22:30:51
 * Aug 12 7:15:34
 * 
 * Complejidad: O(1) promedio para la búsqueda
 */
void consultarIP(IPHashTable& tabla) {
    string ip;
    cin >> ip;
    
    IPRecord* registro = tabla.get(ip);
    
    if (registro == nullptr) {
        cout << "IP no encontrada en los registros." << endl;
    } else {
        // Imprimir sin línea en blanco al inicio
        cout << registro->toString() << endl;
    }
}

/*
 * Función principal
 */
int main() {
    IPHashTable tabla;
    
    cout << "=== Sistema de Analisis de Bitacora - Equipo 3 ===" << endl;
    cout << endl;
    
    // Cargar archivo bitacora3.txt
    if (!cargarBitacora("bitacora3.txt", tabla)) {
        cerr << "No se pudo cargar la bitacora. Terminando programa." << endl;
        return 1;
    }
    
    // Ordenar todos los registros por fecha
    ordenarTodosLosRegistros(tabla);
    cout << endl;
    
    // Menú de consultas interactivas
    int continuar = 1;
    
    while (continuar == 1) {
        consultarIP(tabla);
        cout << endl;
        cin >> continuar;
        
        // Validar entrada
        while (continuar != 0 && continuar != 1) {
            cout << "Entrada invalida. Ingrese 1 para continuar o 0 para salir: ";
            cin >> continuar;
        }
        
        if (continuar == 1) {
            cout << endl;
        }
    }
    
    return 0;
}

/*
 * ANÁLISIS DE COMPLEJIDADES
 * ==========================
 * 
 * cargarBitacora(): O(n)
 *   - n líneas del archivo
 *   - Cada put() es O(1) promedio
 *   - Total: n × O(1) = O(n)
 * 
 * ordenarTodosLosRegistros(): O(n × k log k)
 *   - n = número de IPs únicas
 *   - k = accesos promedio por IP (típicamente pequeño)
 *   - Ordenar cada lista: O(k log k)
 *   - Total: n × O(k log k)
 * 
 * consultarIP(): O(1) promedio
 *   - get() de tabla hash: O(1) promedio
 *   - Imprimir: O(k) donde k = accesos de esa IP
 * 
 * COMPLEJIDAD TOTAL:
 * O(n) + O(n × k log k) + O(consultas)
 * 
 * SUPUESTOS CRÍTICOS:
 * - Factor de carga α < 0.75 (garantizado por rehashing)
 * - Hash dispersa uniformemente (std::hash<string>)
 * - k es pequeño comparado con n (típicamente k < 100)
 * 
 * REFERENCIAS:
 * [1] Cormen et al. (2009). Introduction to Algorithms. MIT Press.
 *     Capítulo 11: Hash Tables
 * [2] GeeksforGeeks. Hashing with Separate Chaining.
 *     https://www.geeksforgeeks.org/hashing-set-2-separate-chaining/
 * [3] stringstream in C++ and its Applications  para usar <sstream> 
    https://www.geeksforgeeks.org/cpp/stringstream-c-applications/
 */