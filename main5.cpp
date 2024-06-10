#include <chrono>
#include <cstdlib>
#include <iostream>

#include "node.h"
#include "arvorebinaria.h"

using std:: cin; 
using std:: cout; 
using std:: string; 
using std:: endl; 
using std:: rand; 

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::nanoseconds;

int main()
{
    
    srand(time(nullptr)); // Inicializar a semente do gerador de números aleatórios

    for (int b = 1; b <= 100; b++)
    {
        LinkedList::Node<int>* head1 = nullptr;
        int a = 0;
        
        while (a < 50)
        {
            int valor = rand() % 20000 + 1;
            if (LinkedList::searchNodebyValue(&head1, valor) == nullptr)
            {
                LinkedList::insertEnd(&head1, valor);
                a++;
            }
        }

        arvorebinaria::Node<int>* arvore = arvorebinaria::createNode(head1->iPayload);
        LinkedList::Node<int>* current = head1->ptrNext;
        while (current != nullptr)
        {
            arvorebinaria::insertNode(arvore, current->iPayload);
            current = current->ptrNext;
        }

        // Gera um valor de busca aleatório
        int searchIndex = rand() % 50;
        current = head1;
        int k = 0;
        while (k < searchIndex && current != nullptr)
        {
            current = current->ptrNext;
            k++;
        }


        // Medição do tempo para DFS
        auto timeStartDfs = high_resolution_clock::now();
        arvorebinaria::dfsSearchNode<int>(arvore, current->iPayload);
        auto timeStopDfs = high_resolution_clock::now();
        auto timeDurationDfs = duration_cast<nanoseconds>(timeStopDfs - timeStartDfs);
        cout << "Iteração " << b << " DFS: " << timeDurationDfs.count() << " nanosegundos" << endl;

        // Medição do tempo para BFS
        auto timeStartBfs = high_resolution_clock::now();
        arvorebinaria::bfsSearchNode<int>(arvore, current->iPayload);
        auto timeStopBfs = high_resolution_clock::now();
        auto timeDurationBfs = duration_cast<nanoseconds>(timeStopBfs - timeStartBfs);
        cout << "Iteração " << b << " BFS: " << timeDurationBfs.count() << " nanosegundos" << endl;

    }

    

    int tamanho = 1000; 
    int vetor[tamanho]; 
    LinkedList::Node<int>* head = nullptr; 
    arvorebinaria::Node<int>* arvore = nullptr; 

    for (int i = 1; i <= 100; i++)
    {
        for (int i = 0; i < tamanho ; i++)
        {
            vetor[i] = rand() % 1000 + 1; 
        }
    
        head = nullptr; 
        arvore = nullptr; 


        // mede o tempo da criação da lista

        auto start = high_resolution_clock::now();
        for (int i = 0; i < tamanho; i++ )
        {
            LinkedList:: insertEnd(&head, vetor[i]);
        }
        auto end = high_resolution_clock::now();
        auto durationList = duration_cast<nanoseconds>(end - start).count();
        cout << "Interação " << i << "  Lista: " << durationList << " nanoseconds" << endl;

        // Mede o tempo de criação da árvore binária de busca
        start = high_resolution_clock::now();
        arvore = arvorebinaria::createNode<int>(vetor[0]);
        for (int i = 0; i < tamanho; ++i)
        {
            arvorebinaria::insertNode(arvore, vetor[i]);
        }
        end = high_resolution_clock::now();
        auto durationTree = duration_cast<nanoseconds>(end - start).count();
        cout << "Interação " << i << "  arvore: " << durationTree << " nanoseconds" << endl;
        cout << endl;
    
    }

    return 0;
}