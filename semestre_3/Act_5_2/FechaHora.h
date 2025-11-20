/*
 * FechaHora.h
 * Estructura para almacenar y comparar fechas con hora
 * 
 * Equipo 3:
 * Edgar Francisco Arechiga Nuño A01647054
 * Diego Martín Lizárraga Sánchez A01647334
 * Aldo Emiliano Galván Gómez A07106914
 */

#ifndef FECHAHORA_H
#define FECHAHORA_H

#include <string>
#include <map>

using namespace std;

class FechaHora {
public:
    string mes;
    int dia;
    string hora;
    int mesNumerico;
    
    // Constructor
    FechaHora(string m = "", int d = 0, string h = "") : mes(m), dia(d), hora(h) {
        // Convertir mes a número para ordenamiento
        map<string, int> meses = {
            {"Jan", 1}, {"Feb", 2}, {"Mar", 3}, {"Apr", 4},
            {"May", 5}, {"Jun", 6}, {"Jul", 7}, {"Aug", 8},
            {"Sep", 9}, {"Oct", 10}, {"Nov", 11}, {"Dec", 12}
        };
        mesNumerico = meses.count(mes) ? meses[mes] : 0;
    }
    
    // Operador de comparación para ordenamiento
    bool operator<(const FechaHora& otra) const {
        if (mesNumerico != otra.mesNumerico) 
            return mesNumerico < otra.mesNumerico;
        if (dia != otra.dia) 
            return dia < otra.dia;
        return hora < otra.hora;
    }
    
    // Convertir a string para imprimir
    string toString() const {
        return mes + " " + to_string(dia) + " " + hora;
    }
};

#endif