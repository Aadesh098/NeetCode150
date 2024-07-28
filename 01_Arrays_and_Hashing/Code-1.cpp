// Contains Duplicates 
// https://leetcode.com/problems/contains-duplicate/description/

bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> check ;
        for(int i = 0 ; i<nums.size() ; i++){
            if(check.find(nums[i]) != check.end()){
                return true ;
            }
            check.insert(nums[i]);
        }
        return false;
    }