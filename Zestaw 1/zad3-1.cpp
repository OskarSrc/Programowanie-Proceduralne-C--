// Napisz funkcję, która oblicza silnię z liczby. Funkcja powinna przyjmować liczbę jako parametr i zwracać wynik.
#include <iostream>
using namespace std;

// Definicja funkcji. 'int' przed nazwą oznacza, że funkcja zwróci liczbę całkowitą.
int silnia(int liczba) {
    int wartosc = 1; // Zaczynamy od 1, bo mnożenie przez 0 dałoby zawsze 0. 
    for (int i = 1; i <= liczba; i++) {
        wartosc *= i; // Mnożymy wynik przez kolejne liczby.
    }
    return wartosc; // Zwracamy obliczony wynik do miejsca wywołania. 
}

int main()
{
    // Wywołujemy funkcję dla liczby 3. Wynik (6) zostanie wypisany. 
    cout << silnia(3);
}