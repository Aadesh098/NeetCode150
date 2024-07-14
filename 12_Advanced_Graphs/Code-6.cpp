// Cheapest Flights Within K Stops
// https://leetcode.com/problems/cheapest-flights-within-k-stops/description/

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> prices(n, INT_MAX);
        prices[src] = 0;
        for (int i = 0; i < k + 1; i++) {
            vector<int> tmpPrices(begin(prices), end(prices));
            for (auto it : flights) {
                int s = it[0];
                int d = it[1];
                int p = it[2];
                if (prices[s] == INT_MAX) continue;
                if (prices[s] + p < tmpPrices[d]) {
                    tmpPrices[d] = prices[s] + p;
                }
            }
            prices = tmpPrices;
        }
        return prices[dst] == INT_MAX ? -1 : prices[dst];
    }