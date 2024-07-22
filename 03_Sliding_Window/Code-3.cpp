// Longest Repeating Character Replacement
// https://leetcode.com/problems/longest-repeating-character-replacement/description/

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