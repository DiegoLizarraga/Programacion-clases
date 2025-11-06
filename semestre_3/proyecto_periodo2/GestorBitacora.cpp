/*
Edgar Francisco Arechiga Nuño A01647054
Diego Martín Lizárraga Sánchez A01647334
Aldo Emiliano Galván Gómez A07106914
*/

#include "GestorBitacora.h"

// Constructor por defecto de GestorBitacora, inicializa numeroEquipo=3 y numeroBusqueda=1 
GestorBitacora::GestorBitacora() : head(nullptr), tail(nullptr), size(0), numeroEquipo(3), numeroBusqueda(1) {}

GestorBitacora::~GestorBitacora() {
    // Liberar toda la lista enlazada
    NodoRegistro* curr = head;
    while (curr != nullptr) {
        NodoRegistro* temp = curr;
        curr = curr->next;
        delete temp;
    }
    head = tail = nullptr;
    size = 0;
}

// Se pone el número de búsqueda para los archivos de salida 
void GestorBitacora::setNumeroBusqueda(int numero) {
    numeroBusqueda = numero;
}

// Obtiene el número de busqueda
int GestorBitacora::getNumeroBusqueda() const {
    return numeroBusqueda;
}

// Carga los archivos de texto 
// Complejidad: O(n) donde n es el número de lineas del archivo
bool GestorBitacora::cargarArchivo(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        return false;
    }

    string linea;
    while (getline(archivo, linea)) {
        if (!linea.empty()) {
            // Insertar al final de la lista enlazada
            NodoRegistro* nvo = new NodoRegistro(linea);
            if (head == nullptr) {
                head = tail = nvo;
            } else {
                tail->next = nvo;
                tail = nvo;
            }
            size++;
        }
    }
    archivo.close();
    return true;
}

// Ordena los registros por IP usando Merge Sort
// Complejidad: O(n log n) en todos los casos (mejor, promedio y peor)
void GestorBitacora::ordenar() {
    if (size > 1) {
        head = mergesort(head);
        // Actualizar tail
        NodoRegistro* curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        tail = curr;
    }
}

// Divide la lista en dos mitades
// Complejidad: O(n) donde n es el tamaño de la lista
NodoRegistro* GestorBitacora::dividirLista(NodoRegistro* head) {
    if (head == nullptr || head->next == nullptr) {
        return nullptr;
    }
    
    NodoRegistro* slow = head;
    NodoRegistro* fast = head->next;
    
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    NodoRegistro* mid = slow->next;
    slow->next = nullptr;
    return mid;
}

// Uso del algoritmo merge sort para ordenar los registros 
// Complejidad: O(n log n)
// Merge Sort es estable y tiene complejidad O(n log n) garantizada en todos los casos
NodoRegistro* GestorBitacora::mergesort(NodoRegistro* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    
    NodoRegistro* mid = dividirLista(head);
    
    NodoRegistro* left = mergesort(head);
    NodoRegistro* right = mergesort(mid);
    
    return mezcla(left, right);
}

// Mezcla dos listas ordenadas en una sola
// Complejidad: O(n) donde n es el tamaño combinado de ambas listas
NodoRegistro* GestorBitacora::mezcla(NodoRegistro* left, NodoRegistro* right) {
    if (left == nullptr) return right;
    if (right == nullptr) return left;
    
    NodoRegistro* resultado = nullptr;
    
    if (comparar(left, right)) {
        resultado = left;
        resultado->next = mezcla(left->next, right);
    } else {
        resultado = right;
        resultado->next = mezcla(left, right->next);
    }
    
    return resultado;
}

// Se comparan dos registros por IP y devuelve true si el primer registro es anterior al segundo registro
// Complejidad: O(1)
bool GestorBitacora::comparar(NodoRegistro* a, NodoRegistro* b) {
    if (a->octeto1 != b->octeto1) {
        return a->octeto1 < b->octeto1;
    }
    if (a->octeto2 != b->octeto2) {
        return a->octeto2 < b->octeto2;
    }
    if (a->octeto3 != b->octeto3) {
        return a->octeto3 < b->octeto3;
    }
    if (a->octeto4 != b->octeto4) {
        return a->octeto4 < b->octeto4;
    }
    return a->puerto < b->puerto;
}

// Guarda el archivo ordenado "bitacoraOrdenada1.3-eq<numeroEquipo>.txt" 
// Complejidad: O(n)
void GestorBitacora::guardarOrdenado() {
    string nombreArchivo = "bitacoraOrdenada1.3-eq" + to_string(numeroEquipo) + ".txt";
    ofstream archivo(nombreArchivo);
    
    if (!archivo.is_open()) {
        return;
    }

    NodoRegistro* curr = head;
    while (curr != nullptr) {
        archivo << curr->lineaCompleta << endl;
        curr = curr->next;
    }
    archivo.close();
}

// Parsea una IP en formato string (###.###.###.###:####) y devuelve los octetos y puerto
// Complejidad: O(1)
void GestorBitacora::parsearIPBusqueda(const string& ipStr, int& oct1, int& oct2, int& oct3, int& oct4, int& port) {
    string ipPart, portPart;
    size_t colonPos = ipStr.find(':');
    
    if (colonPos != string::npos) {
        ipPart = ipStr.substr(0, colonPos);
        portPart = ipStr.substr(colonPos + 1);
    } else {
        ipPart = ipStr;
        portPart = "0";
    }

    istringstream iss(ipPart);
    string octetoStr;
    int octetos[4] = {0, 0, 0, 0}; 

    for (int i = 0; getline(iss, octetoStr, '.') && i < 4; i++) {
        octetos[i] = stoi(octetoStr);
    }

    oct1 = octetos[0];
    oct2 = octetos[1];
    oct3 = octetos[2];
    oct4 = octetos[3];
    port = stoi(portPart);
}

