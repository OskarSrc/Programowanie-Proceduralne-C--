// Zadanie 2.2: Obliczanie N-tego elementu ciągu Fibonacciego
// Napisz dwie funkcje, które obliczą N-ty element ciągu Fibonacciego:
// Funkcja iteracyjna,
// Funkcja rekurencyjna.
// Zmierz czas wykonania obu funkcji dla różnych wartości N (np. N = 10, N = 20, N = 30).

#include <iostream>
#include <ctime>
using namespace std;

// ITERACYJNY: prosta pętla, trzyma tylko dwie poprzednie wartości
// Czas: O(n) — jeden przebieg pętli dla każdego N
long long fibIteracyjny(int n) {
    if (n <= 1) return n; // fib(0)=0, fib(1)=1 — zwracamy wprost

    long long a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b; // Nowy element = suma dwóch poprzednich
        a = b;     // Przesuwamy okno: a staje się poprzednim b
        b = c;     // b staje się nowym elementem
    }
    return b;
}

// REKURENCYJNY: wywołuje siebie dwa razy dla każdego kroku
// Czas: O(2^n) — dla fib(30) ponad milion wywołań!
// fib(30) = fib(29) + fib(28)
//           fib(29) = fib(28) + fib(27)  <- fib(28) liczone drugi raz!
//                     fib(28) = ...       <- i tak dalej w dół
long long fibRekurencyjny(int n) {
    if (n <= 1) return n; // Warunek brzegowy — zatrzymuje rekurencję
    return fibRekurencyjny(n - 1) + fibRekurencyjny(n - 2);
}

// Pomocnicza funkcja — testuje oba dla podanego N
void testuj(int n) {
    cout << "\n--- N = " << n << " ---\n";

    // Najpierw LICZYMY, potem drukujemy — żeby cout nie zaburzał pomiaru
    clock_t start = clock();
    long long wynikIter = fibIteracyjny(n);
    double czasIter = (double)(clock() - start) / CLOCKS_PER_SEC;
    cout << "Iteracyjny:   " << wynikIter << " | czas: " << czasIter << " s\n";

    start = clock();
    long long wynikRek = fibRekurencyjny(n);
    double czasRek = (double)(clock() - start) / CLOCKS_PER_SEC;
    cout << "Rekurencyjny: " << wynikRek << " | czas: " << czasRek << " s\n";
}

int main() {
    testuj(10);
    testuj(20);
    testuj(30);
    // testuj(40); // Odkomentuj żeby poczuć różnicę — rekurencja będzie liczyć kilka sekund
    return 0;
}
