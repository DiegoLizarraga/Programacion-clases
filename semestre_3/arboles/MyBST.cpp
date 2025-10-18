/*
 * Descripción: Implementación de los métodos del Árbol Binario de Búsqueda
 * Autor: [Tu nombre y matrícula]
 * Fecha: 18/10/2025
 */

#include "MyBST.h"
#include <iostream>
#include <queue>
using namespace std;

/*
 * Constructor del BST
 * Inicializa el árbol vacío
 * Código base tomado de MyBST.cpp proporcionado
 */
MyBST::MyBST() {
    this->root = nullptr;
    this->size = 0;
}

/*
 * Regresa el número de elementos en el árbol
 * Retorna: tamaño del árbol
 * Código base tomado de MyBST.cpp proporcionado
 */
int MyBST::length() {
    return this->size;
}

/*
 * Verifica si el árbol está vacío
 * Retorna: true si está vacío, false en caso contrario
 * Código base tomado de MyBST.cpp proporcionado
 */
bool MyBST::isEmpty() {
    return this->size == 0;
}

/*
 * Inserta un nuevo valor en el árbol
 * Parámetro data: valor a insertar
 * Retorna: true si se insertó, false si ya existía
 * Código base tomado de MyBST.cpp proporcionado (insert)
 * Adaptado para usar 'data' en lugar de 'valor' y 'left/right' en lugar de 'izq/der'
 */
bool MyBST::insert(int data) {
    if (this->root == nullptr) {
        this->root = new MyNodeBST(data);
        this->size++;
        return true;
    }
    
    MyNodeBST* current = this->root;
    MyNodeBST* parent = nullptr;
    
    while (current != nullptr) {
        if (current->data == data) {
            return false;
        } else if (data < current->data) {
            parent = current;
            current = current->left;
        } else {
            parent = current;
            current = current->right;
        }
    }
    
    if (data < parent->data) {
        parent->left = new MyNodeBST(data);
    } else {
        parent->right = new MyNodeBST(data);
    }
    
    this->size++;
    return true;
}

/*
 * Busca un valor en el árbol (versión pública)
 * Parámetro data: valor a buscar
 * Retorna: true si existe, false en caso contrario
 */
bool MyBST::search(int data) {
    return search(data, this->root);
}

/*
 * Busca un valor en el árbol (versión recursiva privada)
 * Parámetro data: valor a buscar
 * Parámetro current: nodo actual en la recursión
 * Retorna: true si existe, false en caso contrario
 * Código base tomado de MyBST.cpp proporcionado (searchRec)
 * Adaptado para usar 'data' en lugar de 'valor' y 'left/right' en lugar de 'izq/der'
 */
bool MyBST::search(int data, MyNodeBST* current) {
    if (current == nullptr) {
        return false;
    }
    if (current->data == data) {
        return true;
    } else if (data < current->data) {
        return search(data, current->left);
    } else {
        return search(data, current->right);
    }
}

/*
 * Encuentra el nodo con valor mínimo en un subárbol
 * Parámetro current: raíz del subárbol
 * Retorna: puntero al nodo con valor mínimo
 */
MyNodeBST* MyBST::findMin(MyNodeBST* current) {
    while (current->left != nullptr) {
        current = current->left;
    }
    return current;
}

/*
 * Elimina un valor del árbol (versión privada recursiva)
 * Parámetro data: valor a eliminar
 * Parámetro current: referencia al puntero del nodo actual
 * Retorna: true si se eliminó, false si no existía
 */
bool MyBST::remove(int data, MyNodeBST*& current) {
    if (current == nullptr) {
        return false;
    }
    
    if (data < current->data) {
        return remove(data, current->left);
    } else if (data > current->data) {
        return remove(data, current->right);
    } else {
        if (current->left == nullptr && current->right == nullptr) {
            delete current;
            current = nullptr;
            this->size--;
            return true;
        } else if (current->left == nullptr) {
            MyNodeBST* temp = current;
            current = current->right;
            delete temp;
            this->size--;
            return true;
        } else if (current->right == nullptr) {
            MyNodeBST* temp = current;
            current = current->left;
            delete temp;
            this->size--;
            return true;
        } else {
            MyNodeBST* predecessor = current->left;
            while (predecessor->right != nullptr) {
                predecessor = predecessor->right;
            }
            current->data = predecessor->data;
            return remove(predecessor->data, current->left);
        }
    }
}

