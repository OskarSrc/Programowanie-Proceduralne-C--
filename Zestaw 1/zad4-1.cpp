// Napisz program, który oblicza NWD dwóch liczb za pomocą algorytmu Euklidesa. Funkcję obliczającą NWD zapisz osobno, a główną logikę programu w funkcji głównej.

#include <iostream>

// Funkcja obliczająca NWD za pomocą algorytmu Euklidesa
int nwd(int x, int y) {
    int reszta;
    // Pętla wykonuje się tak długo, aż druga liczba nie stanie się zerem
    while (y != 0) {
        reszta = x % y; // Krok 1: Obliczamy resztę z dzielenia
        x = y;          // Krok 2: Przesuwamy starszą wartość (x staje się y)
        y = reszta;     // Krok 3: Reszta staje się nowym y
    }
    return x; // Na koniec w 'x' ląduje nasz wynik
}

int main() {
    int a, b;
    std::cout << "Podaj pierwsza liczbe: ";
    std::cin >> a;
    std::cout << "Podaj druga liczbe: ";
    std::cin >> b;

    std::cout << "NWD podanych liczb to: " << nwd(a, b) << "\n";
    
    return 0;
}