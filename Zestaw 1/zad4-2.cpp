//Napisz program, który oblicza sumę wszystkich liczb parzystych w zakresie od 1 do n, 
// przy czym n jest liczbą wprowadzoną przez użytkownika. Zastosuj funkcję do obliczenia sumy.

#include <iostream>

// Funkcja obliczająca sumę TYLKO liczb parzystych
int sumaParzystych(int n) {
    int suma = 0; // Akumulator MUSI startować od 0

    // Pętla od 1 do n
    for (int i = 1; i <= n; i++) {
        // Sprawdzamy, czy aktualna liczba (i) dzieli się przez 2 bez reszty
        if (i % 2 == 0) { 
            suma += i; // Jeśli tak, dorzucamy ją do sumy
        }
    }
    return suma;
}

int main() {
    int liczba;
    std::cout << "Podaj zakres (liczbe n): ";
    std::cin >> liczba;

    std::cout << "Suma liczb parzystych od 1 do " << liczba 
              << " wynosi: " << sumaParzystych(liczba) << "\n";
              
    return 0;
}