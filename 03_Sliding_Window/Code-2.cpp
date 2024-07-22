// Longest Substring Without Repeating Characters
// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

int lengthOfLongestSubstring(string s) {
        unordered_set<int> check;
        int ans = 0;
        int i = 0, j = 0;
        while (j < s.size()) {
            while (check.find(s[j]) != check.end()) {
                check.erase(s[i++]);
            }
            ans = max(ans, j - i + 1);
            check.insert(s[j]);
            j++;
        }
        return ans;
    }