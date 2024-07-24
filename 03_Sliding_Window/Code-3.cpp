// Longest Repeating Character Replacement
// https://leetcode.com/problems/longest-repeating-character-replacement/description/

// Algorithm 
// 1. Create a vector count (stores the frequency of each element)
// 2. Create 2 pointer i,j to represent the sliding window 
// 3. Create a variable ans=0 to store the maxSize of the window 
// 4. Create a variable maxCount=0 to store the maxCount element's frequency 

// 5. Traverse the array till (j<s.size())
// 6. Increment the frequency of current element 
// 7. Check if the maxCount needs to be updated 
// 8. Initiate a loop to validate the window (j-i+1-maxCount > k) 
// 9. Decrement the starting elements frequencies and update i accordingly 
// 10. Update Answer if the current window is largest
// 11. Increment j 

// 12. Return the Final Ans

int characterReplacement(string s, int k) {
        vector<int> count(26);
        int i = 0, j = 0;
        int ans = 0;
        int maxCount = 0;
        while (j < s.size()) {
            count[s[j] - 'A']++;
            maxCount = max(maxCount, count[s[j] - 'A']);
            while (j - i + 1 - maxCount > k) {
                count[s[i++] - 'A']--;
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }