/*
 * MyHashTable.cpp
 * Implementación compatible con tu MyLinkedList existente
 * 
 * Autor: Diego Martin Lizarraga Sanchez - A01647334
 * Fecha: Noviembre 2025
 */

#include "MyHashTable.h"
#include <iostream>
#include <stdexcept>

using namespace std;

/*
 * Constructor - Inicializa tabla con tamaño 11
 * 
 * Complejidad: O(1)
 * Supuesto: Factor de carga α < 0.75, hash equitativo
 * 
 * Explicación: Crea arreglo de 11 listas vacías. El tamaño 11
 * es primo, lo que ayuda a la dispersión equitativa con la
 * operación módulo en getPos().
 */
MyHashTable::MyHashTable() {
    this->size = 0;
    this->sizeA = 11;
    this->tabla = new MyLinkedList[this->sizeA];
}

/*
 * Destructor - Libera memoria
 * 
 * Complejidad: O(n + m) donde n=elementos, m=sizeA
 * Supuesto: Factor de carga α < 0.75, hash equitativo
 * 
 * Explicación: Cada MyLinkedList destruye sus nodos (O(n) total),
 * luego se libera el arreglo de listas (O(m)).
 */
MyHashTable::~MyHashTable() {
    delete[] tabla;
}

/*
 * Calcula posición para una clave usando función hash
 * 
 * Complejidad: O(1)
 * Supuesto: Factor de carga α < 0.75, hash equitativo
 * 
 * Explicación: std::hash<string> genera un hash en tiempo
 * proporcional a la longitud del string (constante para strings
 * típicos). La operación módulo % sizeA y abs() son O(1).
 * 
 * La función hash de C++ dispersa las cadenas de manera
 * aproximadamente uniforme, cumpliendo el supuesto de
 * dispersión equitativa.
 */
int MyHashTable::getPos(string key) {
    size_t hashC = hash<string>{}(key);
    int hashCode = static_cast<int>(hashC);
    return abs(hashCode) % this->sizeA;
}

/*
 * Verifica si la tabla está vacía
 * 
 * Complejidad: O(1)
 * Supuesto: Factor de carga α < 0.75, hash equitativo
 * 
 * Explicación: Solo verifica el contador size, que se mantiene
 * actualizado en cada operación put/remove.
 */
bool MyHashTable::isEmpty() {
    return this->size == 0;
}

/*
 * Inserta o actualiza par key-value
 * 
 * Complejidad: O(1) promedio
 * Supuesto: Factor de carga α < 0.75, hash equitativo
 * 
 * Explicación detallada:
 * 1. Verificar factor de carga: O(1)
 * 2. Rehashing (si α >= 0.75): O(n) raramente
 *    - Análisis amortizado: ocurre cada ~0.75m inserciones
 *    - Costo distribuido: O(n)/(0.75m) = O(1) por inserción
 * 3. getPos(key): O(1)
 * 4. Buscar en lista:
 *    - Con α < 0.75 y hash equitativo: longitud esperada = α
 *    - Búsqueda: O(α) = O(1)
 * 5. Actualizar o insertar: O(1)
 * 
 * Total: O(1) + O(1) + O(1) + O(1) = O(1) promedio
 * 
 * El supuesto de hash equitativo garantiza que los elementos
 * se distribuyen uniformemente entre las m posiciones, por lo
 * que cada lista tiene longitud esperada n/m = α < 0.75.
 */
void MyHashTable::put(string key, int value) {
    // Verificar factor de carga y hacer rehashing si es necesario
    double factorCarga = static_cast<double>(size) / sizeA;
    if (factorCarga >= 0.75) {
        rehashing();
    }
    
    int pos = getPos(key);
    MyLinkedList& lista = tabla[pos];
    
    // Buscar si la clave ya existe en la lista
    MyNodoLL* curr = lista.head;
    while (curr != nullptr) {
        if (curr->data.key == key) {  // Acceso correcto: curr->data.key
            // Actualizar valor existente
            curr->data.value = value;  // Acceso correcto: curr->data.value
            return;  // No incrementar size
        }
        curr = curr->next;
    }
    
    // Si no existe, insertar nuevo par al inicio
    HashPair newPair(key, value);  // Crear HashPair
    lista.insertFirst(newPair);     // Pasar HashPair como un solo argumento
    this->size++;
}

