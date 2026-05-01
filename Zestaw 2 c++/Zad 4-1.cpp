//Zadanie 4.1: Sortowanie danych w pliku
//Napisz program, który odczytuje dane liczbowe z pliku tekstowego (np. liczby.txt), sortuje je (np. za pomocą Quick Sort), a następnie zapisuje posortowane liczby do tego samego pliku.

#include <iostream>
#include <fstream>
using namespace std;

int tab[10000]; // Globalna tablica

// Kopiujemy naszego prostego Quick Sorta z Zadania 1.3
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

int main() {
    int i = 0;
    
    // 1. Odczyt z pliku (zakładamy, że plik liczby.txt już istnieje)
    ifstream wejscie("liczby.txt");
    if (!wejscie) {
        cout << "Najpierw wygeneruj liczby.txt w zadaniu 3.1!" << endl;
        return 1;
    }
    while (wejscie >> tab[i]) {
        i++;
    }
    wejscie.close();

    // 2. Sortowanie
    quickSort(0, i - 1);

    // 3. Zapis do TEGO SAMEGO pliku (nadpisanie starego)
    ofstream wyjscie("liczby.txt");
    for (int j = 0; j < i; j++) {
        wyjscie << tab[j] << "\n";
    }
    wyjscie.close();

    cout << "Posortowano i nadpisano plik liczby.txt!" << endl;
    return 0;
}