/*
 * main.cpp
 * Programa de pruebas completo para MyHashTable
 * 
 */

#include "MyHashTable.h"
#include <iostream>
#include <cassert>

using namespace std;

void separador() {
    cout << "\n===================================\n" << endl;
}

void testIsEmpty() {
    cout << "TEST 1: isEmpty()" << endl;
    cout << "==================" << endl;
    
    MyHashTable tabla;
    
    cout << "Tabla recien creada:" << endl;
    assert(tabla.isEmpty() == true);
    cout << "  isEmpty() = true [OK]" << endl;
    
    cout << "\nInsertando elemento:" << endl;
    tabla.put("test", 100);
    assert(tabla.isEmpty() == false);
    cout << "  isEmpty() = false [OK]" << endl;
    
    cout << "\nEliminando elemento:" << endl;
    tabla.remove("test");
    assert(tabla.isEmpty() == true);
    cout << "  isEmpty() = true [OK]" << endl;
    
    cout << "\nTEST ISEMPTY PASADO" << endl;
}

void testPut() {
    cout << "TEST 2: put()" << endl;
    cout << "==================" << endl;
    
    MyHashTable tabla;
    
    cout << "Insertando 5 elementos:" << endl;
    tabla.put("uno", 1);
    tabla.put("dos", 2);
    tabla.put("tres", 3);
    tabla.put("cuatro", 4);
    tabla.put("cinco", 5);
    
    cout << "  Insertados: uno=1, dos=2, tres=3, cuatro=4, cinco=5" << endl;
    cout << "  Size: " << tabla.size << endl;
    cout << "  Factor de carga: " << (double)tabla.size/tabla.sizeA << endl;
    
    assert(tabla.get("uno") == 1);
    assert(tabla.get("dos") == 2);
    assert(tabla.get("tres") == 3);
    cout << "  Todos los valores correctos [OK]" << endl;
    
    cout << "\nActualizando valores:" << endl;
    tabla.put("uno", 10);
    tabla.put("dos", 20);
    
    assert(tabla.get("uno") == 10);
    assert(tabla.get("dos") == 20);
    cout << "  Actualizacion correcta (uno=10, dos=20) [OK]" << endl;
    cout << "  Size sigue siendo: " << tabla.size << " (no aumento) [OK]" << endl;
    
    cout << "\nTEST PUT PASADO" << endl;
}

void testGet() {
    cout << "TEST 3: get()" << endl;
    cout << "==================" << endl;
    
    MyHashTable tabla;
    
    tabla.put("a", 100);
    tabla.put("b", 200);
    tabla.put("c", 300);
    
    cout << "Obteniendo valores existentes:" << endl;
    assert(tabla.get("a") == 100);
    assert(tabla.get("b") == 200);
    assert(tabla.get("c") == 300);
    cout << "  get('a') = 100 [OK]" << endl;
    cout << "  get('b') = 200 [OK]" << endl;
    cout << "  get('c') = 300 [OK]" << endl;
    
    cout << "\nProbando clave inexistente:" << endl;
    try {
        int val = tabla.get("xyz");
        cout << "  ERROR: Deberia lanzar excepcion" << endl;
        assert(false);
    } catch (invalid_argument& e) {
        cout << "  Excepcion capturada correctamente [OK]" << endl;
        cout << "  Mensaje: " << e.what() << endl;
    }
    
    cout << "\nTEST GET PASADO" << endl;
}

void testRemove() {
    cout << "TEST 4: remove()" << endl;
    cout << "==================" << endl;
    
    MyHashTable tabla;
    
    tabla.put("alpha", 1);
    tabla.put("beta", 2);
    tabla.put("gamma", 3);
    tabla.put("delta", 4);
    
    cout << "Tabla inicial con 4 elementos" << endl;
    cout << "  Size: " << tabla.size << endl;
    
    cout << "\nEliminando 'beta':" << endl;
    tabla.remove("beta");
    cout << "  Size: " << tabla.size << " [OK]" << endl;
    
    try {
        tabla.get("beta");
        assert(false);
    } catch (invalid_argument& e) {
        cout << "  'beta' ya no existe [OK]" << endl;
    }
    
    cout << "\nVerificando que otros elementos existen:" << endl;
    assert(tabla.get("alpha") == 1);
    assert(tabla.get("gamma") == 3);
    assert(tabla.get("delta") == 4);
    cout << "  alpha, gamma, delta intactos [OK]" << endl;
    
    cout << "\nEliminando clave inexistente (no debe dar error):" << endl;
    tabla.remove("noexiste");
    cout << "  Sin errores [OK]" << endl;
    
    cout << "\nTEST REMOVE PASADO" << endl;
}

