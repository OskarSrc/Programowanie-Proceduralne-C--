// Zadanie 4.2: Zapis i odczyt z pliku z większą ilością danych
// Rozszerz program z zadania 4.1 tak, aby obsługiwał duże pliki z danymi (np. 1 milion liczb).
// Program powinien działać wydajnie, zarządzać pamięcią i sortować dane w sposób optymalny.
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;

// Tablica globalna na 1 000 000 elementów
// MUSI być globalna — taka ilość danych na stosie (w main) spowodowałaby crash
// Stos ma zwykle ~1-8 MB, a samo int[1000000] to już 4 MB
int tab[1000000];

// =============================================
// QUICK SORT — identyczny jak w 4.1
// Przy milionie elementów O(n log n) to ~20 milionów operacji
// Bubble Sort zrobiłby to samo w ~1 bilion operacji — różnica jest ogromna
// =============================================
void quickSort(int lewy, int prawy) {
    if (lewy >= prawy) return; // Zakres 1-elementowy — już posortowany

    int srodek = tab[(lewy + prawy) / 2]; // Pivot ze środka
    int i = lewy, j = prawy;

    while (i <= j) {
        while (tab[i] < srodek) i++; // Szukamy za dużego od lewej
        while (tab[j] > srodek) j--; // Szukamy za małego od prawej
        if (i <= j) {
            swap(tab[i], tab[j]); // Zamieniamy — każdy na właściwą stronę
            i++; j--;
        }
    }

    quickSort(lewy, j);  // Sortuj lewą część
    quickSort(i, prawy); // Sortuj prawą część
}

int main() {
    srand(time(0));

    // =============================================
    // KROK 1: Generowanie pliku z milionem liczb
    // Robimy to programowo — ręczne wpisanie miliona liczb byłoby niemożliwe
    // =============================================
    cout << "Generuje 1 000 000 liczb do pliku milion.txt... (chwileczke)\n";

    ofstream generator("milion.txt");
    for (int j = 0; j < 1000000; j++) {
        generator << rand() % 1000000 << "\n"; // Losowe liczby 0-999999
    }
    generator.close();

    // =============================================
    // KROK 2: Odczyt z pliku do tablicy
    // Wczytujemy liczby jedna po drugiej — pętla kończy się automatycznie
    // gdy operator >> napotka koniec pliku
    // =============================================
    cout << "Wczytuje z pliku...\n";

    int n = 0; // Licznik wczytanych elementów
    ifstream wejscie("milion.txt");
    while (wejscie >> tab[n]) {
        n++;
    }
    wejscie.close();

    cout << "Wczytano: " << n << " liczb\n";

    // =============================================
    // KROK 3: Sortowanie
    // Mierzymy tylko czas sortowania — bez I/O, żeby wynik był czysty
    // =============================================
    cout << "Sortuje " << n << " liczb (Quick Sort)...\n";

    clock_t start = clock();
    quickSort(0, n - 1);
    double czas = (double)(clock() - start) / CLOCKS_PER_SEC;

    cout << "Czas sortowania: " << czas << " s\n";

    // =============================================
    // KROK 4: Zapis posortowanych danych z powrotem do pliku
    // ofstream nadpisuje plik automatycznie — czyści go przed zapisem
    // =============================================
    cout << "Zapisuje posortowane liczby z powrotem do pliku...\n";

    ofstream wyjscie("milion.txt");
    for (int j = 0; j < n; j++) {
        wyjscie << tab[j] << "\n";
    }
    wyjscie.close();

    cout << "Gotowe! Plik milion.txt zawiera " << n << " posortowanych liczb\n";

    return 0;
}
