// Napisz program, który sprawdza, czy rok jest przestępny. Wykorzystaj odpowiednie warunki
//  (np. rok przestępny, jeśli jest podzielny przez 4, ale nie przez 100, chyba że jest podzielny przez 400).

#include <iostream>

int main()
{
    int x;
    std::cout << "Podaj rok: ";
    std::cin >> x;

    // Rok jest przestępny, gdy dzieli się przez 4 BEZ RESZTY (%) 
    // ORAZ (&&) jednocześnie NIE dzieli się przez 100 (!=) 
    if (x % 4 == 0 && x % 100 != 0)
    {
        std::cout << "rok jest przystepny\n"; 
    }
    // Wyjątek: pełne stulecia są przestępne tylko jeśli dzielą się przez 400 
    else if(x % 400 == 0)
    {
        std::cout << "rok jest przystepny\n"; 
    }
    // Jeśli nie spełnia tych warunków matematycznych, nie jest przestępny 
    else
    {
        std::cout << "rok nie jest przystepny\n"; 
    }
}