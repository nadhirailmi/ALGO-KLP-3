#include <iostream>
#include <vector>

using namespace std;

void findIceCreamPair(int m, const vector<int>& prices) {
    int n = prices.size();
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (prices[i] + prices[j] == m) {
                cout << "Es krim dengan total 4 dolar adalah = " << (i + 1) << " dan " << (j + 1) << endl;
                return;
            }
        }
    }
}

int main() {
    int m = 4;
    vector<int> prices = {1, 4, 5, 3, 2};
    
    findIceCreamPair(m, prices);
    
    return 0;
}