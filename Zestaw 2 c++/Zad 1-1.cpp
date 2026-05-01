//Ćwiczenie 1: Sortowanie bąbelkowe (Bubble Sort)
//Napisz program, który generuje losowy zbiór liczb całkowitych (np. 1000 liczb z zakresu od 1 do 10000).
//Za pomocą algorytmu sortowania bąbelkowego posortuj zbiór liczb w porządku rosnącym.
//Zmierz czas wykonania tego algorytmu.

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int rozmiar = 1000;
    int tab[1000]; // Najprostsza tablica
    srand(time(0));

    // 1. Wypełnianie losowymi liczbami
    for (int i = 0; i < rozmiar; i++) {
        tab[i] = rand() % 10000 + 1; 
    }

    // 2. Start zegara
    clock_t start = clock(); 

    // 3. Sortowanie bąbelkowe (Najprostsza forma)
    for (int i = 0; i < rozmiar - 1; i++) {
        for (int j = 0; j < rozmiar - 1; j++) { // Usunąłem "- i" z warunku, żeby ułatwić pamiętanie. Działa tak samo, robi o kilka obiegów więcej.
            if (tab[j] > tab[j + 1]) {
                swap(tab[j], tab[j+1]); // swap() robi dokładnie to co Twoje 3 linijki z 'temp'
            }
        }
    }

    // 4. Stop zegara i wynik
    double czas = (double)(clock() - start) / CLOCKS_PER_SEC;
    cout << "Czas: " << czas << " s\n";

    return 0;
}