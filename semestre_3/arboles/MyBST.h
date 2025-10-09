#ifnedf MYBST_H



struct MyNodoBST{
    in valor;
    MyNodoBST* izq;
    MyNodoBST* der;
    MyNodeBST(int valor,MyNodeBST* izq, MyNodeBST* der){
        this->valor = valor;
        this->izq = izq;
        this->der = der;
    }

    MyNodeoBST(int valor):MyNodeBST(valor,nullptr,nullptr){}
    ~MyNodeBST();
    
        
}


class MyBST {
    private:
    bool searchRec( int data,MyNodoBST* current);
    

   public:
   MyNodoBST* root;
    int size;
   MyBST();
   ~MyBST();
    int length();
    bool isEmpty();
    bool search(int data);
    bool searchRec(int data);
    bool insert(int data);
    bool remove(int data);




}