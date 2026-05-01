//Zadanie 3.4: Zapis i odczyt obiektów do pliku
//Napisz program, który tworzy strukturę Osoba z polami: imie, nazwisko, wiek. Program powinien:
//Tworzyć 3 obiekty tej struktury,
//Zapisać te obiekty do pliku tekstowego,
//Odczytać je z pliku i wyświetlić na ekranie

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Osoba {
    string imie;
    string nazwisko;
    int wiek;
};

int main() {
    Osoba osoby[3] = {
        {"Jan", "Kowalski", 25},
        {"Anna", "Nowak", 30},
        {"Piotr", "Wisniewski", 22}
    };

    ofstream zapis("osoby.txt");
    for (int i = 0; i < 3; i++) {
        zapis << osoby[i].imie << " "
              << osoby[i].nazwisko << " "
              << osoby[i].wiek << "\n";
    }
    zapis.close();

    cout << "Odczytane osoby z pliku:" << endl;
    ifstream odczyt("osoby.txt");
    Osoba o;
    while (odczyt >> o.imie >> o.nazwisko >> o.wiek) {
        cout << o.imie << " " << o.nazwisko << ", wiek: " << o.wiek << endl;
    }
    odczyt.close();

    return 0;
}