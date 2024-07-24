// Longest Substring Without Repeating Characters
// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

// Algorithm 
// 1. Create a set to store the occuring elements of the string 
// 2. Create 2 pointers to depict the sliding window 
// 3. Traverse the complete string till (j<s.size())
// 4. Validate the Window (Check if current element(s[j]) doesn't exist in set , if it does erase elements from the window start until it doesn't)
// 5. Calculate the size of valid window , check if it is larger than ans , update ans accordingly 
// 6. Insert the element (s[j])
// 7. Increment j 

// 8. Return ans

int lengthOfLongestSubstring(string s) {
        unordered_set<int> check;
        int ans = 0;
        int i = 0, j = 0;
        while (j < s.size()) {
            while (check.find(s[j]) != check.end()) {
                check.erase(s[i++]);
            }
            ans = max(ans, j - i + 1);
            check.insert(s[j]);
            j++;
        }
        return ans;
    }