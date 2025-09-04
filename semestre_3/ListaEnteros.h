#indef LISTAENTEROS_H
#define LISTAENTEROS_H


Class ListaEnteros{
    private:
        int* valores; //puntero a int con un apuntador
        int size,  //numero de valores almacenados
            length;  //la capacidad del arreglo
    public:
        ListaEnteros(int length); //constructor
        ListaEnteros(int length,int valores[]); //constructor con arreglo
      
     //implementar estos metodos
     void imprime();
     int busquedaSecuencial(int valor);
     int busquedaBinaria(int valor);
    void bubleSort();
    void selectionSort();



};


#endif