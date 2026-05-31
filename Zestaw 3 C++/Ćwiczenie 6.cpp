// Ćwiczenie 6: Dynamiczna tablica (resizable array)
// Stwórz dynamiczną tablicę, która przechowuje liczby całkowite.
// Rozmiar tablicy może rosnąć w razie potrzeby — gdy tablica osiągnie pełną pojemność,
// należy zaalokować większy blok pamięci, skopiować dane i zwolnić poprzedni.

#include <iostream>
using namespace std;

// =============================================
// STRUKTURA — trzyma wszystko co potrzebne do zarządzania tablicą
//   dane      — wskaźnik na aktualny blok pamięci
//   rozmiar   — ile elementów aktualnie przechowujemy
//   pojemnosc — ile elementów MOŻEMY przechować zanim trzeba rozszerzyć
// =============================================
struct Tablica {
    int* dane;
    int rozmiar;
    int pojemnosc;
};

// =============================================
// INICJALIZACJA — tworzymy pustą tablicę z początkową pojemnością
// =============================================
void inicjalizuj(Tablica& t, int pojemnoscPoczatkowa = 4) {
    t.dane = new int[pojemnoscPoczatkowa]; // Alokujemy pierwszy blok
    t.rozmiar = 0;                         // Na razie nic nie przechowujemy
    t.pojemnosc = pojemnoscPoczatkowa;     // Możemy wpisać 4 elementy zanim rozszerzymy
}

// =============================================
// ROZSZERZ — podwaja pojemność tablicy gdy jest pełna
// To jest serce całego ćwiczenia
// =============================================
void rozszerz(Tablica& t) {

    // Nowa pojemność = dwukrotność poprzedniej
    // Podwajanie jest standardową strategią — nie rozszerzamy o 1,
    // bo wtedy przy każdym dodaniu musielibyśmy kopiować całą tablicę
    int nowaPojemnosc = t.pojemnosc * 2;

    // Alokujemy NOWY, większy blok pamięci
    int* noweDane = new int[nowaPojemnosc];

    // Kopiujemy wszystkie elementy ze starego bloku do nowego
    for (int i = 0; i < t.rozmiar; i++) {
        noweDane[i] = t.dane[i];
    }

    // Zwalniamy STARY blok — już go nie potrzebujemy
    delete[] t.dane;

    // Podmieniamy wskaźnik i aktualizujemy pojemność
    t.dane = noweDane;
    t.pojemnosc = nowaPojemnosc;

    cout << "Rozszerzono pojemnosc do: " << nowaPojemnosc << "\n";
}

// =============================================
// DODAJ — wstawia element na koniec tablicy
// Jeśli tablica pełna — najpierw rozszerza
// =============================================
void dodaj(Tablica& t, int wartosc) {

    // Czy tablica jest pełna? Jeśli tak — rozszerzamy przed dodaniem
    if (t.rozmiar == t.pojemnosc) {
        rozszerz(t);
    }

    // Wpisujemy wartość na pierwsze wolne miejsce
    t.dane[t.rozmiar] = wartosc;
    t.rozmiar++;
}

// =============================================
// WYSWIETL — pokazuje wszystkie elementy i aktualny stan tablicy
// =============================================
void wyswietl(const Tablica& t) {
    cout << "Elementy (" << t.rozmiar << "/" << t.pojemnosc << "): ";
    for (int i = 0; i < t.rozmiar; i++) {
        cout << t.dane[i] << " ";
    }
    cout << "\n";
}

// =============================================
// ZWOLNIJ — zwalnia pamięć po zakończeniu pracy
// =============================================
void zwolnij(Tablica& t) {
    delete[] t.dane;
    t.dane = nullptr;
    t.rozmiar = 0;
    t.pojemnosc = 0;
}

int main() {

    Tablica t;
    inicjalizuj(t, 4); // Startujemy z pojemnością 4

    // Dodajemy 8 elementów — tablica rozszerzy się automatycznie po 4. i 8. elemencie
    for (int i = 1; i <= 8; i++) {
        cout << "Dodaje: " << i * 10 << "\n";
        dodaj(t, i * 10);
        wyswietl(t);
    }

    zwolnij(t); // Zwalniamy pamięć przed końcem programu

    return 0;
}
