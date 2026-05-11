#include <iostream>
#include <vector>
using namespace std;

bool isSorted(vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i - 1] > arr[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    vector<int> arr = {10, 20, 30, 40, 50};
    cout << (isSorted(arr) ? "true\n" : "false\n");

    return 0;
}
