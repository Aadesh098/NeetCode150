// Contains Duplicates 
// https://leetcode.com/problems/contains-duplicate/description/

// Algorithm 
// 1. Create a Hashmap to store the already occured elements 

// 2. Traverse the Complete Array and Check if the element occurs in the set already ?
// 3. If yes -> Return True 
// 4. If no -> Add the element to the set 

// 5. Return False if no Duplicate Found

bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> check; 
        for (int i = 0; i < nums.size(); i++){
            if (check.find(nums[i]) != check.end()) {
                return true;
            }
            check.insert(nums[i]);
        }
        return false;
    }