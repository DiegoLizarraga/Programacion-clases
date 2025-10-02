// Diego Martin Lizarraga Sanchez - A01647334
#include "MyLinkedList.h"

using namespace std;

// Constructar 
MyLinkedList::MyLinkedList() {
    this->size = 0;
    this->head = this->tail = nullptr;

}

// Destructor - Complejidad: O(n)
MyLinkedList::~MyLinkedList() {
    MyNodoLL* curr = this->head;
    while (curr != nullptr) {
        MyNodoLL* temp = curr;
        curr = curr->next;
        delete temp;
    }
    this->head = this->tail = nullptr;
    this->size = 0;
}


// Retorna el tamaño de la lista - Complejidad: O(1)
int MyLinkedList::length() {
    return this->size;
}

// Verifica si la lista está vacía - Complejidad: O(1)
bool MyLinkedList::isEmpty() {
    return this->size == 0;
}

// Retorna el primer elemento - Complejidad: O(1)
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


// Retorna el elemento en la posición pos - Complejidad: O(n)
int MyLinkedList::getAt(int pos) {
    if (pos < 0 || pos >= this->size) {
        throw invalid_argument("Error: posicion invalida");
    }
    MyNodoLL* curr = this->head;
    for (int i = 0; i < pos; i++) {
        curr = curr->next;
    }
    return curr->data;
}

// Modifica el elemento en la posición pos - Complejidad: O(n)
void MyLinkedList::setAt(int pos, int data) {
    if (pos < 0 || pos >= this->size) {
        throw invalid_argument("Error: posicion invalida");
    }
    MyNodoLL* curr = this->head;
    for (int i = 0; i < pos; i++) {
        curr = curr->next;
    }
    curr->data = data;
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

// Inserta un elemento al final - Complejidad: O(1)
void MyLinkedList::insertLast(int data) {
    MyNodoLL* nvo = new MyNodoLL(data, nullptr);
    if (this->size == 0) {
        this->head = this->tail = nvo;
    } else {
        this->tail->next = nvo;
        this->tail = nvo;
    }
    this->size++;
}

// Inserta un elemento en la posición pos - Complejidad: O(n)
void MyLinkedList::insertAt(int pos, int data) {
    if (pos < 0 || pos > this->size) {
        throw invalid_argument("Error: posicion invalida");
    }
    if (pos == 0) {
        insertFirst(data);
    } else if (pos == this->size) {
        insertLast(data);
    } else {
        MyNodoLL* curr = this->head;
        for (int i = 0; i < pos - 1; i++) {
            curr = curr->next;
        }
        MyNodoLL* nvo = new MyNodoLL(data, curr->next);
        curr->next = nvo;
        this->size++;
    }
}

// Elimina el primer elemento - Complejidad: O(1)
void MyLinkedList::removeFirst() {
    if (this->size == 0) {
        throw invalid_argument("Error: lista vacia");
    }
    MyNodoLL* temp = this->head;
    this->head = this->head->next;
    delete temp;
    this->size--;
    if (this->size == 0) {
        this->tail = nullptr;
    }
}

// Elimina el último elemento - Complejidad: O(n)
void MyLinkedList::removeLast() {
    if (this->size == 0) {
        throw invalid_argument("Error: lista vacia");
    }
    if (this->size == 1) {
        delete this->head;
        this->head = this->tail = nullptr;
        this->size = 0;
    } else {
        MyNodoLL* curr = this->head;
        while (curr->next != this->tail) {
            curr = curr->next;
        }
        delete this->tail;
        this->tail = curr;
        this->tail->next = nullptr;
        this->size--;
    }
}

// Elimina el elemento en la posición pos - Complejidad: O(n)
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

// Sobrecarga del operador << - Complejidad: O(n)
ostream& operator<<(ostream& os, const MyLinkedList& ll) {
    MyNodoLL* curr = ll.head;
    while (curr != nullptr) {
        os << curr->data << ",";
        curr = curr->next;
    }
    return os;
}