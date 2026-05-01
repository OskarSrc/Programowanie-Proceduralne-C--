//Zadanie 3.1: Zapis danych do pliku
//Napisz program, który generuje losowy zbiór liczb całkowitych (np. 1000 liczb) i zapisuje go do pliku tekstowego o nazwie liczby.txt.
//Zadbaj o to, by każda liczba była zapisana w osobnej linii.

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    ofstream plik("liczby.txt");

    srand(time(0));
    for (int i = 0; i < 1000; i++) {
        plik << rand() % 10000 + 1 << "\n";
    }

    plik.close();
    cout << "Zapisano 1000 liczb do liczby.txt" << endl;

    return 0;
}