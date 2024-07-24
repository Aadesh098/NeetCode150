// Encode and Decode String 
// https://neetcode.io/problems/string-encode-and-decode

// Algorithm 
// 1. Encode - Create a String Ans 
// 2. Add the (Length of the String + # + String) to Ans for each string

// 3. Decode - Create a Vector<string> ans 
// 4. Traverse the Complete string
// 5. Scan the Length of the String via # and then extract the actual string via substr(startIndex , length)
// 6. Add the string to ans 
// 7. Update Relevant Variables 

// 8. Return ans

string encode(vector<string>& strs) {
        string ans = "" ;
        for(int i = 0 ; i<strs.size() ; i++){
            string str = strs[i] ;
            ans += to_string(str.size()) + '#' + str ;
        }
        return ans ;
    }

    vector<string> decode(string s) {
        vector<string> ans ;
        for(int i = 0 ; i<s.size() ;){
            int j = i ;
            while(s[j] != '#'){
                j++ ;
            }
            int length = stoi(s.substr(i,j-i));
            string str = s.substr(j+1 , length);
            ans.push_back(str);
            i = j+1+length;
        }
        return ans ;
    }