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
void selectionSort(Node*); 
void optimizedSelectionSort(Node*);
Node* copyList(int, Node**); 

int main()
{
   Node* vetor[4];
    double vetor_tempo[13];

    // Gerar listas aleatórias
    for (int i = 0; i < 3; ++i)
    {  
        Node* head = createRandomList(10);
        Node* head_copia = copyList(10, &head); 

        auto timeStart = high_resolution_clock::now();
        selectionSort(head);
        auto timeStop = high_resolution_clock::now();

        auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
        vetor_tempo[i] = timeDuration.count();
        cout << "Tempo utilizado do selectionSort para a Lista " << i + 1 << ": " << vetor_tempo[i] << " nanosegundos" << endl;
        
        timeStart = high_resolution_clock::now();
        optimizedSelectionSort(head_copia);
        timeStop = high_resolution_clock::now();

        timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
        vetor_tempo[i] = timeDuration.count();
        cout << "Tempo utilizado do  optimizedSelectionSort para a Lista " << i + 1 << ": " << vetor_tempo[i] << " nanosegundos" << endl;
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


void selectionSort(Node* head)
{
    if (head == nullptr || head -> ptrNext == nullptr)
    {
        // Se a lista estiver vazia ou contiver apenas um nó, não há nada a fazer
        return;
    }

    Node* current = head; // Começamos do nó inicial da lista
    Node* start = current->ptrNext;

    while (current != nullptr)
    { // Enquanto não chegarmos ao final da lista

        while (start != nullptr ) { // Enquanto não chegarmos ao final da lista
            if (current->iPayload > start->iPayload)
            {
                trocaValor(current, start);
            }
            start = start->ptrNext; // Avançar para o próximo nó
        } 
        current = current->ptrNext; // Avançar para o próximo nó para a próxima iteração
    }
}

void optimizedSelectionSort(Node* head)
{
   if (head == nullptr || head->ptrNext == nullptr)
    {
        // Se a lista estiver vazia ou contiver apenas um nó, não há nada a fazer
        return;
    }

    Node* current = head; // Ponteiro para o início da lista não ordenada
    bool bOrdered; // Variável para verificar se a lista está ordenada

    while (current->ptrNext != nullptr && !bOrdered)
    { // Enquanto houver elementos não ordenados e a lista não estiver ordenada
        bOrdered = true; // Supõe que a lista está ordenada nesta iteração
        Node* minNode = current; // Inicialmente, consideramos o nó atual como o mínimo 

        // Encontrar o nó com o menor valor a partir do nó atual
        Node* temp = current->ptrNext;
        while (temp != nullptr)
        {
            if (temp->iPayload < minNode->iPayload)
            {
                minNode = temp;
               bOrdered = false; // Se houver algum elemento menor, a lista não está ordenada
            }
            temp = temp->ptrNext;
        }
        // Trocar os valores entre o nó atual e o nó com o menor valor
        if (minNode != current)
        {
            trocaValor(current, minNode);
        }
        // Avançar para o próximo elemento não ordenado
        current = current->ptrNext;
    }
}

