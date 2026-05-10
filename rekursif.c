#include <stdio.h>
#include <string.h>

struct Kontak {
    char nama[50];
    char nomor[20];
};

int binarySearch(struct Kontak daftar[], int low, int high, char target[]) {
    if (low > high) {
        return -1;
    }

    int mid = low + (high - low) / 2;

    int res = strcmp(target, daftar[mid].nama);
    if (res == 0) {
        return mid;
    }

    if (res < 0) {
        return binarySearch(daftar, low, mid - 1, target);
    }  

    return binarySearch(daftar, mid + 1, high, target);
}

int main() {
    struct Kontak bukuTelepon[] = {
        {"Alice", "0812-111"},
        {"Budi", "0813-222"},
        {"Charlie", "0814-333"},
        {"Dewi", "0815-444"},
        {"Eko", "0816-555"}
    };
   
    int n = sizeof(bukuTelepon) / sizeof(bukuTelepon[0]);
    char cariNama[] = "Dewi";

    int hasil = binarySearch(bukuTelepon, 0, n - 1, cariNama);

    if (hasil != -1) {
        printf("Kontak ditemukan! %s: %s\n", bukuTelepon[hasil].nama, bukuTelepon[hasil].nomor);
    } else {
        printf("Kontak tidak ditemukan.\n");
    }

    return 0;
}