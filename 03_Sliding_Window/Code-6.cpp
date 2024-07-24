// Sliding Window Maximum
// https://leetcode.com/problems/sliding-window-maximum/description/

// Algorithm 
// 1. Create a deque -> store the indices of max window values
// 2. Create an ans vector
// 3. Create 2 vairable i=0 , j=0 to depict the current window 
// 4. Traverse the input array till (j<nums.size())
// 5. While curr element > back elements of deque we pop
// 6. Insert the curr element in the deque
// 7. If the front index of queue goes out of window -> pop
// 8. If a valid window -> we push the front element in deque to ans
// 9. Increment i and j respectively 

//10. Return the ans vector
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        int i = 0;
        int j = 0;
        while (j < nums.size()) {
            while (!dq.empty() && nums[dq.back()] < nums[j]) {
                dq.pop_back();
            }
            dq.push_back(j);
            if (i > dq.front()) {
                dq.pop_front();
            }   
            if (j + 1 >= k) {
                ans.push_back(nums[dq.front()]);
                i++;
            }
            j++;
        }
        return ans;
    }