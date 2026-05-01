//Zadanie 3.5: Zapis danych w formacie CSV
//Napisz program, który zapisuje dane o kilku osobach (imię, nazwisko, wiek) do pliku w formacie CSV (Comma Separated Values).
//Program powinien również umożliwiać odczyt danych z tego pliku i wyświetlanie ich na ekranie.

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    // Zapis do CSV
    ofstream zapis("osoby.csv");
    zapis << "imie,nazwisko,wiek\n";
    zapis << "Jan,Kowalski,25\n";
    zapis << "Anna,Nowak,30\n";
    zapis << "Piotr,Wisniewski,22\n";
    zapis.close();

    cout << "Odczytane dane z CSV:" << endl;

    // Odczyt z CSV
    ifstream odczyt("osoby.csv");
    string linia;
    getline(odczyt, linia); // pomiń nagłówek

    while (getline(odczyt, linia)) {
        stringstream ss(linia);
        string imie, nazwisko, wiek;
        getline(ss, imie, ',');
        getline(ss, nazwisko, ',');
        getline(ss, wiek, ',');
        cout << "Imie: " << imie
             << ", Nazwisko: " << nazwisko
             << ", Wiek: " << wiek << endl;
    }
    odczyt.close();

    return 0;
}