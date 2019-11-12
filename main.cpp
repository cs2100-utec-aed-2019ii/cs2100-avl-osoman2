#include "AVL.h"


int main(){
    AVL<int>* arbol = new AVL<int>();
    auto a =  arbol->insert(10);
    auto b = arbol->insert(9);
    auto c = arbol->insert(8);
    // cout<<arbol->search(10)->dato<<endl;
    cout<<arbol->root->dato<<endl;

    cout<<arbol->root->left->dato<<endl;

    cout<<arbol->search(9)-> dato<<endl;
    arbol->preord();
    arbol->inord();
    arbol->postord();
    delete arbol;
    return 0;
}