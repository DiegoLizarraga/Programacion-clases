#ifdef LISTAENTEROS_H
#define LISTAENTEROS_H


class ListaEnteros {
    private:
        int* valores; //arreglo de enteros
        int size; //cantidad de elementos en el arreglo
        int length; //capacidad del arreglo
    public:
        ListaEnteros(int length); //constructor que recibe la capacidad del arreglo
        ListaEnteros(int length, int valores[]); //constructor que recibe la capacidad y un arreglo con los valores iniciales4
    
    void swap(int i, int j); //intercambia los valores en las posiciones i y j
    int busquedaSecuencial(int valor); //busca un valor en el arreglo y regresa su indice o -1 si no lo encuentra
    int busquedaBinaria(int valor); //busqueda binaria, regresa el indice o -1 si no lo encuentra

    void imprime(); //imprime los valores del arreglo
    void bubleSort(); //ordena el arreglo con el metodo de burbuja
        

};

#endif

int main() {
    int valores[] = {5, 3, 8, 6, 2};
    ListaEnteros lista(5, valores);
    lista.imprime();
    lista.bubleSort();
    lista.imprime();
    return 0;
}