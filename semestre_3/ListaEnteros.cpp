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
    for(int i=0; i<size-1; i++){
        int min = i;
        for(int j=i+1; j<size; j++){
            if(this->valores[j] < this->valores[min]){
                min = j;
            }
        }
        swap(i, min);
    }
}

void ListaEnteros::mergesort(int ini, int fin) {
    if(ini < fin){
        int mid = (ini + fin) / 2;
        mergesort(ini, mid);
        mergesort(mid + 1, fin);
        mezcla(ini, fin);
    }
}

void ListaEnteros::mergesort() {
    mergesort(0, this->size - 1);
}

int ListaEnteros::particionar(int ini, int fin) {
    int pivote = this->valores[fin];
    int i = ini - 1;
    for(int j = ini; j < fin; j++) {
        if(this->valores[j] <= pivote) {
            i++;
            swap(i, j);
        }
    }
    swap(i + 1, fin);
    return i + 1;
}

void ListaEnteros::quicksort(int ini, int fin) {
    if(ini < fin) {
        int pi = particionar(ini, fin);
        quicksort(ini, pi - 1);
        quicksort(pi + 1, fin);
    }
}

void ListaEnteros::quicksort() {
    quicksort(0, this->size - 1);
}