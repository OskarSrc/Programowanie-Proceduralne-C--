//Zadanie 2.1: Obliczanie silni
//Napisz dwie funkcje, które obliczą silnię liczby całkowitej:
//Funkcja iteracyjna,
//Funkcja rekurencyjna.
//Porównaj obie implementacje pod względem wydajności, zwłaszcza przy większych liczbach (np. 20!).

#include <iostream>
#include <ctime>
using namespace std;

long long silniaIteracyjna(int n) {
    long long wynik = 1;
    for (int i = 2; i <= n; i++) {
        wynik *= i;
    }
    return wynik;
}

long long silniaRekurencyjna(int n) {
    if (n <= 1) return 1; // Warunek brzegowy - bez niego pętla szłaby w nieskończoność
    return n * silniaRekurencyjna(n - 1); // Funkcja woła samą siebie, "zmniejszając" problem
}

int main() {
    int n = 20;

    clock_t start = clock();
    cout << "Silnia iteracyjna: " << silniaIteracyjna(n) << "\n";
    cout << "Czas: " << (double)(clock() - start) / CLOCKS_PER_SEC << " s\n\n";

    start = clock();
    cout << "Silnia rekurencyjna: " << silniaRekurencyjna(n) << "\n";
    cout << "Czas: " << (double)(clock() - start) / CLOCKS_PER_SEC << " s\n";

    return 0;
}