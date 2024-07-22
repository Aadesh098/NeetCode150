// Two Sum 
// https://leetcode.com/problems/two-sum/description/

vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> check;
        for (int i = 0; i < nums.size(); i++) {
            int comp = target - nums[i];
            if (check.find(comp) != check.end()) {
                return {check[comp], i};
            }
            check[nums[i]] = i;
        }
        return {-1, -1};
    }