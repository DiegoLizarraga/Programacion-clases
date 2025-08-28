/*el polimorfismo en tiempo de ejecucion (dinamico)
trata con una sobreescritura. esta se hace a la par que se ejecuta 

puede cambiar su comportamiento


pasos para el poli dinamico:

1-clase base abstracta (cuando se tratan clases base tenemos funciones virtuales)
2-implementacion de clases derivadas. 
3-uso de punteros


funcion virtual base

funcion virutual pura
*/
#include <iostream> 

using namespace std;

class Empleado{
private:
    /* data */
public:
    //virtual void puesto(); // Función virtual 
    virtual void puesto() const= 0; // Función virtual pura

};
class Gerente : public Empleado {
    public:
    void puesto() const override; //indicamos subreescritura de la funcion virtual

};
class Supervisor : public Empleado {
    public:
    void puesto() const override; //indicamos subreescritura de la funcion virtual

};
void Gerente::puesto() const{
    cout << "soy un gerente" << endl; //el mismo espacio se sustituye ahora se sobrescribe la funcion virtual
};

void Supervisor::puesto() const{
    cout << "soy un Supervisor" << endl; //el mismo espacio se sustituye ahora se sobrescribe la funcion virtual
};


int main(){
    cout << "Polimorfismo Dinamico en C++" << endl;
    // Aquí podrías crear instancias de clases derivadas y usarlas
    // a través de punteros a la clase base.
    Gerente G1;
    Supervisor SUP1; // Llamada a la función virtual de la clase Gerente
    G1.puesto();
    SUP1.puesto(); // Llamada a la función virtual de la clase Supervisor
    return 0;
}