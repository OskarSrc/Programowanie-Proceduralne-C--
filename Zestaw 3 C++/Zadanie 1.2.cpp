#include <iostream>
using namespace std;

int main() {
    int m, n;
    cout << "Podaj liczbe wierszy (m): ";
    cin >> m;
    cout << "Podaj liczbe kolumn (n): ";
    cin >> n;

    // alokacja - tablica wskaźników do wierszy
    int** tab = new int*[m];
    for (int i = 0; i < m; i++) {
        tab[i] = new int[n];
    }

    // wprowadzanie
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << "tab[" << i << "][" << j << "]: ";
            cin >> tab[i][j];
        }
    }

    // wyswietlanie
    cout << "\nTablica:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << tab[i][j] << "\t";
        }
        cout << "\n";
    }

    // zwolnienie pamieci - najpierw wiersze, potem główny wskaźnik
    for (int i = 0; i < m; i++) {
        delete[] tab[i];
    }
    delete[] tab;

    return 0;
}