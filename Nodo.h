#ifndef Nodo_H
#define Nodo_H



template <class T>
class Node
{
    
    public: 
        T dato;
        Node<T>*left;
        Node<T>*right;
        int height;
        int weight;
  
        Node(T dat):dato(dat),left(nullptr),right(nullptr),height(0),weight(0){}
        Node():height(0),weight(0),left(nullptr),right(nullptr){}
        ~Node();
        
   
};

#endif