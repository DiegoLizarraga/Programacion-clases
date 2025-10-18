/*
 * Implementacion de un Arbol Binario de BUsqueda (BST)
 * Autor: Diego Martin Lizarraga Sanchez A01647334
 * Fecha: 18/10/2025
 */

#ifndef MYBST_H
#define MYBST_H

struct MyNodeBST {
    int data;
    MyNodeBST *left;
    MyNodeBST *right;
    
    MyNodeBST(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class MyBST {
    private:
        int size;
        MyNodeBST* root;
        
        // Métodos auxiliares privados para recursión
        bool search(int data, MyNodeBST* current);
        void preorder(MyNodeBST* current);
        void inorder(MyNodeBST* current);
        void postorder(MyNodeBST* current);
        int height(MyNodeBST* current);
        MyNodeBST* findMin(MyNodeBST* current);
        bool remove(int data, MyNodeBST*& current);
        
    public:
        MyBST();
        int length();
        bool isEmpty();
        bool search(int data);
        bool insert(int data);
        bool remove(int data);
        void preorder();
        void inorder();
        void postorder();
        void level();
        void visit(int type);
        int height();
        void ancestors(int data);
        int whatLevelAmI(int data);
};

#endif