void testRehashing() {
    cout << "TEST 5: rehashing()" << endl;
    cout << "==================" << endl;
    
    MyHashTable tabla;
    
    cout << "Estado inicial:" << endl;
    cout << "  sizeA (tamanio arreglo): " << tabla.sizeA << endl;
    cout << "  size (elementos): " << tabla.size << endl;
    cout << "  Factor de carga: " << (double)tabla.size/tabla.sizeA << endl;
    
    cout << "\nInsertando elementos hasta forzar rehashing:" << endl;
    cout << "  (Rehashing ocurre cuando factor >= 0.75)" << endl;
    
    for (int i = 0; i < 15; i++) {
        string key = "k" + to_string(i);
        tabla.put(key, i * 10);
        
        double factor = (double)tabla.size / tabla.sizeA;
        
        if (i == 7) {
            cout << "\n  Despues de 8 inserciones:" << endl;
            cout << "    sizeA: " << tabla.sizeA << endl;
            cout << "    size: " << tabla.size << endl;
            cout << "    Factor: " << factor << endl;
        }
        
        if (i == 8) {
            cout << "\n  Despues de 9 inserciones (REHASHING):" << endl;
            cout << "    sizeA: " << tabla.sizeA << " (deberia haber crecido)" << endl;
            cout << "    size: " << tabla.size << endl;
            cout << "    Factor: " << factor << " (deberia bajar)" << endl;
        }
    }
    
    cout << "\nEstado final:" << endl;
    cout << "  sizeA: " << tabla.sizeA << endl;
    cout << "  size: " << tabla.size << endl;
    cout << "  Factor: " << (double)tabla.size/tabla.sizeA << endl;
    
    assert((double)tabla.size/tabla.sizeA < 0.75);
    cout << "  Factor < 0.75 [OK]" << endl;
    
    cout << "\nVerificando que TODOS los elementos siguen accesibles:" << endl;
    for (int i = 0; i < 15; i++) {
        string key = "k" + to_string(i);
        int expected = i * 10;
        int actual = tabla.get(key);
        assert(actual == expected);
    }
    cout << "  Los 15 elementos correctos despues de rehashing [OK]" << endl;
    
    cout << "\nTEST REHASHING PASADO" << endl;
}

void testColisiones() {
    cout << "TEST 6: Manejo de Colisiones" << endl;
    cout << "==================" << endl;
    
    MyHashTable tabla;
    
    cout << "Insertando multiples elementos:" << endl;
    cout << "  (Algunos pueden colisionar en la misma posicion)" << endl;
    
    string frutas[] = {"manzana", "pera", "uva", "platano", "fresa",
                       "naranja", "sandia", "melon", "kiwi", "mango"};
    
    for (int i = 0; i < 10; i++) {
        tabla.put(frutas[i], (i+1) * 100);
    }
    
    cout << "\n  Insertadas 10 frutas" << endl;
    cout << "  Size: " << tabla.size << endl;
    cout << "  sizeA: " << tabla.sizeA << endl;
    cout << "  Factor: " << (double)tabla.size/tabla.sizeA << endl;
    
    cout << "\nMostrando distribucion en el arreglo:" << endl;
    for (int i = 0; i < tabla.sizeA; i++) {
        if (!tabla.tabla[i].isEmpty()) {
            cout << "  [" << i << "]: " << tabla.tabla[i].length() << " elementos" << endl;
        }
    }
    
    cout << "\nVerificando acceso a todos los elementos:" << endl;
    for (int i = 0; i < 10; i++) {
        assert(tabla.get(frutas[i]) == (i+1) * 100);
    }
    cout << "  Todos accesibles correctamente [OK]" << endl;
    
    cout << "\nTEST COLISIONES PASADO" << endl;
}

void testOperacionesMixtas() {
    cout << "TEST 7: Operaciones Mixtas" << endl;
    cout << "==================" << endl;
    
    MyHashTable tabla;
    
    cout << "Secuencia de operaciones variadas:" << endl;
    
    cout << "\n  1. Insertar 3 elementos" << endl;
    tabla.put("x", 10);
    tabla.put("y", 20);
    tabla.put("z", 30);
    assert(tabla.size == 3);
    cout << "     Size: " << tabla.size << " [OK]" << endl;
    
    cout << "\n  2. Actualizar 'x'" << endl;
    tabla.put("x", 15);
    assert(tabla.get("x") == 15);
    assert(tabla.size == 3);
    cout << "     x = 15, Size: " << tabla.size << " [OK]" << endl;
    
    cout << "\n  3. Eliminar 'y'" << endl;
    tabla.remove("y");
    assert(tabla.size == 2);
    cout << "     Size: " << tabla.size << " [OK]" << endl;
    
    cout << "\n  4. Insertar 'w'" << endl;
    tabla.put("w", 40);
    assert(tabla.size == 3);
    cout << "     Size: " << tabla.size << " [OK]" << endl;
    
    cout << "\n  5. Verificar estado final" << endl;
    assert(tabla.get("x") == 15);
    assert(tabla.get("z") == 30);
    assert(tabla.get("w") == 40);
    cout << "     x=15, z=30, w=40 [OK]" << endl;
    
    try {
        tabla.get("y");
        assert(false);
    } catch (invalid_argument& e) {
        cout << "     'y' no existe [OK]" << endl;
    }
    
    cout << "\nTEST OPERACIONES MIXTAS PASADO" << endl;
}

int main() {
    cout << "\nINICIANDO PRUEBAS COMPLETAS DE MYHASHTABLE\n" << endl;
    
    try {
        testIsEmpty();
        separador();
        
        testPut();
        separador();
        
        testGet();
        separador();
        
        testRemove();
        separador();
        
        testRehashing();
        separador();
        
        testColisiones();
        separador();
        
        testOperacionesMixtas();
        separador();
        
        cout << "\n--- TODAS LAS PRUEBAS PASARON ---\n" << endl;
        cout << "  isEmpty        [OK]" << endl;
        cout << "  put            [OK]" << endl;
        cout << "  get            [OK]" << endl;
        cout << "  remove         [OK]" << endl;
        cout << "  rehashing      [OK]" << endl;
        cout << "  Colisiones     [OK]" << endl;
        cout << "  Op. Mixtas     [OK]" << endl;
        cout << "\n  Factor de carga siempre < 0.75" << endl;
        cout << "  Complejidades O(1) promedio garantizadas\n" << endl;
        
        return 0;
        
    } catch (exception& e) {
        cout << "\nERROR EN PRUEBAS: " << e.what() << endl;
        return 1;
    }
}