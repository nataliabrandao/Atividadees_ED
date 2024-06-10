#include <iostream> 

#include "arvorebinaria.h"
#include "node.h"

using namespace std; 

namespace arvorebinaria 
{

    template <typename T> 
    Node<T>* createNode(T iValue)
    {
        Node<T>* tmp = (Node<T>*) malloc(sizeof(Node<T>));
    
        if (tmp == nullptr)
        {
            cerr << "Erro em createNode: malloc" << endl;
            exit(1);
        }
    
        tmp->iPayload = iValue;
        tmp->ptrLeft = nullptr;
        tmp->ptrRight = nullptr;
        tmp->ptrNext = nullptr; 
    
        return tmp;
    }

    template <typename T>
    Node<T>* insertNode( Node<T>* startingNode, T iData)
    {
        if(startingNode == nullptr)
        {
           return createNode(iData);
        }
    
        if(iData < startingNode->iPayload)
        {
            startingNode->ptrLeft = insertNode(startingNode->ptrLeft, iData);
        }
        else
        {
            startingNode->ptrRight = insertNode(startingNode->ptrRight, iData);
        }
    
        return startingNode;
    }

    template <typename T>
    Node<T>* dfsSearchNode( Node<T>* startingNode, T iData)
    {
        if(startingNode == nullptr) return nullptr;
        else if(iData == startingNode->iPayload) return startingNode;
        else if(iData < startingNode->iPayload) return dfsSearchNode(startingNode->ptrLeft, iData);
        else return dfsSearchNode(startingNode->ptrRight, iData);
    }

    template <typename T>
    Node<T>* lesserLeaf( Node<T>* startingNode)
    {
        Node<T>* ptrCurrent = startingNode;
 
        while (ptrCurrent && ptrCurrent->ptrLeft != nullptr) ptrCurrent = ptrCurrent->ptrLeft;
    
        return ptrCurrent;
    }

    template <typename T>
    Node<T>* deleteNode(Node<T>* startingNode, T iData)
    {
        if (startingNode == nullptr) return nullptr;
    
        if (iData < startingNode->iPayload) startingNode->ptrLeft = deleteNode(startingNode->ptrLeft, iData);
        else if (iData > startingNode->iPayload) startingNode->ptrRight = deleteNode(startingNode->ptrRight, iData);
        else
        {
            Node<T>* ptrTemp = nullptr;
        
            if (startingNode->ptrLeft == nullptr)
            {
                ptrTemp = startingNode->ptrRight;
                free(startingNode);
                return ptrTemp;
            }
            else if (startingNode->ptrRight == nullptr)
            {
                ptrTemp = startingNode->ptrLeft;
                free(startingNode);
                return ptrTemp;            
            }
        
            ptrTemp = lesserLeaf(startingNode->ptrRight);
        
            startingNode->iPayload = ptrTemp->iPayload;
        
            startingNode->ptrRight = deleteNode(startingNode->ptrRight, ptrTemp->iPayload);
        }
    
        return startingNode;
    }

    template <typename T>
    void traversePreOrder(Node<T>* ptrStartingNode)
    {
        if (ptrStartingNode != nullptr)
        {
            cout << " " << ptrStartingNode->iPayload;
            traversePreOrder(ptrStartingNode->ptrLeft);
            traversePreOrder(ptrStartingNode->ptrRight);
        }
    }

    template <typename T>
    void traverseInOrder(Node<T>* ptrStartingNode)
    {
        if (ptrStartingNode != nullptr)
        {
            traverseInOrder(ptrStartingNode->ptrLeft);
            cout << " " << ptrStartingNode->iPayload;
            traverseInOrder(ptrStartingNode->ptrRight);
        }
    }

    template <typename T>
    void traversePostOrder(Node<T>* ptrStartingNode)
    {
        if (ptrStartingNode != nullptr)
        {
            traversePostOrder(ptrStartingNode->ptrLeft);
            traversePostOrder(ptrStartingNode->ptrRight);
            cout << " " << ptrStartingNode->iPayload;
        }
    }

    template <typename T>
    Node<T>* bfsSearchNode(Node<T>* startingNode, T iValue)
    {
        if (startingNode == nullptr)
            return nullptr;

        Node<T>* frente = startingNode;
        Node<T>* tras = startingNode;

        while (frente != nullptr)
        {
            if (frente->iPayload == iValue)
                return frente;  // Encontrou o nó com o valor desejado

            if (frente->ptrLeft != nullptr)
            {
                tras->ptrNext = frente->ptrLeft;
                tras = tras->ptrNext;
            }
            if (frente->ptrRight != nullptr)
            {
                tras->ptrNext = frente->ptrRight;
                tras = tras->ptrNext;
            }

            frente = frente->ptrNext;
        }

        return nullptr; // Se iValue não foi encontrado na árvore
    }

        
    template <typename T>
    int treeHeight(Node<T>* startingNode)
    {
        if (startingNode == nullptr) return 0;
        else
        {
            int iLeftHeight = treeHeight(startingNode->ptrLeft);
            int iRightHeight = treeHeight(startingNode->ptrRight);
        
            return max(iLeftHeight, iRightHeight) + 1;
        }
    }

    template <typename T>
    void bfsTraversal(Node<T>* ptrStartingNode)
    {
        if (ptrStartingNode == nullptr)
            return;

        Node<T>* frente = nullptr;
        Node<T>* tras = nullptr;

        tras = frente = ptrStartingNode;
        
        while (frente != nullptr) 
        {
            cout << frente-> iPayload << " ";

            if (frente->ptrLeft != nullptr)
            {
                tras-> ptrNext = frente->ptrLeft;
                tras = tras-> ptrNext;
            }
            if (frente->ptrRight != nullptr)
            {
                tras-> ptrNext = frente->ptrRight;
                tras = tras-> ptrNext;
            }

            frente = frente-> ptrNext;
        }
    }


// Instanciação explícita para os tipos inteiros
    template Node<int>* createNode(int);
    template Node<int>* insertNode(Node<int>*, int);
    template Node<int>* dfsSearchNode(Node<int>*, int);
    template Node<int>* lesserLeaf(Node<int>*);
    template Node<int>* deleteNode(Node<int>*, int);
    template void traversePreOrder(Node<int>*);
    template void traverseInOrder(Node<int>*);
    template void traversePostOrder(Node<int>*);
    template void bfsTraversal(Node<int>*);
    template int treeHeight(Node<int>*);
    template Node<int>* bfsSearchNode(Node<int>*, int);

} // namespace arvorebinaria



