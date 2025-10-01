#ifndef REGISTRO_BITACORA_H
#define REGISTRO_BITACORA_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <fstream>

using namespace std;

// La clase RegistroBitacora
// Esta clase representa la entrada del docu bitácora.txt con la informacion o datos de las entradas de acceso no autorizado.

// los datos se ven reflejados por los usuarios por mes abreviado, dia del mes. (ej. "31 Jun")
class RegistroBitacora {
private:
    string mes; 
    int dia;
    string hora;
    string ip;
    string razon;
    string lineaCompleta;
    int mesNumerico;
    
    // La función parsearLinea que sirve para extraer
    // los componentes de la bitacora.txt
    void parsearLinea(const string& linea);
public:
    
    // Constructor que inicializa el registro a partir de cada log
    RegistroBitacora(const string& linea);
    ~RegistroBitacora(); //Destructor
    // Getters
    string getMes() const; //obtiene el mes en formato de texto (ej. "Dic")
    int getDia() const; // Obtiene el día del mes (ej. 1-31)
    string getHora() const; //Obtiene la hora en formato HH:MM:SS.
    string getLineaCompleta() const; //Obtiene la linea completa
    int getMesNumerico() const; //Obtiene el mes de manera numerica (ej. 1-12)
    static int convertirMesANumero(const string& mes);//Convertir el mes de string a un int

};

// La clase GestorBitacora gestiona una colección de registros
// de bitácora. También logra cargas los logs desde un archivo. 
class GestorBitacora {
private:
    vector<RegistroBitacora> registros; //Aquí está el vector donde se agrega el archivo bitacora.txt
    int numeroEquipo; //Indice del equipo, nosotros el 3 :D
    int numeroBusqueda; //Contador para los nombres de los archivos finales

    
    // Uso del algoritmo merge sort para ordenar los registros, con parametros de indices del primer y segundo subarreglo
    void mergesort(int ini, int fin);
    
    // Mezcla dos subarreglos ordenados en uno solo
    void mezcla(int ini, int mid, int fin);

   //se comparan dos registros por fecha y devuelve true si el primer registro es anterior al segundo registro
    bool comparar(const RegistroBitacora& a, const RegistroBitacora& b); 

    // Busca logs en el rango de fechas dados por el usuario con los parametros de mes y dia inicial y mes y dia final
    vector<RegistroBitacora> buscarEnRango(const string& mesInicio, int diaInicio, 
                                          const string& mesFin, int diaFin);
public:
    GestorBitacora(); //constructor
    ~GestorBitacora(); //Destructor


    bool cargarArchivo(const string& nombreArchivo); //carga los archivos de texto
    void setNumeroBusqueda(int numero); // se estable el numero de la cantidad de archivos de busqueda para los archivos de salida
    int getNumeroBusqueda() const; //Obtiene el numero de busqueda 
    void ordenar(); //ordena los registros
    void guardarOrdenado(); //ordena el archivo "bitacoraOrdenada1.3-eq<numeroEquipo>.txt".
    void guardarResultados(const vector<RegistroBitacora>& resultados, int numeroSalida); //Guarda los resultados de la busqueda en el archivo resultado 
    void realizarBusqueda(); //menu de solicitud de fecha inicial y final para buscar registros
};

#endif
