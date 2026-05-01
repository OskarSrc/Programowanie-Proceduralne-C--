//Zadanie 2.3: Wyszukiwanie w zbiorze
//Napisz dwie funkcje do wyszukiwania elementu w posortowanej tablicy:
//Wyszukiwanie binarne za pomocą iteracji,
//Wyszukiwanie binarne za pomocą rekurencji.
//Porównaj czas wykonania obu algorytmów dla dużych zbiorów danych (np. 10 000 elementów).

#include <iostream>
#include <ctime>
using namespace std;

int tab[10000]; // Globalna tablica

int szukajIter(int lewy, int prawy, int szukana) {
    while (lewy <= prawy) {
        int srodek = (lewy + prawy) / 2; // Wybieramy środek książki
        if (tab[srodek] == szukana) return srodek; // Znaleźliśmy!
        if (tab[srodek] < szukana) lewy = srodek + 1; // Szukana jest po prawej stronie
        else prawy = srodek - 1; // Szukana jest po lewej stronie
    }
    return -1;
}

int szukajRek(int lewy, int prawy, int szukana) {
    if (lewy > prawy) return -1; // Nie ma
    int srodek = (lewy + prawy) / 2;
    if (tab[srodek] == szukana) return srodek; // Znaleźliśmy!
    
    // Wołamy funkcję rekurencyjnie na odpowiedniej połówce
    if (tab[srodek] < szukana) return szukajRek(srodek + 1, prawy, szukana); 
    else return szukajRek(lewy, srodek - 1, szukana);
}

int main() {
    int n = 10000;
    // Ważne: Do wyszukiwania binarnego tablica MUSI być posortowana!
    for (int i = 0; i < n; i++) tab[i] = i * 2; // Tablica parzystych: 0, 2, 4...

    int szukana = 18000;

    clock_t start = clock();
    int w1 = szukajIter(0, n - 1, szukana);
    cout << "Pętla - Indeks: " << w1 << " | Czas: " << (double)(clock() - start) / CLOCKS_PER_SEC << " s\n";

    start = clock();
    int w2 = szukajRek(0, n - 1, szukana);
    cout << "Rekurencja - Indeks: " << w2 << " | Czas: " << (double)(clock() - start) / CLOCKS_PER_SEC << " s\n";

    return 0;
}