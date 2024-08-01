// Daily Temperatures
// https://leetcode.com/problems/daily-temperatures/description/

vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<pair<int, int>> stk;
        vector<int> ans(n,0);
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