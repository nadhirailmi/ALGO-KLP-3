// Library untuk menampilkan output ke layar
#include <iostream>

// Library untuk menggunakan tipe data vector
#include <vector>

// Supaya tidak perlu menulis std:: setiap saat
using namespace std;

// Fungsi untuk mengecek apakah array sudah urut
// bool artinya fungsi ini hanya mengembalikan true atau false
// vector<int>& arr artinya menerima inputan array angka
bool isSorted(vector<int>& arr) {

    // Perulangan dimulai dari index 1 bukan 0
    // Karena kita bandingkan elemen sebelumnya arr[i-1] dengan arr[i]
    // arr.size() menghitung jumlah elemen array secara otomatis
    for (int i = 1; i < arr.size(); i++) {

        // Cek apakah elemen sebelumnya lebih besar dari elemen sekarang
        // Kalau iya berarti array tidak urut
        if (arr[i - 1] > arr[i]) {

            // Langsung berhenti dan kembalikan false
            // Tidak perlu cek sisanya karena sudah pasti tidak urut
            return false;
        }
    }

    // Kalau semua elemen sudah dicek dan tidak ada yang salah
    // Berarti array sudah urut, kembalikan true
    return true;
}

// Fungsi utama, program selalu mulai berjalan dari sini
int main() {

    // Membuat array pertama yang sudah urut
    vector<int> arr1 = {10, 20, 30, 40, 50};

    // Membuat array kedua yang tidak urut
    vector<int> arr2 = {90, 80, 100, 70, 40, 30};

    // Menampilkan hasil untuk array pertama
    cout << "Input  : {10, 20, 30, 40, 50}" << endl;
    cout << "Output : " << (isSorted(arr1) ? "true" : "false") << endl;
    cout << "Explanation : The given array is sorted" << endl;


    // Menampilkan hasil untuk array kedua
    cout << "Input  : {90, 80, 100, 70, 40, 30}" << endl;
    cout << "Output : " << (isSorted(arr2) ? "true" : "false") << endl;
    cout << "Explanation : The given array is not sorted" << endl;

    // Program selesai berjalan dengan sukses
    return 0;
}