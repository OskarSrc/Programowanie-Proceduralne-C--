//Zadanie 1.4: Porównanie metod sortowania
//Wygeneruj zbiór liczb o rozmiarze 1000, 5000, 10000 i przeprowadź pomiary czasów wykonania:
//Sortowanie bąbelkowe (z optymalizacją),
//Quick Sort,
//Sortowanie przez scalanie (Merge Sort).
//Porównaj wyniki i wyciągnij wnioski na temat efektywności tych metod.
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Tablice globalne — unikamy alokacji na stosie dla dużych rozmiarów
int oryginal[10000]; // Oryginalne losowe dane — kopiowane przed każdym testem
int tab[10000];      // Tablica robocza — każdy algorytm sortuje swoją kopię
int pomocnicza[10000]; // Używana tylko przez Merge Sort do scalania

// =============================================
// BUBBLE SORT — zoptymalizowany
// Argument: n — ile elementów sortujemy
// =============================================
void bubbleSort(int n) {
    for (int i = 0; i < n - 1; i++) {

        bool zamiana = false; // Zakładamy że zakres jest już posortowany

        // Po i-tym przejściu ostatnie i elementów jest na swoich miejscach
        // "- i" skraca zakres — nie sprawdzamy tego co już posortowane
        for (int j = 0; j < n - 1 - i; j++) {
            if (tab[j] > tab[j + 1]) {
                swap(tab[j], tab[j + 1]);
                zamiana = true; // Coś zamieniliśmy — tablica nie była posortowana
            }
        }

        // Żadnej zamiany w całym przejściu = tablica posortowana = koniec
        if (!zamiana) break;
    }
}

void quickSort(int lewy, int prawy) {

    // WARUNEK STOPU:
    // Jeśli zakres ma 1 element lub jest pusty — nie ma co sortować, wychodzimy.
    // Np. quickSort(5, 5) — jeden element, już "posortowany".
    // Np. quickSort(5, 4) — pusty zakres, też wychodzimy.
    if (lewy >= prawy) return;

    // WYBÓR PIVOTA:
    // Pivot to "punkt odniesienia" — liczba, względem której dzielimy tablicę.
    // Wszystko mniejsze od pivota pójdzie w lewo, większe w prawo.
    // Bierzemy element ze ŚRODKA zakresu (nie z początku ani końca).
    // Dlaczego środek? Bo jeśli tablica jest już posortowana i weźmiemy
    // pivot z końca — Quick Sort zdegeneruje się do O(n²). Środek to omija.
    int srodek = tab[(lewy + prawy) / 2];

    // Dwa wskaźniki — startują z przeciwnych końców zakresu i idą ku sobie
    int i = lewy;  // i startuje z lewej, będzie szedł w prawo →
    int j = prawy; // j startuje z prawej, będzie szedł w lewo ←

    // GŁÓWNA PĘTLA PODZIAŁU:
    // Trwa dopóki wskaźniki się nie miną (i > j oznacza że podział gotowy)
    while (i <= j) {

        // Przesuwamy i w prawo, POMIJAJĄC elementy mniejsze od pivota.
        // Te elementy są już po właściwej stronie (mniejsze = powinny być po lewej).
        // Zatrzymujemy się gdy znajdziemy element >= pivot — ten jest nie na miejscu.
        while (tab[i] < srodek) i++;

        // Przesuwamy j w lewo, POMIJAJĄC elementy większe od pivota.
        // Te elementy są już po właściwej stronie (większe = powinny być po prawej).
        // Zatrzymujemy się gdy znajdziemy element <= pivot — ten jest nie na miejscu.
        while (tab[j] > srodek) j--;

        // W tym momencie:
        // tab[i] to element ZA DUŻY jak na lewą stronę (>= pivot, a jest po lewej)
        // tab[j] to element ZA MAŁY jak na prawą stronę (<= pivot, a jest po prawej)
        // Jeśli wskaźniki się jeszcze nie minęły — zamieniamy je miejscami
        if (i <= j) {
            swap(tab[i], tab[j]); // Za duży wędruje w prawo, za mały w lewo
            i++; // Przesuwamy oba wskaźniki — ten element już załatwiony
            j--;
        }
    }

    // PO WYJŚCIU Z PĘTLI:
    // Wszystko w zakresie [lewy..j] jest <= pivot  (lewa część)
    // Wszystko w zakresie [i..prawy] jest >= pivot  (prawa część)
    // Pivot niekoniecznie leży dokładnie pośrodku — ale podział jest POPRAWNY.

    // Teraz sortujemy obie części osobno — to samo co wyżej, ale na mniejszym zakresie.
    // Z każdym wywołaniem zakresy są coraz krótsze, aż dojdziemy do warunków stopu.
    quickSort(lewy, j); // Sortuj lewą część
    quickSort(i, prawy); // Sortuj prawą część
}
// =============================================
// MERGE SORT — sortowanie przez scalanie
// Strategia: dziel na pół, sortuj każdą połówkę, scal z powrotem
// =============================================
void mergeSort(int lewy, int prawy) {

    // Zakres jednoelementowy — już posortowany, kończymy
    if (lewy >= prawy) return;

    int srodek = (lewy + prawy) / 2;

    // Najpierw rekurencyjnie sortujemy obie połówki...
    mergeSort(lewy, srodek);     // lewa połówka:  [lewy..srodek]
    mergeSort(srodek + 1, prawy); // prawa połówka: [srodek+1..prawy]

    // ...a potem scalamy je w jedną posortowaną całość

    // Kopiujemy aktualny zakres do tablicy pomocniczej
    // (nie możemy scalać w miejscu — nadpisalibyśmy dane których jeszcze potrzebujemy)
    for (int i = lewy; i <= prawy; i++) pomocnicza[i] = tab[i];

    int i = lewy;       // Wskaźnik na lewą połówkę w pomocniczej
    int j = srodek + 1; // Wskaźnik na prawą połówkę w pomocniczej
    int k = lewy;       // Wskaźnik zapisu do tab[]

    // Porównujemy elementy obu połówek i wstawiamy mniejszy do tab[]
    while (i <= srodek && j <= prawy) {
        if (pomocnicza[i] <= pomocnicza[j]) tab[k++] = pomocnicza[i++];
        else tab[k++] = pomocnicza[j++];
    }

    // Jeśli w lewej połówce zostały elementy — dopisujemy je
    // (prawa połówka jest już na swoim miejscu — nic nie trzeba robić)
    while (i <= srodek) tab[k++] = pomocnicza[i++];
}

