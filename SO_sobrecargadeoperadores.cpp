#include <bits/stdc++.h>

using namespace std;

class calculadora{
    private:
    int real, imaginaria; //creamos las variables para el numero complejo


    public:
        //creacion de un constructor (sobre carga de constructor)
        calculadora();
        calculadora(int,int);
        float promedio(int , int );
        double promedio(double , double );
        float promedio(int , int , int , int );
        float promedio(int [],int);
        int getReal();
        int getImag();
        //sobrecarga de operadores con el operador +
        calculadora operator+(calculadora);
        
};

calculadora::calculadora(){
    real=0;
    imaginaria=0;
}

calculadora::calculadora(int Real, int Imag){
    real=Real;
    imaginaria=Imag;
}
//si quieres en otro archivo este es el so.cpp

int calculadora::getReal(){
    return real;
}
int calculadora::getImag(){
    return imaginaria;
}

//sobrecarga de operadores
calculadora calculadora::operator+(calculadora NC2){
    //se va retornar un objeto complejo
    return calculadora((real+NC2.real)/2, (imaginaria+NC2.imaginaria)/2);
}

float calculadora::promedio(int A, int B){
    return (A+B)/2.0f;
}


double calculadora::promedio(double A, double B){
    return (A+B)/2;
}

float calculadora::promedio(int A, int B,int C, int D){
    return (A+B+C+D)/4.0f;
}

float calculadora::promedio(int Arreglo[],int Tamano){
    float suma=0;
    for(int i=0;i<Tamano;i++){
        suma+=Arreglo[i];
    }
    return suma/Tamano;
}

int main() {
	//se pone la clase y el nombre porque no tenemos un constructor pero si los metodos

    calculadora calc;
    cout<<"Promedio con metodo promedio: "<<calc.promedio(5,7)<<endl;
    calculadora NC1(5,4),NC2(7,2);
    //nuevo numero complejo
    calculadora NC3=NC1+NC2;
    cout<<NC3.getReal()<<"+"<<NC3.getImag()<<"i"<<endl;
    

	return 0;
}

