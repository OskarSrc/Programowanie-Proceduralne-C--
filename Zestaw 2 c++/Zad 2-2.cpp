// Zadanie 2.2: Obliczanie N-tego elementu ciągu Fibonacciego
// Napisz dwie funkcje, które obliczą N-ty element ciągu Fibonacciego:
// Funkcja iteracyjna,
// Funkcja rekurencyjna.
// Zmierz czas wykonania obu funkcji dla różnych wartości N (np. N = 10, N = 20, N = 30).


#include <iostream>
#include <ctime>
using namespace std;

long long fibIteracyjny(int n) {
    if (n <= 1) return n;
    long long a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

long long fibRekurencyjny(int n) {
    if (n <= 1) return n; // Warunek brzegowy
    // Zauważ, że tu powstaje gigantyczne drzewo wywołań - dlatego jest to tak wolne!
    return fibRekurencyjny(n - 1) + fibRekurencyjny(n - 2); 
}

int main() {
    int n1 = 10, n2 = 20, n3 = 30; // Możesz dodać 40, to komputer chwilę "pomyśli"

    cout << "Test dla N=" << n3 << "\n";
    clock_t start = clock();
    cout << "Iteracyjny: " << fibIteracyjny(n3) << "\n";
    cout << "Czas iteracyjny: " << (double)(clock() - start) / CLOCKS_PER_SEC << " s\n";

    start = clock();
    cout << "Rekurencyjny: " << fibRekurencyjny(n3) << "\n";
    cout << "Czas rekurencyjny: " << (double)(clock() - start) / CLOCKS_PER_SEC << " s\n";

    return 0;
}