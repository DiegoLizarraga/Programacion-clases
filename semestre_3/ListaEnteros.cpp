#include "ListaEnteros.h"


ListaEnteros::ListaEnteros(int length) {
    //crear el arreglo y iniciar los valores de size y length
    this->length = length;
    this->size = 0;
    this->valores = new int[length];
}


ListaEnteros::ListaEnteros(int length, int valores[]:ListaEnteros(length)) { //reutilizar el constructor anterior
    //inicializar el arreglo con los valores del arreglo recibido
    
    for(int i=0; i<length; i++){
        this->valores[i] = valores[i];
    }
    this->size = length;
    

   


}