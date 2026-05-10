#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> maxOfSubarrays(vector<int>& arr, int k) {
    deque<int> dq;
    vector<int> result;

    for (int i = 0; i < arr.size(); i++) {

        while (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();

        while (!dq.empty() && arr[dq.back()] < arr[i])
            dq.pop_back();

        dq.push_back(i);

        if (i >= k - 1)
            result.push_back(arr[dq.front()]);
    }

    return result;
}

int main() {
    vector<int> arr = {1, 2, 3, 1, 4, 5, 2, 3, 6};
    int k = 3;

    vector<int> ans = maxOfSubarrays(arr, k);

    for (int x : ans)
        cout << x << " ";

    return 0;
}