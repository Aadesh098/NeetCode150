// Largest Rectangle in Histogram
// https://leetcode.com/problems/largest-rectangle-in-histogram/

// Algorithm
// 1. Create a stack pair<int,int> to store the index and height of the element
// 2. Create an ans variable to store the maxArea
// 3. Traverse the complete input array
// 4. Create a variable start=i , to extend the histogram to left
// 5. Initiate a loop If stack not empty & previous height is larger
// 6. Calculate it's area and pop it 
// 7. Update ans and start=index
// 8. Push {start,heights[i]} to the stack

// 9. Calculate the area for bars that made till the end 
// 10. Update ans accordingly 

// 11. Return ans

int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> stk;
        int ans = 0;        
        for (int i = 0; i < heights.size(); i++) {
            int start = i;
            while (!stk.empty() && stk.top().second > heights[i]) {
                int index = stk.top().first;
                int width = i - index;
                int height = stk.top().second;
                stk.pop();
                ans = max(ans, height * width);
                start = index;
            }
            stk.push({start, heights[i]});
        }
        while (!stk.empty()) {
            int width = heights.size() - stk.top().first;
            int height = stk.top().second;
            stk.pop();
            ans = max(ans, height * width);
        }                 
        return ans;
    }