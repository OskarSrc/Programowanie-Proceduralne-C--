#include <iostream>
using namespace std;

int main() {
    int* tab = new int[10]; // alokacja dynamiczna

    // wprowadzanie
    for (int i = 0; i < 10; i++) {
        cout << "Podaj liczbe " << i + 1 << ": ";
        cin >> tab[i];
    }

    // wyswietlanie
    cout << "\nTablica: ";
    for (int i = 0; i < 10; i++) {
        cout << tab[i] << " ";
    }
    cout << endl;

    delete[] tab; // zwolnienie pamieci
    return 0;
}