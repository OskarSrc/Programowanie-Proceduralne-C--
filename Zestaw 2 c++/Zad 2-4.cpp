//Zadanie 2.4: Zliczanie sumy liczb w tablicy
//Napisz dwie funkcje, które obliczą sumę elementów w tablicy liczb całkowitych:
//Funkcja iteracyjna,
//Funkcja rekurencyjna.
//Porównaj obie metody pod względem wydajności dla różnych rozmiarów tablic (np. 100, 1000, 10000 elementów).
#include <iostream>
#include <ctime>
using namespace std;

int tab[10000]; // Globalna tablica — unikamy przepełnienia stosu przy dużych rozmiarach

// =============================================
// SUMA — wersja iteracyjna (pętla)
// Argument: n — ile elementów sumujemy
// =============================================
long long sumaIter(int n) {
    long long suma = 0;
    // Zwykła pętla — dodajemy każdy element po kolei
    // Prosto, szybko, bezpiecznie dla dowolnego n
    for (int i = 0; i < n; i++) suma += tab[i];
    return suma;
}

// =============================================
// SUMA — wersja rekurencyjna
// Argument: n — ile elementów sumujemy (od początku tablicy)
// =============================================
long long sumaRek(int n) {

    // Warunek stopu: pusta tablica = suma zero
    if (n == 0) return 0;

    // Bierzemy OSTATNI element i dodajemy do sumy RESZTY (bez tego elementu)
    // sumaRek(4) = tab[3] + sumaRek(3)
    //                        = tab[2] + sumaRek(2)
    //                                   = tab[1] + sumaRek(1)
    //                                              = tab[0] + sumaRek(0)
    //                                                         = 0
    // UWAGA: dla n=10000 powstaje 10000 zagnieżdżonych wywołań na stosie!
    // To może skończyć się crash'em (stack overflow) — stąd iteracja jest tu lepsza
    return tab[n - 1] + sumaRek(n - 1);
}

// Pomocnicza — testuje oba algorytmy dla podanego rozmiaru
void testuj(int n) {
    // Wypełniamy tablicę liczbami 1, 2, 3, ..., n
    for (int i = 0; i < n; i++) tab[i] = i + 1;

    cout << "\n--- ROZMIAR: " << n << " ---\n";

    // Najpierw liczymy, potem drukujemy — żeby cout nie zaburzał pomiaru
    clock_t start = clock();
    long long wynikIter = sumaIter(n);
    double czasIter = (double)(clock() - start) / CLOCKS_PER_SEC;
    cout << "Iteracja   - Suma: " << wynikIter << " | Czas: " << czasIter << " s\n";

    start = clock();
    long long wynikRek = sumaRek(n);
    double czasRek = (double)(clock() - start) / CLOCKS_PER_SEC;
    cout << "Rekurencja - Suma: " << wynikRek << " | Czas: " << czasRek << " s\n";
}

int main() {
    // Testujemy dla trzech rozmiarów zgodnie z treścią zadania
    testuj(100);
    testuj(1000);
    testuj(10000); // Przy 10000 rekurencja może się wysypać na niektórych kompilatorach

    // Wniosek: obie metody dają ten sam wynik, ale:
    // Iteracja   — O(n), bezpieczna dla dowolnego n, zero ryzyka
    // Rekurencja — O(n), ale każde wywołanie zajmuje miejsce na stosie.
    //              Dla n=10000 to 10000 poziomów głębokości — ryzyko stack overflow.
    //              Rekurencja ma sens gdy problem naturalnie się na nią rozkłada
    //              (drzewa, Quick Sort) — do prostej sumy to przerost formy nad treścią.

    return 0;
}
