#include <iostream>

using namespace std;

int promedio(int a, int b) {
	return (a + b) / 2;
}

int promedio(float a, float b) {
    
	return (a + b) / 2;
}

int promedio(int a, int b, int c, int d) {
	return (a + b + c + d) / 4;
}

int promedio(int arreglo[], int tamano) {
    
 
    int suma=0;
    
    for (int i=0;i<tamano;i++){
        suma+=arreglo[i];
    }
    
    return suma/tamano;
}

int main() {
	cout<<"EL promedio es "<<promedio(3, 9)<<endl;
	cout<<"EL promedio es "<<promedio(3, 9, 8, 9)<<endl;

	int arreglo[]= {5,8,2,9};

	cout<<"EL promedio "<< promedio (arreglo[0],arreglo[1],arreglo[2],arreglo[3])<<endl;
   
	cout<<sizeof(arreglo)/sizeof(arreglo[0])<<endl;
	cout<<"EL promedio "<<promedio(arreglo,sizeof(arreglo)/sizeof(arreglo[0]))<<endl;
	//llamar a la funcion con un arreglo
	cout<<"promedio de dos numeros es: "<<promedio(3.78f,9.34f)<<endl;
	
	return 0;
}