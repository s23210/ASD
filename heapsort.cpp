#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;
void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);

        heapify(arr, i, 0);
    }
}

int main() {
    int array[500000];
    ifstream file;
    file.open("downSortedData.txt", ios::in);

    if (!file.good()) {
        return 0;
    } else {
        for (int i = 0; i < 500000; i++)
            file >> array[i];
    }

    file.close();

    int N = sizeof(array)/sizeof(array[0]);

    clock_t start = clock();

    heapSort(array, N);

    clock_t end = clock();

    double elapsed = double(end - start) / CLOCKS_PER_SEC;

    for (int i = 0; i < N; i++)
        cout << array[i] << endl;

    cout << "Elapsed time: " << elapsed << " seconds" << "\n";

    return 0;
}