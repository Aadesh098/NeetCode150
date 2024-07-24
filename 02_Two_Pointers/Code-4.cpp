// Container with Most Water 
// https://leetcode.com/problems/container-with-most-water/description/

// Algorithm 
// 1. Create two Pointers i=0 and j=n-1
// 2. Create an Ans variable 
// 3. Traverse the Array til i<j
// 4. Evaluate the current area = width * min(height[i] , height[j])
// 5. If the current area > and -> update ans 
// 6. If height[i] <= height[j] -> i++ ;
// 7. Else -> j-- 

// 8. Return Ans 


int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int ans = 0;
        while (i < j) {
            int curr = (j - i) * min(height[i], height[j]);
            ans = max(curr, ans);
            if (height[i] <= height[j]) {
                i++;
            } else {
                j--;
            }
        }
        return ans;
    }