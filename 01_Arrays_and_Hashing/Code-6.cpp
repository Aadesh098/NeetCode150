// Encode and Decode String 
// https://neetcode.io/problems/string-encode-and-decode

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