// Evaluate Reverse Polish Notation
// https://leetcode.com/problems/evaluate-reverse-polish-notation/description/

int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (int i = 0; i < tokens.size(); i++) {
            string token = tokens[i];
            if (token.size() > 1 || isdigit(token[0])) {
                stk.push(stoi(token));
                continue;
            }
            int num2 = stk.top();
            stk.pop();
            int num1 = stk.top();
            stk.pop();
            int ans = 0;
            if (token == "+") {
                ans = num1 + num2;
            } else if (token == "-") {
                ans = num1 - num2;
            } else if (token == "*") {
                ans = num1 * num2;
            } else {
                ans = num1 / num2;
            }
            stk.push(ans);
        }
        return stk.top();
    }