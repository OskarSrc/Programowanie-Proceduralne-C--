//Zadanie 4.1: Sortowanie danych w pliku
//Napisz program, który odczytuje dane liczbowe z pliku tekstowego (np. liczby.txt),
//sortuje je (np. za pomocą Quick Sort), a następnie zapisuje posortowane liczby do tego samego pliku.
#include <iostream>
#include <fstream>
using namespace std;

int tab[10000]; // Globalna tablica — max 10000 liczb z pliku

// =============================================
// QUICK SORT — działa na globalnej tablicy tab[]
// (komentarze jak w poprzednich zadaniach)
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

    quickSort(lewy, j); // Sortuj lewą część
    quickSort(i, prawy); // Sortuj prawą część
}

int main() {
    int n = 0; // Licznik wczytanych liczb

    // =============================================
    // KROK 1: Odczyt z pliku
    // ifstream = input file stream — otwiera plik do CZYTANIA
    // =============================================
    ifstream wejscie("liczby.txt");

    int x;
    // Operator >> zwraca false gdy skończy się plik lub trafi na błąd
    // Pętla sama się zatrzyma na końcu pliku
    while (wejscie >> x) {
        tab[n] = x;
        n++;
    }

    wejscie.close(); // Zamykamy plik po odczycie — dobra praktyka

    // =============================================
    // KROK 2: Sortowanie
    // Sortujemy zakres [0..n-1] — tyle ile wczytaliśmy
    // =============================================
    quickSort(0, n - 1);

    // =============================================
    // KROK 3: Zapis do tego samego pliku
    // ofstream = output file stream — otwiera plik do ZAPISU
    // UWAGA: otwarcie istniejącego pliku przez ofstream automatycznie
    // go NADPISUJE (czyści zawartość przed zapisem) — dlatego możemy
    // użyć tej samej nazwy "liczby.txt" bez ryzyka zduplikowania danych
    // =============================================
    ofstream wyjscie("liczby.txt");

    for (int j = 0; j < n; j++) {
        wyjscie << tab[j] << "\n"; // Każda liczba w nowej linii
    }

    wyjscie.close(); // Zamykamy plik po zapisie

    cout << "Wczytano " << n << "
