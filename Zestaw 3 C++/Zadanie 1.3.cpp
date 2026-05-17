#include <iostream>
using namespace std;

struct Node {
    int dane;
    Node* nastepny;
};

// dodaj na poczatek
void dodajNaPoczatek(Node*& glowa, int wartosc) {
    Node* nowy = new Node;
    nowy->dane = wartosc;
    nowy->nastepny = glowa;
    glowa = nowy;
}

// dodaj na koniec
void dodajNaKoniec(Node*& glowa, int wartosc) {
    Node* nowy = new Node;
    nowy->dane = wartosc;
    nowy->nastepny = nullptr;

    if (glowa == nullptr) {
        glowa = nowy;
        return;
    }

    Node* temp = glowa;
    while (temp->nastepny != nullptr) {
        temp = temp->nastepny;
    }
    temp->nastepny = nowy;
}

// wyswietlanie
void wyswietl(Node* glowa) {
    Node* temp = glowa;
    while (temp != nullptr) {
        cout << temp->dane << " -> ";
        temp = temp->nastepny;
    }
    cout << "NULL\n";
}

// zwolnienie pamieci
void zwolnij(Node*& glowa) {
    while (glowa != nullptr) {
        Node* temp = glowa;
        glowa = glowa->nastepny;
        delete temp;
    }
}

int main() {
    Node* glowa = nullptr;

    dodajNaPoczatek(glowa, 10);
    dodajNaPoczatek(glowa, 20);
    dodajNaKoniec(glowa, 5);
    dodajNaKoniec(glowa, 1);

    wyswietl(glowa);

    zwolnij(glowa);
    return 0;
}