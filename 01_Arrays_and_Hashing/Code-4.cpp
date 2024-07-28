// Valid Anagrams 
// https://leetcode.com/problems/group-anagrams/

string getKey(string str) {
        vector<int> count(26);
        for (int i = 0; i < str.length(); i++) {
            count[str[i] - 'a']++;
        }
        string key = "";
        for (int i = 0; i < 26; i++) {
            key += to_string(count[i] + '#');
        }
        return key;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> check;
        for (int i = 0; i < strs.size(); i++) {
            string key = getKey(strs[i]);
            check[key].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for (auto& pair : check) {
            ans.push_back(pair.second);
        }
        return ans;
    }