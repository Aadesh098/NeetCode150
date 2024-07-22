// Min Stack
// https://leetcode.com/problems/min-stack/

vector<pair<int, int>> arr;
    MinStack() {}
    void push(int val) {
        if (arr.empty()) {
            pair<int, int> temp = {val, val};
            arr.push_back(temp);
        } else {
            pair<int, int> temp = {val, min(arr.back().second, val)};
            arr.push_back(temp);
        }
    }
    void pop() {
        if (arr.size() == 0) {
            return;
        }
        arr.pop_back();
    }
    int top() {
        if (arr.size() == 0) {
            return -1;
        }
        return arr.back().first;
    }
    int getMin() {
        if (arr.size() == 0) {
            return -1;
        }
        return arr.back().second;
    }