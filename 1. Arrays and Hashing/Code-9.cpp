// Longest Common Subsequence
// https://leetcode.com/problems/longest-consecutive-sequence/description/

int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s(nums.begin(), nums.end());
        int longest = 0;
        for(auto &n: s){
            if(s.find(n-1) == s.end()){
                int length = 1; 
                while(s.count(n + length)){
                    ++length;
                }
                longest = max(longest, length);
            } 
        }
        return longest;
    }