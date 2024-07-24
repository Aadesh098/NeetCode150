// 3 Sum
// https://leetcode.com/problems/3sum/

// Algorithm
// 1. Sort the Input Array
// 2. Create a set<vector> to input unique answers 

// 3. Traverse the Complete Input Array till n-2 
// 4. Declare 2 pointers j,k nd Initialize them by i+1 and n-1 
// 5. Initatiate an Inner Loop till j<k
// 6. Evaulate Sum = (nums[i] + nums[j] + nums[k])
// 7. If sum == 0 -> add the elements to the set & update pointers
// 8. If sum > 0 -> k-- 
// 9. Else -> j++ 

// 10. Create vector<vector> ans 
// 11. Traverse the set and copy the set elements to the ans vector

// 12. Return Ans


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