// Ćwiczenie 6: Dynamiczna tablica (resizable array)
// Stwórz dynamiczną tablicę, która przechowuje liczby całkowite.
// Rozmiar tablicy może rosnąć w razie potrzeby — gdy tablica osiągnie pełną pojemność,
// należy zaalokować większy blok pamięci, skopiować dane i zwolnić poprzedni.
#include <iostream>
using namespace std;

// =============================================
// STRUKTURA TABLICY — Wyobraź sobie, że to Twój regał na książki
// =============================================
struct Tablica {
    int* dane;     // Wskaźnik (adres) na to, gdzie fizycznie stoi Twój regał
    int rozmiar;   // Ile książek FAKTYCZNIE na nim teraz leży
    int pojemnosc; // Ile książek MAKSYMALNIE wejdzie, zanim regał pęknie
};

// =============================================
// INICJALIZACJA — Kupujemy pierwszy, mały regał
// Używamy ampersanda (&), żeby modyfikować oryginał z main()
// =============================================
void inicjalizuj(Tablica& t, int pojemnoscPoczatkowa = 4) {
    t.dane = new int[pojemnoscPoczatkowa]; // Alokujemy w pamięci nowy regał na 4 miejsca
    t.rozmiar = 0;                         // Na razie nie ma na nim ani jednej książki
    t.pojemnosc = pojemnoscPoczatkowa;     // Zapisujemy w dokumentach, że mieści 4
}

// =============================================
// ROZSZERZ — Najważniejsza funkcja! (Regał jest pełny)
// W C++ nie da się magicznie rozciągnąć tablicy w pamięci.
// Musimy kupić nowy regał, przenieść rzeczy i wyrzucić stary.
// =============================================
void rozszerz(Tablica& t) {
    // 1. Zawsze PODWAJAMY rozmiar (żeby nie biegać do sklepu po nowy regał co jedną książkę)
    int nowaPojemnosc = t.pojemnosc * 2; 

    // 2. Kupujemy nowy, 2x większy regał
    int* noweDane = new int[nowaPojemnosc]; 

    // 3. Mozolnie, sztuka po sztuce, przenosimy książki ze starego regału na nowy
    for (int i = 0; i < t.rozmiar; i++) {
        noweDane[i] = t.dane[i]; 
    }

    // 4. Rąbiemy stary, mały regał na drewno (BARDZO WAŻNE: zwalniamy starą pamięć!)
    delete[] t.dane; 
    
    // 5. Od teraz oficjalnie "nasz główny regał" to ten nowy, duży
    t.dane = noweDane;           
    t.pojemnosc = nowaPojemnosc; // Aktualizujemy papiery o nowej pojemności
}

// =============================================
// DODAJ — Wkładanie nowej książki (elementu) na koniec
// =============================================
void dodaj(Tablica& t, int wartosc) {
    // Przed włożeniem książki patrzymy, czy regał nie jest pełny
    if (t.rozmiar == t.pojemnosc) {
        rozszerz(t); // Jeśli pełny, wołamy naszą funkcję, która kupi większy regał
    }
    
    // Kładziemy nową wartość na pierwsze wolne miejsce (indeks to zawsze aktualny rozmiar)
    t.dane[t.rozmiar] = wartosc; 
    
    // Zaznaczamy, że mamy o jedną książkę więcej
    t.rozmiar++;                 
}

// =============================================
// WYŚWIETL — Wypisanie wszystkiego na ekran (bez & bo tylko patrzymy)
// =============================================
void wyswietl(const Tablica& t) {
    cout << "Stan (" << t.rozmiar << "/" << t.pojemnosc << "): ";
    for (int i = 0; i < t.rozmiar; i++) {
        cout << t.dane[i] << " ";
    }
    cout << "\n";
}

// =============================================
// ZWOLNIJ — Likwidacja pokoju (zwalniamy pamięć przed zamknięciem)
// =============================================
void zwolnij(Tablica& t) {
    delete[] t.dane; // Niszczymy nasz ostatni regał (obojętnie jak bardzo był rozszerzony)
    t.dane = nullptr;
    t.rozmiar = 0;
    t.pojemnosc = 0;
}

int main() {
    Tablica t;
    inicjalizuj(t, 4); // Startujemy skromnie, z pojemnością 4

    // Próbujemy wcisnąć 9 elementów. 
    // Tablica "pęknie" i sama rozszerzy się dwa razy w tle (przy 5 i 9 elemencie)!
    for (int i = 1; i <= 9; i++) {
        dodaj(t, i * 10); 
        wyswietl(t); // Zobaczysz na ekranie, jak rośnie pojemność
    }

    zwolnij(t); // Zawsze po sobie sprzątamy

    return 0;
}
