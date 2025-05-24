#include <bits/stdc++.h>

using namespace std;

//.h

class Vector{
    private:
    int x,y;

    public:
    Vector();
    Vector(int, int);
    Vector operator+(Vector);
    bool operator==(Vector);
    int operator*(Vector);
    Vector operator*(int);
    int getX();
    int getY();
};
//.cpp
Vector::Vector(){
    x=0;
    y=0;
}
Vector::Vector(int X,int Y){
    x=X;
    y=Y;
}

int Vector::getX(){
    return x;
}
int Vector::getY(){
    return y;
}
Vector Vector::operator+(Vector V2){
    return Vector(x+V2.x, y+V2.y);
}
bool Vector::operator==(Vector V2){
    return ((x==V2.x)&&(y==V2.y));
}

int Vector::operator*(Vector V2){
    return (x*V2.x)+(x+y*V2.y);
}

Vector Vector::operator*(int Escalar){
    return Vector(x*Escalar, y*Escalar);
}
ostream& operator<<(ostream& salida, Vector v2){
    //pendiente explicar
    //acedemos a sus miembros
    return salida<<v2.getX()<<","<<v2.getY()<<endl;
}
int main(){
    Vector V1(3,2), V2(4,2);
    Vector V3=V1+V2;
    cout<<"suma es "<<V3.getX()<<","<<V3.getY()<<endl;
    cout<<"Los vectores son"<<((V1==V2)?" iguales":" diferentes")<<endl;
    cout<<"El producto punto es "<<V1*V2<<endl;
    V3=V1*2;
    cout<<"El producto (3,2)*2 es: "<<V3.getX()<<","<<V3.getY()<<endl;
    cout<<"El producto (3,2)*2 es: "<<V3<<endl;

    return 0;
}