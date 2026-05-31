#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

const int N = 20; // Liczebność zbioru

int main() {
    int d[N]; // Tablica do sortowania
    int i, j; // Liczniki pętli
    int pmin; // Indeks aktualnie znalezionego minimum

    srand((unsigned)time(NULL)); // Inicjalizujemy generator losowy aktualnym czasem
                                 // Bez tego rand() daje te same liczby przy każdym uruchomieniu

    // Wypełniamy tablicę losowymi liczbami z zakresu 0-99
    for (i = 0; i < N; i++) {
        d[i] = rand() % 100;
    }

    // Wyświetlamy tablicę przed sortowaniem
    // setw(4) — każda liczba zajmuje 4 znaki, żeby kolumny były równe
    cout << "Przed sortowaniem:\n";
    for (i = 0; i < N; i++) {
        cout << setw(4) << d[i];
    }
    cout << endl;

    // SORTOWANIE PRZEZ WYBÓR
    // Zewnętrzna pętla j: przesuwamy "granicę" posortowanej części
    // Na początku każdego przejścia zakładamy że d[j] jest minimalne (pmin = j)
    // Wewnętrzna pętla i: szukamy prawdziwego minimum w nieposortowanej części [j+1..N-1]
    // Po znalezieniu minimum — zamieniamy je z d[j]
    // Po j-tym przejściu pierwszych j+1 elementów jest już na swoich miejscach
    for (j = 0; j < N - 1; j++) {
        pmin = j; // Zakładamy że element na pozycji j jest najmniejszy
        for (i = j + 1; i < N; i++) {
            if (d[i] < d[pmin]) {
                pmin = i; // Znaleźliśmy mniejszy — zapamiętujemy jego indeks
            }
        }
        // Zamieniamy znalezione minimum z pierwszym elementem nieposortowanej części
        swap(d[pmin], d[j]);
    }

    // Wyświetlamy tablicę po sortowaniu
    cout << "Po sortowaniu:\n";
    for (i = 0; i < N; i++) {
        cout << setw(4) << d[i];
    }
    cout << endl;

    return 0;
}
