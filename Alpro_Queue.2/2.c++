#include <iostream>      // Library untuk input dan output
#include <vector>        // Library vector
#include <deque>         // Library deque

using namespace std;     // Agar tidak perlu menulis std::

vector<int> findMaximumWindow(vector<int>& data, int windowSize) {

    // Deque untuk menyimpan index elemen
    deque<int> indexQueue;

    // Vector untuk menyimpan hasil maksimum
    vector<int> maximumResults;

    // Membaca seluruh elemen array
    for (int currentIndex = 0;
         currentIndex < data.size();
         currentIndex++) {

        // Menghapus index yang sudah keluar dari sliding window
        if (!indexQueue.empty() &&
            indexQueue.front()
            <= currentIndex - windowSize) {

            indexQueue.pop_front();
        }

        // Menghapus elemen yang nilainya lebih kecil
        // dari elemen baru
        while (!indexQueue.empty() &&

               data[indexQueue.back()]
               < data[currentIndex]) {

            indexQueue.pop_back();
        }

        // Menambahkan index elemen baru ke deque
        indexQueue.push_back(currentIndex);

        // Jika ukuran window sudah penuh
        if (currentIndex >= windowSize - 1) {

            // Mengambil nilai maksimum
            // dari bagian depan deque
            maximumResults.push_back(

                data[indexQueue.front()]
            );
        }
    }

    // Mengembalikan hasil akhir
    return maximumResults;
}

int main() {

    // Data array input
    vector<int> numbers =
    {1, 2, 3, 1, 4, 5, 2, 3, 6};

    // Ukuran sliding window
    int k = 3;

    // Memanggil function
    vector<int> output =
    findMaximumWindow(numbers, k);

    cout << "Maximum value in each window: ";

    // Menampilkan hasil akhir  
    for (int value : output) {

        cout << value << " ";
    }

    return 0;
}