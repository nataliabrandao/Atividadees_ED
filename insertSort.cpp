#include <iostream> 
#include <chrono>
#include <cstdlib>

using std:: cin; 
using std:: cout; 
using std:: string; 
using std:: endl; 
using std:: rand; 

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::nanoseconds;

typedef struct Node 
{
    int iPayload; 
    Node* ptrNext; 
    Node* ptrPrev;

}Node;

//Protótipos das funções
Node* createNode(int); 
void insertEnd(Node**, int); 
void trocaValor(Node* , Node*);
Node* createRandomList(int);
void insertionSort (Node* ); 

int main()
{
    Node* vetor[5];
    double vetor_tempo[5];

    // Gerar listas aleatórias
    for (int i = 0; i < 5; ++i)
    {
        vetor[i] = createRandomList(10);

        auto timeStart = high_resolution_clock::now();
        insertionSort(vetor[i]);
        auto timeStop = high_resolution_clock::now();

        auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
        vetor_tempo[i] = timeDuration.count();
        cout << "Tempo utilizado para a Lista " << i + 1 << ": " << vetor_tempo[i] << " nanosegundos" << endl;
    }
    
    return 0; 
}

Node* createNode(int iPayload)
    {
        Node* temp = (Node*) malloc(sizeof(Node)); 
        temp -> iPayload = iPayload;
        temp-> ptrNext = nullptr;
        temp -> ptrPrev = nullptr; 

        return temp;
    }

void insertEnd(Node** head, int iPayload)
{
    Node* newNode = createNode(iPayload); 
    
    if (*head == nullptr)
    {
        newNode -> ptrPrev = nullptr; 
        (*head) = newNode; 
        return; 
    }

    Node* temp = (*head); 
    
    while(temp -> ptrNext != nullptr) temp = temp -> ptrNext;
    newNode -> ptrPrev = temp;  
    temp -> ptrNext = newNode;  
}

void trocaValor(Node* node1, Node* node2)
{
    int temp = node1 -> iPayload;
    node1 -> iPayload = node2 -> iPayload;
    node2 -> iPayload = temp;
}

// Função para criar e retornar uma lista com elementos aleatórios
Node* createRandomList(int numElements)
{
    Node* head = nullptr;

    for (int i = 0; i < numElements; i++)
    {
        insertEnd(&head, rand() % 100); // Gera números aleatórios entre 0 e 99
    }
    return head;
}

void insertionSort (Node* head)
{
    if (head == nullptr || head -> ptrNext == nullptr)
        return; // Não há nada para ordenar se a lista estiver vazia ou tiver apenas um elemento

   Node* current2 = head -> ptrNext;   

    while (current2 != nullptr)
    {
        Node* current1 = head;  

        while (current1 != current2)
        {
            if (current1 -> iPayload > current2 -> iPayload)
            {
                trocaValor(current1, current2); 
            }
            else 
            {
                current1 = current1 -> ptrNext; 
            }
        }
        current2 = current2 -> ptrNext; 
    }
}
