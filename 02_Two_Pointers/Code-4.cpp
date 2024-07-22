// Container with Most Water 
// https://leetcode.com/problems/container-with-most-water/description/

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