#include <iostream>
#include <string>

using namespace std;

// **Clase Base (Padre)**: La "madre" de todas las figuras. Tiene posición (x, y) y un método para "dibujarse".
class Shape {
protected:
    int x;  // Posición en X (horizontal)
    int y;  // Posición en Y (vertical)

public:
    // Constructor: Aquí le damos valores iniciales a x y y.
    Shape(int X, int Y) : x(X), y(Y) {}  

    // Método Virtual: Esto permite que las clases hijas lo modifiquen (polimorfismo si).
    virtual string draw() { return "Soy una figura"; }  

    // Método normal: Devuelve la posición X.
    int getX() { return x; }  
};

// **Clase Círculo con radio
class Circle : public Shape {
private:
    int radio;  // El radio 

public:
    // Constructor: Llama al constructor de Shape 
    Circle(int X, int Y, int R) : Shape(X, Y), radio(R) {}  

    // **Sobrescribe el método draw(
    string draw() override { return "Soy un circulo"; }  
};

// --Clase Rectángulo  Tiene ancho y alto.
class Rectangle : public Shape {
private:
    int alto;   // Qué tan alto es
    int ancho;  // Qué tan ancho es

public:
    // Constructor: Llama al de Shape y guarda alto y ancho.
    Rectangle(int X, int Y, int Alto, int Ancho) : Shape(X, Y), alto(Alto), ancho(Ancho) {}  

    // :D Sobrescribe el método draw()
    string draw() override { return "Soy un rectangulo"; }  
};

// Clase Polígono Tiene número de lados me van a regresar a primaria no me acordaba
class Polygon : public Shape {
private:
    int lados;  // Cuántos lados tiene (3=triángulo, 4=cuadrado, etc.)

public:
    // Constructor: Llama al de Shape y guarda el número de lados.
    Polygon(int X, int Y, int Lados) : Shape(X, Y), lados(Lados) {}  

    
    string draw() override { return "Soy un poligono de " + to_string(lados) + " lados"; }  
};


int main() {
    // Creamos un círculo en (0,0) con radio 5.
    Circle circulo(0, 0, 5);  

    // Creamos un rectángulo en (10,20) de tamaño 30x40.
    Rectangle rect(10, 20, 30, 40);  

    // Creamos un polígono en (5,5) con 6 lados (hexágono).
    Polygon hexagono(5, 5, 6);  

    cout << "=== Figuras ===" << endl;
    cout << "1. " << circulo.draw() << endl;     // Llama a draw() del círculo.
    cout << "2. " << rect.draw() << endl;        // Llama a draw() del rectángulo.
    cout << "3. " << hexagono.draw() << endl;    // Llama a draw() del polígono.

    return 0;
}