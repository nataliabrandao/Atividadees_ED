#include <iostream> 
#include <chrono>
#include <cstdlib>

#include "node.h"

using std:: cin; 
using std:: cout; 
using std:: string; 
using std:: endl; 
using std:: rand; 

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::nanoseconds;

// main para o insertsort
int main() 
{
    LinkedList::Node<int>* vetor[100];
    double vetor_tempo[100];

    // Gerar listas aleatórias
    for (int i = 0; i < 100; ++i)
    {
        vetor[i] = LinkedList::createRandomList<int>(10000);

        auto timeStart = high_resolution_clock::now();
        LinkedList::insertionSort(vetor[i]);
        auto timeStop = high_resolution_clock::now();

        auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
        vetor_tempo[i] = timeDuration.count();
        cout << "Tempo utilizado do insertSort para a Lista " << i + 1 << ": " << vetor_tempo[i] << " nanosegundos" << endl;
    }
    
    return 0; 
}
