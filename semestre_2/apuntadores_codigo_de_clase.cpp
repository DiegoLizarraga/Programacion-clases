#include <iostream>
using namespace std;

void FuncionIntercambio(int *A, int *B) {
    int c= *A; // Guardamos el valor de A en una variable temporal
    *A = *B;      // Asignamos el valor de B a A
    *B = c;   // Asignamos el valor temporal a B
}


int main() {
    int A = 70;
    int B = 80;

    cout << "Antes del intercambio: A = " << A << ", B = " << B << endl;

    FuncionIntercambio(&A, &B); // Pasamos las direcciones de memoria de A y B

    cout << "Después del intercambio: A = " << A << ", B = " << B << endl;

    return 0;
}