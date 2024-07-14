// Valid Parentheses
// https://leetcode.com/problems/valid-parentheses/description/

bool isValid(string s) {
        stack<char> ans;
        for (int i = 0; i < s.length(); i++) {
            if (ans.empty()) {
                ans.push(s[i]);
            } else {
                if (ans.top() == '(' && s[i] == ')') {
                    ans.pop();
                } else if (ans.top() == '{' && s[i] == '}') {
                    ans.pop();
                } else if (ans.top() == '[' && s[i] == ']') {
                    ans.pop();
                } else {
                    ans.push(s[i]);
                }
            }
        }
        return ans.empty();
    }