#include <iostream>
using namespace std;




/*
int main() {
    //declaramos variables que ya tienen un espacio de memoria
    //con el &ingreso de la variable
    int A;
    int B;
    cout<<&A<<endl; //dirección de memoria de A
    cout<<&B<<endl; //dirección de memoria de B
    //hay 4 bites porque los enteros ocupan 4 bytes en memoria
    

    //creamos un puntero que apunta a la dirección de memoria de A
    int *pointer=&A; //puntero que apunta a A
    //ahora dice la dirección de memoria de A
    cout<<"el valor del apuntador es"<<pointer<<endl; //dirección de memoria de A a través del puntero
    cout<<"el valor de A es"<<*pointer<<endl; //valor de A a través del puntero
    *pointer=89;
    cout<<"el valor de A es"<<*pointer<<endl; //valor de A después de cambiarlo a través del puntero
    cout<<"el valor de A es"<<A<<endl; //valor de A después de cambiarlo a través del puntero

    //cout<<"el tamano de apuntador de un entero es> "<<sizeof(pointer)<<endl; //valor de A después de cambiarlo a través del puntero
    //cout<<"el tamano de apuntador de un double es> "<<sizeof(pointer_double)<<endl;



    //uso en los arreglos

    int arreglo[5]={1,2,3,4,5};
    int *puntero_arreglo=arreglo; //puntero que apunta al primer elemento del arreglo
    cout<<"el valor del primer elemento del arreglo es: "<<*puntero_arreglo<<" , "<<puntero_arreglo<<endl endl; //valor del primer elemento del arreglo a través del puntero
    cout<<"el valor del segundo elemento del arreglo es: "<<*(puntero_arreglo+1)<<endl; //valor del segundo elemento del arreglo a través del puntero
    cout<<"el valor del tercer elemento del arreglo es: "<<*(puntero_arreglo+2)<<endl; //valor del tercer elemento del arreglo a través del puntero
    cout<<"el valor del cuarto elemento del arreglo es: "<<*(puntero_arreglo+3)<<endl; //valor del cuarto elemento del arreglo a través del puntero
    pointer_arreglo++; //ahora el puntero apunta al segundo elemento del arreglo
    cout<<"el valor del segundo elemento del arreglo es: "<<*puntero_arreglo<<endl; //valor del segundo elemento del arreglo a través del puntero


    return 0;
}
*/



void Funcion1(int* A){
    cout<<" A es: "<<A<<endl; //dirección de memoria de A
    *A=68; //esto no funciona porque A es un entero, no un puntero

}

void Funcion2(int &A){
    //cout<<" A es: "<<*A<<endl; //dirección de memoria de A
    A=234; 

int main(){

    int A=7, B=9;
    cout<<"La dirección de memoria de A es: "<<&A<<endl; //dirección de memoria de A
    cout<<"El valor de A es: "<<A<<endl; //valor de A
    Funcion1(&A); //llamamos a la función que recibe A por valor, no por referencia
    cout<<"El valor de A depues de la funcion es: "<<A<<endl; //valor de A después de llamar a la función
    cout<<"valor de B antes de la funcion: "<<B<<endl; //valor de B antes de llamar a la función
    Funcion2(B); //llamamos a la función que recibe A por referencia    
    cout<<"El valor de B depues de la funcion es: "<<B<<endl; //valor de B después de llamar a la función

    return 0;
}