#pragma once

namespace LinkedList
{
    // Estrutura do nó da lista duplamente encadeada
    template <typename T>
    struct Node {
        T iPayload;
        Node* ptrNext;
        Node* ptrPrev;
    };

    // Protótipos das funções

    template <typename T>
    Node<T>* createNode(T);

    template <typename T>
    void insertEnd(Node<T>**, T );

    template <typename T>
    void trocaValor(Node<T>*, Node<T>*);

    template <typename T>
    Node<T>* createRandomList(int);
    
    template <typename T>
    Node<T>* copyList(int, Node<T>**);

    template <typename T>
    void displayList(Node<T>*);

    template <typename T>
    Node<T>* searchNodebyValue(Node<T>** , T ); 

    template <typename T>
    void bubbleSort(Node<T>*);

    template <typename T>
    void optimizedBubbleSort(Node<T>*);

    template <typename T>
    void selectionSort(Node<T>*);

    template <typename T>
    void optimizedSelectionSort(Node<T>*);

    template <typename T>
    void insertionSort(Node<T>*);

    template <typename T>
    void shellSort(Node<T>*);


} // namespace LinkedList