// =============================================
// TESTUJ — uruchamia wszystkie 3 algorytmy na tym samym zestawie danych
// Argument: n — rozmiar testu
// =============================================
void testuj(int n) {

    // Generujemy n losowych liczb 1-10000 jako wspólny punkt startowy
    for (int i = 0; i < n; i++) oryginal[i] = rand() % 10000 + 1;

    cout << "\n--- ROZMIAR: " << n << " ---\n";

    // --- Bubble Sort ---
    // Kopiujemy oryginał do tab[] — każdy algorytm startuje z tych samych danych
    for (int i = 0; i < n; i++) tab[i] = oryginal[i];
    clock_t start = clock();
    bubbleSort(n);
    cout << "Bubble Sort: " << (double)(clock() - start) / CLOCKS_PER_SEC << " s\n";

    // --- Quick Sort ---
    for (int i = 0; i < n; i++) tab[i] = oryginal[i];
    start = clock();
    quickSort(0, n - 1);
    cout << "Quick Sort:  " << (double)(clock() - start) / CLOCKS_PER_SEC << " s\n";

    // --- Merge Sort ---
    for (int i = 0; i < n; i++) tab[i] = oryginal[i];
    start = clock();
    mergeSort(0, n - 1);
    cout << "Merge Sort:  " << (double)(clock() - start) / CLOCKS_PER_SEC << " s\n";
}

// =============================================
// MAIN
// Wnioski z wyników:
//   Bubble Sort — O(n²): przy 10x większej tablicy czas rośnie ~100x
//   Quick Sort  — O(n log n): przy 10x większej tablicy czas rośnie ~33x
//   Merge Sort  — O(n log n): podobny wynik do Quick Sort, zawsze stabilny
// =============================================
int main() {
    srand(time(0));
    testuj(1000);
    testuj(5000);
    testuj(10000);
    return 0;
}
