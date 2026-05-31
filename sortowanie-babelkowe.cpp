#include <iostream>
#include <iomanip>  // setw() — wyrównanie liczb przy wyświetlaniu
#include <cstdlib>  // rand(), srand()
#include <ctime>    // time() — ziarno dla generatora losowego
using namespace std;

const int N = 20; // Liczebność zbioru — zmień tutaj żeby testować inne rozmiary

int main() {
    int d[N]; // Tablica do sortowania
    int i, j; // Liczniki pętli — styl klasyczny, zadeklarowane na górze

    srand((unsigned)time(NULL)); // Inicjalizujemy generator losowy aktualnym czasem
                                 // Bez tego rand() daje te same liczby przy każdym uruchomieniu

    // Wypełniamy tablicę losowymi liczbami z zakresu 0-99
    for (i = 0; i < N; i++) d[i] = rand() % 100;

    // Wyświetlamy tablicę przed sortowaniem
    // setw(4) — każda liczba zajmuje 4 znaki, żeby kolumny były równe
    cout << "Przed sortowaniem:\n";
    for (i = 0; i < N; i++) cout << setw(4) << d[i];
    cout << endl;

    // Sortowanie bąbelkowe — wersja podstawowa (bez optymalizacji)
    // Zewnętrzna pętla j: ile razy "przelatujemy" przez tablicę (N-1 razy)
    // Wewnętrzna pętla i: porównujemy sąsiednie pary d[i] i d[i+1]
    // Jeśli lewa > prawa — zamieniamy miejscami
    // Po każdym przejściu największy nieposortowany element "wypływa" na koniec
    for (j = 0; j < N - 1; j++) {
        for (i = 0; i < N - 1; i++) {
            if (d[i] > d[i + 1]) {
                swap(d[i], d[i + 1]);
            }
        }
    }

    // Wyświetlamy tablicę po sortowaniu
    cout << "Po sortowaniu:\n";
    for (i = 0; i < N; i++) cout << setw(4) << d[i];
    cout << endl;

    return 0;
}
