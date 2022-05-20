#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {

    clock_t start = clock();

    srand(time(0));

    std::fstream file("unsortedData.txt");
    if (!file.good()) {
        return 0;
    } else {
        for (int i = 0; i < 5000000; i++) {
            int random = rand();
            file << random << " ";
            file.flush();
        }
        file.close();
    }

    clock_t end = clock();

    double elapsed = double(end - start) / CLOCKS_PER_SEC;

    cout << "Czas: " << elapsed << "s";

    return 0;
}