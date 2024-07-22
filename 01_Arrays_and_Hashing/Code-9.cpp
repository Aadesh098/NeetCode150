// Longest Common Subsequence
// https://leetcode.com/problems/longest-consecutive-sequence/description/

int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int ans = 0;
        for (auto n : s) {
            if (s.find(n - 1) == s.end()) {
                int length = 1;
                while (s.find(n + length) != s.end()) {
                    length++;
                }
                ans = max(ans, length);
            }
        }
        return ans;
    }