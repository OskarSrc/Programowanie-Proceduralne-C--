// Napisz program, który oblicza sumę liczb od 1 do n (gdzie n to liczba wprowadzona przez użytkownika).

#include <iostream>
using namespace std;

int main()
{
    // 'suma' musi być wyzerowana na starcie, inaczej program doda liczby do "śmieci" z pamięci.
    int a, suma = 0;
    cout << "Podaj liczbe: ";
    cin >> a;

    // Pętla wykonuje się dokładnie 'a' razy.
    for (int i = 1; i <= a; i++) {
        suma += i; // To samo co: suma = suma + i;
    }
    cout << "Suma liczb od 1 do " << a << " jest rowna: " << suma;
}