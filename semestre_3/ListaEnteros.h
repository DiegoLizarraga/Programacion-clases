#indef LISTAENTEROS_H
#define LISTAENTEROS_H


Class ListaEnteros{
    private:
        int* valores; //puntero a int con un apuntador
        int size,  //numero de valores almacenados
            length;  //la capacidad del arreglo
        void mergesort(int ini, int fin);
        void mezcla(int ini, int fin);  
        void quicksort(int ini, int fin);
        int particionar(int ini, int fin);  

             
    public:
        ListaEnteros(int length); //constructor
        ListaEnteros(int length,int valores[]); //constructor con arreglo
      
     //implementar estos metodos
     void imprime();
     void swap(int i, int j);
     int busquedaSecuencial(int valor);
     int busquedaBinaria(int valor);
    void bubleSort();
    void selectionSort();
    void insertionSort();
    void mergeSort();//funcion de preparacion
    void quickSort();



};


#endif