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

    // Wypełniamy tab1 losowymi liczbami 1-10000
    // tab2 dostaje te same liczby — żeby porównanie czasów było uczciwe
    for (int i = 0; i < ROZMIAR; i++) {
        tab1[i] = rand() % 10000 + 1;
        tab2[i] = tab1[i];
    }

    // =============================================
    // 1. ZWYKŁY BUBBLE SORT (bez optymalizacji)
    // =============================================
    // Zewnętrzna pętla: ile razy "przelatujemy" przez tablicę
    // Każde przejście gwarantuje, że jeden element (największy) trafia na koniec
    clock_t start1 = clock();
    for (int i = 0; i < ROZMIAR - 1; i++) {
        // Wewnętrzna pętla: porównujemy sąsiadów od początku do końca
        // Uwaga: zawsze leci do ROZMIAR-1, nawet jeśli tablica jest już posortowana!
        // To jest właśnie marnotrawstwo, które optymalizacja naprawia.
        for (int j = 0; j < ROZMIAR - 1; j++) {
            if (tab1[j] > tab1[j + 1]) {
                swap(tab1[j], tab1[j + 1]);
            }
        }
    }
    cout << "Czas zwykly: " << (double)(clock() - start1) / CLOCKS_PER_SEC << " s\n";

    // =============================================
    // 2. ZOPTYMALIZOWANY BUBBLE SORT
    // =============================================
    clock_t start2 = clock();
    for (int i = 0; i < ROZMIAR - 1; i++) {

        // Flaga: zakładamy na początku każdego przejścia, że tablica jest już posortowana
        bool zamiana = false;

        // Optymalizacja 1: "- i" na końcu
        // Po i-tym przejściu ostatnie i elementów jest już na swoich miejscach
        // Nie ma sensu ich ponownie sprawdzać — skracamy zakres pętli
        for (int j = 0; j < ROZMIAR - 1 - i; j++) {
            if (tab2[j] > tab2[j + 1]) {
                swap(tab2[j], tab2[j + 1]);
                zamiana = true; // Musieliśmy coś zamienić — tablica NIE była posortowana
            }
        }

        // Optymalizacja 2: wczesne wyjście
        // Jeśli przeszliśmy całe przejście i nie zamieniliśmy ANI JEDNEJ pary,
        // to tablica jest już posortowana — przerywamy zamiast robić puste pętle
        if (!zamiana) break;
    }
    cout << "Czas zoptymalizowany: " << (double)(clock() - start2) / CLOCKS_PER_SEC << " s\n";

    return 0;
}
