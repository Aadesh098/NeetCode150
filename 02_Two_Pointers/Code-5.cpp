// Tapping Rain Water
// https://leetcode.com/problems/trapping-rain-water/description/

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