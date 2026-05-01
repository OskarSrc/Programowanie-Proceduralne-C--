// Zadanie 4.2: Zapis i odczyt z pliku z większą ilością danych
// Rozszerz program z zadania 4.1 tak, aby obsługiwał duże pliki z danymi (np. 1 milion liczb). Program powinien działać wydajnie, zarządzać pamięcią i sortować dane w sposób optymalny.

#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;

int tab[1000000]; 

void quickSort(int lewy, int prawy) {
    if (lewy >= prawy) return;
    int srodek = tab[(lewy + prawy) / 2];
    int i = lewy, j = prawy;
    while (i <= j) {
        while (tab[i] < srodek) i++;
        while (tab[j] > srodek) j--;
        if (i <= j) {
            swap(tab[i], tab[j]);
            i++; j--;
        }
    }
    quickSort(lewy, j);
    quickSort(i, prawy);
}

int main() {
    srand(time(0));
    
    cout << "Generuje 1 milion liczb do pliku milion.txt... (chwileczke)\n";
    ofstream generator("milion.txt");
    for(int j = 0; j < 1000000; j++) {
        generator << rand() % 1000000 << "\n";
    }
    generator.close();
    
    // 2. Właściwe zadanie: Odczyt
    cout << "Wczytuje z pliku...\n";
    int i = 0;
    ifstream wejscie("milion.txt");
    while (wejscie >> tab[i]) {
        i++;
    }
    wejscie.close();

    // 3. Sortowanie
    cout << "Sortuje 1 000 000 liczb (Quick Sort)...\n";
    clock_t start = clock();
    quickSort(0, i - 1);
    cout << "Czas sortowania: " << (double)(clock() - start) / CLOCKS_PER_SEC << " s\n";

    // 4. Nadpisanie pliku
    cout << "Zapisuje posortowane z powrotem...\n";
    ofstream wyjscie("milion.txt");
    for (int j = 0; j < i; j++) {
        wyjscie << tab[j] << "\n";
    }
    wyjscie.close();

    cout << "Gotowe! Zobacz plik milion.txt" << endl;
    return 0;
}