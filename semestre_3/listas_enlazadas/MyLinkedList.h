#ifndef  MYLINKEDLIST_H
#define  MYLINKEDLIST_H

struct Node {
    int data;
    MyNodoLL* next;

    MyNodoLL(int data,MyNodoLL* next){
        this->data = data;
        this->next = next;
    }

    MyNodoLL(int data): MyNodoLL(data,nullptr) {
        
    }
    
};

//EN LA CLASE TIENES PRIVATE, PROTECT Y PUBLIC
//UN STRUCT ES SIMILAR A UNA CLASE, PERO TODOS SUS ATRIBUTOS SON PUBLICOS POR DEFECTO

class MYLINKEDLIST_H {
    //para ver el tamano pos guardo el size
   private:
    int size;


   MyNodoLL* head;
   //tener un apuntador al ultimo puedo llegar directamente
   MyNodoLL* tail;
  public:
    //constructor
    MyLinkedList();
    //detructor
    ~MyLinkedList();
    int length();
    bool isEmpty();
    int first();
    int last();
    int getAt(int pos);
    void setAt(int pos, int data);
    void insertFirst(int data);
    void insertLast(int data);
    void insertAt(int pos, int data);
    void removeAt(int pos);
  

};       

#endif  /* MYLINKEDLIST_H */