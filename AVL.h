#ifndef AVL_H
#define AVL_H
#include <iostream>
#include "Nodo.h"
using namespace std;
template <class T>
class AVL
{
public:
    Node<T>* root;


    AVL(void):root(nullptr){}
    ~AVL(){}

    void insert(const T &dato){
        return insert(root,dato);
    }
    void insert(Node<T>* &nodo, const T &dato){
        if(nodo == nullptr)
        {
            nodo= new Node<T>(dato); 
        }
        if(dato<nodo->dato) insert(nodo->left,dato);
        else if(dato>nodo->dato) insert(nodo->right,dato);
        else return;
        
    }
    void swap(Node<T>*&nodo1,Node<T>*&nodo2){
        T datoaux = nodo1->dato;
        nodo1->dato = nodo2->dato;
        nodo2->dato = datoaux;
    }

    Node<T>* search(T dato){
        Node<T>* temp = root;
        while(temp){
            if(dato == temp->dato) return temp;
            else {
                if(dato<temp->dato) temp = temp->left;
                else temp = temp->right;
            }
        }
        cout<<"No se encontro el elemento \n";
        return nullptr;
    }
    void balance(){

    }
   
};


#endif