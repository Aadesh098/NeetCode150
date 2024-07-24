// Generate Parentheses
// https://leetcode.com/problems/generate-parentheses/description/

// Algorithm
// 1. Create a vector string to store the ans 
// 2. Call a void helper funtion with vals -> n,open,close,curr_str,&ans
// 3. Base Case -> if open==n && close==n , push the curr->str to ans & return  
// 4. If (open count < n) add an opening bracket 
// 5. If (open count > close) add a closing bracket 

// 6. Return the ans 

void generate(int n, int open, int close, string str, vector<string>& ans) {
        if (open == n && close == n) {
            ans.push_back(str);
            return;
        }
        if (open < n) {
            generate(n, open + 1, close, str + '(', ans);
        }
        if (open > close) {
            generate(n, open, close + 1, str + ')', ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generate(n, 0, 0, "", ans);
        return ans;
    }