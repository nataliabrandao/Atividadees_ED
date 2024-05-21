#include <chrono>
#include <cstdlib>
#include <ctime> 
#include <iostream>

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

        auto timeStart = high_resolution_clock::now();
        shellSort<int>(vetor[i]);
        auto timeStop = high_resolution_clock::now();

        auto timeDuration = std::chrono::duration_cast<nanoseconds>(timeStop - timeStart);
        vetor_tempo[i] = timeDuration.count();

    }
}
