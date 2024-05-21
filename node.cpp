#include <iostream>
#include <cstdlib>

#include "node.h"

using namespace std;

namespace LinkedList
{
    template <typename T>
    Node<T>* createNode(T iPayload)
    {
        Node<T>* temp = (Node<T>*) malloc(sizeof(Node<T>*));
        temp->iPayload = iPayload;
        temp->ptrNext = nullptr;
        temp->ptrPrev = nullptr;
        return temp;
    }

    template <typename T>
    void insertEnd(Node<T>** head, T iPayload)
    {
        Node<T>* newNode = createNode(iPayload);

        if (*head == nullptr)
        {
            *head = newNode;
            return;
        }

        Node<T>* temp = *head;
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

        for (int gap = size / 2; gap > 0; gap /= 2)
        {
            for (int i = gap; i < size; ++i)
            {
                Node<T>* current = head;
                for (int j = 0; j < i; ++j)
                {
                    current = current->ptrNext;
                }

                Node<T>* current2 = current;
                for (int j = gap; j > 0 && current2 != nullptr; --j)
                {
                    Node<T>* temp = current2;
                    while (temp->iPayload < temp->ptrPrev->iPayload && temp != nullptr)
                    {
                        trocaValor(temp, temp->ptrPrev);
                        temp = temp->ptrPrev;
                    }
                }
            }
        }
}

} // namespace LinkedList


