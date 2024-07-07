// Best Time to Buy and Sell Stock
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

int maxProfit(vector<int>& prices) {
        int ans = 0 ;
        int left = 0 ;
        for(int right = 0 ; right<prices.size() ; right++){ 
            if(prices[right] > prices[left]){
                ans = max(ans , prices[right]-prices[left]);
            }else{
                left = right ;
            }
        }
        return ans ;
    }