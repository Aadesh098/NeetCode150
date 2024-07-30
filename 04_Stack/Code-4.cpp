// Generate Parentheses
// https://leetcode.com/problems/generate-parentheses/description/

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