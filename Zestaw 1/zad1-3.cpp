// Napisz program, który sprawdza, czy podana liczba jest liczbą parzystą czy nieparzystą.

#include <iostream>

int main()
{
    int x;
    std::cout << "Podaj liczbe: ";
    std::cin >> x;

    if (x % 2 == 0)
    {
        std::cout << "liczba jest parzysta\n";
    }
    else
    {
        std::cout << "liczba nie jest parzysta\n";
    }
}