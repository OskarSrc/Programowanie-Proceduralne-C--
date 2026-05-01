//Zadanie 3.2: Odczyt danych z pliku
//Napisz program, który wczytuje liczby z pliku tekstowego liczby.txt, sortuje je w porządku rosnącym (np. za pomocą Quick Sort) i zapisuje wynik do nowego pliku tekstowego posortowane_liczby.txt.

#include <iostream>
#include <fstream>
#include <algorithm> 
using namespace std;

int main() {
    int tab[1000]; // Używamy naszej starej, dobrej "sztywnej" tablicy
    int x, i = 0;

    // 1. Odczyt z pliku
    ifstream wejscie("liczby.txt");
    while (wejscie >> x) {
        tab[i] = x;
        i++; // Liczymy, ile liczb realnie wczytaliśmy
    }
    wejscie.close();

    // 2. Sortowanie (używamy gotowca, żeby nie pisać tu znów QuickSorta na 30 linijek)
    // tab to początek, a tab + i to koniec naszej tablicy
    sort(tab, tab + i); 

    // 3. Zapis do nowego pliku
    ofstream wyjscie("posortowane_liczby.txt");
    for (int j = 0; j < i; j++) {
        wyjscie << tab[j] << "\n";
    }
    wyjscie.close();

    cout << "Posortowano i zapisano do posortowane_liczby.txt" << endl;

    return 0;
}