//Zadanie 3.4: Zapis i odczyt obiektów do pliku
//Napisz program, który tworzy strukturę Osoba z polami: imie, nazwisko, wiek. Program powinien:
//Tworzyć 3 obiekty tej struktury,
//Zapisać te obiekty do pliku tekstowego,
//Odczytać je z pliku i wyświetlić na ekranie

#include <iostream>
#include <fstream>
#include <string>  // Biblioteka wymagana, bo używamy napisów (string)
using namespace std;

// ==========================================
// PUNKT ZAPALNY NR 1: STRUCT vs CLASS
// ==========================================
// Prowadzący: "A dlaczego użył Pan struktury (struct), a nie klasy (class)?"
// Twoja Tarcza: "Ponieważ w strukturze w C++ wszystkie pola są domyślnie PUBLICZNE. 
// Klasa ma domyślnie pola prywatne, co wymagałoby pisania dodatkowych metod (getterów i setterów). 
// Do prostego grupowania danych (tzw. struktura POD - Plain Old Data) struct jest czystszy i szybszy."
struct Osoba {
    string imie;
    string nazwisko;
    int wiek;
};

int main() {
    // Tworzymy tablicę 3 obiektów typu Osoba i od razu wypełniamy ją danymi
    Osoba osoby[3] = {
        {"Jan", "Kowalski", 25},
        {"Anna", "Nowak", 30},
        {"Piotr", "Wisniewski", 22}
    };

    // Otwieramy plik do zapisu (pamiętamy: brutalne nadpisanie istniejącego pliku!)
    ofstream zapis("osoby.txt");
    for (int i = 0; i < 3; i++) {
        
        // ==========================================
        // PUNKT ZAPALNY NR 2: DLACZEGO ZAPISUJEMY SPACJE? (Najważniejsze!)
        // ==========================================
        // Prowadzący: "Po co te spacje między imieniem, a nazwiskiem w pliku?"
        // Twoja Tarcza: "Operator odczytu '>>' czyta ciąg znaków tylko do pierwszej napotkanej 
        // spacji (tzw. białego znaku). Jeśli złączę imię z nazwiskiem (JanKowalski), 
        // to przy odczycie strumień wciągnie wszystko do zmiennej 'imie', a potem 
        // program się wysypie przy próbie wczytania wieku."
        zapis << osoby[i].imie << " "
              << osoby[i].nazwisko << " "
              << osoby[i].wiek << "\n";
    }
    zapis.close(); // Pamiętamy o zrzuceniu bufora na dysk

    cout << "Odczytane osoby z pliku:" << endl;
    
    // Otwieramy ten sam plik do odczytu
    ifstream odczyt("osoby.txt");
    
    // Tworzymy pusty obiekt pomocniczy - to taki "koszyk", do którego 
    // będziemy tymczasowo ładować dane prosto z pliku.
    Osoba o;
    
    // ==========================================
    // PUNKT ZAPALNY NR 3: ODCZYT WIELOKROTNY W WHILE
    // ==========================================
    // Pętla odczytuje 3 rzeczy w jednej linijce. Jak to wytłumaczyć?
    // Twoja Tarcza: "Strumień próbuje wczytać najpierw imię, potem nazwisko, a na końcu wiek. 
    // Jeśli z jakiegoś powodu np. braknie wieku w pliku tekstowym, całe to potrójne zapytanie 
    // zwróci FAŁSZ i pętla w ogóle się nie wykona dla tego uszkodzonego wiersza."
    while (odczyt >> o.imie >> o.nazwisko >> o.wiek) {
        cout << o.imie << " " << o.nazwisko << ", wiek: " << o.wiek << endl;
    }
    odczyt.close(); // Zamykamy plik odczytu

    return 0;
}
