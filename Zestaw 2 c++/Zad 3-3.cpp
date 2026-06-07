#include <iostream>
#include <fstream>  // Biblioteka niezbędna do obsługi plików
using namespace std;

int main() {
    // 1. Otwieramy strumień wejściowy. 
    // Pamiętamy: on tylko czyta, nie tworzy pliku, jeśli go nie ma.
    ifstream wejscie("liczby.txt");
    
    // ==========================================
    // PUNKT ZAPALNY NR 1: TYPY ZMIENNYCH
    // ==========================================
    // Dlaczego suma to double, a nie int? 
    // Odpowiedź na obronę: "Gdyby suma i ilosc były typu int, to przy dzieleniu 
    // (suma / ilosc) kompilator obciąłby ułamek jeszcze przed zapisaniem wyniku 
    // do zmiennej srednia. Zmieniając sumę na double, wymuszam dokładne 
    // dzielenie zmiennoprzecinkowe."
    double suma = 0;
    int ilosc = 0;
    int x;

    // Magiczna pętla while z operatorem >>. Czyta z pliku, dopóki nie natrafi
    // na koniec pliku (EOF) lub błędne dane.
    while (wejscie >> x) {
        suma += x; // To samo co: suma = suma + x
        ilosc++;   // Liczymy, ile faktycznie liczb wpadło z pliku
    }
    wejscie.close(); // Odczyt zakończony, zamykamy plik.

    // ==========================================
    // PUNKT ZAPALNY NR 2: DZIELENIE PRZEZ ZERO
    // ==========================================
    // Zabezpieczenie przed złośliwym prowadzącym, który podsunie pusty plik.
    if (ilosc > 0) {
        // Obliczamy średnią tylko wtedy, gdy wczytaliśmy JAKĄKOLWIEK liczbę.
        double srednia = suma / ilosc;

        // Otwieramy strumień wyjściowy. Domyślny tryb - BRUTALNE NADPISANIE.
        // Jeśli plik 'wyniki.txt' istniał, jego zawartość idzie do kosza.
        ofstream wyjscie("wyniki.txt");
        wyjscie << "Suma: " << suma << "\n";
        wyjscie << "Srednia: " << srednia << "\n";
        wyjscie.close(); // Zrzut bufora na dysk twardy

        cout << "Suma: " << suma << endl;
        cout << "Srednia: " << srednia << endl;
        cout << "Wyniki zapisano do wyniki.txt" << endl;
    } else {
        // Jeśli plik był pusty albo nie istniał, wywalamy elegancki komunikat
        // zamiast pozwolić na wysypanie się programu przez dzielenie przez zero.
        cout << "Brak danych do przetworzenia. Plik byl pusty lub nie istnial!" << endl;
    }

    return 0;
}
