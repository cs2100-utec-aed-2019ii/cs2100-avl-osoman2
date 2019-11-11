#include "AVL.h"


int main(){
    AVL<int>* arbol = new AVL<int>();
    arbol->insert(10);
    arbol->insert(9);
    arbol->insert(8);
    // cout<<arbol->search(10)->dato<<endl;
    cout<<arbol->root->dato<<endl;
 
    // cout<<arbol->root->left<<endl;

    //out<<arbol->search(9)-> dato<<endl;
    delete arbol;
    return 0;
}