/*
 * Elimina un valor del árbol (versión pública)
 * Parámetro data: valor a eliminar
 * Retorna: true si se eliminó, false si no existía
 */
bool MyBST::remove(int data) {
    return remove(data, this->root);
}

/*
 * Recorrido preorden (versión privada recursiva)
 * Parámetro current: nodo actual
 */
void MyBST::preorder(MyNodeBST* current) {
    if (current != nullptr) {
        cout << current->data << ",";
        preorder(current->left);
        preorder(current->right);
    }
}

/*
 * Recorrido preorden (versión pública)
 */
void MyBST::preorder() {
    preorder(this->root);
}

/*
 * Recorrido inorden (versión privada recursiva)
 * Parámetro current: nodo actual
 */
void MyBST::inorder(MyNodeBST* current) {
    if (current != nullptr) {
        inorder(current->left);
        cout << current->data << ",";
        inorder(current->right);
    }
}

/*
 * Recorrido inorden (versión pública)
 */
void MyBST::inorder() {
    inorder(this->root);
}

/*
 * Recorrido postorden (versión privada recursiva)
 * Parámetro current: nodo actual
 */
void MyBST::postorder(MyNodeBST* current) {
    if (current != nullptr) {
        postorder(current->left);
        postorder(current->right);
        cout << current->data << ",";
    }
}

/*
 * Recorrido postorden (versión pública)
 */
void MyBST::postorder() {
    postorder(this->root);
}

/*
 * Recorrido por niveles
 * Imprime los elementos separados por comas
 */
void MyBST::level() {
    if (this->root == nullptr) {
        return;
    }
    
    queue<MyNodeBST*> cola;
    cola.push(this->root);
    
    while (!cola.empty()) {
        MyNodeBST* current = cola.front();
        cola.pop();
        
        cout << current->data << ",";
        
        if (current->left != nullptr) {
            cola.push(current->left);
        }
        if (current->right != nullptr) {
            cola.push(current->right);
        }
    }
}

/*
 * Despliega el recorrido según el tipo especificado
 * Parámetro type: 1=preorder, 2=inorder, 3=postorder, 4=level
 */
void MyBST::visit(int type) {
    if (type == 1) {
        preorder();
    } else if (type == 2) {
        inorder();
    } else if (type == 3) {
        postorder();
    } else if (type == 4) {
        level();
    }
}

/*
 * Calcula la altura de un subárbol (versión privada recursiva)
 * Parámetro current: raíz del subárbol
 * Retorna: altura del subárbol
 */
int MyBST::height(MyNodeBST* current) {
    if (current == nullptr) {
        return 0;
    }
    
    int leftHeight = height(current->left);
    int rightHeight = height(current->right);
    
    if (leftHeight > rightHeight) {
        return leftHeight + 1;
    } else {
        return rightHeight + 1;
    }
}

/*
 * Calcula la altura del árbol (versión pública)
 * Retorna: altura del árbol
 */
int MyBST::height() {
    return height(this->root);
}

/*
 * Imprime los ancestros de un nodo
 * Parámetro data: valor del nodo
 */
void MyBST::ancestors(int data) {
    if (this->root == nullptr || !search(data)) {
        return;
    }
    
    MyNodeBST* current = this->root;
    bool first = true;
    
    while (current != nullptr && current->data != data) {
        if (!first) {
            cout << ",";
        }
        cout << current->data;
        first = false;
        
        if (data < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
}

/*
 * Encuentra el nivel de un nodo en el árbol
 * Parámetro data: valor a buscar
 * Retorna: nivel del nodo (0 para raíz), -1 si no existe
 */
int MyBST::whatLevelAmI(int data) {
    if (this->root == nullptr) {
        return -1;
    }
    
    MyNodeBST* current = this->root;
    int level = 0;
    
    while (current != nullptr) {
        if (current->data == data) {
            return level;
        } else if (data < current->data) {
            current = current->left;
            level++;
        } else {
            current = current->right;
            level++;
        }
    }
    
    return -1;
}