// Two Sum (Input Array Sorted)
// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/

// Algorithm 
// 1. Create 2 Pointers i=0 , j=n-1 

// 2. Traverse the array till (i<j)
// 3. Evaluate sum of elements 
// 4. If sum == target -> return Indexes 
// 5. If sum > target -> j-- 
// 6. Else -> i++ 

// 7. If a valid answer is not possible , Return {-1,-1}

vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = numbers.size() - 1;
        while (i < j) {
            int sum = numbers[i] + numbers[j];
            if (sum == target) {
                return {i + 1, j + 1};
            } else if (sum > target) {
                j--;
            } else {
                i++;
            }
        }
        return {-1, -1};
    }