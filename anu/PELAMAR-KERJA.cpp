#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Pelamar {
    string nama;
    float nilai_tes;
    float nilai_wawancara;
    float nilai_akhir;
    string status;
};

int main() {
    vector<Pelamar> pelamar_list;
    int pelamar_jumlah, data_valid = 0, data_tdk_valid = 0, lulus = 0;
    float total_nilai_akhir = 0, max1 = 0, max2 = 0, avg_nilai = 0;

    cout << "Masukkan jumlah pelamar: ";
    cin >> pelamar_jumlah;

    for (int i = 0; i < pelamar_jumlah; i++) {
        cout << "\nData pelamar ke-" << i+1 << endl;
        Pelamar p;

        cout << "Masukkan nama Pelamar: ";
        cin >> p.nama;
        cout << "Masukkan nilai tes: ";
        cin >> p.nilai_tes;
        cout << "Masukkan nilai wawancara: ";
        cin >> p.nilai_wawancara;

        if (p.nilai_tes < 0 || p.nilai_tes > 100 || p.nilai_wawancara < 0 || p.nilai_wawancara > 100) {
            cout << "Maaf data anda tidak valid\n";
            data_tdk_valid++;
            p.nilai_akhir = 0;
            p.status = "Tidak Valid";
        } else {
            data_valid++;
            p.nilai_akhir = (0.6 * p.nilai_tes) + (0.4 * p.nilai_wawancara);
            cout << "Nilai akhir: " << p.nilai_akhir << endl;

            if (p.nilai_akhir >= 75) {
                cout << "Selamat lulus!\n";
                p.status = "Lulus";
                lulus++;
            } else {
                cout << "Maaf tidak lulus\n";
                p.status = "Tidak Lulus";
            }

            if (p.nilai_akhir > max1) {
                max2 = max1;
                max1 = p.nilai_akhir;
            } else if (p.nilai_akhir > max2) {
                max2 = p.nilai_akhir;
            }

            total_nilai_akhir += p.nilai_akhir;
        }

        pelamar_list.push_back(p);
    }

    if (data_valid > 0) {
        avg_nilai = total_nilai_akhir / data_valid;
    }

    cout << "\n----- Rekap Hasil Tes -----\n";
    for (int i = 0; i < pelamar_list.size(); i++) {
        cout << pelamar_list[i].nama 
             << " | Nilai Akhir: " << pelamar_list[i].nilai_akhir 
             << " | Status: " << pelamar_list[i].status << endl;
    }
    cout << "---------------------------\n";
    cout << "Jumlah data tidak valid: " << data_tdk_valid << endl;
    cout << "Jumlah data valid: " << data_valid << endl;
    cout << "Jumlah pelamar lulus: " << lulus << endl;
    cout << "Rata-rata nilai: " << avg_nilai << endl;
    cout << "Dua nilai tertinggi: " << max1 << " dan " << max2 << endl;

    return 0;
}