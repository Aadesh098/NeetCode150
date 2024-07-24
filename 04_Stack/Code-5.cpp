// Daily Temperatures
// https://leetcode.com/problems/daily-temperatures/description/

// Algorithm 
// 1. Create a stack of pair<int,int> to store day , temp
// 2. Create a vector<int> ans to store the answers
// 3. Traverse the complete array 
// 4. Extract the curr day nd curr temp in 2 variables 
// 5. Initiate a loop till stack empty or temp of previous day is less than curr temp
// 6. pop the previous day and update ans vector by the difference of the days
// 7. If the curr temp is less than previous day temp -> push it to stack 

// 8. Return ans vector  

vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<pair<int, int>> stk;
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            int currDay = i;
            int currTemp = temperatures[i];
            while (!stk.empty() && stk.top().second < currTemp) {
                int prevDay = stk.top().first;
                int prevTemp = stk.top().second;
                stk.pop();
                ans[prevDay] = currDay - prevDay;
            }
            stk.push({currDay, currTemp});
        }
        return ans;
    }