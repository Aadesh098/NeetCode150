// Longest Common Subsequence
// https://leetcode.com/problems/longest-consecutive-sequence/description/

int longestConsecutive(vector<int>& nums) {
        unordered_set<int> check(nums.begin() , nums.end());
        int ans = 0 ;
        for(auto it : check){
            if(check.find(it-1) == check.end()){
                int length = 1 ;
                while(check.find(it+length) != check.end()){
                    length++ ;
                }  
                ans = max(ans , length);
            }
        }
        return ans ;
    }