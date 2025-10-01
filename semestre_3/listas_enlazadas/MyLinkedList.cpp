#include "MyLinkedList.h"

using namespace std;

MyLinkedList::MyLinkedList() {
    this->size = 0;
    this->head = this->tail = nullptr;

}


//metodo que regresa el tamano de la lista
int MyLinkedList::length() {
    return this->size;
}


//dice si tiene consas la lista
bool MyLinkedList::isEmpty() {
  return this->size == 0;
}


//regresa el primer elemento
int MyLinkedList::first() {
    if (this->size != 0) {
        return this->head->data;
        //esto se usa porque si no tenemos datos en la lista pues no tenemos nada que regresar
    }else{
        throw  invalid_argument("Error: lista vacia para el primer elemento");
    }
    
}


//el del ultmo elemento ne la lista
int MyLinkedList::last() {
    if (this->size != 0) {
        return this->tail->data;
        //esto se usa porque si no tenemos datos en la lista pues no tenemos nada que regresar
    }else{
        throw  invalid_argument("Error: lista vacia para el ultimo elemento");
    }
    
}

//insertar al inicio
void MyLinkedList::insertFirst(int data) {
    MyNodoLL* nvo = new MyNodoLL(data, this->head);
    this->head = nvo;
    this ->size++;
    if (this->size == 1) {
        this->tail = nvo;
    }
}

//terminar el getat
int MyLinkedList::getAt(int pos) {
MyNodoLL* curr = this->head;
    for (int i = 0; i < pos; i++) {
        curr = curr->next;
    }
    return curr->data;
}


//implementar


//investigar borrado de listas enlazadas

Mylinkedlist::removeAt(int pos){
    if (pos < 0 || pos >= this->size) {
        throw out_of_range("Error: posicion invalida");
    }
    MyNodoLL* curr = this->head;
    MyNodoLL* prev = nullptr;
    for (int i = 0; i < pos; i++) {
        prev = curr;
        curr = curr->next;
    }
    if (prev == nullptr) {
        this->head = curr->next;
    } else {
        prev->next = curr->next;
    }
    if (curr == this->tail) {
        this->tail = prev;
    }
    delete curr;
    this->size--;
}