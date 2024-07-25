// Koko Eating Bananas
// https://leetcode.com/problems/koko-eating-bananas/description/

// Algorithm 
// 1. Create 2 pointers start=1 , end= max element of the array (Establishes our ans space)
// 2. Create a variable ans=end , to store the min no. of bananas to eat in an hour
// 3. Initiate a loop (start <= end)
// 4. Evaluate mid 
// 4. Calculate the total hours taken if the eating rate is mid 
// 5. If it is less than previous ans & h , update ans & update end = mid-1
// 6. If more start=mid+1

// 7. Return ans
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