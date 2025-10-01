#include "sort.h"

// Constructor que inicializa un registro a partir de cada log
// Almacena la línea completa y parsea sus componentes
RegistroBitacora::RegistroBitacora(const string& linea) {
    lineaCompleta = linea;
    parsearLinea(linea);
}

RegistroBitacora::~RegistroBitacora() {
    // Los string se destruyen automáticamente
    // No hay recursos dinámicos que liberar manualmente
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

//La función parsearLinea que sirve para extraer los componentes de la bitacora.txt
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

// Convertir el mes de string a un int 
int RegistroBitacora::convertirMesANumero(const string& mes) {
    map<string, int> meses = {
        {"Jan", 1}, {"Feb", 2}, {"Mar", 3}, {"Apr", 4},
        {"May", 5}, {"Jun", 6}, {"Jul", 7}, {"Aug", 8},
        {"Sep", 9}, {"Oct", 10}, {"Nov", 11}, {"Dec", 12}
    };
    return meses.count(mes) ? meses[mes] : 0; // Devuelve 0 si el mes es inválido
}

// Constructor por defecto de GestorBitacora, inicializa numeroEquipo=3 y numeroBusqueda=1 
GestorBitacora::GestorBitacora() : numeroEquipo(3), numeroBusqueda(1) {}

GestorBitacora::~GestorBitacora() {
    // Los string se destruyen automáticamente
    // No hay recursos dinámicos que liberar manualmente
}

// Se pone el número de búsqueda para los archivos de salida 
void GestorBitacora::setNumeroBusqueda(int numero) {
    numeroBusqueda = numero;
}

// Obtiene el número de búsqueda
int GestorBitacora::getNumeroBusqueda() const {
    return numeroBusqueda;
}

// Carga los archivos de texto 
bool GestorBitacora::cargarArchivo(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cerr << "Error: No se pudo abrir el archivo " << nombreArchivo << endl;
        return false;
    }

    string linea;
    while (getline(archivo, linea)) {
        if (!linea.empty()) {
            registros.push_back(RegistroBitacora(linea)); // agrega cada línea como registro
        }
    }
    archivo.close();
    
    cout << "Se cargaron " << registros.size() << " registros." << endl;
    return true;
}

// Ordena los registros por fecha usando Merge 
void GestorBitacora::ordenar() {
    if (registros.size() > 1) {
        mergesort(0, registros.size() - 1); // llamar al algorimto merge sort
    }
    cout << "Registros ordenados por fecha usando Merge Sort." << endl;
}

// Uso del algoritmo merge sort para ordenar los registros 
void GestorBitacora::mergesort(int ini, int fin) {
    if (ini < fin) {
        int mid = (ini + fin) / 2; // Calcular punto medio
        mergesort(ini, mid);       // Ordenar primera mitad
        mergesort(mid + 1, fin);   // Ordenar segunda mitad
        mezcla(ini, mid, fin);     // Mezcla
    }
}

// Mezcla dos subarreglos ordenados en uno solo 
void GestorBitacora::mezcla(int ini, int mid, int fin) {
    vector<RegistroBitacora> temp;
    int i = ini, j = mid + 1;
    
    // Mezcla los dos subarreglos ordenados
    while (i <= mid && j <= fin) {
        if (comparar(registros[i], registros[j])) {
            temp.push_back(registros[i]);
            i++;
        } else {
            temp.push_back(registros[j]);
            j++;
        }
    }
    
    // Copia elementos restantes del primer subarreglo
    while (i <= mid) {
        temp.push_back(registros[i]);
        i++;
    }
    
    // Copiar elementos restantes del segundo subarreglo
    while (j <= fin) {
        temp.push_back(registros[j]);
        j++;
    }
    
    // Copia de vuelta al array original
    for (int k = 0; k < temp.size(); k++) {
        registros[ini + k] = temp[k];
    }
}