/*
 * Obtiene valor asociado a clave
 * 
 * Complejidad: O(1) promedio
 * Supuesto: Factor de carga α < 0.75, hash equitativo
 * 
 * Explicación:
 * 1. getPos(key): O(1)
 * 2. Búsqueda en lista:
 *    - Con dispersión equitativa: longitud esperada = α < 0.75
 *    - Búsqueda secuencial: O(α) = O(1)
 * 3. Retornar valor: O(1)
 * 
 * Total: O(1) + O(1) + O(1) = O(1) promedio
 * 
 * Peor caso (sin supuestos): O(n) si todas las claves
 * colisionan en una posición, pero esto viola el supuesto
 * de dispersión equitativa.
 */
int MyHashTable::get(string key) {
    int pos = getPos(key);
    MyLinkedList& lista = tabla[pos];
    
    if (lista.isEmpty()) {
        throw invalid_argument("Error: clave '" + key + "' no encontrada");
    }
    
    // Buscar en la lista
    MyNodoLL* curr = lista.head;
    while (curr != nullptr) {
        if (curr->data.key == key) {  // Acceso correcto: curr->data.key
            return curr->data.value;   // Acceso correcto: curr->data.value
        }
        curr = curr->next;
    }
    
    throw invalid_argument("Error: clave '" + key + "' no encontrada");
}

/*
 * Elimina par key-value de la tabla
 * 
 * Complejidad: O(1) promedio
 * Supuesto: Factor de carga α < 0.75, hash equitativo
 * 
 * Explicación:
 * 1. getPos(key): O(1)
 * 2. Buscar posición en lista: O(α) = O(1)
 * 3. removeAt(index):
 *    - En lista de longitud α: O(α) = O(1)
 * 4. Decrementar size: O(1)
 * 
 * Total: O(1) + O(1) + O(1) + O(1) = O(1) promedio
 * 
 * Con listas cortas (α < 0.75), todas las operaciones
 * de búsqueda y eliminación son tiempo constante esperado.
 */
void MyHashTable::remove(string key) {
    int pos = getPos(key);
    MyLinkedList& lista = tabla[pos];
    
    if (lista.isEmpty()) {
        return;  // No hay nada que eliminar
    }
    
    // Buscar la clave en la lista
    MyNodoLL* curr = lista.head;
    int index = 0;
    
    while (curr != nullptr) {
        if (curr->data.key == key) {  // Acceso correcto: curr->data.key
            // Encontrada, eliminar usando removeAt
            lista.removeAt(index);
            this->size--;
            return;
        }
        curr = curr->next;
        index++;
    }
}

/*
 * Rehashing - Duplica tamaño y redistribuye elementos
 * 
 * Complejidad: O(n) donde n = número de elementos
 * Supuesto: Factor de carga α < 0.75, hash equitativo
 * 
 * Explicación detallada:
 * 1. Guardar referencia a tabla antigua: O(1)
 * 2. Crear nueva tabla de tamaño 2m+1: O(1)
 *    - El nuevo tamaño es impar para mantener buena dispersión
 * 3. Recorrer todas las posiciones antiguas: O(m)
 * 4. Procesar n elementos totales:
 *    - Para cada elemento:
 *      * Calcular nuevo hash: O(1)
 *      * Insertar en nueva posición: O(1)
 *    - Total: n × O(1) = O(n)
 * 5. Liberar tabla antigua: O(n + m)
 * 
 * Total: O(1) + O(1) + O(m) + O(n) + O(n+m) = O(n + m)
 * 
 * Como se activa cuando n ≥ 0.75m (α ≥ 0.75), tenemos n ≥ m,
 * por tanto: O(n + m) = O(n)
 * 
 * Análisis del factor de carga:
 * - Antes del rehashing: α = n/m ≥ 0.75
 * - Después del rehashing: α' = n/(2m+1) ≈ n/(2m) ≈ α/2 ≈ 0.375
 * - Esto garantiza que α' < 0.75 después del rehashing
 * - El siguiente rehashing ocurrirá cuando se duplique n
 * 
 * El tamaño 2m+1 (impar) ayuda a evitar divisores comunes
 * con patrones de hash, mejorando la dispersión.
 */
