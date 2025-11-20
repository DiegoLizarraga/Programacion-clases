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
#include <sstream> // Para istringstream 

using namespace std;

class FechaHora {
public:
    string mes;
    int dia;
    string hora;
    int mesNumerico;
    int horaSegundos;  // Hora convertida a segundos totales
    
    // Convierte hora HH:MM:SS a segundos totales
    int convertirHoraASegundos(const string& h) {
        int horas = 0, minutos = 0, segundos = 0;
        char sep;
        
        istringstream iss(h);
        iss >> horas >> sep >> minutos >> sep >> segundos;
        
        return horas * 3600 + minutos * 60 + segundos;
    }
    
    // Constructor
    FechaHora(string m = "", int d = 0, string h = "") : mes(m), dia(d), hora(h) {
        // Convertir mes a número para ordenamiento
        map<string, int> meses = {
            {"Jan", 1}, {"Feb", 2}, {"Mar", 3}, {"Apr", 4},
            {"May", 5}, {"Jun", 6}, {"Jul", 7}, {"Aug", 8},
            {"Sep", 9}, {"Oct", 10}, {"Nov", 11}, {"Dec", 12}
        };
        mesNumerico = meses.count(mes) ? meses[mes] : 0;
        horaSegundos = convertirHoraASegundos(hora);
    }
    
    // Operador de comparación para ordenamiento
    bool operator<(const FechaHora& otra) const {
        // Primero comparar mes
        if (mesNumerico != otra.mesNumerico) 
            return mesNumerico < otra.mesNumerico;
        
        // Luego comparar día
        if (dia != otra.dia) 
            return dia < otra.dia;
        
        // Finalmente comparar hora (como segundos, no como string)
        return horaSegundos < otra.horaSegundos;
    }
    
    // Convertir a string para imprimir
    string toString() const {
        return mes + " " + to_string(dia) + " " + hora;
    }
};

#endif