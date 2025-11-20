 /* IPRecord.h
 * Clase para almacenar el historial de accesos de una IP
 * 
 * Equipo 3:
 * Edgar Francisco Arechiga Nuño A01647054
 * Diego Martín Lizárraga Sánchez A01647334
 * Aldo Emiliano Galván Gómez A07106914
 */

#ifndef IPRECORD_H
#define IPRECORD_H

#include <string>
#include <vector>
#include <algorithm>
#include "FechaHora.h"

using namespace std;

class IPRecord {
private:
    string ip;
    vector<FechaHora> accesos;
    
public:
    // Constructor
    IPRecord(string ipAddress = "");
    
    // Agrega un nuevo acceso
    void agregarAcceso(string mes, int dia, string hora);
    
    // Ordena los accesos por fecha
    void ordenarAccesos();
    
    // Getters
    string getIP() const;
    int getNumAccesos() const;
    const vector<FechaHora>& getAccesos() const;
    
    // Imprime el resumen (formato requerido sin espacios entre líneas)
    string toString() const;
};

#endif
