//Zadanie 3.1: Zapis danych do pliku
//Napisz program, który generuje losowy zbiór liczb całkowitych (np. 1000 liczb) i zapisuje go do pliku tekstowego o nazwie liczby.txt.
//Zadbaj o to, by każda liczba była zapisana w osobnej linii.

#include <iostream>
#include <fstream>  // Biblioteka WYMAGANA do obsługi plików (file stream)
#include <cstdlib>  // Biblioteka do rand() i srand()
#include <ctime>    // Biblioteka do time()
using namespace std;

int main() {
    ofstream plik("liczby.txt");

    // "Ziarno" dla generatora losowego. Pobiera aktualny czas komputera, 
    // żeby przy każdym odpaleniu programu losowała się INNA pula liczb.
    // Bez tego rand() za każdym razem wyplułby identyczną sekwencję.
    srand(time(0)); 
    
    // Pętla odpala się równo 1000 razy
    for (int i = 0; i < 1000; i++) {
        // rand() % 10000 + 1 generuje losową liczbę z zakresu od 1 do 10000.
        // Operator '<<' wpycha tę liczbę do pliku, a '\n' od razu łamie linię (enter),
        // żeby każda liczba była ładnie w nowym wierszu.
        plik << rand() % 10000 + 1 << "\n";
    }

    // Święta zasada programowania obiektowego: jak otworzyłeś zasób, to go zamknij!
    // To fizycznie zrzuca resztę danych z pamięci operacyjnej (bufora) na dysk twardy 
    // i odblokowuje plik dla innych programów.
    plik.close(); 
    
    // Komunikat kontrolny do czarnej konsoli, żebyśmy wiedzieli, że skończył pracę
    cout << "Zapisano 1000 liczb do pliku liczby.txt" << endl;

    return 0;
}
