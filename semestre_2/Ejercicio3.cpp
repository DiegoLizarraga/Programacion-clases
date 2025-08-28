#include <iostream> 
#include <cmath>    // Para funciones matemáticas como sqrt y pow

using namespace std; 

// Clase base que representa un punto en un espacio bidimensional con coordenadas x e y
class Punto2D {
protected:
    double x, y; // Coordenadas protegidas para acceso por clases derivadas

public:
    // Constructor para inicializar las coordenadas x e y
    Punto2D(double xCoord, double yCoord) : x(xCoord), y(yCoord) {}

    // Obtener la coordenada x
    double getX() const { return x; }
    
    // Obtener la coordenada y
    double getY() const { return y; }

    // Método virtual para calcular la distancia euclidiana entre este punto y otro
    virtual double calcularDistancia(const Punto2D* otro) const {
        if (!otro) { // Verifica si el puntero es nulo para evitar errores
            cout << "Error: Puntero nulo en calcularDistancia" << endl;
            return 0.0;
        }
        // Calcula la distancia euclidiana 2D: sqrt((x2-x1)^2 + (y2-y1)^2)
        return sqrt(pow(x - otro->getX(), 2) + pow(y - otro->getY(), 2));
    }

    // Sobrecarga del operador + para sumar dos puntos 2D, devolviendo un nuevo Punto2D
    Punto2D operator+(const Punto2D& otro) const {
        return Punto2D(x + otro.getX(), y + otro.getY());
    }

    // Método virtual para imprimir las coordenadas del punto
    virtual void imprimir() const {
        cout << "Punto2D(" << x << ", " << y << ")";
    }

    // Destructor virtual para garantizar la limpieza adecuada de clases derivadas
    virtual ~Punto2D() = default;
};

// Clase derivada que representa un punto en un espacio tridimensional, hereda de Punto2D
class Punto3D : public Punto2D {
private:
    double z; // Coordenada z adicional para el espacio 3D

public:
    // Constructor para inicializar x, y (a través de Punto2D) y z
    Punto3D(double xCoord, double yCoord, double zCoord) : Punto2D(xCoord, yCoord), z(zCoord) {}

    // Obtener la coordenada z
    double getZ() const { return z; }

    // Sobrescribe calcularDistancia para calcular distancia 3D o usar 2D si es necesario
    double calcularDistancia(const Punto2D* otro) const override {
        if (!otro) { // Verifica si el puntero es nulo
            cout << "Error: Puntero nulo en calcularDistancia" << endl;
            return 0.0;
        }
        // Intenta convertir el otro punto a Punto3D para calcular distancia 3D
        const Punto3D* otro3D = dynamic_cast<const Punto3D*>(otro);
        if (otro3D) {
            // Calcula la distancia euclidiana 3D: sqrt((x2-x1)^2 + (y2-y1)^2 + (z2-z1)^2)
            return sqrt(pow(x - otro3D->getX(), 2) + pow(y - otro3D->getY(), 2) + pow(z - otro3D->getZ(), 2));
        }
        // Si no es Punto3D, advierte y usa el cálculo de distancia 2D
        cout << "Advertencia: Tratando Punto3D como Punto2D para cálculo de distancia (z ignorado)" << endl;
        return Punto2D::calcularDistancia(otro);
    }

    // Sobrecarga del operador + para sumar este punto 3D con otro punto
    Punto3D operator+(const Punto2D& otro) const {
        // Intenta convertir el otro punto a Punto3D
        const Punto3D* otro3D = dynamic_cast<const Punto3D*>(&otro);
        if (otro3D) {
            // Si ambos son Punto3D, suma todas las coordenadas
            return Punto3D(x + otro3D->getX(), y + otro3D->getY(), z + otro3D->getZ());
        }
        // Si el otro es Punto2D, suma x e y, establece z en 0 y advierte
        cout << "Advertencia: Sumando Punto2D a Punto3D, estableciendo z en 0" << endl;
        return Punto3D(x + otro.getX(), y + otro.getY(), 0);
    }

    // Sobrescribe imprimir para mostrar las coordenadas 3D
    void imprimir() const override {
        cout << "Punto3D(" << x << ", " << y << ", " << z << ")";
    }
};

// Función principal para demostrar la funcionalidad
int main() {
    // Crear puntos usando punteros para polimorfismo
    Punto2D* p1 = new Punto2D(1.0, 2.0); // Punto 2D en (1, 2)
    Punto2D* p2 = new Punto3D(1.0, 2.0, 3.0); // Punto 3D en (1, 2, 3)
    Punto2D* p3 = new Punto3D(4.0, 5.0, 6.0); // Punto 3D en (4, 5, 6)

    // Calcular y mostrar distancias
    cout << "Distancia p1-p2 (2D a 3D): " << p1->calcularDistancia(p2) << endl; // Esperado: 3 (z ignorado)
    cout << "Distancia p2-p3 (3D a 3D): " << p2->calcularDistancia(p3) << endl; // Esperado: ~5.19615

    // Sumar puntos y mostrar resultado
    cout << "Suma p1 + p2 (2D + 3D): ";
    Punto2D suma = *p1 + *p2; // Usa Punto2D::operator+, resulta en Punto2D
    suma.imprimir(); // Esperado: Punto2D(2, 4)
    cout << endl;

    // Sumar dos objetos Punto3D
    Punto3D* p3d = dynamic_cast<Punto3D*>(p2); // Convierte p2 a Punto3D
    Punto3D* p3d2 = dynamic_cast<Punto3D*>(p3); // Convierte p3 a Punto3D
    if (p3d && p3d2) {
        cout << "Suma p2 + p3 (3D + 3D): ";
        Punto3D suma3D = *p3d + *p3d2; // Usa Punto3D::operator+
        suma3D.imprimir(); // Esperado: Punto3D(5, 7, 9)
        cout << endl;
    } else {
        cout << "Error: No se pudo convertir a Punto3D para suma 3D" << endl;
    }

    // Liberar memoria asignada dinámicamente
    delete p1;
    delete p2;
    delete p3;
    return 0;
}
