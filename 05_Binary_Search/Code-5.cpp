// Search in Rotated Sorted Array
// https://leetcode.com/problems/search-in-rotated-sorted-array/

// Algorithm 
// 1. Declare 2 pointers start=0 , end=n-1 
// 2. Initiate a loop till (start<=end)
// 3. Evaluate mid & check if the target element exists at mid , if yes -> return mid
// 4. If the left subarray is sorted (nums[start] <= nums[mid]) 
// 5. Check if the target element exists in it , if yes -> (end=mid-1) , if no -> (start=mid+1) 
// 6. Else if the right subarray is sorted 
// 7. Check if the target element exists in it , if yes -> (start=mid+1) , if no -> (end=mid-1)

// 8. If no element found -> return -1 
int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                return mid;
            }else if (nums[start] <= nums[mid]) {
                if (nums[start] <= target && target <= nums[mid]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            } else {
                if (nums[mid] <= target && target <= nums[end]) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        return -1; 
    }