// Koko Eating Bananas
// https://leetcode.com/problems/koko-eating-bananas/description/

int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int start = 1;
        int end = 0;
        for (int i = 0; i < n; i++) {
            end = max(end, piles[i]);
        }
        int result = end;
        while (start <= end) {
            int k = start + (end - start) / 2;
            long int hours = 0;
            for (int i = 0; i < n; i++) {
                hours += ceil((double) piles[i] / k);
            }
            if (hours <= h) {
                result = min(result, k);
                end = k - 1;
            } else {
                start = k + 1;
            }
        }
        return result;
    }