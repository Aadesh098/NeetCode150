// Minimum Window Substring 
// https://leetcode.com/problems/minimum-window-substring/description/

// Algorithm 
// 1. Create an unordrered_map to store char elements -> frequencies 
// 2. Traverse the string t and increment the frequencies of elements 
// 3. Create 2 pointers i=0 , j=0 to depict the size of the window 
// 4. Create 2 variables minStart=0 and minLength=inf to depict the smallest valid window
// 5. Create a variable counter=t.size() -> chars needed to match t string

// 6. Traverse string s till (s<s.size())
// 7. Check if elements frequency > 0 -> counter-- 
// 8. Decrement the frequency as we have the element & increment j
// 9. Validate the window -> While counter == 0 , check if the size of window is minimum 
// 10. Update the minStart and minLength pointers accorindgly 
// 11. Shrink the Size of window -> check[s[i]]++
// 12. If the element frequency > 0 -> counter++ , increment i 

// 13. If minLenght == INT_MAX return "" , else return the min substring

string minWindow(string s, string t) {
        unordered_map<char, int> check;
        for (int i = 0; i < t.size(); i++) {
            check[t[i]]++;
        }        
        int i = 0;
        int j = 0;
        int counter = t.size();        
        int minStart = 0;
        int minLength = INT_MAX;
        while (j < s.size()){
            if (check[s[j]] > 0) {
                counter--;
            }
            check[s[j]]--;
            j++;
            while (counter == 0) {
                if (j - i < minLength) {
                    minStart = i;
                    minLength = j - i;
                }
                check[s[i]]++;
                if (check[s[i]] > 0) {
                    counter++;
                }
                i++;
            }
        }        
        if (minLength != INT_MAX) {
            return s.substr(minStart, minLength);
        }
        return "";
    }