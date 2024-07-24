// Valid Palindrome
// https://leetcode.com/problems/valid-palindrome/

// Algorithm 
// 1. Create two pointers i=0 & j=n-1 

// 2. Traverse the Array till (i<j)
// 3. If s[i] != alnum -> i++ 
// 4. If s[j] != alnum -> j-- 
// 5. If lower(s[i] != s[j]) -> return False 
// 6. Else Update Pointers i++ , j-- 

// 7. If no discrepencies found -> return True  

bool isPalindrome(string s) {
        int i = 0 ;
        int j = s.size()-1 ;
        while(i<j){
            if(!isalnum(s[i])){
                i++;
            }else if(!isalnum(s[j])){
                j-- ;
            }else if(tolower(s[i]) != tolower(s[j])){
                return false ;
            }else{
                i++ ;
                j-- ;
            }
        }
        return true ;
    }