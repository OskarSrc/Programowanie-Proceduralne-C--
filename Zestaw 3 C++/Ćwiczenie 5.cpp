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

// =============================================
// WĘZEŁ KOLEJKI — podstawowy "klocek" (Nasz pojedynczy klient)
// Każdy klient trzyma:
//   dane     — numerek klienta (np. pobrany z biletomatu)
//   nastepny — adres osoby, która stoi bezpośrednio ZA NIM w kolejce
// =============================================
struct Node {
    int dane;
    Node* nastepny; 
};

// =============================================
// WIZUALIZACJA KOLEJKI W PAMIĘCI (Zasada FIFO: First In, First Out)
// 
// [KASA]
// poczatek → [10 | ptr] → [20 | ptr] → [30 | nullptr] ← koniec
//            wychodzi        stoi        wchodzi
//            pierwszy       w środku     ostatni
// =============================================


// =============================================
// PUSH — Dodawanie klienta NA SAM KONIEC kolejki
// Używamy ampersandów (&), żeby fizycznie zmieniać oryginały wskaźników w main()
// =============================================
void push(Node*& poczatek, Node*& koniec, int wartosc) {
    
    // 1. Otwieramy drzwi sklepu i wchodzi nowy klient (tworzymy węzeł).
    // Nowy klient staje na końcu, więc nie ma NIKOGO za sobą (dlatego nullptr).
    Node* nowy = new Node{wartosc, nullptr};

    // 2. Co jeśli sklep był całkowicie pusty?
    if (koniec == nullptr) {
        // Nowy klient ma luksus. Jest jednocześnie pierwszym (przy kasie) 
        // i ostatnim (na końcu). Oba wskaźniki pokazują na niego.
        poczatek = nowy;
        koniec = nowy; 
    } 
    // 3. Co jeśli w kolejce już ktoś stoi?
    else {
        // Klient, który do tej pory był na końcu (koniec), musi zauważyć, 
        // że ktoś za nim stanął. Dajemy mu do ręki wskaźnik na nowego klienta.
        koniec->nastepny = nowy; 
        
        // Teraz oficjalnie przesuwamy tabliczkę "KONIEC KOLEJKI" na tego nowego klienta.
        koniec = nowy;           
    }
}


// =============================================
// POP — Obsługa klienta (wychodzi z POCZĄTKU kolejki, od kasy)
// Zawsze obsługujemy tego, kto ma wskaźnik 'poczatek'
// =============================================
void pop(Node*& poczatek, Node*& koniec) {
    
    // 1. Zabezpieczenie: Kasjerka nie może nikogo obsłużyć, jeśli sklep jest pusty!
    if (poczatek == nullptr) return; 

    // 2. Łapiemy klienta, który właśnie stoi przy kasie (żeby go potem usunąć z pamięci).
    Node* temp = poczatek;         
    
    // 3. Kasa woła "Następny proszę!". 
    // Zmieniamy wskaźnik 'poczatek' na osobę, która stała tuż za obsłużonym klientem.
    poczatek = poczatek->nastepny; 
    
    // 4. BARDZO WAŻNY WARUNEK: A co, jeśli to był OSTATNI klient w sklepie?
    // Jeśli po jego wyjściu początek stał się pusty (nullptr), to znaczy, 
    // że wskaźnik 'koniec' też musi zostać wyzerowany (zamykamy kolejkę).
    if (poczatek == nullptr) {
        koniec = nullptr;
    }
    
    // 5. Fizycznie wyrzucamy obsłużonego klienta ze sklepu (z pamięci komputera).
    // Zapobiega to słynnym wyciekom pamięci.
    delete temp; 
}


// =============================================
// WYŚWIETL — Kasjerka rozgląda się po kolejce od początku do końca
// UWAGA: Tutaj NIE MA ampersanda! Node* poczatek, a nie Node*& poczatek.
// Dzięki temu kasjerka tylko patrzy (pracuje na kopii wzroku), 
// a nie przesuwa fizycznie ludzi w kolejce.
// =============================================
void wyswietl(Node* poczatek) {
    // Dopóki wzrok kasjerki nie trafi na pustkę (nullptr)...
    while (poczatek != nullptr) {
        cout << poczatek->dane << " -> "; // ...wykrzycz numerek klienta
        poczatek = poczatek->nastepny;    // ...i przenieś wzrok na osobę za nim
    }
    cout << "NULL\n"; // Koniec kolejki
}


// =============================================
// ZWOLNIJ — Zamykamy sklep, wyganiamy wszystkich z kolejki
// Zwalnianie całej pamięci na koniec działania programu
// =============================================
void zwolnij(Node*& poczatek, Node*& koniec) {
    // Genialny manewr: nie musimy pisać od nowa usuwania. 
    // Po prostu wywołujemy naszą funkcję pop() tak długo, aż nikogo nie będzie.
    while (poczatek != nullptr) {
        pop(poczatek, koniec);
    }
}


// =============================================
// MAIN — GŁÓWNY PROGRAM
// =============================================
int main() {
    Node* poczatek = nullptr; // Otwieramy sklep: początek kolejki jest pusty
    Node* koniec = nullptr;   // Koniec kolejki również jest pusty

    // Wpuszczamy klientów (każdy staje karnie na końcu)
    push(poczatek, koniec, 10); // Wchodzi pan 10
    push(poczatek, koniec, 20); // Pan 20 staje za panem 10
    push(poczatek, koniec, 30); // Pan 30 staje za panem 20

    cout << "Kolejka w sklepie: ";
    wyswietl(poczatek); // Wyświetli: 10 -> 20 -> 30 -> NULL

    // Obsługujemy pierwszego klienta przy kasie (pana 10)
    pop(poczatek, koniec); 
    
    cout << "Po obsluzeniu pierwszego klienta: ";
    wyswietl(poczatek); // Wyświetli: 20 -> 30 -> NULL

    // Zamykamy sklep, wyrzucamy resztę ludzi do zera
    zwolnij(poczatek, koniec); 
    return 0;
}
