
#include <chrono>
#include <cstdlib>
#include <ctime> 

#include "node.h"

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
    Node<int>* vetor[100];
    double vetor_tempo[100];

    // Gerar listas aleatórias
    for (int i = 0; i < 100; ++i)
    {
        vetor[i] = createRandomList<int>(10000);
        Node<int>* vetor_copia = copyList<int>(10000, &vetor[i]);

        // Bubble Sort
        auto timeStart = high_resolution_clock::now();
        bubbleSort<int>(vetor[i]);
        auto timeStop = high_resolution_clock::now();
        auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
        vetor_tempo_bubble[i] = timeDuration.count();
        cout << "Tempo utilizado do bubbleSort para a Lista " << i + 1 << ": " << vetor_tempo_bubble[i] << " nanosegundos" << endl;

        // Optimized Bubble Sort
        timeStart = high_resolution_clock::now();
        optimizedBubbleSort<int>(vetor_copia);
        timeStop = high_resolution_clock::now();
        timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
        vetor_tempo_optimized_bubble[i] = timeDuration.count();
        cout << "Tempo utilizado do optimizedBubbleSort para a Lista " << i + 1 << ": " << vetor_tempo_optimized_bubble[i] << " nanosegundos" << endl;
    }
}
