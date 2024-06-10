#pragma once 

#include "node.h"

namespace arvorebinaria 
{
    template <typename T>
    struct Node
    {
        T iPayload; // valor armazenado no nó
  
        Node* ptrLeft; // ponteiro para o nó filho à esquerda
        Node* ptrRight; // ponteiro para o nó filho à direita
        Node* ptrNext; // usado na função de travessia em largura 
    };

    template <typename T> 
    Node<T>* createNode(T); 

    template <typename T>
    Node<T>* insertNode( Node<T>*, T ); 

    template <typename T>
    Node<T>* dfsSearchNode( Node<T>*, T); 

    template <typename T>
    Node<T>* lesserLeaf( Node<T>*); 

    template <typename T>
    Node<T>* deleteNode(Node<T>*, T );

    template <typename T>
    void traversePreOrder(Node<T>*);

    template <typename T>
    void traverseInOrder(Node<T>*);

    template <typename T>
    void traversePostOrder(Node<T>*);

    template <typename T>
    void bfsTraversal(Node<T>*);

    template <typename T>
    Node<T>* bfsSearchNode(Node<T>*, T);

    template <typename T>
    int treeHeight(Node<T>* );

} // namespace arvorebinaria
    



