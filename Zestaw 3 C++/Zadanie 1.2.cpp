// Ćwiczenie 2: Dynamiczna alokacja pamięci – tablica dwuwymiarowa
// Stwórz program, który dynamicznie alokuje pamięć dla tablicy dwuwymiarowej
// o wymiarach m x n. Program powinien umożliwić wprowadzenie danych do tablicy
// oraz ich wyświetlenie. Po zakończeniu pracy z tablicą należy zwolnić pamięć.

#include <iostream>
using namespace std;

int main() {
    int m, n;
    cout << "Podaj liczbe wierszy (m): ";
    cin >> m;
    cout << "Podaj liczbe kolumn (n): ";
    cin >> n;

    // ALOKACJA TABLICY DWUWYMIAROWEJ
    // Nie możemy zrobić "new int[m][n]" gdy m i n są zmiennymi
    // Zamiast tego alokujemy w dwóch krokach:
    //
    // Krok 1: Alokujemy tablicę m wskaźników — każdy będzie wskazywał na jeden wiersz
    //         Wyobraź sobie to jako słupek m "haczyków"
    int** tab = new int*[m];

    // Krok 2: Dla każdego wiersza alokujemy osobno tablicę n liczb
    //         Każdy "haczyk" dostaje swój rząd liczb
    for (int i = 0; i < m; i++) {
        tab[i] = new int[n];
    }

    // W pamięci wygląda to tak:
    // tab →  [ptr0] → [0][1][2]...[n-1]   (wiersz 0)
    //        [ptr1] → [0][1][2]...[n-1]   (wiersz 1)
    //        ...
    //        [ptrm] → [0][1][2]...[n-1]   (wiersz m-1)

    // WPROWADZANIE — podwójna pętla: i = wiersz, j = kolumna
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << "tab[" << i << "][" << j << "]: ";
            cin >> tab[i][j]; // Działa tak samo jak na zwykłej tablicy 2D
        }
    }

    // WYŚWIETLANIE — \t (tabulator) wyrównuje kolumny wizualnie
    cout << "\nTablica:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << tab[i][j] << "\t";
        }
        cout << "\n"; // Nowa linia po każdym wierszu
    }

    // ZWALNIANIE PAMIĘCI — KOLEJNOŚĆ MA ZNACZENIE!
    // Musimy zwolnić w odwrotnej kolejności niż alokowaliśmy:
    //
    // Krok 1: Najpierw zwalniamy każdy wiersz osobno
    //         Gdybyśmy najpierw zwolnili tab (główny wskaźnik),
    //         stracilibyśmy adresy wierszy — wyciek pamięci!
    for (int i = 0; i < m; i++) {
        delete[] tab[i]; // Zwalniamy i-ty wiersz
    }

    // Krok 2: Dopiero teraz zwalniamy tablicę wskaźników
    delete[] tab;

    return 0;
}
