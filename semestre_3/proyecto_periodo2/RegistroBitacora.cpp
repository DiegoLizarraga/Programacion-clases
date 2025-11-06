/*
Edgar Francisco Arechiga Nuño A01647054
Diego Martín Lizárraga Sánchez A01647334
Aldo Emiliano Galván Gómez A07106914
*/

#include "RegistroBitacora.h"

// Constructor que inicializa un registro a partir de cada log
// Almacena la línea completa y parsea sus componentes
RegistroBitacora::RegistroBitacora(const string& linea) {
    lineaCompleta = linea;
    parsearLinea(linea);
    parsearIP(ip);
}

RegistroBitacora::~RegistroBitacora() {
    // Los string se destruyen automaticamente
    //pues no hay que liberar nada
}

// Obtiene el mes en formato de texto (ej. "Dic")
string RegistroBitacora::getMes() const { return mes; }

// Obtiene el día del mes (ej. 1-31)
int RegistroBitacora::getDia() const { return dia; }

// Obtiene la hora en formato HH:MM:SS
string RegistroBitacora::getHora() const { return hora; }

// Obtiene la linea completa del log
string RegistroBitacora::getLineaCompleta() const { return lineaCompleta; }

// Obtiene el mes de manera numerica (ej. 1-12)
int RegistroBitacora::getMesNumerico() const { return mesNumerico; }

int RegistroBitacora::getOcteto1() const { return octeto1; }
int RegistroBitacora::getOcteto2() const { return octeto2; }
int RegistroBitacora::getOcteto3() const { return octeto3; }
int RegistroBitacora::getOcteto4() const { return octeto4; }
int RegistroBitacora::getPuerto() const { return puerto; }

// La funcion parsearLinea que sirve para extraer los componentes de la bitacora.txt
void RegistroBitacora::parsearLinea(const string& linea) {
    istringstream iss(linea);
    string token;

    iss >> mes; // Extrae mes
    mesNumerico = convertirMesANumero(mes);    
    
    iss >> dia; // Extrae día
    
    iss >> hora; // Extrae hora
    
    iss >> ip;  // Extrae IP
    
    // El resto es la razón
    getline(iss, razon);
    if (!razon.empty() && razon[0] == ' ') {
        razon = razon.substr(1); // Quitar espacio inicial
    }
}

void RegistroBitacora::parsearIP(const string& ipStr) {
    // Ejemplo de ipStr: "192.168.0.1:8080"
    string ipPart, portPart;
    size_t colonPos = ipStr.find(':');
    
    if (colonPos != string::npos) {
        ipPart = ipStr.substr(0, colonPos); // Parte de la IP (antes de ':')
        portPart = ipStr.substr(colonPos + 1); // Parte del puerto (después de ':')
    } else {
        ipPart = ipStr; // Sin puerto, toda la cadena es la IP
        portPart = "0"; // Puerto por defecto
    }

    istringstream iss(ipPart);
    string octetoStr;
    int octetos[4] = {0, 0, 0, 0}; 

    for (int i = 0; getline(iss, octetoStr, '.') && i < 4; i++) {
        octetos[i] = stoi(octetoStr);
    }

    octeto1 = octetos[0];
    octeto2 = octetos[1];
    octeto3 = octetos[2];
    octeto4 = octetos[3];

    puerto = stoi(portPart);
}

// Convertir el mes de string a un int 
int RegistroBitacora::convertirMesANumero(const string& mes) {
    map<string, int> meses = {
        {"Jan", 1}, {"Feb", 2}, {"Mar", 3}, {"Apr", 4},
        {"May", 5}, {"Jun", 6}, {"Jul", 7}, {"Aug", 8},
        {"Sep", 9}, {"Oct", 10}, {"Nov", 11}, {"Dec", 12}
    };
    return meses.count(mes) ? meses[mes] : 0; // Devuelve 0 si el mes es inválido
}