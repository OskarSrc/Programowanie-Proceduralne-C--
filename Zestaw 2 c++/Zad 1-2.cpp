// Ćwiczenie 1.2: Optymalizacja sortowania bąbelkowego
// Zoptymalizuj algorytm sortowania bąbelkowego, aby zakończył działanie, jeśli podczas jednego przejścia przez zbiór nie wystąpiły żadne zamiany.
// Przetestuj czas wykonania z optymalizacją i porównaj go z wersją nieoptymalizowaną.

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int ROZMIAR = 1000;
    int tab1[1000]; // Dla zwyklego
    int tab2[1000]; // Dla optymalnego

    srand(time(0));
    for (int i = 0; i < ROZMIAR; i++) {
        tab1[i] = rand() % 10000 + 1;
        tab2[i] = tab1[i]; // Kopiujemy, zeby bylo sprawiedliwie
    }

    // 1. Zwykly Bubble Sort
    clock_t start1 = clock();
    for (int i = 0; i < ROZMIAR - 1; i++) {
        for (int j = 0; j < ROZMIAR - 1; j++) {
            if (tab1[j] > tab1[j + 1]) {
                swap(tab1[j], tab1[j + 1]); // Jedna linijka zamiast trzech!
            }
        }
    }
    cout << "Czas zwykly: " << (double)(clock() - start1) / CLOCKS_PER_SEC << " s\n";

    // 2. Zoptymalizowany Bubble Sort
    clock_t start2 = clock();
    for (int i = 0; i < ROZMIAR - 1; i++) {
        bool zamiana = false; // Zakladamy, ze jest juz posortowane
        for (int j = 0; j < ROZMIAR - 1 - i; j++) {
            if (tab2[j] > tab2[j + 1]) {
                swap(tab2[j], tab2[j + 1]);
                zamiana = true; // Zaznaczamy, ze ruszylismy tablice
            }
        }
        if (!zamiana) break; // Jesli nic nie zamienilismy, koniec!
    }
    cout << "Czas zoptymalizowany: " << (double)(clock() - start2) / CLOCKS_PER_SEC << " s\n";

    return 0;
}