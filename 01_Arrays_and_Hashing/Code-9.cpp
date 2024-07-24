// Longest Common Subsequence
// https://leetcode.com/problems/longest-consecutive-sequence/description/

// Algorithm 
// 1. Create a Set for all the elements in the Array 
// 2. Create an ans variable 

// 3. Traverse the Array and check for an element if no Element-1 exists
// 4. If yes -> Find the length of the Sequence starting from the Element 
// 5. If the Sequence is longer than ans , we update ans 

// 6. Return Ans

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