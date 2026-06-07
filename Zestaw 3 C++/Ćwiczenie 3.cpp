// ============================================================================
// Ćwiczenie 3: Lista jednokierunkowa
// ============================================================================
// Opis: Stwórz dynamiczną listę jednokierunkową, która pozwala na dodawanie 
// nowych elementów na początku i na końcu listy.
//
// Zadanie:
// 1. Utwórz strukturę dla pojedynczego elementu listy (zawierającego dane 
//    i wskaźnik na następny element).
// 2. Dodaj funkcje do:
//    - Dodawania elementu na początek listy.
//    - Dodawania elementu na koniec listy.
//    - Wyświetlania listy.
// 3. Po zakończeniu programu zwolnij pamięć, usuwając wszystkie elementy listy.
//
// Wskazówka: Użyj wskaźników do dynamicznego alokowania pamięci dla nowych elementów.
// ============================================================================

#include <iostream>
using namespace std;

// Pojedynczy "wagon" naszej listy
struct Node {
    int dane;         // Wartość liczbowa
    Node* nastepny;   // Wskaźnik na kolejny wagon (lub nullptr, jeśli to koniec)
};

// Dodawanie na początek (używamy & żeby trwale zmienić oryginał z maina)
void dodajNaPoczatek(Node*& glowa, int wartosc) {
    // Super myk z klamerkami: od razu tworzy węzeł z wartością i podpina starą głowę jako następnik
    Node* nowy = new Node{ wartosc, glowa };
    glowa = nowy; // Nowy element staje się oficjalnie pierwszą głową
}

// Dodawanie na koniec
void dodajNaKoniec(Node*& glowa, int wartosc) {
    // Tworzymy nowy węzeł, który będzie ostatni, więc wskazuje na nullptr
    Node* nowy = new Node{ wartosc, nullptr };
    
    // Jeśli lista jest pusta, nowy element staje się głową
    if (glowa == nullptr) {
        glowa = nowy;
        return;
    }
    
    // Zmienna pomocnicza do "przejścia" przez listę
    Node* temp = glowa;
    
    // Jedziemy do ostatniego wagonu (takiego, który z tyłu nie ma nic podpiętego)
    while (temp->nastepny != nullptr)
        temp = temp->nastepny;
        
    // Podpinamy nasz nowy wagon na sam koniec
    temp->nastepny = nowy;
}

// Wyświetlanie (Brak & w parametrze! Pracujemy na kopii wskaźnika, więc nic nie psujemy)
void wyswietl(Node* glowa) {
    while (glowa != nullptr) {
        cout << glowa->dane << " -> ";
        glowa = glowa->nastepny; // Przesuwamy się do przodu na kopii wskaźnika
    }
    cout << "NULL\n";
}

// Zwalnianie pamięci ("Zasada Tarzana")
void zwolnij(Node*& glowa) {
    while (glowa != nullptr) {
        Node* temp = glowa;       // 1. Łapiemy aktualny węzeł
        glowa = glowa->nastepny;  // 2. Przesuwamy głowę dalej (łapiemy nową lianę)
        delete temp;              // 3. Bezpiecznie kasujemy stary węzeł
    }
}

int main() {
    Node* glowa = nullptr; // Na start lista jest całkowicie pusta

    dodajNaPoczatek(glowa, 10); // 10 -> NULL
    dodajNaPoczatek(glowa, 20); // 20 -> 10 -> NULL
    dodajNaKoniec(glowa, 5);    // 20 -> 10 -> 5 -> NULL
    dodajNaKoniec(glowa, 1);    // 20 -> 10 -> 5 -> 1 -> NULL

    wyswietl(glowa); // Wyświetli: 20 -> 10 -> 5 -> 1 -> NULL
    zwolnij(glowa);  // Sprzątanie po sobie (brak wycieków pamięci)

    return 0;
}
