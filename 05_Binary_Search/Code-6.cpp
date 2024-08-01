// Time Based Key-Value Store
// https://leetcode.com/problems/time-based-key-value-store/

unordered_map<string, vector<pair<int, string>>> m;
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (m.find(key) == m.end()) {
            return "";
        }
        int start = 0;
        int end = m[key].size() - 1;
        string ans = "" ;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if(m[key][mid].first == timestamp){
                return m[key][mid].second ;
            }else if (m[key][mid].first < timestamp) {
                ans = m[key][mid].second;
                start = mid + 1;
            } else{
                end = mid - 1;
            }
        }
        return ans;
    }