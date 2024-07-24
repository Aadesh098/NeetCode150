// Two Sum 
// https://leetcode.com/problems/two-sum/description/

// Algorithm 
// 1. Create a Hashmap to store Elements and their Indexes

// 2. Traverse the Array 
// 3. Find the compliment of the Element for the Target 
// 4. Check if it exists in the Hashmap 
// 5. If yes -> Return the Indexes 

// 6. If all No -> Return {-1,-1}

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