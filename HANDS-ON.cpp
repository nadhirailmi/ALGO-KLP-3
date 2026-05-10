#include <iostream>
#include <vector>

using namespace std;

void findCemilan(int m, const vector<int>& harga) {
    int n = 6;
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (harga[i] + harga[j] == m) {
                cout << "Cemilan dengan total 10 adalah yang memiliki index = " << (i+1) << " dan " << (j+1) << endl;
                return;
            }
        }
    }
}

int main() {
    int m = 10;
    vector<int> harga = {2, 6, 3, 8, 4, 7};
    
    findCemilan(m, harga);
    
    return 0;
}