#include <stack>
#include <algorithm>

class MinStack {
private:
    std::stack<std::pair<int, int>> st;

public:
    MinStack() {}
    
    void push(int val) {
        if (st.empty()) {
            st.push({val, val});
        } else {
            st.push({val, std::min(val, st.top().second)});
        }
    }
    
    void pop() {
        if (!st.empty()) st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};