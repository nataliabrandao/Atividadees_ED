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
void bubbleSort(Node*); 
void optimizedBubblesort(Node*);
Node* copyList(int, Node**); 

int main()
{
    Node* vetor[100];
    double vetor_tempo[100];

    // Gerar listas aleatórias
    for (int i = 0; i < 100; ++i)
    {  
        Node* head = createRandomList(10000);
        Node* head_copia = copyList(10000, &head); 

        auto timeStart = high_resolution_clock::now();
        bubbleSort(head);
        auto timeStop = high_resolution_clock::now();

        auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
        vetor_tempo[i] = timeDuration.count();
        cout << "Tempo utilizado do bubbleSort para a Lista " << i + 1 << ": " << vetor_tempo[i] << " nanosegundos" << endl;
       
        timeStart = high_resolution_clock::now();
        optimizedBubblesort(head_copia);
        timeStop = high_resolution_clock::now();

        timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
        vetor_tempo[i] = timeDuration.count();
        cout << "Tempo utilizado do optimizedBubblesort para a Lista " << i + 1 << ": " << vetor_tempo[i] << " nanosegundos" << endl;
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

Node* copyList(int numElements, Node** head)
{
    Node* headcopy = nullptr;
    Node* current = *head; 

    for (int i = 0; i < numElements; i++)
    {
        insertEnd(&headcopy, current->iPayload); // Gera números aleatórios entre 0 e 99
        current = current->ptrNext;
    }
    return headcopy;
}

void bubbleSort(Node* head)
{
    if (head == nullptr || head->ptrNext == nullptr)
    {
        // Se a lista estiver vazia ou contiver apenas um nó, não há nada a fazer
        return;
    }

    Node* lastNode = nullptr;
    Node* firstNode = head;

    while (firstNode -> ptrNext != nullptr)
    {
       
        Node* current = head;

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

void optimizedBubblesort(Node* head)
{
    if (head == nullptr || head -> ptrNext == nullptr)
    {
        // Se a lista estiver vazia ou contiver apenas um nó, não há nada a fazer
        return;
    }

    bool unordered = false;
    Node* lastNode = nullptr;

    do
    {
        unordered = false;
        Node* current = head;

        while (current->ptrNext != lastNode)
        {
            if (current->iPayload > current->ptrNext->iPayload)
            {
                trocaValor(current, current->ptrNext);
                unordered = true;
            }
            current = current->ptrNext;
        }
        // O último nó (atualmente) não precisa ser considerado na próxima iteração
        lastNode = current;

    } while (unordered);
}


