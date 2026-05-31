// Ćwiczenie 3: Lista jednokierunkowa
// Stwórz dynamiczną listę jednokierunkową, która pozwala na dodawanie nowych elementów
// na początku i na końcu listy.

#include <iostream>
using namespace std;

// WĘZEŁ LISTY — podstawowy "klocek" z którego zbudowana jest lista
// Każdy węzeł trzyma:
//   dane      — przechowywana wartość
//   nastepny  — wskaźnik na kolejny węzeł (lub nullptr jeśli to ostatni)
struct Node {
    int dane;
    Node* nastepny;
};

// Lista w pamięci wygląda tak:
// glowa → [20|ptr] → [10|ptr] → [5|ptr] → [1|nullptr]
//          węzeł1     węzeł2     węzeł3     węzeł4 (ostatni)

// =============================================
// DODAJ NA POCZĄTEK
// Node*& glowa — referencja do wskaźnika, żeby móc zmienić gdzie glowa wskazuje
// =============================================
void dodajNaPoczatek(Node*& glowa, int wartosc) {

    Node* nowy = new Node; // Alokujemy nowy węzeł na stercie
    nowy->dane = wartosc;  // Wpisujemy wartość

    // Nowy węzeł wskazuje na to, co dotychczas było głową
    // (czyli "wpychamy" go przed całą resztę listy)
    nowy->nastepny = glowa;

    // Nowy węzeł staje się nową głową
    glowa = nowy;
}

// =============================================
// DODAJ NA KONIEC
// Musimy dojść do ostatniego węzła — tego który ma nastepny == nullptr
// =============================================
void dodajNaKoniec(Node*& glowa, int wartosc) {

    Node* nowy = new Node;
    nowy->dane = wartosc;
    nowy->nastepny = nullptr; // Nowy węzeł będzie ostatni — nic za nim

    // Przypadek szczególny: lista jest pusta
    // Nowy węzeł od razu staje się głową
    if (glowa == nullptr) {
        glowa = nowy;
        return;
    }

    // Przechodzimy przez listę aż do ostatniego węzła
    // Ostatni to ten, którego nastepny == nullptr
    Node* temp = glowa;
    while (temp->nastepny != nullptr) {
        temp = temp->nastepny;
    }

    // temp wskazuje teraz na ostatni węzeł — podczepiamy za nim nowy
    temp->nastepny = nowy;
}

// =============================================
// WYŚWIETLANIE
// Przechodzimy od głowy do końca, drukując każdy węzeł
// =============================================
void wyswietl(Node* glowa) {
    Node* temp = glowa;
    while (temp != nullptr) {
        cout << temp->dane << " -> ";
        temp = temp->nastepny; // Przechodzimy do następnego węzła
    }
    cout << "NULL\n"; // NULL oznacza koniec listy
}

// =============================================
// ZWALNIANIE PAMIĘCI
// Usuwamy węzły jeden po drugim od głowy
// WAŻNE: zanim usuniemy węzeł, zapamiętujemy gdzie jest następny
//        bo po delete węzeł przestaje istnieć i tracimy dostęp do nastepny
// =============================================
void zwolnij(Node*& glowa) {
    while (glowa != nullptr) {
        Node* temp = glowa;        // Zapamiętujemy aktualną głowę
        glowa = glowa->nastepny;   // Przesuwamy głowę na następny węzeł
        delete temp;               // Teraz możemy bezpiecznie usunąć stary węzeł
    }
}

int main() {
    Node* glowa = nullptr; // Pusta lista — głowa wskazuje na nullptr

    dodajNaPoczatek(glowa, 10); // Lista: 10 -> NULL
    dodajNaPoczatek(glowa, 20); // Lista: 20 -> 10 -> NULL
    dodajNaKoniec(glowa, 5);    // Lista: 20 -> 10 -> 5 -> NULL
    dodajNaKoniec(glowa, 1);    // Lista: 20 -> 10 -> 5 -> 1 -> NULL

    wyswietl(glowa); // Drukujemy listę

    zwolnij(glowa);  // Zwalniamy całą pamięć przed końcem programu

    return 0;
}
