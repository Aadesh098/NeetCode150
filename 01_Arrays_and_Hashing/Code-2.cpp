// Valid Anagram 
// https://leetcode.com/problems/valid-anagram/

// Algorithm
// 1. If the Length of Anagrams are Different Return False 
// 2. Create 2 Hashmaps to store character frequencies of the anagrams

// 3. Traverse both Anagrams and store the frequency of each character in the Hashmaps Created

// 4. Traverse through the smap and check if the Frequencies match ?
// 5. If no -> Return False ;

// 6. If all yes -> return True

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