
#include <iostream>

using namespace std;

//h
class Animales{
    private:
        
    public: 
    string comida;
    Animales(string);
    virtual void comer() const=0; //virtual pura

};
//cpp
Animales::Animales(string Comida){
    comida=Comida;
}


class Perro:public Animales{
    public:
        Perro(string);
        void comer() const override;
};

Perro::Perro(string Comida):Animales(Comida){};

void Perro::comer() const {
    cout << "El perro come: " <<comida<< endl;
}

int main() {
    cout << "Polimorfismo Dinamico en C++" << endl;
    
    // Aquí podrías crear instancias de clases derivadas y usarlas
    // a través de punteros a la clase base.
    Perro firulais("Croquetas");
    firulais.comer(); // Llamada a la función virtual de la clase Perro
    
    return 0;
}

