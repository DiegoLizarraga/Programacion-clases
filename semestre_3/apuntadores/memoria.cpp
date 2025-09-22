#include <bits/stdc++.h>

using namespace std;

void swap1(int a, int b){

    int aux=a;
    a=b;
    b=aux;
}

void swap2(int* a, int* b){
    cout<<a<<" "<<b<<endl;
    int aux= *a;
   *a=*b;
    *b=aux;
    
}

void swap3(int &a, int &b){
    //lo de arriba es una copia por valor. 
    int aux=a;
    a=b;
    b=aux;
}


int main(){
  int a=10; // se crea la a y le da un lugar en la memoria
  int b;
  int* ptr=&a;// ptr en otra direccion de memoria es un apuntador. guarda la direccion de memoria de a
  int* ptr2=ptr;
  *ptr=50; //quiero cambiar el valor de lo que apunta. quiero acceder a la variable

  cout<<a<<" "<<*ptr<<endl;

  a=10;
  b=50;
  swap1(a,b);
  cout<<a<<" "<<b<<endl;
  // no hay ningun cambia con las variables porque no cambia con lo de la funcion 
  
  
  a=10;
  b=50;
  swap2(&a,&b);
  cout<<a<<" "<<b<<endl;
  //al mandarle se guarda la direccion y como es apuntador va a esa direccion
 
  
  
  
   a=10;
  b=50;
  swap3(a,b);
  cout<<a<<" "<<b<<endl;
  //no se paso ningina direccion, solo se usa como una variable nornal, las referencias son estaticas
  //uan vez se inicializan ya no se pueden separar.
  
  
  
  return 0;
}