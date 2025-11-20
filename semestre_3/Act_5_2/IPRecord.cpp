
// ============================================================
// IPRecord.cpp
// ============================================================
/*
 * IPRecord.cpp
 * Implementación de la clase IPRecord
 */

#include "IPRecord.h"

// Constructor
IPRecord::IPRecord(string ipAddress) : ip(ipAddress) {}

// Agrega un nuevo acceso
void IPRecord::agregarAcceso(string mes, int dia, string hora) {
    accesos.push_back(FechaHora(mes, dia, hora));
}

// Ordena los accesos por fecha usando sort de STL
// Complejidad: O(k log k) donde k = número de accesos
void IPRecord::ordenarAccesos() {
    sort(accesos.begin(), accesos.end());
}

// Obtiene la IP
string IPRecord::getIP() const { 
    return ip; 
}

// Obtiene el número de accesos
int IPRecord::getNumAccesos() const { 
    return accesos.size(); 
}

// Obtiene todos los accesos
const vector<FechaHora>& IPRecord::getAccesos() const {
    return accesos;
}

// Imprime el resumen en el formato requerido
// Sin espacios en blanco entre líneas
string IPRecord::toString() const {
    if (accesos.empty()) {
        return ip + "\n(Sin registros)";
    }
    
    string resultado = ip;
    for (const auto& acceso : accesos) {
        resultado += "\n" + acceso.toString();
    }
    return resultado;
}