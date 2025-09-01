#include "ListaEnteros.h"
#include <iostream>

ListaEnteros::ListaEnteros(int length) {
    //crear el arreglo y iniciar los valores de size y length
    this->size = 0;
    this->valores = new int[length];
    this->length = length;
}


ListaEnteros::ListaEnteros(int lenght, int valores[]):ListaEnteros(lenght){
    this -> valores = new int[lenght];
    for(int i=0; i<lenght; i++){
        this -> valores[i] = valores[i];
    }
    this -> size=lenght;


    void ListaEnteros::swap(int i, int j) {
        int aux = this->valores[i];  //
        this->valores[i] = this->valores[j];
        this->valores[j] = aux;
    }


    void ListaEnteros::imprime() {
        //imprimir los valores del arreglo
        for(int i=0; i<size; i++){
            cout << this->valores[i] << " , ";
        }
        cout << endl;
    }
    

    void ListaEnteros::bubleSort() {
        //ordenar el arreglo con el metodo de burbuja
        bool ordenados; 
        for(int i=0; i<size-1; i++){
            ordenados=true;
            for(int j=0; j<size-i-1; j++){
                if(this->valores[j] > this->valores[j+1]){
                    swap(j, j+1);
                    ordenados=false;
                    
                }
            }
        }
    }


}




