#include <Shape.h>

int main()
{
    //instancias de clase
    Shape Fig1=Shape(5,6); //opcion Fig1
    Shape Fig2(7,9); //opcion 2 
    
    cout<<"Figura 1 "<<Fig1.draw()<<" con x en: "<<Fig1.getX()<<endl;
    cout<<"Figura 2 "<<Fig2.draw()<<" con x en: "<<Fig2.getX()<<endl;
    
    Circle Circulo1(4,5,7);
    cout<<"Circulo: "<<Circulo1.draw()<<"Con x en: "<<Circulo1.getX()<<endl;
    
    return 0;
};