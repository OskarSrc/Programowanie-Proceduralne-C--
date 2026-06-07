#include <iostream>
using namespace std;

int main() {
    int tablica[] = { 45, 12, 89, 33, 7 };
    int rozmiar = 5;

    cout << "Przed sortowaniem: ";
    for (int i = 0; i < rozmiar; i++) cout << tablica[i] << " ";
    cout << "\n";

    // ==========================================
    // SORTOWANIE PRZEZ WYBÓR (Selection Sort)
    // Analogia: Szukamy najmniejszej karty i kładziemy ją na początku.
    // ==========================================
    
    // Zewnętrzna pętla (i): Mówi nam, które z kolei miejsce na stole aktualnie zapełniamy.
    // Jeśli i=0, to szukamy najmniejszej liczby na pierwsze miejsce. 
    // Jeśli i=1, to szukamy na drugie miejsce, itd.
    for (int i = 0; i < rozmiar - 1; i++) {
        
        // 1. Zanim zaczniemy przeszukiwać resztę stołu, zakładamy wstępnie, 
        // że liczba, która leży na naszym aktualnym miejscu 'i', jest najmniejsza.
        // Zmienna 'min' przechowuje tylko ADRES (indeks) tej najmniejszej liczby.
        int min = i; 
        
        // 2. Wewnętrzna pętla (j): Przeszukuje resztę stołu (zawsze na prawo od 'i').
        // Dlatego 'j' zaczyna się od 'i + 1'.
        for (int j = i + 1; j < rozmiar; j++) {
            
            // 3. Sprawdzamy: czy liczba, na którą właśnie patrzymy (tablica[j]), 
            // jest MNIEJSZA od tej, którą dotychczas uważaliśmy za najmniejszą?
            if (tablica[j] < tablica[min]) {
                
                // Bingo! Znaleźliśmy jeszcze mniejszą liczbę. 
                // Aktualizujemy nasz notes – teraz 'min' wskazuje na pozycję 'j'.
                min = j; 
            }
        }
            
        // 4. Koniec przeszukiwania reszty stołu. Zmienna 'min' wskazuje teraz 
        // na bezwzględnie najmniejszą liczbę po prawej stronie.
        // Zamieniamy ją miejscami z liczbą, która stała na naszym docelowym miejscu 'i'.
        swap(tablica[i], tablica[min]);
    }

    // ==========================================

    cout << "Po sortowaniu:     ";
    for (int i = 0; i < rozmiar; i++) cout << tablica[i] << " ";
    cout << "\n";

    return 0;
}
