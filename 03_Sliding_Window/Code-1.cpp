// Best Time to Buy and Sell Stock
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

// Algorithm 
// 1. Create a pointer left=0 to keep tack of buying Day
// 2. Create a variable ans=0 to store the max profit
// 3. Traverse the array , right = 1 -> n-1 (represents sell day)
// 4. If Selling Price(prices[right]) > Buying Price(prices[left])
// 5. check if the profit > maxProfit , if yes -> update ans 
// 6 Else Buy Day is updated to sell day (left = right)

// 7. Return ans 

int maxProfit(vector<int>& prices) {
        int ans = 0;
        int left = 0;
        for (int right = 1; right < prices.size(); right++) {
            if (prices[right] > prices[left]) {
                ans = max(ans, prices[right] - prices[left]);
            } else {
                left = right;
            }
        }
        return ans;
    }