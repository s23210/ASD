|  | tablica losowych liczb | tablica posortowanych liczb | tablica odwrotnie posortowanych liczb |
|--|--|--|--|
| Quick Sort | 0.086s | ERROR | ERROR |
| Merge Sort | 0.132s | 0.099s | 0.099s |
| Heap Sort | 0.146s | 0.107s | 0.098s |
| Bubble Sort | 747.944s | 205.381s | 784.723s |

---

Wnioski:
- Quick sort nie działa dla dużych tablic liczb posortowanych (Error code=3221225725), nie ma znaczenia także, czy posortowane są w górę, czy w dół;
- Quick sort w najgorszym wypadku (tablica już posortowana w górę lub w dół) natrafia na problem przepełnienia stosu przez zbyt głęboką rekursję. Dzieje się tak, ponieważ dzieli tablicę na dwie niezbalansowane o wielkościach 0 oraz N - 1;
- Najszybszym algorytmem jest merge sort, a zaraz po nim trochę wolniejszy heap sort;
- Dla merge sort nie ma znaczenia, czy uprzednio posortowana tablica została posortowana w górę, czy w dół (czasy są porównywalne);
- Bubble sort jest najwolniejszym algorytmem;
- Bubble sort szybciej posortował tablicę liczb losowych, niż posortowanych odwrotnie;
- Dla każdego algorytmu posortowanie uprzednio posortowanej w górę tablicy jest dużo szybsze.