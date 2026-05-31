// Ćwiczenie 5: Kolejka dynamiczna
// Stwórz strukturę danych kolejki (FIFO), która pozwala na dodawanie elementów na koniec
// i usuwanie z początku kolejki.
// Zaimplementuj funkcje do:
//   push   — dodaj element na koniec kolejki
//   pop    — usuń element z początku kolejki
//   wyświetl — pokaż wszystkie elementy w kolejce
//   zwolnij  — zwolnij pamięć po zakończeniu pracy

#include <iostream>
using namespace std;

// WĘZEŁ KOLEJKI — identyczny jak w liście i stosie
struct Node {
    int dane;
    Node* nastepny;
};

// Kolejka w pamięci wygląda tak:
// poczatek → [10|ptr] → [20|ptr] → [30|nullptr] ← koniec
//             wychodzi pierwszy        wchodzi ostatni
//
// FIFO — First In, First Out
// Kolejka jak w sklepie: kto przyszedł pierwszy, wychodzi pierwszy

// =============================================
// PUSH — dodaj element NA KONIEC kolejki
// Nowy element zawsze ląduje z tyłu
// =============================================
void push(Node*& poczatek, Node*& koniec, int wartosc) {

    Node* nowy = new Node;
    nowy->dane = wartosc;
    nowy->nastepny = nullptr; // Nowy węzeł będzie ostatni — nic za nim

    // Przypadek szczególny: kolejka jest pusta
    // Nowy węzeł jest jednocześnie początkiem i końcem
    if (koniec == nullptr) {
        poczatek = nowy;
        koniec = nowy;
        return;
    }

    // Podczepiamy nowy węzeł za dotychczasowym końcem
    koniec->nastepny = nowy;

    // Nowy węzeł staje się nowym końcem
    koniec = nowy;
}

// =============================================
// POP — usuń element Z POCZĄTKU kolejki
// Zawsze wychodzimy od przodu — jak w kolejce w sklepie
// =============================================
void pop(Node*& poczatek, Node*& koniec) {

    // Nie można nic zabrać z pustej kolejki
    if (poczatek == nullptr) {
        cout << "Kolejka pusta!\n";
        return;
    }

    Node* temp = poczatek;          // Zapamiętujemy aktualny początek
    poczatek = poczatek->nastepny;  // Początek przesuwa się na następny węzeł

    // Jeśli po usunięciu kolejka jest pusta — koniec też ustawiamy na nullptr
    if (poczatek == nullptr) {
        koniec = nullptr;
    }

    delete temp; // Usuwamy stary początek z pamięci
}

// =============================================
// WYŚWIETL — pokaż wszystkie elementy od początku do końca
// =============================================
void wyswietl(Node* poczatek) {
    if (poczatek == nullptr) {
        cout << "Kolejka pusta!\n";
        return;
    }

    Node* temp = poczatek;
    while (temp != nullptr) {
        cout << temp->dane << " -> ";
        temp = temp->nastepny;
    }
    cout << "NULL\n";
}

// =============================================
// ZWOLNIJ — usuń wszystkie węzły z pamięci
// =============================================
void zwolnij(Node*& poczatek, Node*& koniec) {
    while (poczatek != nullptr) {
        Node* temp = poczatek;
        poczatek = poczatek->nastepny;
        delete temp;
    }
    koniec = nullptr; // Koniec też zerujemy — kolejka oficjalnie pusta
}

int main() {
    Node* poczatek = nullptr; // Pusty początek
    Node* koniec = nullptr;   // Pusty koniec

    // Dodajemy elementy — każdy ląduje NA KOŃCU
    push(poczatek, koniec, 10); // Kolejka: 10
    push(poczatek, koniec, 20); // Kolejka: 10 -> 20
    push(poczatek, koniec, 30); // Kolejka: 10 -> 20 -> 30

    cout << "Kolejka: ";
    wyswietl(poczatek); // 10 -> 20 -> 30 -> NULL

    // Pop usuwa z POCZĄTKU — wychodzi 10, nie 30
    pop(poczatek, koniec);
    cout << "Po pop: ";
    wyswietl(poczatek); // 20 -> 30 -> NULL

    // Zwalniamy całą pamięć
    zwolnij(poczatek, koniec);

    return 0;
}
