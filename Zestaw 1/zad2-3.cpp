// Napisz program, który rysuje prostokąt z gwiazdek o wymiarach podanych przez użytkownika (szerokość i wysokość).

#include <iostream>
using namespace std;

int main()
{
    int szerokosc, wysokosc;
    cout << "Podaj szerokosc prostokata: ";
    cin >> szerokosc; 
    cout << "Podaj wysokosc prostokata: ";
    cin >> wysokosc; 

    // Pętla zewnętrzna steruje wierszami (wysokość). 
    for (int i = 1; i <= wysokosc; i++) {
        // Pętla wewnętrzna rysuje gwiazdki w jednym wierszu (szerokość).
        for (int j = 1; j <= szerokosc; j++) {
            cout << "*"; 
        }
        // Po narysowaniu rzędu gwiazdek, musimy przejść do nowej linii.
        cout << "\n";
    }
}