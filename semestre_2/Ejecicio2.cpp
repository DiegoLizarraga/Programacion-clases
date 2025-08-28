#include <iostream>
#include <string>

using namespace std;  // Permite usar elementos de la biblioteca estándar sin std::

/**
 * Clase base abstracta que representa un Empleado genérico
 * Contiene información básica y métodos para cálculo de salario
 * Implementa operadores de comparación basados en el salario
 */
class Empleado {
protected:
    string nombre;  // Nombre del empleado
    int edad;      // Edad del empleado (no puede ser negativa)

public:
    /**
     * Constructor de la clase Empleado
     * @param n Nombre del empleado
     * @param e Edad del empleado (si es negativa, se establece a 0)
     */
    Empleado(const string& n, int e) : nombre(n), edad(e < 0 ? 0 : e) {}

    /**
     * Método virtual puro para calcular el salario
     * @return Salario calculado del empleado
     */
    virtual double calcularSalario() const = 0;

    /**
     * Operador menor que (comparación por salario)
     * @param otro Empleado a comparar
     * @return true si este empleado gana menos que el otro
     */
    bool operator<(const Empleado& otro) const {
        return calcularSalario() < otro.calcularSalario();
    }

    /**
     * Operador mayor que (comparación por salario)
     * @param otro Empleado a comparar
     * @return true si este empleado gana más que el otro
     */
    bool operator>(const Empleado& otro) const {
        return calcularSalario() > otro.calcularSalario();
    }

    /**
     * Operador igualdad (comparación por salario)
     * @param otro Empleado a comparar
     * @return true si los empleados ganan igual
     */
    bool operator==(const Empleado& otro) const {
        return calcularSalario() == otro.calcularSalario();
    }

    // Destructor virtual para permitir la destrucción correcta de clases derivadas
    virtual ~Empleado() = default;
};

/**
 * Clase derivada que representa un Empleado con salario fijo
 * Hereda de Empleado y añade salario fijo mensual
 */
class EmpleadoBase : public Empleado {
private:
    double salarioFijo;  // Salario mensual fijo

public:
    /**
     * Constructor de EmpleadoBase
     * @param n Nombre del empleado
     * @param e Edad del empleado
     * @param salario Salario fijo mensual (si es negativo, se establece a 0)
     */
    EmpleadoBase(const string& n, int e, double salario)
        : Empleado(n, e), salarioFijo(salario < 0 ? 0 : salario) {}

    /**
     * Calcula el salario (en este caso simplemente devuelve el salario fijo)
     * @return Salario fijo del empleado
     */
    double calcularSalario() const override {
        return salarioFijo;
    }
};

/**
 * Clase derivada que representa un Empleado por horas
 * Hereda de Empleado y añade horas trabajadas y pago por hora
 */
class EmpleadoPorHora : public Empleado {
private:
    double horasTrabajadas;  // Horas trabajadas en el mes
    double pagoPorHora;      // Pago por cada hora trabajada

public:
    /**
     * Constructor de EmpleadoPorHora
     * @param n Nombre del empleado
     * @param e Edad del empleado
     * @param horas Horas trabajadas (si son negativas, se establecen a 0)
     * @param pago Pago por hora (si es negativo, se establece a 0)
     */
    EmpleadoPorHora(const string& n, int e, double horas, double pago)
        : Empleado(n, e), horasTrabajadas(horas < 0 ? 0 : horas), pagoPorHora(pago < 0 ? 0 : pago) {}

    /**
     * Calcula el salario multiplicando horas trabajadas por pago por hora
     * @return Salario calculado
     */
    double calcularSalario() const override {
        return horasTrabajadas * pagoPorHora;
    }
};

/**
 * Clase derivada que representa un Empleado por comisión
 * Hereda de Empleado y añade ventas y tasa de comisión
 */
class EmpleadoPorComision : public Empleado {
private:
    double ventas;        // Monto total de ventas realizadas
    double tasaComision;  // Porcentaje de comisión sobre ventas

public:
    /**
     * Constructor de EmpleadoPorComision
     * @param n Nombre del empleado
     * @param e Edad del empleado
     * @param v Ventas realizadas (si son negativas, se establecen a 0)
     * @param tasa Tasa de comisión (si es negativa, se establece a 0)
     */
    EmpleadoPorComision(const string& n, int e, double v, double tasa)
        : Empleado(n, e), ventas(v < 0 ? 0 : v), tasaComision(tasa < 0 ? 0 : tasa) {}

    /**
     * Calcula el salario multiplicando ventas por tasa de comisión
     * @return Salario calculado
     */
    double calcularSalario() const override {
        return ventas * tasaComision;
    }
};

int main() {
    // Creación de empleados de diferentes tipos
    Empleado* emp1 = new EmpleadoBase("Juan", 30, 5000.0);
    Empleado* emp2 = new EmpleadoPorHora("Ana", 25, 160.0, 20.0);
    Empleado* emp3 = new EmpleadoPorComision("Pedro", 35, 100000.0, 0.1);

    // Mostrar salarios de cada empleado
    cout << "Salario Juan: $" << emp1->calcularSalario() << endl;
    cout << "Salario Ana: $" << emp2->calcularSalario() << endl;
    cout << "Salario Pedro: $" << emp3->calcularSalario() << endl;

    // Comparaciones entre empleados
    cout << "Juan > Ana: " << (*emp1 > *emp2) << endl;    // Compara salarios
    cout << "Ana < Pedro: " << (*emp2 < *emp3) << endl;   // Compara salarios

    // Liberar memoria
    delete emp1;
    delete emp2;
    delete emp3;
    
    return 0;
}