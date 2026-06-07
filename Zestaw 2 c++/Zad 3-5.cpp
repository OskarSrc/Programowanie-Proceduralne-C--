#include <iostream>
#include <fstream>
#include <string>
#include <sstream> // NOWOŚĆ: Biblioteka do "strumieni napisowych" (String Stream)
using namespace std;

int main() {
    // ==========================================
    // 1. ZAPIS DO PLIKU CSV
    // ==========================================
    ofstream zapis("osoby.csv"); // Otwieramy/nadpisujemy plik
    
    // Zapisujemy nagłówek. Dlaczego to robimy? 
    // Tarcza: "Pliki CSV (Comma Separated Values) z definicji powinny w pierwszej 
    // linijce opisywać, czym są kolejne kolumny. To standardowa praktyka bazodanowa."
    zapis << "imie,nazwisko,wiek\n"; 
    
    // Zapisujemy dane oddzielając je PRZECINKAMI (bez spacji!).
    zapis << "Jan,Kowalski,25\n";
    zapis << "Anna Maria,Nowak,30\n"; // <- Wrzuciłem tu podwójne imię specjalnie!
    zapis << "Piotr,Wisniewski,22\n";
    zapis.close();

    cout << "Odczytane dane z CSV:" << endl;

    // ==========================================
    // 2. ODCZYT Z PLIKU (TUTAJ JEST NAJWIĘCEJ PUŁAPEK)
    // ==========================================
    ifstream odczyt("osoby.csv");
    string linia;
    
    // PUNKT ZAPALNY NR 1: Po co ten pojedynczy getline na początku?
    // Twoja Tarcza: "Muszę wczytać pierwszą linijkę w próżnię (pominąć nagłówek), 
    // żeby pętla poniżej nie próbowała przerobić słowa 'wiek' na liczbę."
    getline(odczyt, linia); 

    // PUNKT ZAPALNY NR 2: Dlaczego while z getline(), a nie wejscie >> ?
    // Twoja Tarcza: "Funkcja getline() wczytuje CAŁĄ linijkę z pliku, 
    // wliczając w to spacje. Dzięki temu rozwiązujemy problem podwójnych imion, 
    // na którym poległby zwykły operator >>."
    while (getline(odczyt, linia)) {
        
        // PUNKT ZAPALNY NR 3: Co to jest stringstream i po co to tu jest?
        // Twoja Tarcza: "Mamy wczytaną całą linijkę jako jeden długi tekst (string). 
        // Żeby łatwo ją pociąć na kawałki, wsadzamy ją do sztucznego strumienia 
        // (stringstream). Dzięki temu możemy używać na niej tych samych funkcji 
        // do czytania, co na prawdziwym pliku." 
        stringstream ss(linia);
        
        string imie, nazwisko, wiek;
        
        // PUNKT ZAPALNY NR 4: Trzy argumenty w getline
        // Twoja Tarcza: "Standardowy getline czyta aż do znaku Entera. 
        // Dodając trzeci argument (','), mówię mu: 'Czytaj tylko do momentu, 
        // aż natrafisz na przecinek, a potem się zatrzymaj'. 
        // Tak krok po kroku wyciągam z linijki kolejne kolumny."
        getline(ss, imie, ',');
        getline(ss, nazwisko, ',');
        getline(ss, wiek, ','); // Tu można by dać po prostu getline(ss, wiek), bo to koniec linii
        
        cout << "Imie: " << imie
             << ", Nazwisko: " << nazwisko
             << ", Wiek: " << wiek << endl;
    }
    odczyt.close();

    return 0;
}
