#include <stdio.h>
#include <string.h>

struct Kontak {
    char nama[50];
    char nomor[50];
};

void binary_iteratif(struct Kontak a[], int n, char key[]) {
    int low = 0;
    int high = n - 1;
    int ditemukan = 0;

    while (low <= high) {
        int mid = (low + high) / 2;
        int res = strcmp(key, a[mid].nama);

        if (res == 0) {
            printf("\n>>> Kontak '%s' ditemukan! Nomor: %s\n", a[mid].nama, a[mid].nomor);
            ditemukan = 1;
            break;
        } 
        else if (res < 0) {
            high = mid - 1;
        } 
        else {
            low = mid + 1;
        }
    }

    if (!ditemukan) {
        printf("\n>>> Pencarian '%s' gagal. Nama tidak ada dalam daftar.\n", key);
    }
}

int main() {
    struct Kontak bukuTelepon[] = {
        {"Iqdam", "0813"}, 
        {"Keisya", "0816"},
        {"Luffy", "0815"},
        {"Mozes", "0814"},
        {"Nadhira", "0812"}
    };
    int n = 5;
    char inputNama[50];

    printf("=== APLIKASI BUKU TELEPON ===\n");
    printf("Masukkan nama yang ingin dicari: ");
 
    scanf("%s", inputNama);

    printf("\n--- Sedang Mencari... ---\n");
    binary_iteratif(bukuTelepon, n, inputNama);

    return 0;
}