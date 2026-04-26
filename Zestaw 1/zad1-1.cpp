// Ćwiczenie 1:
// Napisz program, który sprawdza, czy podana liczba jest dodatnia, ujemna czy równa zero. Program powinien wypisać odpowiednią informację.

#include <iostream>

int main()
{
    int x; // Deklaracja zmiennej całkowitej dla przechowywania liczby
    std::cout << "Podaj liczbe: ";
    std::cin >> x;

    // Sprawdzamy pierwszy warunek: czy x jest dokładnie zerem
    // Używamy '==', bo '=' służy do przypisywania wartości, a '==' do porównywania.
    if (x == 0)
    {
        std::cout << "Podana liczba: " << x << " jest rowna zero.\n";
    }
    // Jeśli nie zero, sprawdzamy czy mniejsza od zera (ujemna)
    else if (x < 0)
    {
        std::cout << "Podana liczba: " << x << " jest mniejsza od zera.\n";
    }
    // Jeśli żadne z powyższych, to matematycznie musi być dodatnia
    else
    {
        std::cout << "Podana liczba: " << x << " jest wieksza od zera.\n";
    }
}