#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>

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
    Node<T>* createNode(T iPayload);

    template <typename T>
    void insertEnd(Node<T>** head, T iPayload);

    template <typename T>
    void trocaValor(Node<T>* node1, Node<T>* node2);

    template <typename T>
    Node<T>* createRandomList(int numElements);

    template <typename T>
    Node<T>* copyList(int numElements, Node<T>** head);

    template <typename T>
    void displayList(Node<T>* node);

    template <typename T>
    void bubbleSort(Node<T>* head);

    template <typename T>
    void optimizedBubbleSort(Node<T>* head);

    template <typename T>
    void selectionSort(Node<T>* head);

    template <typename T>
    void optimizedSelectionSort(Node<T>* head);

    template <typename T>
    void insertionSort(Node<T>* head);

    template <typename T>
    void shellSort(Node<T>* head);

} // namespace LinkedList
