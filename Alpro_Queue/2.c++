#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> cariMaksimumWindow(vector<int>& arr, int ukuranWindow) {

    deque<int> antreanIndeks;
    vector<int> hasil;

    // Perulangan untuk membaca seluruh array
    for (int i = 0; i < arr.size(); i++) {

        
        // Menghapus indeks yang sudah keluar dari window
      
        if (!antreanIndeks.empty() &&
            antreanIndeks.front() <= i - ukuranWindow) {

            antreanIndeks.pop_front();
        }

        
        // Menghapus elemen yang lebih kecil dari elemen baru
        // karena tidak mungkin menjadi maksimum
        
        while (!antreanIndeks.empty() &&
               arr[antreanIndeks.back()] < arr[i]) {

            antreanIndeks.pop_back();
        }

        // Menambahkan indeks baru ke deque

        antreanIndeks.push_back(i);


        // Jika window sudah penuh,
        // ambil nilai maksimum dari depan deque
    
        if (i >= ukuranWindow - 1) {

            hasil.push_back(
                arr[antreanIndeks.front()]
            );
        }
    }

    return hasil;
}

int main() {

    vector<int> data = {1, 2, 3, 1, 4, 5, 2, 3, 6};

    int k = 3;

    vector<int> output =
        cariMaksimumWindow(data, k);

    cout << "Hasil maksimum tiap window: ";

    for (int nilai : output) {
        cout << nilai << " ";
    }

    return 0;
}