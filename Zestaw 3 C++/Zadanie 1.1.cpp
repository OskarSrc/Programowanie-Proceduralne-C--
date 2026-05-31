// Ćwiczenie 1: Dynamiczna alokacja pamięci – tablica jednowymiarowa
// Stwórz program, który dynamicznie alokuje pamięć dla tablicy jednowymiarowej.
// Program powinien umożliwić użytkownikowi wprowadzenie danych do tablicy oraz wyświetlenie
// tych danych. Po zakończeniu pracy z tablicą należy zwolnić pamięć.

#include <iostream>
using namespace std;

int main() {

    // Dynamiczna alokacja tablicy na 10 liczb całkowitych
    // "new int[10]" rezerwuje pamięć na stercie (heap), nie na stosie
    // Zwraca wskaźnik na pierwszy element — zapisujemy go w tab
    // WAŻNE: pamięć zarezerwowana przez "new" NIE zwalnia się sama —
    //        musimy ją ręcznie zwolnić przez "delete[]" na końcu
    int* tab = new int[10];

    // Wprowadzanie danych przez użytkownika
    for (int i = 0; i < 10; i++) {
        cout << "Podaj liczbe " << i + 1 << ": ";
        cin >> tab[i]; // tab[i] działa tak samo jak na zwykłej tablicy
    }

    // Wyświetlanie wprowadzonych danych
    cout << "\nTablica: ";
    for (int i = 0; i < 10; i++) {
        cout << tab[i] << " ";
    }
    cout << endl;

    // Zwolnienie pamięci — obowiązkowe po każdym "new"
    // "delete[]" (z nawiasami) — bo zwalniamy TABLICĘ, nie pojedynczy element
    // Bez tego linia pamięć pozostaje zajęta aż do zamknięcia programu (wyciek pamięci)
    delete[] tab;

    return 0;
}