// Convierte la lista enlazada a un vector temporal para búsqueda binaria
// Complejidad: O(n)
vector<NodoRegistro*> GestorBitacora::listaAVector() {
    vector<NodoRegistro*> vec;
    NodoRegistro* curr = head;
    while (curr != nullptr) {
        vec.push_back(curr);
        curr = curr->next;
    }
    return vec;
}

// Encuentra el primer nodo que cumple con la condición de inicio usando búsqueda binaria
// Complejidad: O(log n)
// Esta función aprovecha que la lista está ordenada por IP
NodoRegistro* GestorBitacora::buscarInicio(long long valorInicio) {
    vector<NodoRegistro*> vec = listaAVector();
    
    if (vec.empty()) {
        return nullptr;
    }
    
    int left = 0;
    int right = vec.size() - 1;
    int resultado = -1;
    
    // Búsqueda binaria para encontrar el primer elemento >= valorInicio
    while (left <= right) {
        int mid = left + (right - left) / 2;
        long long valorMid = vec[mid]->getValorIP();
        
        if (valorMid >= valorInicio) {
            resultado = mid;
            right = mid - 1; // Buscar más a la izquierda
        } else {
            left = mid + 1;
        }
    }
    
    if (resultado == -1) {
        return nullptr;
    }
    
    return vec[resultado];
}

// Busca logs en el rango de IPs dados por el usuario
// Complejidad: O(log n + k) donde k es el número de resultados
// Búsqueda binaria para encontrar el inicio (O(log n))
// Luego búsqueda secuencial solo en el rango hasta encontrar el final (O(k))
NodoRegistro* GestorBitacora::buscarEnRangoIP(const string& ipInicio, const string& ipFin) {
    NodoRegistro* resultHead = nullptr;
    NodoRegistro* resultTail = nullptr;
    
    // Parsear IPs de inicio y fin
    int oct1Ini, oct2Ini, oct3Ini, oct4Ini, puertoIni;
    int oct1Fin, oct2Fin, oct3Fin, oct4Fin, puertoFin;
    
    parsearIPBusqueda(ipInicio, oct1Ini, oct2Ini, oct3Ini, oct4Ini, puertoIni);
    parsearIPBusqueda(ipFin, oct1Fin, oct2Fin, oct3Fin, oct4Fin, puertoFin);
    
    // Crear valores compuestos para comparación
    long long valorIni = ((long long)oct1Ini << 32) | ((long long)oct2Ini << 24) | 
                         ((long long)oct3Ini << 16) | ((long long)oct4Ini << 8) | puertoIni;
    long long valorFin = ((long long)oct1Fin << 32) | ((long long)oct2Fin << 24) | 
                         ((long long)oct3Fin << 16) | ((long long)oct4Fin << 8) | puertoFin;
    
    // Usar búsqueda binaria para encontrar el inicio del rango (O(log n))
    NodoRegistro* curr = buscarInicio(valorIni);
    
    // Si no se encontró ningún elemento >= valorInicio no hay resultados
    if (curr == nullptr) {
        return nullptr;
    }
    
    // Recorrer secuencialmente desde el inicio hasta el final del rango
    // Se detiene INMEDIATAMENTE cuando pasa el valor final (aprovecha que esta ordenado)
    // Complejidad: O(k) donde k es el número de resultados
    // NO continúa iterando después de pasar el rango final
    while (curr != nullptr) {
        long long valorActual = curr->getValorIP();
        
        // OPTIMIZACION CRITICA: Si ya pasamos el rango final, detenemos la busqueda
        // Esto evita continuar iterando innecesariamente por el resto del archivo
        if (valorActual > valorFin) {
            break; // Salida temprana - no mas iteraciones
        }
        
        // Solo procesamos si está dentro del rango
        // (ya sabemos que valorActual >= valorInicio por la búsqueda binaria)
        if (valorActual >= valorIni) {
            // Crear un nuevo nodo con los datos
            NodoRegistro* nvo = new NodoRegistro(curr->lineaCompleta);
            if (resultHead == nullptr) {
                resultHead = resultTail = nvo;
            } else {
                resultTail->next = nvo;
                resultTail = nvo;
            }
        }
        
        curr = curr->next;
    }
    
    return resultHead;
}

// Guarda los resultados de la búsqueda en el archivo resultado
// Complejidad: O(k) donde k es el número de resultados
void GestorBitacora::guardarResultados(NodoRegistro* resultados, int numeroSalida) {
    string nombreArchivo = "salida" + to_string(numeroSalida) + "-eq3.txt";
    ofstream archivo(nombreArchivo);
    
    if (!archivo.is_open()) {
        return;
    }

    NodoRegistro* curr = resultados;
    while (curr != nullptr) {
        archivo << curr->lineaCompleta << endl;
        curr = curr->next;
    }
    archivo.close();
    
    // Liberar memoria de los resultados
    curr = resultados;
    while (curr != nullptr) {
        NodoRegistro* temp = curr;
        curr = curr->next;
        delete temp;
    }
}

// Menu de solicitud de IP inicial y final para buscar registros
// Complejidad total: O(log n + k) donde k es el número de resultados
void GestorBitacora::realizarBusquedaIP() {
    string ipInicio, ipFin;
    cin >> ipInicio >> ipFin;
    
    NodoRegistro* resultados = buscarEnRangoIP(ipInicio, ipFin);
    guardarResultados(resultados, getNumeroBusqueda());
}