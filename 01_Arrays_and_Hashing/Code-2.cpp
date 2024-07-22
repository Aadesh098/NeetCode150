// Valid Anagram 
// https://leetcode.com/problems/valid-anagram/

bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false ;
        }
        unordered_map<char,int> smap ;
        unordered_map<char,int> tmap ;
        for(int i = 0 ; i<s.size() ; i++){
            smap[s[i]]++ ;
            tmap[t[i]]++ ;
        }
        for(auto& pair : smap){
            if(pair.second != tmap[pair.first]){
                return false ;
            }
        }
        return true ;
    }