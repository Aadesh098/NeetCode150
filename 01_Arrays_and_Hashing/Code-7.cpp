// Product of Array Except Self
// https://leetcode.com/problems/product-of-array-except-self/

// Algorithm 
// 1. Create a Vector Ans and Initialize it with 1
// 2. Create a Variable Prefix = 1 ;

// 3. Traverse the Array and update Ans by Multiplying with Prefix 
// 4.  Update Prefix by Multiplying it with the Array Element 

// 5. Create a Variable Postfix = 1 ;
// 6. Traverse the Array in reverse and update Ans by Multiplying with Postfix 
// 7. Update Postfix by Multiplying it with the Array Element 

// 8. Return Ans

vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(), 1);
        int prefix = 1;
        for (int i = 0; i < nums.size(); i++) {
            ans[i] *= prefix;
            prefix *= nums[i];
        }
        int postfix = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            ans[i] *= postfix;
            postfix *= nums[i];
        }
        return ans;
    }