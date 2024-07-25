// Find Minimum in Rotated Sorted Array
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/

// Algorithm
// 1. Declare 2 pointers start=0 , end=n-1 
// 2. Check if the input array is not rotated (nums[start] <= nums[end]) , if yes -> return the first element 
// 3. Initiate a loop till (start <= end)
// 4. Evaluate the mid element 
// 5. Check if we are at the pivot element (mid > 0 && nums[mid - 1] > nums[mid]) or nums[mid + 1] < nums[mid)
// 6. Return the relevant min element 
// 7. If the current subarray (nums[start]<=nums[mid]) is sorted move the mid to right part
// 8. Else move the mid to left part 

// 9. Return -1 if invalid input 

int findMin(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;
        if (nums[start] <= nums[end]) {
            return nums[start];
        }
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (mid > 0 && nums[mid - 1] > nums[mid]) {
                return nums[mid];
            } else if (mid < nums.size() - 1 && nums[mid + 1] < nums[mid]) {
                return nums[mid + 1];
            } else if (nums[start] <= nums[mid]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return -1;
    }