// Se comparan dos registros por fecha y devuelve true si el primer registro es anterior al segundo registro
bool GestorBitacora::comparar(const RegistroBitacora& a, const RegistroBitacora& b) {
    if (a.getMesNumerico() != b.getMesNumerico()) {
        return a.getMesNumerico() < b.getMesNumerico();
    }
    if (a.getDia() != b.getDia()) {
        return a.getDia() < b.getDia();   
    }
    return a.getHora() < b.getHora();
}

// Ordena el archivo "bitacoraOrdenada1.3-eq<numeroEquipo>.txt" 
void GestorBitacora::guardarOrdenado() {
    string nombreArchivo = "bitacoraOrdenada1.3-eq" + to_string(numeroEquipo) + ".txt";
    ofstream archivo(nombreArchivo);
    
    if (!archivo.is_open()) {
        cerr << "Error: No se pudo crear el archivo " << nombreArchivo << endl;
        return;
    }

    for (const auto& registro : registros) {
        archivo << registro.getLineaCompleta() << endl; // Escribir cada registro
    }
    archivo.close();
    cout << "Archivo ordenado guardado como: " << nombreArchivo << endl;
}

// Menu de solicitud de fecha inicial y final para buscar registros 
void GestorBitacora::realizarBusqueda() {
    string mesInicio, mesFin;
    int diaInicio, diaFin;
    
    cout << "\nIngrese fecha de inicio (formato: MMM DD): ";
    cin >> mesInicio >> diaInicio;
    
    cout << "Ingrese fecha de fin (formato: MMM DD): ";
    cin >> mesFin >> diaFin;
    
    vector<RegistroBitacora> resultados = buscarEnRango(mesInicio, diaInicio, mesFin, diaFin);
    
    if (resultados.empty()) {
        cout << "No se encontraron registros en el rango especificado." << endl;
    } else {
        cout << "Se encontraron " << resultados.size() << " registros." << endl;
        guardarResultados(resultados, getNumeroBusqueda());
    }
}

// Busca logs en el rango de fechas dados por el usuario con los parámetros de mes y día inicial y mes y día final 
vector<RegistroBitacora> GestorBitacora::buscarEnRango(const string& mesInicio, int diaInicio, 
                                      const string& mesFin, int diaFin) {
    vector<RegistroBitacora> resultados;
    int mesInicioNum = RegistroBitacora::convertirMesANumero(mesInicio);
    int mesFinNum = RegistroBitacora::convertirMesANumero(mesFin);
    
    for (const auto& registro : registros) {
        int mesReg = registro.getMesNumerico();
        int diaReg = registro.getDia();
        
        bool enRango = false;
        
        if (mesInicioNum == mesFinNum) {
            if (mesReg == mesInicioNum && diaReg >= diaInicio && diaReg <= diaFin) {
                enRango = true;
            }
        } else if (mesInicioNum < mesFinNum) {
            if ((mesReg == mesInicioNum && diaReg >= diaInicio) ||
                (mesReg > mesInicioNum && mesReg < mesFinNum) ||
                (mesReg == mesFinNum && diaReg <= diaFin)) {
                enRango = true;
            }
        }
        
        if (enRango) {
            resultados.push_back(registro); // agrega registro al resultado
        }
    }
    
    return resultados;
}

// Guarda los resultados de la búsqueda en el archivo resultado
void GestorBitacora::guardarResultados(const vector<RegistroBitacora>& resultados, int numeroSalida) {
    string nombreArchivo = "salida" + to_string(numeroSalida) + "-eq3.txt";
    ofstream archivo(nombreArchivo);
    
    if (!archivo.is_open()) {
        cerr << "Error: No se pudo crear el archivo " << nombreArchivo << endl;
        return;
    }

    for (const auto& registro : resultados) {
        archivo << registro.getLineaCompleta() << endl; // escribe cada registro
    }
    archivo.close();
    cout << "Resultados guardados en: " << nombreArchivo << endl;
}
