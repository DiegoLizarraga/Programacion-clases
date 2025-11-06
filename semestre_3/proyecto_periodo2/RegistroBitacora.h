/*
Edgar Francisco Arechiga Nuño A01647054
Diego Martín Lizárraga Sánchez A01647334
Aldo Emiliano Galván Gómez A07106914
*/

#ifndef REGISTRO_BITACORA_H
#define REGISTRO_BITACORA_H

#include <iostream>
#include <string>
#include <sstream>
#include <map>

using namespace std;

// La clase RegistroBitacora
// Esta clase representa la entrada del documento bitácora.txt con la información 
// o datos de las entradas de acceso no autorizado.
// Los datos se ven reflejados por los usuarios por mes abreviado, dia del mes. (ej. "31 Jun")
class RegistroBitacora {
private:
    string mes; 
    int dia;
    string hora;
    string ip;
    int octeto1, octeto2, octeto3, octeto4; // Octetos de la IP
    int puerto; // Puerto de la IP
    string razon;
    string lineaCompleta;
    int mesNumerico;
    
    // La función parsearLinea que sirve para extraer los componentes de la bitacora.txt
    void parsearLinea(const string& linea);
    void parsearIP(const string& ip);
    
public:
    // Constructor que inicializa el registro a partir de cada log
    RegistroBitacora(const string& linea);
    ~RegistroBitacora(); //Destructor
    
    // Getters
    string getMes() const; //Obtiene el mes en formato de texto (ej. "Dic")
    int getDia() const; // Obtiene el día del mes (ej. 1-31)
    string getHora() const; //Obtiene la hora en formato HH:MM:SS.
    string getLineaCompleta() const; //Obtiene la linea completa
    int getMesNumerico() const; //Obtiene el mes de manera numerica (ej. 1-12)
    int getOcteto1() const; //Obtiene el primer octeto de la IP
    int getOcteto2() const; //Obtiene el segundo octeto de la IP
    int getOcteto3() const; //Obtiene el tercer octeto de la IP
    int getOcteto4() const; //Obtiene el cuarto octeto de la IP
    int getPuerto() const; //Obtiene el puerto de la IP
    static int convertirMesANumero(const string& mes); //Convertir el mes de string a un int
};

#endif