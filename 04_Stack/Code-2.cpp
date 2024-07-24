// Min Stack
// https://leetcode.com/problems/min-stack/

// Algorithm 
// 1. Create a vector of pairs to implement the stack
// 2. If no value exists in the array -> push {val,val}
// 3. Else push {val , min(val,previous min element)}

// 4. If array is empty -> return 
// 5. Else pop the last element

// 6. If array is empty -> return -1 
// 7. Else return arr.back().first 

// 8. If array is empty -> return -1 
// 9. Else retunr arr.back().second

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