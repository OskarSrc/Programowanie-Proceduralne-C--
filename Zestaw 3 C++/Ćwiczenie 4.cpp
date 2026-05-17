#include <iostream>
using namespace std;

struct Node {
    int dane;
    Node* nastepny;
};

// push - dodaj na stos
void push(Node*& szczyt, int wartosc) {
    Node* nowy = new Node;
    nowy->dane = wartosc;
    nowy->nastepny = szczyt;
    szczyt = nowy;
}

// pop - zdejmij ze stosu
void pop(Node*& szczyt) {
    if (szczyt == nullptr) {
        cout << "Stos pusty!\n";
        return;
    }
    Node* temp = szczyt;
    szczyt = szczyt->nastepny;
    delete temp;
}

// top - podejrzyj szczyt
int top(Node* szczyt) {
    if (szczyt == nullptr) {
        cout << "Stos pusty!\n";
        return -1;
    }
    return szczyt->dane;
}

// isEmpty - czy pusty
bool isEmpty(Node* szczyt) {
    return szczyt == nullptr;
}

// zwolnienie pamieci
void zwolnij(Node*& szczyt) {
    while (szczyt != nullptr) {
        Node* temp = szczyt;
        szczyt = szczyt->nastepny;
        delete temp;
    }
}

int main() {
    Node* szczyt = nullptr;

    push(szczyt, 10);
    push(szczyt, 20);
    push(szczyt, 30);

    cout << "Szczyt: " << top(szczyt) << "\n"; // 30
    pop(szczyt);
    cout << "Po pop, szczyt: " << top(szczyt) << "\n"; // 20
    cout << "Czy pusty: " << isEmpty(szczyt) << "\n"; // 0 = nie

    zwolnij(szczyt);
    return 0;
}