#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

int main() {
    int array[500000];

    ifstream file;
    file.open("unsortedData.txt", ios::in);

    if (!file.good()) {
        return 0;
    } else {
        for (int i = 0; i < 500000; i++)
            file >> array[i];
    }

    file.close();


    int N = sizeof(array)/sizeof(array[0]);

    clock_t start = clock();

    bubbleSort(array, N);

    clock_t end = clock();

    double elapsed = double(end - start) / CLOCKS_PER_SEC;

    for (int i = 0; i < N; i++) {
        cout << array[i] << endl;
    }

    cout << "Elapsed time: " << elapsed << " seconds" << "\n";

    return 0;
}