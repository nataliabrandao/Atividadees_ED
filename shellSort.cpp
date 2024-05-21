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
} Node;

// Protótipos das funções
Node* createNode(int);
void insertEnd(Node**, int);
Node* createRandomList(int);
void insertionSort(Node*);
void shellSort(Node*);
void displayList(Node*); 
void trocaValor(Node*, Node* );


// Função principal
int main()
{
    Node* vetor[1];
    double vetor_tempo[1];

    // Gerar listas aleatórias
    for (int i = 0; i < 1; ++i)
    {
        vetor[i] = createRandomList(6);

        // Medição do tempo para o Shell Sort
        auto timeStart = high_resolution_clock::now();
        shellSort(vetor[i]);
        auto timeStop = high_resolution_clock::now();

        auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
        vetor_tempo[i] = timeDuration.count();
        cout << "Tempo utilizado para a Lista " << i + 1 << ": " << vetor_tempo[i] << " nanosegundos" << endl;
    }

    return 0;
}

// Função para criar um novo nó
Node* createNode(int iPayload)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->iPayload = iPayload;
    temp->ptrNext = nullptr;
    temp->ptrPrev = nullptr;

    return temp;
}

// Função para inserir um novo nó no final da lista
void insertEnd(Node** head, int iPayload)
{
    Node* newNode = createNode(iPayload);

    if (*head == nullptr) {
        newNode->ptrPrev = nullptr;
        (*head) = newNode;
        return;
    }

    Node* temp = (*head);

    while (temp->ptrNext != nullptr) temp = temp->ptrNext;
    newNode->ptrPrev = temp;
    temp->ptrNext = newNode;
}

// Função para trocar o payload de dois nós (Node)
void trocaValor(Node* node1, Node* node2) 
{
    int temp = node1->iPayload;
    node1->iPayload = node2->iPayload;
    node2->iPayload = temp;
}

// Função para criar e retornar uma lista com elementos aleatórios
Node* createRandomList(int numElements)
{
    Node* head = nullptr;

    srand(time(0));

    for (int i = 0; i < numElements; i++) {
        insertEnd(&head, rand() % 101); // Gera números inteiros entre 1 e 100
    }
    return head;
}



// Função Shell Sort para a lista duplamente encadeada
void shellSort(Node* head)
{
    if (head == nullptr || head->ptrNext == nullptr)
    {
        return;
    }

    // Contando o número de elementos na lista
    int tamanho = 0;
    Node* temp = head;
    while (temp != nullptr)
    {
        tamanho++;
        temp = temp->ptrNext;
    }

    cout << "Tamanho da lista: " << tamanho << endl;

    // Inicializando o gap e começando o Shell Sort
    for (int gap = tamanho / 2; gap >= 1; gap /= 2)
    {
        cout << "Gap atual: " << gap << endl;

        for (int i = gap; i < tamanho; i++)
        {
            Node* current = head;
            for (int j = 0; j < i; j++)
            {
                current = current->ptrNext;
            }

            Node* current2 = current;

            cout << "Comparando e possivelmente trocando valores..." << endl;

            for (int j = gap; j > 0 && current2 != nullptr; j--)
            {
                Node* prev = current2;
                for (int k = 0; k < gap && current2 != nullptr; k++)
                {
                    current2 = current2->ptrPrev;
                }

                if (current2 != nullptr)
                {
                    cout << "Comparando " << current2->iPayload << " e " << prev->iPayload << endl;
                    if (current2->iPayload > prev->iPayload)
                    {
                        cout << "Trocando " << current2->iPayload << " e " << prev->iPayload << endl;
                        trocaValor(current2, prev);
                    }
                }
            }
        }
    }
    cout << "Lista ordenada:" << endl;
    displayList(head);
}

void displayList(Node* node)
{

    if (node == nullptr)
    {
        cout << "lista vazia: não é possível display " << endl;
        return;
    }
    if (node -> ptrPrev != nullptr)
    {
        cout << "Meio ou fim da lista : não display " << endl;
        return;
    }


    Node* temp = node;

    cout << "Payload : "; 
    
    //percoremos a lista tae seu fim e o ptrnext do ultimo nó é NULL
    while (temp != nullptr)
    {
        cout << temp -> iPayload << " "; 
        temp = temp-> ptrNext; 
    }

    cout << endl; 

}


