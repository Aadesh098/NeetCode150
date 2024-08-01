// Koko Eating Bananas
// https://leetcode.com/problems/koko-eating-bananas/description/

int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int start = 1;
        int end = 0;
        for (int i = 0; i < n; i++) {
            end = max(end, piles[i]);
        }
        int ans = end;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            long int hours = 0;
            for (int i = 0; i < n; i++) {
                hours += ceil((double) piles[i] / mid);
            } 
            if (hours <= h) {
                ans = min(ans, mid);
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }