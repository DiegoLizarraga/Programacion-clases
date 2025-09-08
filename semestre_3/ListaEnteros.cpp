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
        if(ordenados) break;
    }


}


void ListaEnteros::selectionSort() {
    //ordenar el arreglo con el metodo de seleccion
    int posMin;
    for(int i=0; i<this->size-1; i++){
        posMin =i;
        for(int j=i+1; j<this->size; j++){
            if(this->valores[j] < this->valores[posMin]){
                posMin = j; //si hay un valor menor, actualizar la posicion
            }
        }
        swap(i,posMin); //intercambiar el valor actual con el valor minimo    
    }
}
void ListaEnteros::insertionSort() {
    //ordenar el arreglo con el metodo de insercion
    for(int i=1; i<this->size; i++){
        for(int j=i-1; i<this->size; i++){
            if(this->valores[j] > this->valores[j+1]){
                swap(j, j+1);
            }else{
                break; //si ya esta en orden, salir del ciclo
            }
        }
    }
}

void ListaEnteros::mezcla(int ini, int fin){
    //crea un arreglo de tamaño suficiente para mezclar los dos subarreglos
    //quepan los elementos entre ini y fin
    //pasar los elementos de manera ordenada enre ini y central y entre central+1 y fin
    //regresar los elementos ya ordenados al arreglo original
   
    //completar

}


void ListaEnteros::mergeSort(int ini, int fin) {
    //metodo auxiliar para mergeSort
    if(ini < fin){
        int central = (ini + fin) / 2;
        mergeSort(ini, central); //ordenar la primera mitad
        mergeSort(central+1, fin); //ordenar la segunda mitad
        mezcla(ini, fin); //mezclar las dos mitades
    }
}

void ListaEnteros::mergeSort() {
    //ordenar el arreglo con el metodo de mezcla
    mergeSort(0, this->size-1);
}
