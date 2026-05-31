// Ćwiczenie 4: Stos dynamiczny
// Stwórz dynamiczną strukturę danych reprezentującą stos.
// Implementacja stosu powinna zawierać operacje:
//   push  — dodaj element na szczyt stosu
//   pop   — zdejmij element ze szczytu
//   top   — podejrzyj szczyt bez zdejmowania
//   isEmpty — sprawdź czy stos jest pusty

#include <iostream>
using namespace std;

// WĘZEŁ STOSU — identyczny jak w liście jednokierunkowej
// Stos to tak naprawdę lista, na której operujemy tylko od jednego końca (szczytu)
struct Node {
    int dane;
    Node* nastepny; // Wskazuje na węzeł pod spodem
};

// Stos w pamięci wygląda tak (30 jest na szczycie):
// szczyt → [30|ptr] → [20|ptr] → [10|nullptr]
//           góra                   dół stosu

// =============================================
// PUSH — dodaj element na szczyt
// Działa dokładnie jak "dodaj na początek" w liście
// Nowy element zawsze ląduje na górze
// =============================================
void push(Node*& szczyt, int wartosc) {
    Node* nowy = new Node;
    nowy->dane = wartosc;

    // Nowy węzeł wskazuje na dotychczasowy szczyt
    // (wkładamy go "na wierzch" stosu)
    nowy->nastepny = szczyt;

    // Nowy węzeł staje się nowym szczytem
    szczyt = nowy;
}

// =============================================
// POP — zdejmij element ze szczytu
// Usuwa tylko JEDEN węzeł — ten na samej górze
// =============================================
void pop(Node*& szczyt) {

    // Nie można zdjąć nic z pustego stosu
    if (szczyt == nullptr) {
        cout << "Stos pusty!\n";
        return;
    }

    Node* temp = szczyt;        // Zapamiętujemy aktualny szczyt
    szczyt = szczyt->nastepny;  // Szczyt przesuwa się na węzeł pod spodem
    delete temp;                // Usuwamy stary szczyt z pamięci
}

// =============================================
// TOP — podejrzyj szczyt BEZ zdejmowania
// Zwraca wartość, ale węzeł zostaje na stosie
// =============================================
int top(Node* szczyt) {
    if (szczyt == nullptr) {
        cout << "Stos pusty!\n";
        return -1; // Wartość sygnalizująca błąd
    }
    return szczyt->dane;
}

// =============================================
// ISEMPTY — sprawdź czy stos jest pusty
// Stos jest pusty gdy szczyt wskazuje na nullptr
// =============================================
bool isEmpty(Node* szczyt) {
    return szczyt == nullptr;
}

// =============================================
// ZWOLNIJ — usuń wszystkie węzły ze stosu
// Działa jak pop w pętli — zdejmuje po jednym aż do pustego
// =============================================
void zwolnij(Node*& szczyt) {
    while (szczyt != nullptr) {
        Node* temp = szczyt;
        szczyt = szczyt->nastepny;
        delete temp;
    }
}

int main() {
    Node* szczyt = nullptr; // Pusty stos — szczyt wskazuje na nullptr

    // Dodajemy trzy elementy — każdy ląduje NA WIERZCHU
    push(szczyt, 10); // Stos: 10
    push(szczyt, 20); // Stos: 20 -> 10
    push(szczyt, 30); // Stos: 30 -> 20 -> 10

    // top() nie zdejmuje — tylko podgląda
    cout << "Szczyt: " << top(szczyt) << "\n"; // 30

    // pop() zdejmuje jeden element z góry
    pop(szczyt);
    cout << "Po pop, szczyt: " << top(szczyt) << "\n"; // 20

    // isEmpty zwraca 0 (false) bo stos ma jeszcze elementy
    cout << "Czy pusty: " << isEmpty(szczyt) << "\n"; // 0 = nie

    // Zwalniamy całą pozostałą pamięć przed końcem programu
    zwolnij(szczyt);

    return 0;
}
