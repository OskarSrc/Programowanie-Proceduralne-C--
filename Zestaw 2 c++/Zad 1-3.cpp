// Zadanie 1.3: Sortowanie szybkie (Quick Sort)
// Napisz program, który generuje losowy zbiór liczb całkowitych.
// Za pomocą algorytmu Quick Sort posortuj zbiór liczb w porządku rosnącym.
// Zmierz czas wykonania algorytmu Quick Sort i porównaj go z czasem wykonania sortowania bąbelkowego.
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// =============================================
// QUICK SORT — schemat Hoare'a
// Argumenty:
//   tab[]  — tablica do posortowania
//   lewy   — indeks początku aktualnego zakresu
//   prawy  — indeks końca aktualnego zakresu
// =============================================
void quickSort(int tab[], int lewy, int prawy) {

    // Warunek zakończenia rekurencji:
    // Jeśli zakres ma 0 lub 1 element — jest już posortowany, wracamy
    if (lewy >= prawy) return;

    // Wybieramy pivot ze środka zakresu (nie z początku ani końca)
    // Środkowy pivot chroni przed najgorszym przypadkiem O(n²)
    // który wystąpiłby przy pivocie z końca na już posortowanej tablicy
    int srodek = tab[(lewy + prawy) / 2];

    // Dwa wskaźniki startują z przeciwnych końców zakresu
    // i będzie szedł w prawo, j będzie szedł w lewo
    int i = lewy, j = prawy;

    // Główna pętla podziału — trwa dopóki wskaźniki się nie miną
    while (i <= j) {

        // Przesuwamy i w prawo, pomijając elementy mniejsze od pivota
        // (są już po właściwej — lewej — stronie)
        while (tab[i] < srodek) i++;

        // Przesuwamy j w lewo, pomijając elementy większe od pivota
        // (są już po właściwej — prawej — stronie)
        while (tab[j] > srodek) j--;

        // Oba wskaźniki zatrzymały się:
        // i stoi na elemencie >= pivot (a jest po lewej — źle!)
        // j stoi na elemencie <= pivot (a jest po prawej — źle!)
        // Zamieniamy je miejscami
        if (i <= j) {
            swap(tab[i], tab[j]);
            i++; // Przesuwamy dalej, żeby nie utknąć w miejscu
            j--;
        }
    }

    // Po wyjściu z pętli: wszystko w [lewy..j] <= pivot
    //                     wszystko w [i..prawy] >= pivot
    // Pivot nie musi być dokładnie pośrodku — ważne, że podział jest poprawny

    // Rekurencyjnie sortujemy lewą część (od lewy do j)
    quickSort(tab, lewy, j);

    // Rekurencyjnie sortujemy prawą część (od i do prawy)
    quickSort(tab, i, prawy);
}

int main() {
    const int ROZMIAR = 1000;
    int tab[ROZMIAR]; // const pozwala użyć ROZMIAR jako rozmiaru tablicy

    srand(time(0)); // Inicjalizujemy generator losowy aktualnym czasem

    // Wypełniamy tablicę losowymi liczbami z zakresu 1-10000
    for (int i = 0; i < ROZMIAR; i++) tab[i] = rand() % 10000 + 1;

    clock_t start = clock(); // Zapamiętujemy czas przed sortowaniem

    quickSort(tab, 0, ROZMIAR - 1); // Sortujemy cały zakres [0, 999]

    // Obliczamy i wyświetlamy czas: różnica taktów / takty na sekundę
    cout << "Czas Quick Sort: " << (double)(clock() - start) / CLOCKS_PER_SEC << " s\n";

    return 0;
}
