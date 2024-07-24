// Evaluate Reverse Polish Notation
// https://leetcode.com/problems/evaluate-reverse-polish-notation/description/

// Algorithm 
// 1. Create a stack to store the numeric elements
// 2. Traverse all the tokens 
// 3. Extract the current token & check if it is a digit(isdigit(token[0])
// 4. If yes -> push(stoi(token)) & skip iteration 
// 5. Else extract the top 2 elements and perform the operation 
// 6. Store the result back in the stack 

// 7. Finally return the top element in the stack 

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