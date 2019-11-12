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

    Node<T>* insert( T dato){
        return insert(root,dato);
    }

    Node<T>* insert(Node<T>* &nodo,  T dato){
        if(nodo == nullptr)
        {
            nodo= new Node<T>(dato);
            nodo->weight = 0;
            return nodo;
        }
        if (dato > nodo->dato) nodo->right = insert(nodo->right,dato);
        else if (dato < nodo->dato) nodo->left = insert(nodo->left,dato);
        else return nullptr;
        nodo->weight = height(nodo->left)- height(nodo->right);
        nodo->height  = 1 + height(nodo->left) > height(nodo->right)? height(nodo->left): height(nodo->right);

        if(nodo->weight<-1 || nodo->weight>1){
            if(nodo->weight<-1){
                if(dato>nodo->right->dato) return left_rot(nodo);
                else if(dato<nodo->right->dato){nodo->right = right_rot(nodo->right);return left_rot(nodo);}
            }
            else {
                if(dato<nodo->left->dato) return right_rot(nodo);
                else if (dato>nodo->left->dato) {nodo->left = left_rot(nodo->left);return right_rot(nodo);}
            }
        }
        return nodo;
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

    Node<T>* right_rot(Node<T> *nodo)
    {
        Node<T> *aux = nodo->left;
        Node<T> *temp = aux->right;

        aux->right = nodo;nodo->left = temp;

        aux->height  = 1 + height(aux->left) > height(aux->right)? height(aux->left) : height(aux->right);
        nodo->height  = 1 + height(nodo->left) > height(nodo->right)? height(nodo->left) : height(nodo->right);

        return nodo;
    }

    Node<T> *left_rot(Node<T>* nodo)
    {
        Node<T> *aux = nodo->right;
        Node<T> *temp = aux->left;

        aux->left = nodo; nodo->right = temp;
        nodo->height  = 1 + height(nodo->left) > height(nodo->right)? height(nodo->left) : height(nodo->right);
        aux->height  = 1 + height(aux->left) > height(aux->right)? height(aux->left) : height(aux->right);

        return nodo;
    }

    int height(Node<T> *nodo)
    {
        if (nodo == nullptr)return 0;
        return nodo->height;
    }

    void preord(){
        cout<<"Pre order: \n";preord(root);cout<<endl;
    }
    void inord(){
        cout<<"In order: \n";inord(root);cout<<endl;
    }
    void postord(){
        cout<<"Post order: \n";postor(root);cout<<endl;
    }

    void preord(Node<T>* nodo){
        if(nodo){
            cout<<nodo->dato<<" ";
            preord(nodo->left);
            preord(nodo->right);
        }
        else{
            return;
        }
    }
    void inord(Node<T>* nodo){
        if(nodo){
            inord(nodo->left);
            cout<<nodo->dato<<" ";
            inord(nodo->right);
        }
        else{
            return;
        }
    }
    void postor(Node<T>* nodo){
        if(nodo){
            postor(nodo->left);
            postor(nodo->right);
            cout<<nodo->dato<<" ";
        }
        else{
            return;
        }
    }

};


#endif