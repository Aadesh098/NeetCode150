// Permutation in a String
// https://leetcode.com/problems/permutation-in-string/description/

// Algorithm 
// 1. Create variables m,n to store size of the two strings 
// 2. If s1 size > s2 size -> return false 
// 3. Create a vector count -> stores the frequency of each alphabet

// 4. Traverse both strings 0->m
// 5. Increase Frequencies of s1 elements and Decrease Frequencies of s2 elements 
 
// 6. Check if all alphabets frequency is 0. If yes -> return true 
// 7. Traverse the s2 stiring from m->n 
// 8. Increment the count of s2[i-m] elements and Decrement the count of s2[i] elements
// 9. Check if all alphabets frequency is 0. If yes -> return true 

// 10. If no valid permutation exists -> return false 

bool isPermutation(vector<int>& count) {
        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) {
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        if (m > n) {
            return false;
        }
        vector<int> count(26, 0);
        for (int i = 0; i < m; i++) {
            count[s1[i] - 'a']++;
            count[s2[i] - 'a']--;
        }
        if (isPermutation(count)) {
            return true;
        }
        for (int i = m; i < n; i++) {
            count[s2[i] - 'a']--;
            count[s2[i - m] - 'a']++;
            if (isPermutation(count)) {
                return true;
            }
        }
        return false;
    }