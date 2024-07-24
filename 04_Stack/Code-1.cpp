// Valid Parentheses
// https://leetcode.com/problems/valid-parentheses/description/

// Alrogithm 
// 1. Create a stack to store string elements 
// 2. Traverse the string 
// 3. If stack is empty -> push s[i]
// 4. Else -> Check if the stack.top element is an opening bracket nd the curr element is a closing bracket -> pop
// 5. If none of the conditions meet -> push s[i]

// Return Boolean -> ans.empty() 

bool isValid(string s) {
        stack<char> ans;
        for (int i = 0; i < s.length(); i++) {
            if (ans.empty()) {
                ans.push(s[i]);
            } else {
                if (ans.top() == '(' && s[i] == ')') {
                    ans.pop();
                } else if (ans.top() == '[' && s[i] == ']') {
                    ans.pop();
                } else if (ans.top() == '{' && s[i] == '}') {
                    ans.pop();
                } else {
                    ans.push(s[i]);
                }
            }
        }
        return ans.empty();
    }