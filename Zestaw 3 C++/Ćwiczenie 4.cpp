#include <iostream>
using namespace std;

// Struktura pojedynczego elementu (wyobraź sobie, że to jeden talerz na stosie)
struct Node {
    int dane;       // Trzyma konkretną liczbę
    Node* nastepny; // Trzyma adres do talerza pod spodem
};

// PUSH: Kładzenie nowego talerza na samą górę
void push(Node*& szczyt, int wartosc) {
    // "Myk" z klamerkami: to nowy standard C++. Tworzy węzeł i od razu 
    // przypisuje mu 'wartosc' oraz podpina go do aktualnego 'szczytu'.
    // Na koniec nowo stworzony węzeł staje się oficjalnie nowym szczytem.
    szczyt = new Node{wartosc, szczyt}; 
}

// POP: Zdejmowanie jednego talerza z góry
void pop(Node*& szczyt) {
    if (szczyt == nullptr) return; // Zabezpieczenie: jeśli nie ma talerzy, nic nie rób
    
    Node* temp = szczyt;       // 1. Łapiemy górny talerz w zmienną pomocniczą
    szczyt = szczyt->nastepny; // 2. Szczytem staje się teraz talerz poziom niżej
    delete temp;               // 3. Fizycznie niszczymy ten stary, górny talerz
}

// TOP: Tylko zerkamy na górny talerz (bez jego usuwania)
int top(Node* szczyt) {
    // Używamy tzw. operatora trójargumentowego (warunek ? prawda : fałsz)
    // Jeśli szczyt istnieje (!= nullptr), zwróć jego dane. Jeśli nie, zwróć -1 (jako błąd).
    return (szczyt != nullptr) ? szczyt->dane : -1; 
}

// ISEMPTY: Sprawdzenie, czy stos jest pusty
bool isEmpty(Node* szczyt) {
    return szczyt == nullptr; // Zwróci true (1), jeśli szczyt to NULL
}

// ZWOLNIJ: Sprzątanie pamięci na sam koniec działania programu
void zwolnij(Node*& szczyt) {
    // Genialny myk: dopóki stos nie jest pusty, po prostu wywołujemy naszą 
    // funkcję pop(), która po kolei zdejmuje talerze i czyści pamięć.
    while (szczyt != nullptr) {
        pop(szczyt); 
    }
}
