// Zadanie 1.3: Sortowanie szybkie (Quick Sort)
// Napisz program, który generuje losowy zbiór liczb całkowitych.
// Za pomocą algorytmu Quick Sort posortuj zbiór liczb w porządku rosnącym.
// Zmierz czas wykonania algorytmu Quick Sort i porównaj go z czasem wykonania sortowania bąbelkowego.

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Prosty Quick Sort do zapisu na tablicy
void quickSort(int tab[], int lewy, int prawy) {
    if (lewy >= prawy) return; // Warunek zakonczenia
    
    int srodek = tab[(lewy + prawy) / 2]; // Wybieramy Pivot (Szefa) dokladnie na srodku
    int i = lewy, j = prawy;
    
    while (i <= j) {
        while (tab[i] < srodek) i++; // Idziemy od lewej szukajac wiekszych
        while (tab[j] > srodek) j--; // Idziemy od prawej szukajac mniejszych
        if (i <= j) {
            swap(tab[i], tab[j]); // Jak znalezlismy, zamieniamy
            i++; 
            j--;
        }
    }
    
    // Sortujemy lewa i prawa czesc
    quickSort(tab, lewy, j);
    quickSort(tab, i, prawy);
}

int main() {
    int ROZMIAR = 1000;
    int tab[1000];

    srand(time(0));
    for (int i = 0; i < ROZMIAR; i++) tab[i] = rand() % 10000 + 1;

    clock_t start = clock();
    quickSort(tab, 0, ROZMIAR - 1);
    
    cout << "Czas Quick Sort: " << (double)(clock() - start) / CLOCKS_PER_SEC << " s\n";
    return 0;
}