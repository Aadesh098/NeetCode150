// Tapping Rain Water
// https://leetcode.com/problems/trapping-rain-water/description/

// Algorithm 
// 1. Create two pointers i=0 and j=n-1 
// 2. Create 2 variables to track heights -> maxLeft , maxRight 
// 3. Create an Ans Variable 
// 4. Traverse the Array till i<j
// 5. Check which maxHeight is lesser 
// 6. If maxLeft -> i++ , re-evluate max(maxLeft , hegiht[i]) 
// 7. Add the Trapped water(maxLeft - height[i]) to ans  
// 8. If maxRight -> j-- , re-evluate max(maxRight , height[j]) 
// 9. Add the Trapped water(maxRight - height[j]) to ans

// 10. Return Ans

int trap(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int maxLeft = height[i];
        int maxRight = height[j];
        int ans = 0;
        while (i < j) {
            if (maxLeft <= maxRight) {
                i++;
                maxLeft = max(height[i], maxLeft);
                ans += maxLeft - height[i];
            } else {
                j--;
                maxRight = max(height[j], maxRight);
                ans += maxRight - height[j];
            }
        }
        return ans;
    }