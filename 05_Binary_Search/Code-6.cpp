// Time Based Key-Value Store
// https://leetcode.com/problems/time-based-key-value-store/

// Algorithm 
// 1. Create a Hashmap <string , vector<pair<int,string>>> Stores Key -> Vector(Pair(Timestamp , Value))
// 2. Set -> Push the timestamp and value at the relevant key
// 3. Get -> Check if the key exists in the Hashmap , if not return empty string
// 4. Declare 2 variables start = 0 , end = n-1
// 5. Implement Binary Search for the timestamp and return the relevant value
// 6. If not exact find maintain an ans variable to store the closest value such ans < timestamp
// 7. Return ans

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