//Zadanie 2.3: Wyszukiwanie w zbiorze
//Napisz dwie funkcje do wyszukiwania elementu w posortowanej tablicy:
//Wyszukiwanie binarne za pomocą iteracji,
//Wyszukiwanie binarne za pomocą rekurencji.
//Porównaj czas wykonania obu algorytmów dla dużych zbiorów danych (np. 10 000 elementów).
#include <iostream>
#include <ctime>
using namespace std;

int tab[10000]; // Globalna tablica — wypełniana przed testami

// =============================================
// WYSZUKIWANIE BINARNE — wersja iteracyjna (pętla)
// Argumenty:
//   lewy, prawy — zakres przeszukiwania
//   szukana     — liczba której szukamy
// Zwraca: indeks znalezionego elementu, lub -1 jeśli nie ma
// =============================================
int szukajIter(int lewy, int prawy, int szukana) {

    // Pętla działa dopóki zakres nie jest pusty
    // Gdy lewy > prawy — przeszukaliśmy wszystko i nie znaleźliśmy
    while (lewy <= prawy) {

        // Wybieramy środek aktualnego zakresu
        // To jak otwarcie książki telefonicznej na środku
        int srodek = (lewy + prawy) / 2;

        if (tab[srodek] == szukana) return srodek; // Trafiliśmy!

        if (tab[srodek] < szukana) {
            // Środkowy element jest ZA MAŁY — szukana jest gdzieś po prawej
            // Odcinamy lewą połowę, przesuwamy lewy za środek
            lewy = srodek + 1;
        } else {
            // Środkowy element jest ZA DUŻY — szukana jest gdzieś po lewej
            // Odcinamy prawą połowę, cofamy prawy przed środek
            prawy = srodek - 1;
        }
    }

    return -1; // Nie znaleziono — szukana liczba nie istnieje w tablicy
}

// =============================================
// WYSZUKIWANIE BINARNE — wersja rekurencyjna
// Logika identyczna jak wyżej, ale zamiast pętli — wywołuje samą siebie
// na coraz mniejszym zakresie
// =============================================
int szukajRek(int lewy, int prawy, int szukana) {

    // Warunek stopu: zakres pusty — nie znaleziono
    if (lewy > prawy) return -1;

    int srodek = (lewy + prawy) / 2;

    if (tab[srodek] == szukana) return srodek; // Trafiliśmy!

    if (tab[srodek] < szukana) {
        // Szukana jest po prawej — wywołujemy się rekurencyjnie na prawej połowie
        return szukajRek(srodek + 1, prawy, szukana);
    } else {
        // Szukana jest po lewej — wywołujemy się rekurencyjnie na lewej połowie
        return szukajRek(lewy, srodek - 1, szukana);
    }
}

// Pomocnicza — testuje oba algorytmy dla podanej szukanej liczby
void testuj(int n, int szukana) {
    cout << "\n--- Szukamy: " << szukana << " ---\n";

    // Najpierw liczymy, potem drukujemy — żeby cout nie zaburzał pomiaru
    clock_t start = clock();
    int w1 = szukajIter(0, n - 1, szukana);
    double czasIter = (double)(clock() - start) / CLOCKS_PER_SEC;
    cout << "Iteracja   - Indeks: " << w1 << " | Czas: " << czasIter << " s\n";

    start = clock();
    int w2 = szukajRek(0, n - 1, szukana);
    double czasRek = (double)(clock() - start) / CLOCKS_PER_SEC;
    cout << "Rekurencja - Indeks: " << w2 << " | Czas: " << czasRek << " s\n";
}

int main() {
    int n = 10000;

    // Wypełniamy tablicę liczbami parzystymi: 0, 2, 4, 6, ..., 19998
    // WAŻNE: tablica MUSI być posortowana — wyszukiwanie binarne tego wymaga!
    // Gdybyśmy dali losowe liczby bez sortowania, wyniki byłyby błędne.
    for (int i = 0; i < n; i++) tab[i] = i * 2;

    testuj(n, 18000); // Liczba która JEST w tablicy (indeks 9000)
    testuj(n, 18001); // Liczba której NIE MA w tablicy (nieparzysta) — powinno zwrócić -1

    // Wniosek: oba algorytmy mają tę samą złożoność O(log n)
    // Dla 10 000 elementów to maksymalnie ~14 porównań (bo 2^14 = 16384)
    // Czasy wyjdą identyczne — różnica to tylko styl zapisu, nie wydajność

    return 0;
}
