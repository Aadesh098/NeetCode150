// Top K Frequent Elements 
// https://leetcode.com/problems/top-k-frequent-elements/description/

vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> check;
        for (int i = 0; i < nums.size(); i++) {
            check[nums[i]]++;
        }
        vector<vector<int>> buckets(nums.size() + 1);
        for (auto& pair : check) {
            buckets[pair.second].push_back(pair.first);
        }
        vector<int> ans;
        for (int i = nums.size(); i >= 0; i--) {
            if (ans.size() >= k) {
                break;
            }
            for (int j = 0; j < buckets[i].size(); j++) {
                ans.push_back(buckets[i][j]);
            }
        }
        return ans;
    }

vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> check;
        for (int i = 0; i < nums.size(); i++) {
            check[nums[i]]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int, int>>>pq;
        for (auto &pair : check) {
            pq.push({pair.second, pair.first});
            if (pq.size() > k) {
                pq.pop();
            }
        }
        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }