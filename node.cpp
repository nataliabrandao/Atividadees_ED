#include <iostream>
#include <cstdlib>

#include "node.h"
#include "arvorebinaria.h"


using namespace std;

namespace LinkedList
{
    template <typename T>
    Node<T>* createNode(T iPayload)
    {
        Node<T>* temp = (Node<T>*) malloc(sizeof(Node<T>));
        temp->iPayload = iPayload;
        temp->ptrNext = nullptr;
        temp->ptrPrev = nullptr;
        return temp;
    }

    template <typename T>
    void insertEnd(Node<T>** head, T iPayload)
    {
        Node<T>* newNode = createNode(iPayload);

        if ((*head) == nullptr)
        {
            (*head ) = newNode;
            return;
        }

        Node<T>* temp = (*head);
        while (temp->ptrNext != nullptr)
        {
            temp = temp->ptrNext;
        }

        temp->ptrNext = newNode;
        newNode->ptrPrev = temp;
    }

    template <typename T>
    void trocaValor(Node<T>* node1, Node<T>* node2)
    {
        T temp = node1->iPayload;
        node1->iPayload = node2->iPayload;
        node2->iPayload = temp;
    }

    template <typename T>
    Node<T>* createRandomList(int numElements)
    {
        Node<T>* head = nullptr;
        srand(time(nullptr));

        for (int i = 0; i < numElements; ++i)
        {
            insertEnd(&head, rand() % 101); // Gera números aleatórios entre 0 e 100
        }

        return head;
    }

    template <typename T>
    Node<T>* copyList(int numElements, Node<T>** head)
    {
        Node<T>* headcopy = nullptr;
        Node<T>* current = *head;

        for (int i = 0; i < numElements; ++i)
        {
            insertEnd(&headcopy, current->iPayload);
            current = current->ptrNext;
        }

        return headcopy;
    }

    template <typename T>
    void displayList(Node<T>* node)
    {
        if (node == nullptr)
        {
            std::cout << "Lista vazia" << std::endl;
            return;
        }

        Node<T>* temp = node;
        while (temp != nullptr)
        {
            std::cout << temp->iPayload << " ";
            temp = temp->ptrNext;
        }

        std::cout << std::endl;
    }

    template <typename T>
    void bubbleSort(Node<T>* head)
    {
        if (head == nullptr || head->ptrNext == nullptr)
        {
            return;
        }

        Node<T>* lastNode = nullptr;
        Node<T>* firstNode = head;

        while (firstNode->ptrNext != nullptr)
        {
            Node<T>* current = head;

            while (current->ptrNext != lastNode)
            {
                if (current->iPayload > current->ptrNext->iPayload)
                {
                    trocaValor(current, current->ptrNext);
                }
                current = current->ptrNext;
            }

            firstNode = firstNode->ptrNext;
            lastNode = current;
        }
    }

    template <typename T>
    void optimizedBubbleSort(Node<T>* head)
    {
        if (head == nullptr || head->ptrNext == nullptr)
        {
            return;
        }

        bool unordered = false;
        Node<T>* lastNode = nullptr;

        do {
            unordered = false;
            Node<T>* current = head;

            while (current->ptrNext != lastNode)
            {
                if (current->iPayload > current->ptrNext->iPayload)
                {
                    trocaValor(current, current->ptrNext);
                    unordered = true;
                }
                current = current->ptrNext;
            }
            lastNode = current;

        } while (unordered);
    }

    template <typename T>
    void selectionSort(Node<T>* head)
    {
        if (head == nullptr || head->ptrNext == nullptr)
        {
            return;
        }

        Node<T>* current = head;

        while (current != nullptr)
        {
            Node<T>* start = current->ptrNext;

            while (start != nullptr)
            {
                if (current->iPayload > start->iPayload)
                {
                    trocaValor(current, start);
                }
                start = start->ptrNext;
            }

            current = current->ptrNext;
        }
    }

    template <typename T>
    void optimizedSelectionSort(Node<T>* head)
    {
        if (head == nullptr || head->ptrNext == nullptr)
        {
            return;
        }

        Node<T>* current = head;
        bool bOrdered;

        while (current->ptrNext != nullptr)
        {
            bOrdered = true;
            Node<T>* minNode = current;

            Node<T>* temp = current->ptrNext;
            while (temp != nullptr) {
                if (temp->iPayload < minNode->iPayload)
                {
                    minNode = temp;
                    bOrdered = false;
                }
                temp = temp->ptrNext;
            }

            if (minNode != current)
            {
                trocaValor(current, minNode);
            }

            current = current->ptrNext;
        }
    }

    template <typename T>
    void insertionSort(Node<T>* head)
    {
        if (head == nullptr || head->ptrNext == nullptr)
        {
            return;
        }

        Node<T>* current2 = head->ptrNext;

        while (current2 != nullptr) {
            Node<T>* current1 = head;

            while (current1 != current2)
            {
                if (current1->iPayload > current2->iPayload)
                {
                    trocaValor(current1, current2);
                } else
                {
                    current1 = current1->ptrNext;
                }
            }
            current2 = current2->ptrNext;
        }
    }

    template <typename T>
    void shellSort(Node<T>* head)
    {
        if (head == nullptr || head->ptrNext == nullptr)
        {
            return;
        }

        int size = 0;
        Node<T>* temp = head;

        while (temp != nullptr)
        {
            size++;
            temp = temp->ptrNext;
        }

        //cout << "Tamanho da lista: " << size << endl;

        for (int gap = size / 2; gap >= 1; gap /= 2)
        {
            //cout << "Gap atual: " << gap << endl;

            for (int i = gap; i < size; i++)
            {
                Node<T>* current = head;
                for (int j = 0; j < i; j++)
                {
                    current = current->ptrNext;
                }

                Node<T>* current2 = current;
                //cout << "Comparando e possivelmente trocando valores..." << endl;

                for (int j = gap; j > 0 && current2 != nullptr; j--)
                {
                    Node<T>* prev = current2;
                
                    for (int k = 0; k < gap && current2 != nullptr; k++)
                    {
                        current2 = current2->ptrPrev;
                    }

                    if (current2 != nullptr)
                {
                    //cout << "Comparando " << current2->iPayload << " e " << prev->iPayload << endl;
                    if (current2->iPayload > prev->iPayload)
                    {
                        //cout << "Trocando " << current2->iPayload << " e " << prev->iPayload << endl;
                        trocaValor(current2, prev);
                    }
                }
            }
        }
    }
    //cout << "Lista ordenada:" << endl;
    //displayList(head);
    }

    template <typename T>
    Node<T>* searchNodebyValue(Node<T>** head, T iPayload)
    {
    
        // Inicialmente, definimos um ponteiro para percorrer a lista, começando pelo início
        Node<T>* current = (*head);

        // Percorremos a lista até encontrar o valor ou chegar ao final da lista
        while (current != nullptr)
        {
            // Se encontrarmos o valor, retornamos o ponteiro para esse nó
            if (current->iPayload == iPayload)
            {
                //cout << "Valor encontrado!" << endl;
                return current;
            }

            // Avançamos para o próximo nó
            current = current->ptrNext;
        }

        // Se não encontrarmos o valor em nenhum nó, retornamos nullptr
        //cout << "Valor não encontrado na lista." << endl;
        return nullptr;
    }


// Instanciação explícita para os tipos inteiros
    template Node<int>* createNode(int);
    template void  insertEnd(Node<int>**, int);
    template void trocaValor(Node<int>*, Node<int>*);
    template Node<int>* createRandomList(int);
    template Node<int>* copyList(int, Node<int>**);
    template void displayList(Node<int>*);
    template Node<int>* searchNodebyValue(Node<int>** , int ); 

    template void bubbleSort(Node<int>*);
    template void optimizedBubbleSort(Node<int>*);
    template void selectionSort(Node<int>*); 
    template void optimizedSelectionSort(Node<int>*); 
    template void insertionSort(Node<int>*);
    template void shellSort(Node<int>* ); 

    // intanciação explícita para os tipos BinaryTree::Node<int>*
    template Node<arvorebinaria::Node<int>*>* createNode(arvorebinaria::Node<int>*);
    
    
    } // namespace LinkedList

   


