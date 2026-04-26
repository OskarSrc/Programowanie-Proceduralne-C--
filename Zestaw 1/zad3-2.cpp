// Napisz funkcję, która sprawdza, czy dana liczba jest liczbą pierwszą.

#include <iostream>
using namespace std;

// 'void' oznacza, że funkcja nic nie zwraca (sama wypisuje komunikat).
void s(int a) {
    if (a <= 1) { // Liczby mniejsze od 2 nie są pierwsze z definicji. 
        cout << "Podana liczba nie jest liczba pierwsza"; 
    }
    else if (a == 2) { // 2 to jedyna parzysta liczba pierwsza. 
        cout << "Podana liczba jest liczba pierwsza"; 
    }
    else {
        // Sprawdzamy czy liczba 'a' dzieli się przez jakąkolwiek liczbę od 2 do a-1. 
        for (int i = 2; i < a; i++) {
            if (a % i == 0) { // Jeśli znajdziemy dzielnik, liczba nie jest pierwsza. 
                cout << "Podana liczba nie jest liczba pierwsza"; 
                break; // Przerywamy pętlę, nie ma sensu sprawdzać dalej. 
            }
            // Jeśli pętla doszła do końca (i == a-1) i nie znalazła dzielnika, jest pierwsza. 
            else if (i == a - 1) {
                cout << "Podana liczba jest liczba pierwsza";
            }
        }
    }
}

int main()
{
    s(12); // Wywołanie dla liczby 12.
}