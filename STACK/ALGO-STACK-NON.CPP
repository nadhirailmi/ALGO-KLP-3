#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int main() {

    stack<pair<int, int>> st;
    cout << "--- Simulasi Min Stack ---" << endl;
    int val1 = -2;
    st.push({val1, val1});
    cout << "Push: " << val1 << " | Min: " << st.top().second << endl;
    int val2 = 0;
    int minSekarang = min(val2, st.top().second);
    st.push({val2, minSekarang});
    cout << "Push: " << val2 << "  | Min: " << st.top().second << endl;
    int val3 = -3;
    minSekarang = min(val3, st.top().second);
    st.push({val3, minSekarang});
    cout << "Push: " << val3 << " | Min: " << st.top().second << endl;
    cout << "\nNilai Minimum saat ini: " << st.top().second << endl;
    cout << "Melakukan Pop..." << endl;
    st.pop();
    cout << "Top sekarang: " << st.top().first << endl;
    cout << "Min sekarang: " << st.top().second << endl;
    return 0;

}