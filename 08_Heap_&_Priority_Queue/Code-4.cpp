// Kth Largest Element in an Array
// https://leetcode.com/problems/kth-largest-element-in-an-array/

// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         priority_queue<int, vector<int>, greater<int>> pq;
//         for (int i = 0; i < nums.size(); i++) {
//             pq.push(nums[i]);
//             if (pq.size() > k) {
//                 pq.pop();
//             }
//         }
//         return pq.top();
//     }
// };

class Solution {
public:
    int quickSelect(vector<int>& nums, int k, int l, int r) {
        int pivot = nums[r];
        int p_pos = l;
        for (int i = l; i < r; ++i) {
            if (nums[i] <= pivot) {
                swap(nums[i], nums[p_pos]);
                ++p_pos;
            }
        }
        swap(nums[p_pos], nums[r]);
        if (k < p_pos)
            return quickSelect(nums, k, l, p_pos - 1);
        if (k > p_pos)
            return quickSelect(nums, k, p_pos + 1, r);
        return nums[p_pos];
    }
    int findKthLargest(vector<int>& nums, int k) {
        int index = nums.size() - k;
        return quickSelect(nums, index, 0, nums.size() - 1);
    }
};