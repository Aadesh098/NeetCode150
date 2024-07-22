// 3 Sum
// https://leetcode.com/problems/3sum/

vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> check;
        for (int i = 0; i < nums.size() - 2; i++) {
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                if (nums[i] + nums[j] + nums[k] == 0) {
                    check.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                } else if (nums[i] + nums[j] + nums[k] > 0) {
                    k--;
                } else {
                    j++;
                }
            }
        }
        vector<vector<int>> ans;
        for (auto it : check) {
            ans.push_back(it);
        }
        return ans;
    }