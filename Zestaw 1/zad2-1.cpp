// Napisz program, który wypisuje liczby od 1 do 100. 
// Dla liczb podzielnych przez 3 wypisuje "Podzielna przez 3", 
// dla liczb podzielnych przez 5 wypisuje "Podzielna przez 5", 
// a dla liczb podzielnych przez 3 i 5 wypisuje "Podzielna przez 3 i 5".

#include <iostream>
using namespace std;

int main()
{
    // Pętla 'for' od 1 do 100. 'i++' zwiększa licznik o 1 po każdym kroku. 
    for (int i = 1; i <= 100; i++) {
        // Najpierw sprawdzamy podzielność przez 3
        if (i % 3 == 0) {
            // Jeśli tak, od razu sprawdzamy czy też przez 5 (dzielność przez obie) 
            if (i % 5 == 0) {
                cout << "Podzielna przez 3 i 5 \n";
            }
            else {
                cout << "Podzielna przez 3 \n";
            }
        }
        // Jeśli nie dzieli się przez 3, sprawdzamy samą 5 
        else if (i % 5 == 0) {
                cout << "Podzielna przez 5\n";
        }
        // Jeśli przez nic, wypisujemy po prostu liczbę 
        else {
            cout << i << "\n";
        }
    }
}