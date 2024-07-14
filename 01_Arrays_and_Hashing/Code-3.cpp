// Two Sum 
// https://leetcode.com/problems/two-sum/description/

vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> check ;
        for(int i = 0 ; i<nums.size() ; i++){
            int complement = target - nums[i] ;
            if(check.find(complement) != check.end()){
                return { check[complement] , i };
            }else{
                check.insert({nums[i] , i });
            }
        }
        return {-1 , -1};
    }