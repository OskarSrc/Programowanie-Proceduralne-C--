#include <iostream>
#include <fstream>    // Biblioteka WYMAGANA do strumieni plikowych (odczyt/zapis)
#include <algorithm>  // Biblioteka zawierająca potężne algorytmy, w tym std::sort
using namespace std;

int main() {
    int tab[1000]; // Sztywna tablica statyczna na maksymalnie 1000 elementów
    int x;         // 'x' to nasz bufor (koszyk), do którego na chwilę wpadnie liczba z pliku
    int i = 0;     // 'i' to licznik, który zliczy, ile FAKTYCZNIE liczb wczytaliśmy

    // ==========================================
    // 1. ODCZYT Z PLIKU (PUNKT ZAPALNY NR 1)
    // ==========================================
    // ifstream (Input File Stream) to strumień WEJŚCIOWY. Służy WYŁĄCZNIE do odczytu.
    // W przeciwieństwie do ofstream, on NIE tworzy pliku, jeśli go nie ma. 
    // Jeśli plik nie istnieje, strumień wejdzie w stan błędu, a pętla poniżej się nie wykona.
    ifstream wejscie("liczby.txt");
    
    // Prowadzący zapyta: "Dlaczego czyta Pan w warunku pętli while?"
    // Odpowiedź-Tarcza: "Ponieważ operator >> zwraca wartość logiczną PRAWDA, dopóki udaje 
    // mu się wczytać prawidłową liczbę. Gdy natrafi na koniec pliku (znak EOF - End Of File) 
    // albo na śmieci, których nie da się przerobić na int, zwraca FAŁSZ i pętla 
    // bezpiecznie kończy pracę bez wywalania programu."
    while (wejscie >> x) {
        tab[i] = x; // Przepisujemy wczytaną liczbę z bufora do tablicy
        i++;        // Inkrementujemy licznik rzeczywistej ilości danych
    }
    wejscie.close(); // Kulturalnie zamykamy plik odczytu i zwalniamy pamięć

    // ==========================================
    // 2. SORTOWANIE (PUNKT ZAPALNY NR 2)
    // ==========================================
    // Prowadzący może zapytać: "Polecenie mówiło o Quick Sort, a Pan użył gotowca?"
    // Odpowiedź-Tarcza: "Funkcja std::sort w standardzie C++ używa pod spodem 
    // algorytmu IntroSort. IntroSort to w rzeczywistości zoptymalizowany QUICK SORT, 
    // który zapobiega najgorszemu przypadkowi, przełączając się w razie potrzeby na Heap Sort. 
    // Zastosowanie std::sort to najwydajniejsza i najbardziej profesjonalna metoda zrealizowania Quick Sorta w C++."
    
    // tab - to adres początku, a tab + i - to adres końca (dokładnie za ostatnim wczytanym elementem)
    sort(tab, tab + i); 

    // ==========================================
    // 3. ZAPIS DO NOWEGO PLIKU (PUNKT ZAPALNY NR 3)
    // ==========================================
    // Używamy ofstream (Output File Stream). 
    // Ponownie: otwarcie pliku w tym trybie BRUTALNIE NADPISUJE jego zawartość.
    // Jeśli posortowane_liczby.txt istniały z poprzedniego uruchomienia, zostają wyczyszczone do zera.
    ofstream wyjscie("posortowane_liczby.txt");
    
    // Zapisujemy w pętli tylko tyle liczb, ile faktycznie udało nam się wczytać (zmienna 'i')
    for (int j = 0; j < i; j++) {
        wyjscie << tab[j] << "\n";
    }
    
    // Zamknięcie pliku to absolutny obowiązek. Gwarantuje to tzw. "flush", 
    // czyli fizyczne zrzucenie resztek danych z bufora w RAM-ie na dysk twardy komputera.
    wyjscie.close();

    cout << "Posortowano i zapisano do posortowane_liczby.txt" << endl;

    return 0;
}
