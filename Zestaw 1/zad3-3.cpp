// Napisz funkcję, która przyjmuje dwie liczby i zwraca większą z nich.

#include <iostream>

// Funkcja przyjmuje dwie liczby i zwraca tę, która jest większa
float wieksza(float a, float b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int main() {
    float x, y;
    std::cout << "Podaj pierwsza liczbe: ";
    std::cin >> x;
    std::cout << "Podaj druga liczbe: ";
    std::cin >> y;

    // Wywołujemy funkcję wewnątrz std::cout, żeby od razu wypisać wynik
    std::cout << "Wieksza liczba to: " << wieksza(x, y) << "\n";
    
    return 0;
}