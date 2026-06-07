#include <iostream>
#include <fstream>
#include <cstdlib>
#include <chrono> // NOWOŚĆ: Nowoczesna, precyzyjna biblioteka czasu (od C++11)
using namespace std;

// ==========================================
// PUNKT ZAPALNY NR 1: ZMIENNA GLOBALNA
// ==========================================
// Prowadzący: "Dlaczego ta tablica na milion elementów jest wyciągnięta przed maina?"
// Twoja Tarcza: "Gdybym zadeklarował tablicę int tab[1000000] wewnątrz funkcji main, 
// trafiłaby ona na STOS (stack). Stos systemowy ma zazwyczaj tylko od 1 do 8 MB. 
// Milion intów to równe 4 Megabajty, więc program prawie na pewno by się wysypał 
// z błędem Stack Overflow. Wyciągając ją globalnie, umieszczam ją w sekcji danych (BSS), 
// która jest limitowana tylko ilością fizycznego RAM-u w komputerze."
int tab[1000000];

// Funkcja Quick Sort (wersja z pivotem na środku)
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
    // KROK 1: Generowanie pliku (sztuczne dane do testów)
    cout << "Generuje 1 000 000 liczb do pliku milion.txt...\n";
    ofstream generator("milion.txt");
    for (int j = 0; j < 1000000; j++) {
        generator << rand() % 1000000 << "\n";
    }
    generator.close();

    // KROK 2: Odczyt z pliku do globalnej tablicy
    cout << "Wczytuje z pliku...\n";
    int n = 0;
    ifstream wejscie("milion.txt");
    
    // Zabezpieczenie: czytamy, dopóki jest co, ALE nie więcej niż milion (rozmiar tablicy)
    while (n < 1000000 && wejscie >> tab[n]) {
        n++;
    }
    wejscie.close();

    cout << "Wczytano: " << n << " liczb\n";

    // ==========================================
    // PUNKT ZAPALNY NR 2: DLACZEGO CHRONO?
    // ==========================================
    // Prowadzący: "Czemu użył Pan chrono, a nie funkcji clock()?"
    // Twoja Tarcza: "Biblioteka <chrono> to nowoczesny standard C++. Stara funkcja clock() 
    // mierzy tzw. takty procesora, które mogą być bardzo niedokładne przez to, 
    // że dzisiejsze procesory dynamicznie zmieniają taktowanie (np. Turbo Boost). 
    // Zegar high_resolution_clock z chrono daje mi precyzję co do nanosekundy, 
    // całkowicie niezależną od wahań taktowania CPU."
    cout << "Sortuje " << n << " liczb (Quick Sort)...\n";

    // Zapisujemy czas startu używając słówka "auto", żeby kompilator sam domyślił się typu
    auto start = chrono::high_resolution_clock::now();

    quickSort(0, n - 1);

    // Zapisujemy czas końca
    auto koniec = chrono::high_resolution_clock::now();
    
    // Obliczamy różnicę i od razu konwertujemy ją na wygodne sekundy w typie double
    chrono::duration<double> czas = koniec - start;

    // Metoda .count() wyciąga samą wartość liczbową z obiektu czasu
    cout << "Czas sortowania: " << czas.count() << " sekund\n";

    // KROK 4: Nadpisanie pliku posortowanymi danymi
    cout << "Zapisuje posortowane liczby z powrotem do pliku...\n";
    ofstream wyjscie("milion.txt");
    for (int j = 0; j < n; j++) {
        wyjscie << tab[j] << "\n";
    }
    wyjscie.close();

    cout << "Gotowe! Plik milion.txt zawiera " << n << " posortowanych liczb\n";

    return 0;
}
