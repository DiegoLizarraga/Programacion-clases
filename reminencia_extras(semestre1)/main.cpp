#include "Circle.h"
#include <iostream>

using namespace std;

int main() {
    // Instancias de clase
    Shape Fig1 = Shape(5, 6); // opción Fig1
    Shape Fig2(7, 9); // opción 2 
    
    cout << "Figura 1 " << Fig1.draw() << " con x en: " << Fig1.getX() << endl;
    cout << "Figura 2 " << Fig2.draw() << " con x en: " << Fig2.getX() << endl;
    
    Circle Circulo1(4, 5, 7);
    cout << "Circulo: " << Circulo1.draw() << " con x en: " << Circulo1.getX() << endl;
    
    return 0;
}