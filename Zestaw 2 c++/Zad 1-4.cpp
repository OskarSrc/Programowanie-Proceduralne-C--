//Zadanie 1.4: Porównanie metod sortowania
//Wygeneruj zbiór liczb o rozmiarze 1000, 5000, 10000 i przeprowadź pomiary czasów wykonania:
//Sortowanie bąbelkowe (z optymalizacją),
//Quick Sort,
//Sortowanie przez scalanie (Merge Sort).
//Porównaj wyniki i wyciągnij wnioski na temat efektywności tych metod.

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Zwykle wielkie tablice - zero zarzadzania pamiecia "new/delete"
int oryginal[10000];
int tab[10000];
int pomocnicza[10000]; // Potrzebna do Merge Sorta

// --- BABELEK ---
void bubbleSort(int n) {
    for (int i = 0; i < n - 1; i++) {
        bool zamiana = false;
        for (int j = 0; j < n - 1 - i; j++) {
            if (tab[j] > tab[j + 1]) {
                swap(tab[j], tab[j + 1]);
                zamiana = true;
            }
        }
        if (!zamiana) break;
    }
}

// --- QUICK SORT ---
void quickSort(int lewy, int prawy) {
    if (lewy >= prawy) return;
    int srodek = tab[(lewy + prawy) / 2];
    int i = lewy, j = prawy;
    while (i <= j) {
        while (tab[i] < srodek) i++;
        while (tab[j] > srodek) j--;
        if (i <= j) {
            swap(tab[i], tab[j]);
            i++; j--;
        }
    }
    quickSort(lewy, j);
    quickSort(i, prawy);
}

// --- MERGE SORT (Bezpieczna metoda bez VLA) ---
void mergeSort(int lewy, int prawy) {
    if (lewy >= prawy) return;
    
    int srodek = (lewy + prawy) / 2;
    mergeSort(lewy, srodek);
    mergeSort(srodek + 1, prawy);
    
    // Scalanie z wykorzystaniem globalnej tablicy pomocniczej
    for (int i = lewy; i <= prawy; i++) pomocnicza[i] = tab[i];
    
    int i = lewy, j = srodek + 1, k = lewy;
    while (i <= srodek && j <= prawy) {
        if (pomocnicza[i] <= pomocnicza[j]) tab[k++] = pomocnicza[i++];
        else tab[k++] = pomocnicza[j++];
    }
    while (i <= srodek) tab[k++] = pomocnicza[i++];
}

// --- LOGIKA TESTOWANIA ---
void testuj(int n) {
    for (int i = 0; i < n; i++) oryginal[i] = rand() % 10000 + 1;

    cout << "\n--- ROZMIAR: " << n << " ---\n";

    // Test Babelka
    for (int i = 0; i < n; i++) tab[i] = oryginal[i];
    clock_t start = clock();
    bubbleSort(n);
    cout << "Bubble Sort: " << (double)(clock() - start) / CLOCKS_PER_SEC << " s\n";

    // Test Quick Sorta
    for (int i = 0; i < n; i++) tab[i] = oryginal[i];
    start = clock();
    quickSort(0, n - 1);
    cout << "Quick Sort:  " << (double)(clock() - start) / CLOCKS_PER_SEC << " s\n";

    // Test Merge Sorta
    for (int i = 0; i < n; i++) tab[i] = oryginal[i];
    start = clock();
    mergeSort(0, n - 1);
    cout << "Merge Sort:  " << (double)(clock() - start) / CLOCKS_PER_SEC << " s\n";
}

int main() {
    srand(time(0));
    testuj(1000);
    testuj(5000);
    testuj(10000);
    return 0;
}