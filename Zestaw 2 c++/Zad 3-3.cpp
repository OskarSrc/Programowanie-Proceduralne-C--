//Zadanie 3.3: Przetwarzanie danych z pliku
//Napisz program, który wczytuje dane z pliku tekstowego, oblicza średnią oraz sumę liczb, a wynik zapisuje do nowego pliku o nazwie wyniki.txt.
//Plik wejściowy będzie zawierał jedną liczbę w każdej linii.

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream wejscie("liczby.txt");
    double suma = 0;
    int ilosc = 0;
    int x;

    while (wejscie >> x) {
        suma += x;
        ilosc++;
    }
    wejscie.close();

    double srednia = suma / ilosc;

    ofstream wyjscie("wyniki.txt");
    wyjscie << "Suma: " << suma << "\n";
    wyjscie << "Srednia: " << srednia << "\n";
    wyjscie.close();

    cout << "Suma: " << suma << endl;
    cout << "Srednia: " << srednia << endl;
    cout << "Wyniki zapisano do wyniki.txt" << endl;

    return 0;
}