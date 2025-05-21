#include <iostream>
#include <math.h>
#define pi 3.14159

using namespace std;

double area(double r) {

    return pi*pow(r,2);
}

double area(double l, double h,string figura){
    int respuesta=0;
    if(figura=="Rectangulo")
        respuesta=l*h;
    else if(figura=="Triangulo")
        respuesta=(l*h)/2;
    else{
        cout<<"no es valida"<<endl
        respuesta =0;
    }
    
    return respuesta;
}



int main() {
   
    cout << "EL area del circulo es: " << area(6) << endl;

    return 0;
}