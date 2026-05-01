//Zadanie 2.4: Zliczanie sumy liczb w tablicy
//Napisz dwie funkcje, które obliczą sumę elementów w tablicy liczb całkowitych:
//Funkcja iteracyjna,
//Funkcja rekurencyjna.
//Porównaj obie metody pod względem wydajności dla różnych rozmiarów tablic (np. 100, 1000, 10000 elementów).

#include <iostream>
#include <ctime>
using namespace std;

int tab[10000]; // Globalna tablica

long long sumaIter(int n) {
    long long suma = 0;
    for (int i = 0; i < n; i++) suma += tab[i];
    return suma;
}

long long sumaRek(int n) {
    if (n == 0) return 0;
    // Bierzemy ostatni element i dodajemy sumę z reszty (bez tego ostatniego)
    return tab[n - 1] + sumaRek(n - 1); 
}

int main() {
    int rozmiar = 10000;
    for (int i = 0; i < rozmiar; i++) tab[i] = i + 1; // Wypelniamy 1, 2, 3...

    clock_t start = clock();
    cout << "Suma pętla: " << sumaIter(rozmiar) << "\n";
    cout << "Czas: " << (double)(clock() - start) / CLOCKS_PER_SEC << " s\n\n";

    start = clock();
    cout << "Suma rekurencja: " << sumaRek(rozmiar) << "\n";
    cout << "Czas: " << (double)(clock() - start) / CLOCKS_PER_SEC << " s\n";

    return 0;
}