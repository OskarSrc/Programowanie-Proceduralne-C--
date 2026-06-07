#include <iostream>
using namespace std;

int main() {
    // 1. Przygotowujemy dane do posortowania
    int tablica[] = { 45, 12, 89, 33, 7 };
    int rozmiar = 5; // Mamy 5 liczb w tablicy

    // 2. Wypisanie stanu początkowego (żeby udowodnić, że kod działa)
    cout << "Przed sortowaniem: ";
    for (int i = 0; i < rozmiar; i++)
        cout << tablica[i] << " ";
    cout << "\n";

    // ==========================================
    // 3. GŁÓWNY ALGORYTM: ZOPTYMALIZOWANE SORTOWANIE BĄBELKOWE
    // ==========================================
    
    // Zewnętrzna pętla: Liczy, ile razy musimy "przejść" przez całą tablicę.
    // Zawsze potrzebujemy o jedno przejście mniej niż jest elementów (rozmiar - 1).
    for (int przejscie = 0; przejscie < rozmiar - 1; przejscie++)
        
        // Wewnętrzna pętla: Odpowiada za porównywanie konkretnych sąsiadów.
        // Optymalizacja (- przejscie): Po każdym pełnym cyklu, największa liczba 
        // ląduje bezpiecznie na samym końcu. Nie ma sensu sprawdzać tego końca drugi raz!
        for (int indeks = 0; indeks < rozmiar - 1 - przejscie; indeks++)
            
            // Jeśli liczba po lewej stronie jest większa od tej po prawej...
            if (tablica[indeks] > tablica[indeks + 1])
                
                // ...to zamieniamy je miejscami (większy "bąbelek" wędruje w prawo)
                swap(tablica[indeks], tablica[indeks + 1]);

    // ==========================================

    // 4. Wypisanie gotowego, posortowanego wyniku
    cout << "Po sortowaniu:     ";
    for (int i = 0; i < rozmiar; i++)
        cout << tablica[i] << " ";
    cout << "\n";

    return 0;
}
