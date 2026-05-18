#include <iostream>     // Library untuk input dan output
#include <vector>       // Library vector
#include <deque>        // Library deque

using namespace std;    // Agar tidak perlu menulis std::

vector<int> maxOfSubarrays(vector<int>& arr, int k) {

    deque<int> dq;      // Deque untuk menyimpan index kandidat maksimum

    vector<int> result; // Vector untuk menyimpan hasil akhir

    // Loop membaca seluruh elemen array
    for (int i = 0; i < arr.size(); i++) {

        // Menghapus index yang sudah keluar dari window
        while (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();

        // Menghapus elemen yang lebih kecil
        // karena tidak mungkin menjadi maksimum
        while (!dq.empty() &&
               arr[dq.back()] < arr[i])
            dq.pop_back();

        // Menambahkan index baru ke deque
        dq.push_back(i);

        // Jika window sudah penuh
        if (i >= k - 1)

            // Simpan nilai maksimum
            result.push_back(arr[dq.front()]);
    }

    // Mengembalikan hasil akhir
    return result;
}

int main() {

    // Data array
    vector<int> arr =
    {1, 2, 3, 1, 4, 5, 2, 3, 6};

    // Ukuran sliding window
    int k = 3;

    // Menjalankan function
    vector<int> ans =
    maxOfSubarrays(arr, k);

    // Menampilkan output
    for (int x : ans)
        cout << x << " ";

    return 0;
}