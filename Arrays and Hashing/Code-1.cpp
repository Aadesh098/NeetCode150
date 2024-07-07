// Contains Duplicates 
// https://leetcode.com/problems/contains-duplicate/description/

bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> check ;
        for(int i = 0 ; i<nums.size() ; i++){
            if(check.find(nums[i]) != check.end()){
                return true ;
            }
            check[nums[i]]++ ;
        }
        return false ;
    }