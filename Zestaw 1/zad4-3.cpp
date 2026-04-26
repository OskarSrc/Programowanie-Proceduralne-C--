// Napisz program, który przyjmuje listę liczb wprowadzonych przez użytkownika i następnie wypisuje największą oraz najmniejszą liczbę. Do rozwiązania użyj funkcji.

#include <iostream>

// Funkcja znajdująca i wypisująca najmniejszą i największą liczbę
void znajdzMinMax(float tablica[], int rozmiar) {
    // Na starcie zakładamy, że pierwsza podana liczba (indeks 0)
    // jest naszą tymczasowo najmniejszą i największą wartością.
    float min = tablica[0];
    float max = tablica[0];

    // Przeszukujemy resztę tablicy (zaczynamy od indeksu 1)
    for (int i = 1; i < rozmiar; i++) {
        if (tablica[i] < min) {
            min = tablica[i]; // Znaleziono nową najmniejszą
        }
        if (tablica[i] > max) {
            max = tablica[i]; // Znaleziono nową największą
        }
    }

    std::cout << "Najmniejsza z podanych to: " << min << "\n";
    std::cout << "Najwieksza z podanych to: " << max << "\n";
}

int main() {
    int n;
    std::cout << "Ile liczb chcesz wprowadzic? ";
    std::cin >> n;

    // Zabezpieczenie przed wpisaniem zera lub liczby ujemnej
    if (n <= 0) {
        std::cout << "Musisz podac przynajmniej jedna liczbe!\n";
        return 1; 
    }

    // Tworzenie tablicy dynamicznej - pamięć alokowana "w locie" za pomocą 'new'
    float* tablica = new float[n];

    // Wczytywanie liczb do tablicy
    for (int i = 0; i < n; i++) {
        std::cout << "Podaj liczbe nr " << i + 1 << ": ";
        std::cin >> tablica[i];
    }

    // Odpalamy naszą funkcję
    znajdzMinMax(tablica, n);

    // BARDZO WAŻNE: Zwalnianie pamięci!
    // Kiedy używamy 'new', zawsze na końcu musi być 'delete[]', żeby nie wyciekła pamięć.
    delete[] tablica;

    return 0;
}