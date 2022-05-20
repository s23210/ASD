#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
#include <ostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

int partition(int arr[], int p, int r) {
    int x = arr[r];
    int i = p - 1;
    for (int j = p; j < r; j++) {
        if (arr[j] <= x) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[r]);
    return (i + 1);
}

void QS(int arr[], int p, int r) {
    if (p < r) {
        int q = partition (arr, p, r);
        QS (arr, p, q - 1);
        QS (arr, q + 1, r);
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

    QS(array, 0, (N - 1));

    clock_t end = clock();
    double elapsed = double(end - start) / CLOCKS_PER_SEC;

    for (int i = 0; i < N; i++) {
        cout << array[i] << endl;
    }

    cout << "Elapsed time: " << elapsed << " seconds" << "\n";

    //Zapisywanie posortowanej tablicy do sortedData.txt
    //
    // std::fstream file2("sortedData.txt");
    // if (!file2.good()) {
    //     return 0;
    // } else {
    //     for (int i = 0; i < N; i++) {
    //         int sorted = array[i];
    //         file2 << sorted << " ";
    //         file2.flush();
    //     }
    //     file2.close();
    // }

    //Zapisywanie odwrotnie posortowanej tablicy do downSortedData.txt
    //
    // std::fstream file2("downSortedData.txt");
    // if (!file2.good()) {
    //     return 0;
    // } else {
    //     for (int i = N-1; i >= 0; i--) {
    //         int sorted = array[i];
    //         file2 << sorted << " ";
    //         file2.flush();
    //     }
    //     file2.close();
    // }

    return 0;
}