void MyHashTable::rehashing() {
    int oldSizeA = this->sizeA;
    MyLinkedList* oldTabla = this->tabla;
    
    // Crear nueva tabla con tamaño 2*n + 1
    this->sizeA = 2 * oldSizeA + 1;
    this->tabla = new MyLinkedList[this->sizeA];
    this->size = 0;
    
    // Reinsertar todos los elementos
    for (int i = 0; i < oldSizeA; i++) {
        MyLinkedList& lista = oldTabla[i];
        MyNodoLL* curr = lista.head;
        
        while (curr != nullptr) {
            string key = curr->data.key;      // Acceso correcto: curr->data.key
            int value = curr->data.value;     // Acceso correcto: curr->data.value
            
            // Calcular nueva posición e insertar directamente
            // No llamamos a put() para evitar verificar factor de carga
            int newPos = getPos(key);
            HashPair pair(key, value);        // Crear HashPair
            tabla[newPos].insertFirst(pair);  // Pasar HashPair como un solo argumento
            this->size++;
            
            curr = curr->next;
        }
    }
    
    // Liberar la tabla antigua
    delete[] oldTabla;
}

/**
 * ============================================================================
 * RESUMEN DE COMPLEJIDADES (con α < 0.75 y hash equitativo)
 * ============================================================================
 * 
 * Constructor:  O(1)     - Inicializa arreglo de listas vacías
 * Destructor:   O(n+m)   - Libera n elementos y m listas
 * isEmpty:      O(1)     - Verifica contador size
 * put:          O(1)     - Promedio con rehashing amortizado
 * get:          O(1)     - Búsqueda en lista de longitud α
 * remove:       O(1)     - Búsqueda y eliminación en lista corta
 * rehashing:    O(n)     - Procesa todos los elementos una vez
 * getPos:       O(1)     - Función hash y módulo
 * 
 * SUPUESTOS CRÍTICOS:
 * 1. Factor de carga α = n/m < 0.75 se mantiene siempre
 *    - Verificado en put() antes de cada inserción
 *    - Rehashing automático cuando α ≥ 0.75
 * 
 * 2. Hash dispersa equitativamente (distribución uniforme simple)
 *    - std::hash<string> proporciona buena dispersión
 *    - Módulo con número primo (11, 23, 47, ...) mejora uniformidad
 *    - Cada posición tiene longitud esperada α = n/m
 * 
 * 3. Strings de longitud razonable (< 100 caracteres típicamente)
 *    - Hash string es O(longitud), considerado O(1) para strings típicos
 * 
 * Sin estos supuestos, las complejidades pueden degradarse:
 * - put, get, remove: O(n) en peor caso (todas las claves en una posición)
 * - Esto ocurre con hash pobre o α >> 1
 * 
 * ============================================================================
 * 
 * REFERENCIAS:
 * 
 * [1] Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C. (2009).
 *     Introduction to Algorithms (3rd ed.). MIT Press.
 *     Capítulo 11: Hash Tables, Sección 11.2: Hash tables con chaining
 *     - Define "simple uniform hashing" como supuesto de dispersión equitativa
 *     - Demuestra E[longitud lista] = α bajo este supuesto
 *     - Análisis de búsqueda exitosa: Θ(1 + α)
 * 
 * [2] GeeksforGeeks. (2024). Hashing | Set 2 (Separate Chaining).
 *     https://www.geeksforgeeks.org/hashing-set-2-separate-chaining/
 *     (Accedido: Noviembre 2025)
 * 
 * [3] GeeksforGeeks. (2024). Load Factor and Rehashing.
 *     https://www.geeksforgeeks.org/load-factor-and-rehashing/
 *     (Accedido: Noviembre 2025)
 * 
 * [4] cppreference.com. (2024). std::hash.
 *     https://en.cppreference.com/w/cpp/utility/hash
 *     (Accedido: Noviembre 2025)
 * 
 * [5] Sedgewick, R., & Wayne, K. (2011). Algorithms (4th ed.).
 *     Addison-Wesley. Sección 3.4: Hash Tables.
 *     - Discute importancia del factor de carga
 *     - Recomienda mantener α entre 0.5 y 0.75 para buen rendimiento
 */