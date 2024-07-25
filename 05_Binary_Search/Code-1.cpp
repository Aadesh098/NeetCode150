// Binary Search 
// https://leetcode.com/problems/binary-search/

// Algorithm 
// 1. Declare 2 pointers start=0 , end=n-1 
// 2. Initiate a loop till (start <= end)
// 3. Evaluate the mid 
// 4. if element at mid == target -> return mid 
// 5. If element at mid > target -> end = mid-1
// 6. Else -> start = mid+1

// 7. If element not found return -1 ;

int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] < target) {
                start = mid + 1;
            } else if (nums[mid] > target) {
                end = mid - 1;
            } else {
                return mid;
            }
        }
        return -1;
    }