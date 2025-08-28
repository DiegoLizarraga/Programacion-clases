#include <iostream>
#include <string>

using namespace std;  // Permite usar los elementos de la biblioteca estándar sin el prefijo std::

/**
 * Clase base que representa un Envío genérico
 * Contiene información del remitente y destinatario, y costo estándar
 */
class Envio {
protected:
    // Datos del remitente
    string remitenteNombre;
    string remitenteDireccion;
    string remitenteCiudad;
    string remitenteEstado;
    string remitenteCodigoPostal;
    
    // Datos del destinatario
    string destinatarioNombre;
    string destinatarioDireccion;
    string destinatarioCiudad;
    string destinatarioEstado;
    string destinatarioCodigoPostal;
    
    // Costo base del envío
    double costoEstandar;

public:
    /**
     * Constructor de la clase Envio
     * @param rNombre Nombre del remitente
     * @param rDireccion Dirección del remitente
     * @param rCiudad Ciudad del remitente
     * @param rEstado Estado del remitente
     * @param rCodigoPostal Código postal del remitente
     * @param dNombre Nombre del destinatario
     * @param dDireccion Dirección del destinatario
     * @param dCiudad Ciudad del destinatario
     * @param dEstado Estado del destinatario
     * @param dCodigoPostal Código postal del destinatario
     * @param costo Costo estándar del envío
     */
    Envio(const string& rNombre, const string& rDireccion, const string& rCiudad,
          const string& rEstado, const string& rCodigoPostal,
          const string& dNombre, const string& dDireccion, const string& dCiudad,
          const string& dEstado, const string& dCodigoPostal, double costo)
        : remitenteNombre(rNombre), remitenteDireccion(rDireccion), remitenteCiudad(rCiudad),
          remitenteEstado(rEstado), remitenteCodigoPostal(rCodigoPostal),
          destinatarioNombre(dNombre), destinatarioDireccion(dDireccion), destinatarioCiudad(dCiudad),
          destinatarioEstado(dEstado), destinatarioCodigoPostal(dCodigoPostal), costoEstandar(costo) {}

    /**
     * Método virtual para calcular el costo del envío
     * @return Costo del envío (en este caso solo devuelve el costo estándar)
     */
    virtual double calculaCosto() const {
        return costoEstandar;
    }

    // Destructor virtual para permitir la destrucción correcta de clases derivadas
    virtual ~Envio() = default;
};

/**
 * Clase derivada que representa un Paquete
 * Hereda de Envio y añade dimensiones, peso y costo por kilogramo
 */
class Paquete : public Envio {
private:
    double largo;        // Largo del paquete en cm
    double ancho;        // Ancho del paquete en cm
    double profundidad;  // Profundidad del paquete en cm
    double peso;         // Peso del paquete en kg
    double costoPorKg;   // Costo adicional por kilogramo

public:
    /**
     * Constructor de la clase Paquete
     * @param rNombre a rCodigoPostal Datos del remitente (heredados)
     * @param dNombre a dCodigoPostal Datos del destinatario (heredados)
     * @param costo Costo base del envío
     * @param l Largo del paquete
     * @param a Ancho del paquete
     * @param p Profundidad del paquete
     * @param pes Peso del paquete (si es negativo, se establece a 0)
     * @param costoKg Costo por kilogramo (si es negativo, se establece a 0)
     */
    Paquete(const string& rNombre, const string& rDireccion, const string& rCiudad,
            const string& rEstado, const string& rCodigoPostal,
            const string& dNombre, const string& dDireccion, const string& dCiudad,
            const string& dEstado, const string& dCodigoPostal,
            double costo, double l, double a, double p, double pes, double costoKg)
        : Envio(rNombre, rDireccion, rCiudad, rEstado, rCodigoPostal,
                dNombre, dDireccion, dCiudad, dEstado, dCodigoPostal, costo),
          largo(l), ancho(a), profundidad(p), peso(pes < 0 ? 0 : pes), costoPorKg(costoKg < 0 ? 0 : costoKg) {}

    /**
     * Calcula el costo total del paquete
     * @return Costo estándar más el costo por peso (peso * costo por kg)
     */
    double calculaCosto() const override {
        return costoEstandar + (peso * costoPorKg);
    }
};

/**
 * Clase derivada que representa un Sobre
 * Hereda de Envio y añade dimensiones y cargo adicional por tamaño excedente
 */
class Sobre : public Envio {
private:
    double largo;           // Largo del sobre en cm
    double ancho;           // Ancho del sobre en cm
    double cargoAdicional;  // Cargo adicional si excede dimensiones estándar

public:
    /**
     * Constructor de la clase Sobre
     * @param rNombre a rCodigoPostal Datos del remitente (heredados)
     * @param dNombre a dCodigoPostal Datos del destinatario (heredados)
     * @param costo Costo base del envío
     * @param l Largo del sobre
     * @param a Ancho del sobre
     * @param cargo Cargo adicional (si es negativo, se establece a 0)
     */
    Sobre(const string& rNombre, const string& rDireccion, const string& rCiudad,
          const string& rEstado, const string& rCodigoPostal,
          const string& dNombre, const string& dDireccion, const string& dCiudad,
          const string& dEstado, const string& dCodigoPostal,
          double costo, double l, double a, double cargo)
        : Envio(rNombre, rDireccion, rCiudad, rEstado, rCodigoPostal,
                dNombre, dDireccion, dCiudad, dEstado, dCodigoPostal, costo),
          largo(l), ancho(a), cargoAdicional(cargo < 0 ? 0 : cargo) {}

    /**
     * Calcula el costo total del sobre
     * @return Costo estándar más cargo adicional si las dimensiones exceden los límites
     *         (25cm de largo o 30cm de ancho)
     */
    double calculaCosto() const override {
        if (largo > 25 || ancho > 30) {
            return costoEstandar + cargoAdicional;
        }
        return costoEstandar;
    }
};

int main() {
    // Creación de un paquete con todos los datos necesarios
    Envio* envio1 = new Paquete("Juan", "Calle 1", "Ciudad A", "Estado A", "12345",
                                "Ana", "Calle 2", "Ciudad B", "Estado B", "67890",
                                10.0, 20.0, 15.0, 10.0, 5.0, 2.0);
    
    // Creación de un sobre con todos los datos necesarios
    Envio* envio2 = new Sobre("Pedro", "Calle 3", "Ciudad C", "Estado C", "11111",
                              "Maria", "Calle 4", "Ciudad D", "Estado D", "22222",
                              5.0, 26.0, 31.0, 3.0);

    // Mostrar los costos de cada envío
    cout << "Costo Paquete: $" << envio1->calculaCosto() << endl;
    cout << "Costo Sobre: $" << envio2->calculaCosto() << endl;

    // Liberar memoria
    delete envio1;
    delete envio2;
    
    return 0;
}