// Library untuk menampilkan output ke layar
#include <iostream>

// Library untuk menggunakan tipe data vector
#include <vector>

// Library untuk menggunakan fungsi bawaan is_sorted()
#include <algorithm>

// Supaya tidak perlu menulis std:: setiap saat
using namespace std;

// Fungsi untuk mengecek apakah array sudah urut
// bool artinya fungsi ini hanya mengembalikan true atau false
// vector<int>& arr artinya menerima inputan array angka
bool isSorted(vector<int>& arr) {

    // Menggunakan fungsi bawaan C++ yaitu is_sorted()
    // arr.begin() artinya mulai cek dari elemen pertama array
    // arr.end() artinya cek sampai elemen terakhir array
    // Fungsi ini otomatis mengecek semua elemen tanpa perlu buat loop sendiri
    return is_sorted(arr.begin(), arr.end());
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