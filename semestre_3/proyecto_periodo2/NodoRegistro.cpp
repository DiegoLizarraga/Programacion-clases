/*
Edgar Francisco Arechiga Nuño A01647054
Diego Martín Lizárraga Sánchez A01647334
Aldo Emiliano Galván Gómez A07106914
*/

#include "NodoRegistro.h"

// Constructor del nodo
NodoRegistro::NodoRegistro(const string& linea, NodoRegistro* next) {
    this->next = next;
    
    // Parsear la línea
    istringstream iss(linea);
    iss >> mes >> dia >> hora >> ip;
    getline(iss, razon);
    if (!razon.empty() && razon[0] == ' ') {
        razon = razon.substr(1);
    }
    
    lineaCompleta = linea;
    
    // Convertir mes a número
    map<string, int> meses = {
        {"Jan", 1}, {"Feb", 2}, {"Mar", 3}, {"Apr", 4},
        {"May", 5}, {"Jun", 6}, {"Jul", 7}, {"Aug", 8},
        {"Sep", 9}, {"Oct", 10}, {"Nov", 11}, {"Dec", 12}
    };
    mesNumerico = meses.count(mes) ? meses[mes] : 0;
    
    // Parsear IP
    string ipPart, portPart;
    size_t colonPos = ip.find(':');
    
    if (colonPos != string::npos) {
        ipPart = ip.substr(0, colonPos);
        portPart = ip.substr(colonPos + 1);
    } else {
        ipPart = ip;
        portPart = "0";
    }

    istringstream issIP(ipPart);
    string octetoStr;
    int octetos[4] = {0, 0, 0, 0}; 

    for (int i = 0; getline(issIP, octetoStr, '.') && i < 4; i++) {
        octetos[i] = stoi(octetoStr);
    }

    octeto1 = octetos[0];
    octeto2 = octetos[1];
    octeto3 = octetos[2];
    octeto4 = octetos[3];
    puerto = stoi(portPart);
}

// Funcion auxiliar para obtener el valor compuesto de IP para comparaciones
// Complejidad: O(1)
long long NodoRegistro::getValorIP() const {
    return ((long long)octeto1 << 32) | ((long long)octeto2 << 24) | 
           ((long long)octeto3 << 16) | ((long long)octeto4 << 8) | puerto;
}